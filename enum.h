/*******************************************************************************
* This is free and unencumbered software released into the public domain.
*
* Anyone is free to copy, modify, publish, use, compile, sell, or distribute
* this software, either in source code form or as a compiled binary, for any
* purpose, commercial or non-commercial, and by any means.
*
* In jurisdictions that recognize copyright laws, the author or authors of this
* software dedicate any and all copyright interest in the software to the
* public domain. We make this dedication for the benefit of the public at large
* and to the detriment of our heirs and successors. We intend this dedication
* to be an overt act of relinquishment in perpetuity of all present and future
* rights to this software under copyright law.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* For more information, please refer to <http://unlicense.org/>
*
* If you use this software in a product, an acknowledgment in the product
* documentation would be appreciated but is not required.
*
* by Cassio Neri
******************************************************************************/

/// @file enum.h Definition of `ENUM_IMPLEMENT()`.

#ifndef ENUM_H_
#define ENUM_H_

#include <algorithm>
#include <cstring>
#include <type_traits>

#include "TPL.h"

/**
 * @defgroup enum Create enums and conversion functions with TPL.
 * 
 * The file enum.h implements the macro ENUM_IMPLEMENT() which takes a tuple
 * containing data for defining the \c enum, its enumerators and strings which the
 * enumerators can be converted to and from.
 */ 

#ifdef DOXYGEN
/**
 * @brief Convert an enumerator into a string.
 * 
 * If the conversion fails, then to_string_error_handler() is called to
 * handle the error. Notice that a failure in to_string() is probably caused
 * by a bug. Indeed, the given argument is generally a valid enumerator unless
 * it's obtained from casting an invalid integer value to the \c enum \c name.
 * 
 * Example:
 * <pre>
 * ENUM_IMPLEMENT(                   \\
 *     color, default, (             \\
 *         (red  , _, "Red"  , "R"), \\
 *         (green, _, "Green", "G"), \\
 *         (blue , _, "Blue" , "B")  \\
 *     )                             \\
 * )
 * 
 * assert(to_string(color::red  ) == std::string("Red"  ));
 * assert(to_string(color::green) == std::string("Green"));
 * assert(to_string(color::blue ) == std::string("Blue" ));
 * 
 * assert(to_string(color::red  ) != std::string("R"));
 * assert(to_string(color::green) != std::string("G"));
 * assert(to_string(color::blue ) != std::string("B"));
 * </pre>
 * 
 * @param val The enumerator to be converted.
 * 
 * @return The string.
 */
const char*
to_string(name val);
#endif

/**
 * @brief Handler of to_string() failures.
 * 
 * This function is called by to_string() to handle conversion errors. Only a
 * declaration is provided here and users must provide the implementation.
 * 
 * A failure in to_string() is probably due to a bug. Therefore, consider
 * calling std::terminate() in the implementation.
 * 
 * @param name The stringfied name of the \c enum.
 * @param val  The value of the enumerator that could not be converted.
 */
void
to_string_error_handler(const char* name, int val);

#ifdef DOXYGEN
/**
 * @brief Convert a string into an enumerator.
 * 
 * If the conversion fails, then to_value_error_handler() is called to
 * handle the error.
 * 
 * Example:
 * <pre>
 * ENUM_IMPLEMENT(                   \\
 *     color, default, (             \\
 *         (red  , _, "Red"  , "R"), \\
 *         (green, _, "Green", "G"), \\
 *         (blue , _, "Blue" , "B")  \\
 *     )                             \\
 * )
 * 
 * assert(color::red   == to_value<color>("Red"  ));
 * assert(color::green == to_value<color>("Green"));
 * assert(color::blue  == to_value<color>("Blue" ));
 * 
 * assert(color::Red   == to_value<color>("R"));
 * assert(color::Green == to_value<color>("G"));
 * assert(color::Blue  == to_value<color>("B"));
 * </pre>
 * 
 * @tparam name The \c enum name.
 * 
 * @param  str  The string to be converted.
 * 
 * @return The eenum_handlersnumerator.
 */
template <typename name>
name
to_value(const char* str);
#endif

