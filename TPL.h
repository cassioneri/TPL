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

/// @file TPL.h Definition of TPL macros library.

#ifndef TPL_H_
#define TPL_H_

#include "TPLRecursion.h"

/**
 * @internal
 * @brief Identity.
 *
 * Used to add an extra level of indirection and delay concatenation.
 * Specially useful for MSVC when appending a tuple to a macro function
 * to create a function-like macro expansion.
 *
 * Example: Let \c t = <tt>(a, b, c)</tt> and \c F be a function-like macro.
 * Then <tt>TPL_ID(F t)</tt> expands to <tt>F (a, b, c)</tt> and \c F is
 * expanded with arguments \c a, \c b and \c c.
 *
 * @param x The input.
 *
 * @return x.
 */
#define TPL_ID(x) x

/**
 * @internal
 * @brief Concatenate two tokens.
 *
 * Example: <tt>TPL_CAT(F_, 5)<tt> expands to \c F_5.
 *
 * The GNU Preprocessor raises an error when \c TPL_CAT is used with a
 * tuple. For instance, if \c t = <tt>(1, 2)<\tt>, then
 * <tt>TPL_CAT(F, t)<\tt> gives an error. Funilly enough, the preprocessor
 * doesn't stop: it expands <tt>F(t)</tt> if \c F is a macro function and
 * continue processing the file. To avoid this error, use <tt>F t</tt> or
 * <tt>TPL_ID(F t)<\tt>.
 * 
 * @param x The left of the concatenation.
 * @param y The right of the concatenation.
 * 
 * @return The concatenation of \e x and \e y
 **/
#define TPL_CAT(x, y) TPL_CAT_A(x, y)
#define TPL_CAT_A(x, y) x ## y

/**
 * @brief Converts tuple to list.
 * 
 * Example: <tt>TPL_TO_LIST((a, b, c))</tt> expands to <tt>a, b, c</tt>
 * 
 * @param t The tuple.
 *
 * @return The list.
 */
#define TPL_TO_LIST(t) TPL_ID(TPL_TO_LIST_A t)
#define TPL_TO_LIST_A(...) __VA_ARGS__

/**
 * @brief Test if a tuple is empty or not.
 * 
 * Example: <tt>TPL_IS_EMPTY(())</tt> expands to \c 1 and
 * <tt>TPL_IS_EMPTY((a, b, c))</tt> expands to \c 0.
 * 
 * @param t The tuple.
 * @return 1 if the tuple is empty and 0 otherwise.
 */
#define TPL_IS_EMPTY(t) TPL_ID(TPL_IS_EMPTY_L t)

/**
 * @internal
 * @brief Get the 65-th element of a list.
 *
 * @param ... The list.
 * 
 * @return The 65-th element of the list.
 */
#define TPL_ELEMENT_65_L(                                                  \
  x01, x02, x03, x04, x05, x06, x07, x08,                                  \
  x09, x10, x11, x12, x13, x14, x15, x16,                                  \
  x17, x18, x19, x20, x21, x22, x23, x24,                                  \
  x25, x26, x27, x28, x29, x30, x31, x32,                                  \
  x33, x34, x35, x36, x37, x38, x39, x40,                                  \
  x41, x42, x43, x44, x45, x46, x47, x48,                                  \
  x49, x50, x51, x52, x53, x54, x55, x56,                                  \
  x57, x58, x59, x60, x61, x62, x63, x64,                                  \
  x65, ...) x65

/**
 * @internal
 * @brief Check if a list has a comma or not or, in other words if has two
 * or more elements.
 *
 * @param ... The list.
 * 
 * @return 1, if the list has a comma, or 0, otherwise.
 */
#define TPL_HAS_COMMA_L(...) TPL_HAS_COMMA_L_A((__VA_ARGS__,               \
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                          \
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                          \
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,                          \
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))
  
#define TPL_HAS_COMMA_L_A(t) TPL_ID(TPL_ELEMENT_65_L t)  

/**
 * @internal
 * @brief Return a comma.
 * 
 * @param ... Ignored.
 * 
 * @return ,
 */  
#define TPL_COMMA(...) ,
  
