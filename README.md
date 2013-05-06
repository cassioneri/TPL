TPL: A preprocessor library for tuple manipulation {#mainpage}
==



Introduction
--

This library provides preprocessor macros to manipulate tuples. Consider
this simple example.

~~~{.c}
#include <iostream>
#include "TPL.h"

#define PRINT(x) std::cout << x

int main() {
    TPL_FOR_EACH(("Hello World ", 2013, '!'), PRINT);
}
~~~

Macro `TPL_FOR_EACH()` takes a tuple and a macro function and returns
another tuple obtained by memberwise application of the given macro
function. Hence, the line in `main()` first expands to
~~~{.c}
(PRINT("Hello World "), PRINT(2013), PRINT('!'));
~~~
and subsequently to
~~~{.c}
(std::cout << "Hello World ", std::cout << 2013, std::cout << '!');
~~~
Therefore, `Hello World 2013!` will appear on the screen.

A more interesting example is given in `enum.h`. It defines the macro
`ENUM_IMPLEMENT()` that effortlessly create `enum`s and implements
conversion functions to/from strings. For instance, this code
~~~{.c}
ENUM_IMPLEMENT(                   \
    color, default, (             \
        (red  , _, "Red"  , "R"), \
        (green, _, "Green", "G"), \
        (blue , _, "Blue" , "B")  \
    )                             \
)
~~~
creates a scoped `enum` named `color` with three enumerators: `red`, `green`
and `blue`. The enumerators have default values, i.e. `0`, `1` and `2` 
respectively. Strings "Red" and "R" can be converted to red through
`to_value()` and `color::red` can be converted to "Red" through
`to_string()`. Similar facts hold for the other enumerators and their
corresponding strings.



Definitions and conventions
---

TPL adopts the following terminology:

* A **sequence** is a collection of tokens separated by spaces. Example:
~~~{.c}
a b c
~~~
is a sequence with three elements: `a`, `b` and `c`.
 
* A **list** is a collection of tokens separated by commas. Example:
~~~{.c}
a, b, c
~~~
is a list with three elements: `a`, `b` and `c`.
 
* A **tuple** is a list surrounded by parenthesis. Example:
~~~{.c}
(a, b, c)
~~~
is a tuple with three elements: `a`, `b` and `c`.

* A **macro function** is a macro that acts similarly to a function and is
expanded only if its name appears with a pair of parentheses after it.
Examples:
~~~{.c}
#define MAX(a, b) (a>b?a:b) // MAX doesn't expand. MAX(1, 2) expands to 2.
#define ZERO() 0            // ZERO doesn't expand. ZERO() expands to 0.
~~~
contrast those with
~~~{.c}
#define ONE 1               // ONE expands to 1. This is not a macro function.
~~~

Some of macros have both tuple and list versions. In this case, the list
version has a suffix `_L`. For instance, TPL_HEAD() yields the head of a
tuple whereas `TPL_HEAD_L()` gives the head of a list:
~~~{.c}
TPL_HEAD((a, b, c)) // expands to a.
TPL_HEAD_L(a, b, c) // expands to a.
~~~



Supported compilers
---

TPL has been sucessfully tested with:

* GCC 4.7.2
* Clang 3.2
* Intel Compiler 13.1.0
* Visual Studio 2012

However, the example `enum.h` depends on some C++11 features (notably,
scoped `enum`s) which the Intel Compiler 13.1.0 doesn't support.



Known issues
---

**The maximum tuple and list size is 64**: Most of TPL macros need to obtain
the size of a tuple or list. (Failing to correctly perform this task yields
undefined behaviour.) This is done through `TPL_SIZE_L()` and boils down to
getting the number of arguments given to a variadic macro. Unfortunately,
most preprocessors don't provide intrinsic support for this task. Although
TPL can work around this, it's limitted to tuples and lists with at most 64
elements.

**Recursion is emulated and limited to 64 levels**: Macros don't support
recursion and the preprocessor stops the expansion when it detects one. For
instance, consider:
~~~{.c}
#define RECURSIVE(x) x, RECURSIVE(x + 1)
~~~ 
Then `RECURSIVE(1)` expands to
~~~{.c}
1, RECURSIVE(1 + 1)
~~~
This behavior does make sense: Had the expansion continued further,
when should it stop? (Recall that there's no `if` inside a macro.)

The first consequence is that we can't nest a TPL macro inside itself. For
instance, consider the following macros to get the square of the Euclidean
norm of a tuple:
~~~{.c}
#define EUCLIDEAN_NORM_HELPER(x) (x * x) +
#define EUCLIDEAN_NORM_SQR(v) TPL_FOR_EACH_S(v, EUCLIDEAN_NORM_HELPER) 0
~~~
Then, `EUCLIDEAN_NORM_SQR((1, 2, 3))` expands to
~~~{.c}
(1 * 1) + (2 * 2) + (3 * 3) + 0
~~~
So far so good. Consider now that a matrix is defined by a tuple of tuples.
A natural idea to get its norm squared would be
~~~{.c}
#define MATRIX_NORM_HELPER(v) EUCLIDEAN_NORM_SQR(v) +
#define MATRIX_NORM_SQR(m) TPL_FOR_EACH_S(m, MATRIX_NORM_HELPER) 0
~~~
Notice that `MATRIX_NORM_SQR()` calls `TPL_FOR_EACH_S()` which calls
`MATRIX_NORM_HELPER()` which calls `EUCLIDEAN_NORM_SQR()` which calls
`TPL_FOR_EACH_S()` again. Hence, the expansion will stops. Indeed,
`MATRIX_NORM_SQR( ( (1, 2, 3), (4, 5, 6) ) )` expands to
~~~{.c}
TPL_FOR_EACH_S((1, 2, 3), EUCLIDEAN_NORM_HELPER ) 0 + TPL_FOR_EACH_S((4, 5, 6), EUCLIDEAN_NORM_HELPER) 0 + 0
~~~

Although recursion is impossible, it can be emulated by making a sequence of
distinct macros calling each other as the following example illustrates.
~~~{.c}
#define RECURSIVE_3(x) x, RECURSIVE_2(x + 1)
#define RECURSIVE_2(x) x, RECURSIVE_1(x + 1)
#define RECURSIVE_1(x) x  // stops here
RECURSIVE_3(1)
~~~
The last line expands to
~~~{.c}
1, 1 + 1, 1 + 1 + 1
~~~
This emulation technique is behind a few TPL macros (e.g `TPL_FOR_EACH()`).
The sequences of macros used to emulate recursion are define in file
`TPLRecursion.h`. Each sequence is, obvioulsy, finite and this imposes a
limit on the number of "recursion" levels which is 64.



**Some macros are dangerous:** As said above, most TPL macros depend on the
proper functioning of `TPL_SIZE_L()` which in turn depends on the
correctness of `TPL_IS_EMPTY()`. Surprinsingly, this macro's implementation
(borrowed from
[Jens Gustedt](https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/))
is not straightforward because the preprocessor considers an empty list of
arguments as a list having one argument which is empty. Hence, distinghish
lists with zero and one argument is very tricky. Although it works for most
of cases `TPL_IS_EMPTY()` can still be fooled by some dangerous macros whose
expansions start with parenthesis. For instance
~~~{.c}
#define FOOLISH() (
TPL_IS_EMPTY_L(FOOLISH)
~~~
yields the following error on the GNU preprocessor:
> unterminated argument list invoking macro "TPL_HAS_COMMA_L_A"
Despite the diagnostics, the preprocessor carries on and expands the macro
to `0`.

A worse example is this
~~~{.c}
#define NOT_EMPTY (a)
TPL_IS_EMPTY_L(NOT_EMPTY)
~~~
which silently (no error is reported) expands to `1`.



Related work
---

[Boost.Preprocessor](http://www.boost.org/doc/libs/1_53_0/libs/preprocessor/doc/index.html)
is another library which provides preprocessor macros to manipulate tuples
and other data types. Specifically for tuples, it provides two families of
functions: *variadic* and *non variadic*. Non variadic functions require the
user to pass the size of the tuple as an argument. This is annoying and
error prone. Variadic functions can deduce the size of the tuple but
apparently don't work properly with zero-sized tuples as the next example
shows:
~~~{.c}
#define BOOST_PP_VARIADICS
#include <boost/preprocessor/tuple/size.hpp>

BOOST_PP_TUPLE_SIZE((a)) // OK: expands to 1.
BOOST_PP_TUPLE_SIZE(())  // Wrong: also expands to 1.
~~~

Being able to work with zero-sized tuples wasn't the main motivation for
writting TPL though. I've wanted to learn more about preprocessor
metaprogramming techniques and TPL was an exercise that I set myself to.
Others can benefit from studing the code which is self-contained (two header
files) and, IMHO, much simpler to understand than Boost's.



Makefile tags
---

The `makefile` shipped with TPL can run tests and build an example.
More precisely, the main available tags are described below.

* **all**

  Same as `make test && make color && make recursion`.

* **clean**

  Remove `color`, `recursion` and `results.txt`.

* **color**

  Build the executable `color` which tests macro `ENUM_IMPLEMENT()` defined
  in `enum.h`.

* **doc**

  Same as `make html && make pdf`.

* **html**

  Generate HTML documentation -- `html/index.html`. (Requires doxygen.)

* **pdf**

  Generate the PDF documentation -- `TPL.pdf`. (Requires doxygen and latex.)

* **recursion**

  Build the executable `recursion` which is used to generate
  `TPLRecursion.h`. You don't need this unless you want to change the
  maximum allowed tuple size (currently `64`).

* **test**

  Run the preprocessor on `test.cpp` and `diff` the result against
  `expect.txt`. If they don't match, it means that the test have failed and
  the differences will be shown.



Files
---

The following describes the files in this repository. To use the library
you only need `TPL.h` and `TPLRecursion.h`.

* `color.h`, `color.cpp` and `color2.cpp`

  Test macro `ENUM_IMPLEMENT()` defined in `enum.h`. You can build the
  executable with `make color`.

* `doxyfile`

  Used to generate the documentation.

* `enum.h`

  This is an example built on top of TPL. It defines macro
  `ENUM_IMPLEMENT()` which effortlessly implements `enum`s and conversion
  functions to/from string.

* `expected.txt`

  Expected output from preprocessing `test.cpp`. You can run the tests with
  `make test`. This will produce a file `results.txt` which is compared with
  `expected.txt`.

* `makefile`

  To run the test, build the example and do other tasks.

* `README.md`

  Main documentation page. (The page that you're reading right now.)

* `recursion.cpp`

  This program helps to generate `TPLRecursion.h`.

* `test.cpp` 

  Unit tests for TPL. This file is not meant to be compiled but only
  preprocessed. You can use `make test` for this task.

* `TPL.h` and `TPLRecursion.h`

  Implemention of TPL macros.

* `TPL.pdf`

  The PDF documentation.

* `vs2012/*`

  Solution and project files for VS2012. (Not as complete as the makefile.)
