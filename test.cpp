/**
 * @brief Unit test for TPL.
 *
 * To be pre processed but not compiled.
 */

#include "TPL.h"

#define TEST_TPL     (a, b, c)
#define TEST_TPL_F() (a, b, c)
#define TEST_LST      a, b, c
#define TEST_LST_F()  a, b, c
#define BIG_LIST \
  01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, \
  17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, \
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64

TLP_ID {
  TPL_ID(x) == x
}

TLP_CAT {
  TPL_CAT(x, y) == xy
}

TPL_TO_LIST {
  TPL_TO_LIST(()) ==
  TPL_TO_LIST((a)) == a
  TPL_TO_LIST((a, b)) == a, b
  TPL_TO_LIST(TEST_TPL) == a, b, c
  TPL_TO_LIST(TEST_TPL_F()) == a, b, c
}

TPL_IS_EMPTY {
  TPL_IS_EMPTY(()) == 1
  TPL_IS_EMPTY((a:)) == 0
  TPL_IS_EMPTY((a, b)) == 0
  TPL_IS_EMPTY((())) == 0
  TPL_IS_EMPTY(((), b)) == 0
  TPL_IS_EMPTY((a, ())) == 0
  TPL_IS_EMPTY(((), b, ())) == 0
  TPL_IS_EMPTY((TEST_TPL)) == 0
  TPL_IS_EMPTY((TEST_TPL_F())) == 0
  TPL_IS_EMPTY((TEST_LST)) == 0
  TPL_IS_EMPTY((TEST_LST())) == 0
}

TPL_IS_EMPTY_L {
  TPL_IS_EMPTY_L() == 1
  TPL_IS_EMPTY_L(a) == 0
  TPL_IS_EMPTY_L(a, b) == 0
  TPL_IS_EMPTY_L(()) == 0
  TPL_IS_EMPTY_L((), b) == 0
  TPL_IS_EMPTY_L(a, ()) == 0
  TPL_IS_EMPTY_L((), b, ()) == 0
  TPL_IS_EMPTY_L(TEST_TPL) == 0
  TPL_IS_EMPTY_L(TEST_TPL_F()) == 0
  TPL_IS_EMPTY_L(TEST_LST) == 0
  TPL_IS_EMPTY_L(TEST_LST()) == 0
}

TPL_SIZE {
  TPL_SIZE(((a, b, c))) == 1
  TPL_SIZE((~)) == 1
  TPL_SIZE((!)) == 1
  TPL_SIZE((-)) == 1
  TPL_SIZE((+)) == 1
  TPL_SIZE((\)) == 1
  TPL_SIZE((&)) == 1
  TPL_SIZE((*)) == 1
  TPL_SIZE((=)) == 1
  TPL_SIZE(()) == 0
  TPL_SIZE((a)) == 1
  TPL_SIZE((a, b)) == 2
  TPL_SIZE((a, b, c)) == 3
  TPL_SIZE(TEST_TPL) == 3
  TPL_SIZE(TEST_TPL_F()) == 3  
  TPL_SIZE((BIG_LIST)) == 64
}

TPL_SIZE_L {
  TPL_SIZE_L((a, b, c)) == 1
  TPL_SIZE_L(~) == 1
  TPL_SIZE_L(!) == 1
  TPL_SIZE_L(-) == 1
  TPL_SIZE_L(+) == 1
  TPL_SIZE_L(\) == 1
  TPL_SIZE_L(&) == 1
  TPL_SIZE_L(*) == 1
  TPL_SIZE_L(=) == 1
  TPL_SIZE_L() == 0
  TPL_SIZE_L(a) == 1
  TPL_SIZE_L(a, b) == 2
  TPL_SIZE_L(a, b, c) == 3
  TPL_SIZE_L(TEST_TPL) == 1
  TPL_SIZE_L(TEST_TPL_F()) == 1
  TPL_SIZE_L(BIG_LIST) == 64
}

TPL_APPLY_012 {
  TPL_APPLY_012(F_, 0, a, b, c) == F_0 (a, b, c)
  TPL_APPLY_012(F_, 1, a, b, c) == F_1 (a, b, c)
  TPL_APPLY_012(F_, 2, a, b, c) == F_2 (a, b, c)
  TPL_APPLY_012(F_, 3, a, b, c) == F_2 (a, b, c)
  TPL_APPLY_012(F_, 0) == F_0 ()
  TPL_APPLY_012(F_, 1) == F_1 ()
  TPL_APPLY_012(F_, 2) == F_2 ()
  TPL_APPLY_012(F_, 3) == F_2 ()
  TPL_APPLY_012(F_, 3, TEST_LST) == F_2 (a, b, c)
  TPL_APPLY_012(F_, 3, TEST_LST_F()) == F_2 (a, b, c)
}

TPL_HEAD {
  TPL_HEAD(()) ==
  TPL_HEAD((a)) == a
  TPL_HEAD((a, b, c)) == a
  TPL_HEAD(TEST_TPL) == a
  TPL_HEAD(TEST_TPL_F()) == a
}

TPL_HEAD_L {
  TPL_HEAD_L() ==
  TPL_HEAD_L(a) == a
  TPL_HEAD_L(a, b, c) == a
  TPL_HEAD_L(TEST_LST) == a
  TPL_HEAD_L(TEST_LST_F()) == a
}

TPL_TAIL {
  TPL_TAIL(()) == ()
  TPL_TAIL((a)) == ()
  TPL_TAIL((a, b, c)) == (b, c)
  TPL_TAIL(TEST_TPL) == (b, c)
  TPL_TAIL(TEST_TPL_F()) == (b, c)
}