/**
 * @brief Test if a list is empty or not.
 * 
 * Example: <tt>TPL_IS_EMPTY_L()</tt> expands to \c 1 and
 * <tt>TPL_IS_EMPTY_L(a, b, c)</tt> expands to \c 0.
 * 
 * @param ... The list.
 * @return 1 if the list is empty and 0 otherwise.
 */
#define TPL_IS_EMPTY_L(...) TPL_IS_EMPTY_L_A(                              \
  TPL_HAS_COMMA_L(__VA_ARGS__),                                            \
  TPL_HAS_COMMA_L(TPL_COMMA __VA_ARGS__),                                  \
  TPL_HAS_COMMA_L(__VA_ARGS__ ()),                                         \
  TPL_HAS_COMMA_L(TPL_COMMA __VA_ARGS__ ()))
  
#define TPL_IS_EMPTY_L_A(x0, x1, x2, x3) TPL_HAS_COMMA_L(                  \
   TPL_CAT(TPL_CAT(TPL_CAT(TPL_CAT(TPL_IS_EMPTY_CASE_, x0), x1), x2), x3))
   
#define TPL_IS_EMPTY_CASE_0001 ,

/**
 * @brief Get the size of a tuple.
 *
 * Example: <tt>TPL_SIZE((a, b, c))</tt> expands to \c 3.
 *
 * @param t The tuple.
 *
 * @return The size of t.
 */
#define TPL_SIZE(t) TPL_ID(TPL_SIZE_L t)

/**
 * @brief Gets the size of a list.
 *
 * Example: <tt>TPL_SIZE_L(a, b, c)</tt> expands to \c 3.
 *
 * @pre The number of elements cannot exceed \c 64.
 * 
 * @param ... The list.
 *
 * @return The size.
 */
#define TPL_SIZE_L(...)                                                    \
   TPL_SIZE_L_A(TPL_IS_EMPTY_L(__VA_ARGS__), __VA_ARGS__)
  
#define TPL_SIZE_L_A(e, ...)                                               \
  TPL_ID(TPL_CAT(TPL_SIZE_L_C, e) (__VA_ARGS__))
  
// Size of empty tuple
#define TPL_SIZE_L_C1(...) 0

// Size of non empty tuple. Let n the number of argumenst and consider an
// augumented list starting with __VA_ARGS__ followed by 64, 63, ..., 1. If
// n = 64, then the 65-th element of the augumented list is 64. If n = 63,
// then the 65-th element of the augumented  list is 63. In general, if
// n <= 64 then the 65-th element of the list is n. (If n > 64, then the
// 65-th element of the augumented list is the 65-th element of the original
// list and not its size.) The extra pair of parenthesis below is a
// workaround for MSVC because otherwise, it sees __VA_ARGS__ as a single
// token.
#define TPL_SIZE_L_C0(...) TPL_SIZE_L_D((__VA_ARGS__, 64, 63, 62, 61, 60,  \
  59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42,  \
  41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24,  \
  23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  \
   5,  4,  3,  2,  1))

#define TPL_SIZE_L_D(t) TPL_ID(TPL_ELEMENT_65_L t)

// The original idea was taken from [1]. It was also suggested in [1] to add
// an extra level of indirection while concatenating TPL_SIZE_L's result
// with prefix to form new macro functions (e.g., TPL_ELEM_1). However, the
// suggestion was to add the indirection to the functions that concatenate
// the prefix to TPL_SIZE_L's result. Alternatively, I found that adding the
// indirection through TPL_ID (see TPL_SIZE_L_ii) solves this issue once for
// all. The idea to handle 0 size lists was taken from [2].
// [1] http://efesx.com/2010/07/17/variadic-macro-to-count-number-of-arguments/
// [2] https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/