/**
 * @brief Handler of to_value() failures.
 * 
 * This function is called by to_value() to handle conversion errors. Only a
 * declaration is provided here and users must provide the implementation.
 * 
 * @param name The stringfied name of the \c enum.
 * @param str  The string that failed to be converted.
 * @param strs The complete list of allowed strings.
 * @param n    The size of strs.
 */
void
to_value_error_handler(const char* name, const char* str,
  const char* strs[], std::size_t n);

/**
 * @brief Define an \c enum and implement conversion to_string() and
 * to_value().
 *
 * This is an example of how TPL macros can help metaprogramming. Calling
 * this macro passing in the data that <tt>enum</tt>s are based on (name,
 * enumerator, values and strings) will effortlessly define the \c enum and
 * implement the conversion functions to_string() and to_value().
 * 
 * This macro takes three arguments: the \c name of the \c enum, the \c flag
 * that specifies if enumerator values are default or user provided and a
 * tuple \c data containing enumerators data.
 * 
 * \c flag must be either \c default or \c user. In the former case,
 * enumerators will take default values: \c 0, \c 1, \c 2, etc. In the latter
 * case the values are provided by the user in \c data.
 * 
 * Each element of \c data is a tuple containing the data associated with
 * each enumerator. This tuple's first element is the enumerator name.
 * If \c flag is \c user, then the second element is the value of the
 * enumerator. If \c flag is \c default, then the second element is ignored
 * and the enumerator is given a default value. The remaining elements of
 * the tuple, from the third onwards, are literal strings which the
 * enumerator converts to and from. Any such string can be converted to the
 * enumerator through to_value(). Conversely, to_string() converts the
 * enumerator to its <em>main string</em>, that is, the first string
 * provided for the enumerator (i.e. the third element of the tuple).
 * 
 * Example:
 * <pre>
 * ENUM_IMPLEMENT(                   \\
 *     color, default, (             \\
 *         (red  , _, "Red"  , "R"), \\
 *         (green, _, "Green", "G"), \\
 *         (blue , _, "Blue" , "B")  \\
 *     )                             \\
 * )
 * </pre>
 *
 * This creates in the current scope (global, \c namespace or \c class) a
 * scoped \c enum named \c color with three enumerators: \c red, \c green
 * and \c blue. The enumerators have default values, i.e. \c 0, \c 1 and
 * \c 2 respectively.
 * 
 * In the same scope, it implements conversion functions `to_value()` and
 * `to_string()`. The former can convert \c "Red" and \c "R" to
 * \c color::red whereas the latter converts \c color::red to \c "Red".
 * Similar conversions apply between other enumerators and their associated
 * strings.
 *
 * If instead of default values, you want to set <tt>color::red = 1</tt>,
 * <tt>color::green = 2</tt> and <tt>color::blue = 4</tt>, then the
 * following should be used:
 * <pre>
 * ENUM_IMPLEMENT(                   \\
 *     color, user, (                \\
 *         (red  , 1, "Red"  , "R"), \\
 *         (green, 2, "Green", "G"), \\
 *         (blue , 4, "Blue" , "B")  \\
 *     )                             \\
 * )
 * </pre>
 * 
 * @param name The \c enum name.
 * @param flag Either \c default or \c user, indicates if enumerators take
 *             default or user provided values.
 * @param data Tuple containing data of each enumerator.
 *
 * @return Code defining the \c name, to_string() and to_value().
 */
#define ENUM_IMPLEMENT(name, flag, data)                                   \
   ENUM_DEF(name, flag, data)                                              \
   ENUM_TO_STRING(name, data)                                              \
   ENUM_TO_VALUE(name, data)                                               \
  
/**
 * @internal
 * @brief Define the \c enum.
 * 
 * @param name The \c enum name.
 * @param flag Either \c default or \c user, indicates if enumerators take
 *             default or user provided values.
 * @param data Tuple containing data of each enumerator.
 * 
 * @return Code defining the \c enum.
 */  