TPL_TAIL_L {
  TPL_TAIL_L() ==
  TPL_TAIL_L(a) ==
  TPL_TAIL_L(a, b, c) == b, c
  TPL_TAIL_L(TEST_LST) == b, c
  TPL_TAIL_L(TEST_LST_F()) == b, c
}

TPL_ELEMENT {
  TPL_ELEMENT((a, b, c), 0) == a
  TPL_ELEMENT((a, b, c), 1) == b
  TPL_ELEMENT((a, b, c), 2) == c
  TPL_ELEMENT(TEST_TPL, 2) == c
  TPL_ELEMENT(TEST_TPL_F(), 2) == c
  TPL_ELEMENT((a, b, c), TPL_SIZE((a, b))) == c
}

TPL_APPEND {
  TPL_APPEND((), a) == (a)
  TPL_APPEND((a), b) == (a, b)
  TPL_APPEND((a, b, c), d) == (a, b, c, d)
  TPL_APPEND(TEST_TPL, d) == (a, b, c, d)
  TPL_APPEND(TEST_TPL_F(), d) == (a, b, c, d)
}

TPL_INSERT {
  TPL_INSERT((), a) == (a)
  TPL_INSERT((a), b) == (b, a)
  TPL_INSERT((a, b, c), d) == (d, a, b, c)
  TPL_INSERT(TEST_TPL, d) == (d, a, b, c)
  TPL_INSERT(TEST_TPL_F(), d) == (d, a, b, c)
}

TPL_ROTATE {
  TPL_ROTATE(()) == ()
  TPL_ROTATE((a)) == (a)
  TPL_ROTATE((a, b, c)) == (b, c, a)
  TPL_ROTATE(TEST_TPL) == (b, c, a)
  TPL_ROTATE(TEST_TPL_F()) == (b, c, a)
}

TPL_RECURSE {
  TPL_RECURSE((a, b, c), 0, F) == (a, b, c)
  TPL_RECURSE((a, b, c), 1, F) == F((a, b, c))
  TPL_RECURSE((a, b, c), 2, F) ==  F(F((a, b, c)))
  TPL_RECURSE(TEST_TPL, 2, F) ==  F(F((a, b, c)))
  TPL_RECURSE(TEST_TPL_F(), 2, F) ==  F(F((a, b, c)))
}

#define F(x, a) 2*x
#define G(x, a) x + TPL_HEAD(a)

TPL_FOR_EACH {
  TPL_FOR_EACH((), F, ()) == ()
  TPL_FOR_EACH((a), F, ()) == (F(a, ()))
  TPL_FOR_EACH((a, b, c), F, ()) == (F(a, ()), F(b, ()), F(c, ()))
  TPL_FOR_EACH(TEST_TPL, F, ()) == (F(a, ()), F(b, ()), F(c, ()))
  TPL_FOR_EACH(TEST_TPL_F(), F, ()) == (F(a, ()), F(b, ()), F(c, ()))
  TPL_FOR_EACH((), G, (x)) == ()
  TPL_FOR_EACH((a), G, (x)) == (G(a, (x)))
  TPL_FOR_EACH((a, b, c), G, (x)) == (G(a, (x)), G(b, (x)), G(c, (x)))
  TPL_FOR_EACH(TEST_TPL, G, (x)) == (G(a, (x)), G(b, (x)), G(c, (x)))
  TPL_FOR_EACH(TEST_TPL_F(), G, (x)) == (G(a, (x)), G(b, (x)), G(c, (x)))
}

TPL_FOR_EACH_L {
  TPL_FOR_EACH_L((), F, ()) ==
  TPL_FOR_EACH_L((a), F, ()) == F(a, ())
  TPL_FOR_EACH_L((a, b, c), F, ()) == F(a, ()), F(b, ()), F(c, ())
  TPL_FOR_EACH_L(TEST_TPL, F, ()) == F(a, ()), F(b, ()), F(c, ())
  TPL_FOR_EACH_L(TEST_TPL_F(), F, ()) == F(a, ()), F(b, ()), F(c, ())
  TPL_FOR_EACH_L((), G, (x)) ==
  TPL_FOR_EACH_L((a), G, (x)) == G(a, (x))
  TPL_FOR_EACH_L((a, b, c), G, (x)) == G(a, (x)), G(b, (x)), G(c, (x))
  TPL_FOR_EACH_L(TEST_TPL, G, (x)) == G(a, (x)), G(b, (x)), G(c, (x))
  TPL_FOR_EACH_L(TEST_TPL_F(), G, (x)) == G(a, (x)), G(b, (x)), G(c, (x))
}

TPL_FOR_EACH_S {
  TPL_FOR_EACH_S((), F, ()) ==
  TPL_FOR_EACH_S((a), F, ()) == F(a, ())
  TPL_FOR_EACH_S((a, b, c), F, ()) == F(a, ()) F(b, ()) F(c, ())
  TPL_FOR_EACH_S(TEST_TPL, F, ()) == F(a, ()) F(b, ()) F(c, ())
  TPL_FOR_EACH_S(TEST_TPL_F(), F, ()) == F(a, ()) F(b, ()) F(c, ())
  TPL_FOR_EACH_S((), G, (x)) ==
  TPL_FOR_EACH_S((a), G, (x)) == G(a, (x))
  TPL_FOR_EACH_S((a, b, c), G, (x)) == G(a, (x)) G(b, (x)) G(c, (x))
  TPL_FOR_EACH_S(TEST_TPL, G, (x)) == G(a, (x)) G(b, (x)) G(c, (x))
  TPL_FOR_EACH_S(TEST_TPL_F(), G, (x)) == G(a, (x)) G(b, (x)) G(c, (x))
}