/**
 * @internal
 * @brief Concatenate a prefix with \c 0, \c 1 or \c 2 and call the
 * resulting macro function passing given arguments.
 *
 * Given a number \e n, the prefix is concatenated to <tt>min(\e n, 2)</tt>.
 * This is a helper to other macros (e.g. \c TPL_HEAD and \c TPL_TAIL) where
 * the definition of the macro depends on the number of arguments being \c 0,
 * \c 1 or more.
 *
 * Examples:
 * 
 * \li <tt>TPL_APPLY_012(F_, 0, a, b, c)</tt> expands to
 *     <tt>F_0(a, b, c)</tt>.
 * \li <tt>TPL_APPLY_012(F_, 1, a, b, c)</tt> expands to
 *     <tt>F_1(a, b, c)</tt>.
 * \li <tt>TPL_APPLY_012(F_, 2, a, b, c)</tt> expands to
 *     <tt>F_2(a, b, c)</tt>.
 * \li <tt>TPL_APPLY_012(F_, 3, a, b, c)</tt> expands to
 *     <tt>F_2(a, b, c)</tt>.
 *
 * @param p   The macro prefix.
 * @param n   Defines the concatenation number, that is, <tt>min(n, 2)</tt>.
 * @param ... The arguments.
 */
#define TPL_APPLY_012(p, n, ...)                                           \
  TPL_APPLY_012_A(p, TPL_CAT(TPL_MIN_WITH_TWO_, n), __VA_ARGS__)

#define TPL_APPLY_012_A(p, n, ...)                                         \
  TPL_ID(TPL_CAT(p, n) (__VA_ARGS__))

/**
 * @brief Get the head of a tuple.
 * 
 * Example: <tt>TPL_HEAD((a, b, c))</tt> expands to \c a.
 *
 * @parem t The tuple.
 *
 * @return The head.
 */
#define TPL_HEAD(t) TPL_ID(TPL_HEAD_L t)

/**
 * @brief Get the head of a list.
 * 
 * Example: <tt>TPL_HEAD_L(a, b, c)</tt> expands to \c a.
 *
 * @param ... The list.
 *
 * @return The head.
 */
#define TPL_HEAD_L(...)                                                    \
  TPL_APPLY_012(TPL_HEAD_L_A, TPL_SIZE_L(__VA_ARGS__), __VA_ARGS__)
#define TPL_HEAD_L_A0()
#define TPL_HEAD_L_A1(x1) x1
#define TPL_HEAD_L_A2(x1, ...) x1

/**
 * @brief Get the tail of a tuple.
 *
 * Example: <tt>TPL_TAIL_L((a, b, c))</tt> expands to <tt>(b, c)</tt>.
 *
 * @param t The tuple.
 *
 * @return The tail.
 */
#define TPL_TAIL(t) (TPL_ID(TPL_TAIL_L t))

/**
 * @brief Get the tail of a list.
 *
 * Example: <tt>TPL_TAIL_L(a, b, c)<tt> expands to <tt>b, c</tt>.
 *
 * @param ... The list.
 *
 * @return The tail.
 */
#define TPL_TAIL_L(...)                                                    \
  TPL_APPLY_012(TPL_TAIL_L_A, TPL_SIZE_L(__VA_ARGS__), __VA_ARGS__)
#define TPL_TAIL_L_A0(...)
#define TPL_TAIL_L_A1(x1, ...)
#define TPL_TAIL_L_A2(x1, ...) __VA_ARGS__

/**
 * @brief Extract the \e i-th (zero-based) element of a tuple.
 *
 * Example: <tt>TPL_ELEM((a, b, c), 1)</tt> expands to \c b.
 *up
 * @param t The tuple.
 * @param i The index of the element to be extracted.
 *
 * @return The i-th element of \e t.
 */
#define TPL_ELEMENT(t, i) TPL_HEAD(TPL_RECURSE(t, i, TPL_TAIL))

/**
 * @brief Append an element to a tuple.
 *
 * Example: <tt>TPL_APPEND((a, b), c)</tt> expands to <tt>(a, b, c)</tt>.
 *
 * @param t The tuple.
 * @param x The element.
 *
 * @return The appended tuple.
 */
#define TPL_APPEND(t, x) TPL_APPLY_012(TPL_APPEND_A, TPL_SIZE(t), t, x)
#define TPL_APPEND_A0(t, x) (x)
#define TPL_APPEND_A1(t, x) (TPL_TO_LIST(t), x)
#define TPL_APPEND_A2(t, x) (TPL_TO_LIST(t), x)

/**
 * @brief Insert an element to the begining of a tuple.
 *
 * Example: <tt>TPL_INSERT((a, b), c)</tt> expands to <tt>(c, a, b)</tt>.
 *
 * @param t The tuple.
 * @param x The element.
 *
 * @return The inserted tuple.
 */