#define ENUM_DEF(name, flag, data)                                         \
  enum class name {                                                        \
    TPL_FOR_EACH_L(data, ENUM_DEF_ ## flag, _)                             \
  };                                                                       \
 
#define ENUM_DEF_default(data_i, _) TPL_HEAD(data_i)
#define ENUM_DEF_user(data_i, _) TPL_HEAD(data_i) = TPL_ELEMENT(data_i, 1)  

/**
 * @internal
 * @brief Define the conversion function to_string();
 * 
 * @param name The \c enum name.
 * @param data Tuple containing data of each enumerator.
 * 
 * @return Code defining to_string().
 */  
#define ENUM_TO_STRING(name, data)                                         \
  static inline const char*                                                \
  to_string(name val) {                                                    \
    switch (val) {                                                         \
      TPL_FOR_EACH_S(data, ENUM_TO_STRING_A, name)                         \
    }                                                                      \
    to_string_error_handler(#name, static_cast<int>(val));                 \
    return nullptr;                                                        \
  }                                                                        \

#define ENUM_TO_STRING_A(data_i, name)                                     \
  case name::TPL_HEAD(data_i) : return TPL_ELEMENT(data_i, 2);

/**
 * @internal
 * @brief Define the conversion function to_value();
 * 
 * @param name The \c enum name.
 * @param data Tuple containing data of each enumerator.
 * 
 * @return Code defining to_value().
 */  
#define ENUM_TO_VALUE(name, data)                                          \
  template <typename T>                                                    \
  static typename std::enable_if<std::is_same<T, name>::value, name>::type \
  to_value(const char* str) {                                              \
    const auto equal_to_str = [str](const char* s) {                       \
      return std::strcmp(s, str) == 0;                                     \
    };                                                                     \
    static const char* strs[] = { ENUM_TO_VALUE_STRS(data) };              \
    static const int size = sizeof(strs) / sizeof(char*);                  \
    auto idx = std::find_if(strs, strs + size, equal_to_str) - strs;       \
    static const name vals[] = { ENUM_TO_VALUE_VALS(name, data) };         \
    if (idx < size) return vals[idx];                                      \
    static const char* main_strs[] = { ENUM_TO_VALUE_MAIN_STRS(data) };    \
    to_value_error_handler(#name, str, main_strs, TPL_SIZE(data));         \
    return name();                                                         \
  }

/**
 * @internal
 * @brief Get the list of all strings (including aliases).
 * 
 * @param data Tuple containing data of each enumerator.
 * 
 * @return The list of all strings.
 */  
#define ENUM_TO_VALUE_STRS(data)                                           \
  TPL_FOR_EACH_L(data, ENUM_TO_VALUE_STRS_A, _)
  
#define ENUM_TO_VALUE_STRS_A(data_i, _)                                    \
  TPL_TO_LIST(TPL_TAIL(TPL_TAIL(data_i)))

/**
 * @internal
 * @brief Get the list of values with repetition.
 * 
 * @param name The \c enum name.
 * @param data Tuple containing data of each enumerator.
 * 
 * @return The list of all strings.
 */  
#define ENUM_TO_VALUE_VALS(name, data)                                     \
  TPL_FOR_EACH_L(data, ENUM_TO_VALUE_VALS_A, name)

#define ENUM_TO_VALUE_VALS_A(data_i, name)                                 \
  ENUM_REPEAT(name::TPL_HEAD(data_i), TPL_SIZE(TPL_TAIL(TPL_TAIL(data_i))))
  
/**
 * @internal
 * @brief Create a list of a given size where all the elements are equal.
 * 
 * @param val The value of the elements.
 * @param n   The size of the list.
 *
 * @pre n > 0. 
 */  
#define ENUM_REPEAT(val, n)                                                \
  TPL_TO_LIST(TPL_TAIL(TPL_RECURSE((val), n, ENUM_REPEAT_A)))
  
#define ENUM_REPEAT_A(t) TPL_APPEND(t, TPL_HEAD(t))

/**
 * @internal
 * @brief Get the list of main strings.
 * 
 * The main string of an enumerator is the first (third argument of the
 * tuple).
 * 
 * @param val The value of the elements.
 * @param n   The size of the list.
 *
 * @return The list of main strings.
 */  
#define ENUM_TO_VALUE_MAIN_STRS(data)                                      \
  TPL_FOR_EACH_L(data, ENUM_TO_VALUE_MAIN_STRS_A, _)
   
#define ENUM_TO_VALUE_MAIN_STRS_A(data_i, _)                               \
  TPL_ELEMENT(data_i, 2)

#endif // ENUM_H_