#define TPL_INSERT(t, x) TPL_APPLY_012(TPL_INSERT_A, TPL_SIZE(t), t, x)
#define TPL_INSERT_A0(t, x) (x)
#define TPL_INSERT_A1(t, x) (x, TPL_TO_LIST(t))
#define TPL_INSERT_A2(t, x) (x, TPL_TO_LIST(t))

/**
 * @brief Rotate a tuple to the left.
 *
 * Example: <tt>TPL_ROTATE((a, b, c))</tt> expands to <tt>(b, c, a)</tt>.
 *
 * @param t The tuple.
 *
 * @return The rotated tuple.
 */
#define TPL_ROTATE(t)                                                      \
  TPL_APPLY_012(TPL_ROTATE_A, TPL_SIZE(t), TPL_TO_LIST(t))
#define TPL_ROTATE_A0() ()
#define TPL_ROTATE_A1(x1) (x1)
#define TPL_ROTATE_A2(x1, ...) (__VA_ARGS__, x1)

/**
 * @brief Recursively apply a function to a tuple.
 *
 * The function takes one tuple parameter and returns a tuple.
 *
 * Example: <tt>TPL_RECURSE(t, 3, F)</tt> expands to <tt>F(F(F(t))</tt>.
 *
 * @param t The tuple.
 * @param n The number of times the function is iterated.
 * @param F The function.
 *
 * @return The iteration of F.
 */
#define TPL_RECURSE(t, n, F) TPL_ID(TPL_CAT(TPL_RECURSE_, n) (t, F))

/**
 * @brief Get a tuple obtained by memberwise application of a function.
 *
 * Given a tuple <tt>t = (x0, ..., xn)</tt> and a function \c F taking two
 * arguments. <tt>TPL_FOR_EACH(t, F, a)</tt> expands to
 * <tt>(F(x0, a), ..., F(xn, a))</tt>.
 *
 * Notice that the output is a tuple. For similar functions that return a
 * list or a sequence, see \c TPL_FOR_EACH_L and \c TPL_FOR_EACH_S.
 *
 * @param t The tuple.
 * @param F The function.
 * @param a Extra argument for F \c F.
 *
 * @return A tuple obtained by memberwise application of \c F to \c t.
 */
#define TPL_FOR_EACH(t, F, a)                                              \
  TPL_ID(TPL_CAT(TPL_FOR_EACH_, TPL_SIZE(t)) (t, F, a))

/**
 * @brief Get a list obtained by memberwise application of a function.
 *
 * Given a tuple <tt>t = (x0, ..., xn)</tt> and a function \c F taking two
 * arguments. <tt>TPL_FOR_EACH_L(t, F, a)</tt> expands to
 * <tt>F(x0, a), ..., F(xn, a)</tt>.
 *
 * Notice that the output is a list. For similar functions that return
 * a tuple or a sequence, see \c TPL_FOR_EACH and \c TPL_FOR_EACH_S.
 *
 * @param t The tuple to be iterated over.
 * @param F The function.
 * @param a Extra argument for F \c F.
 *
 * @return A list obtained by memberwise application of \c F to \c t.
 */
#define TPL_FOR_EACH_L(t, F, a)                                            \
  TPL_TO_LIST(TPL_FOR_EACH(t, F, a))

/**
 * @brief Get a sequence obtained by memberwise application of a function.
 *
 * Given a tuple <tt>t = (x0, ..., xn)</tt> and a function \c F taking two
 * arguments. <tt>TPL_FOR_EACH_S(t, F, a)</tt> expands to
 * <tt>F(x0, a) ... F(xn, a)</tt>.
 *
 * Notice that the output is a sequence. For similar functions that return a
 * tuple or a list, see \c TPL_FOR_EACH and \c TPL_FOR_EACH_L.
 *
 * @param t The tuple to be iterated over.
 * @param F The function.
 * @param a Extra argument for F \c F.
 *
 * @return A sequence obtained by memberwise application of \c F to \c t.
 */
#define TPL_FOR_EACH_S(t, F, a)                                            \
  TPL_ID(TPL_CAT(TPL_FOR_EACH_S_, TPL_SIZE(t)) (t, F, a))

#endif // TPL_H_
