/**
 * @brief Emulates recursion through function sequences.
 */

#ifndef TPL_RECURSE_H_
#define TPL_RECURSE_H_

// MIN_WITH_TWO
#define TPL_MIN_WITH_TWO_64 2
#define TPL_MIN_WITH_TWO_63 2
#define TPL_MIN_WITH_TWO_62 2
#define TPL_MIN_WITH_TWO_61 2
#define TPL_MIN_WITH_TWO_60 2
#define TPL_MIN_WITH_TWO_59 2
#define TPL_MIN_WITH_TWO_58 2
#define TPL_MIN_WITH_TWO_57 2
#define TPL_MIN_WITH_TWO_56 2
#define TPL_MIN_WITH_TWO_55 2
#define TPL_MIN_WITH_TWO_54 2
#define TPL_MIN_WITH_TWO_53 2
#define TPL_MIN_WITH_TWO_52 2
#define TPL_MIN_WITH_TWO_51 2
#define TPL_MIN_WITH_TWO_50 2
#define TPL_MIN_WITH_TWO_49 2
#define TPL_MIN_WITH_TWO_48 2
#define TPL_MIN_WITH_TWO_47 2
#define TPL_MIN_WITH_TWO_46 2
#define TPL_MIN_WITH_TWO_45 2
#define TPL_MIN_WITH_TWO_44 2
#define TPL_MIN_WITH_TWO_43 2
#define TPL_MIN_WITH_TWO_42 2
#define TPL_MIN_WITH_TWO_41 2
#define TPL_MIN_WITH_TWO_40 2
#define TPL_MIN_WITH_TWO_39 2
#define TPL_MIN_WITH_TWO_38 2
#define TPL_MIN_WITH_TWO_37 2
#define TPL_MIN_WITH_TWO_36 2
#define TPL_MIN_WITH_TWO_35 2
#define TPL_MIN_WITH_TWO_34 2
#define TPL_MIN_WITH_TWO_33 2
#define TPL_MIN_WITH_TWO_32 2
#define TPL_MIN_WITH_TWO_31 2
#define TPL_MIN_WITH_TWO_30 2
#define TPL_MIN_WITH_TWO_29 2
#define TPL_MIN_WITH_TWO_28 2
#define TPL_MIN_WITH_TWO_27 2
#define TPL_MIN_WITH_TWO_26 2
#define TPL_MIN_WITH_TWO_25 2
#define TPL_MIN_WITH_TWO_24 2
#define TPL_MIN_WITH_TWO_23 2
#define TPL_MIN_WITH_TWO_22 2
#define TPL_MIN_WITH_TWO_21 2
#define TPL_MIN_WITH_TWO_20 2
#define TPL_MIN_WITH_TWO_19 2
#define TPL_MIN_WITH_TWO_18 2
#define TPL_MIN_WITH_TWO_17 2
#define TPL_MIN_WITH_TWO_16 2
#define TPL_MIN_WITH_TWO_15 2
#define TPL_MIN_WITH_TWO_14 2
#define TPL_MIN_WITH_TWO_13 2
#define TPL_MIN_WITH_TWO_12 2
#define TPL_MIN_WITH_TWO_11 2
#define TPL_MIN_WITH_TWO_10 2
#define TPL_MIN_WITH_TWO_9 2
#define TPL_MIN_WITH_TWO_8 2
#define TPL_MIN_WITH_TWO_7 2
#define TPL_MIN_WITH_TWO_6 2
#define TPL_MIN_WITH_TWO_5 2
#define TPL_MIN_WITH_TWO_4 2
#define TPL_MIN_WITH_TWO_3 2
#define TPL_MIN_WITH_TWO_2 2
#define TPL_MIN_WITH_TWO_1 1
#define TPL_MIN_WITH_TWO_0 0

// RECURSE
#define TPL_RECURSE_64(t, F) F(TPL_RECURSE_63(t, F))
#define TPL_RECURSE_63(t, F) F(TPL_RECURSE_62(t, F))
#define TPL_RECURSE_62(t, F) F(TPL_RECURSE_61(t, F))
#define TPL_RECURSE_61(t, F) F(TPL_RECURSE_60(t, F))
#define TPL_RECURSE_60(t, F) F(TPL_RECURSE_59(t, F))
#define TPL_RECURSE_59(t, F) F(TPL_RECURSE_58(t, F))
#define TPL_RECURSE_58(t, F) F(TPL_RECURSE_57(t, F))
#define TPL_RECURSE_57(t, F) F(TPL_RECURSE_56(t, F))
#define TPL_RECURSE_56(t, F) F(TPL_RECURSE_55(t, F))
#define TPL_RECURSE_55(t, F) F(TPL_RECURSE_54(t, F))
#define TPL_RECURSE_54(t, F) F(TPL_RECURSE_53(t, F))
#define TPL_RECURSE_53(t, F) F(TPL_RECURSE_52(t, F))
#define TPL_RECURSE_52(t, F) F(TPL_RECURSE_51(t, F))
#define TPL_RECURSE_51(t, F) F(TPL_RECURSE_50(t, F))
#define TPL_RECURSE_50(t, F) F(TPL_RECURSE_49(t, F))
#define TPL_RECURSE_49(t, F) F(TPL_RECURSE_48(t, F))
#define TPL_RECURSE_48(t, F) F(TPL_RECURSE_47(t, F))
#define TPL_RECURSE_47(t, F) F(TPL_RECURSE_46(t, F))
#define TPL_RECURSE_46(t, F) F(TPL_RECURSE_45(t, F))
#define TPL_RECURSE_45(t, F) F(TPL_RECURSE_44(t, F))
#define TPL_RECURSE_44(t, F) F(TPL_RECURSE_43(t, F))
#define TPL_RECURSE_43(t, F) F(TPL_RECURSE_42(t, F))
#define TPL_RECURSE_42(t, F) F(TPL_RECURSE_41(t, F))
#define TPL_RECURSE_41(t, F) F(TPL_RECURSE_40(t, F))
#define TPL_RECURSE_40(t, F) F(TPL_RECURSE_39(t, F))
#define TPL_RECURSE_39(t, F) F(TPL_RECURSE_38(t, F))
#define TPL_RECURSE_38(t, F) F(TPL_RECURSE_37(t, F))
#define TPL_RECURSE_37(t, F) F(TPL_RECURSE_36(t, F))
#define TPL_RECURSE_36(t, F) F(TPL_RECURSE_35(t, F))
#define TPL_RECURSE_35(t, F) F(TPL_RECURSE_34(t, F))
#define TPL_RECURSE_34(t, F) F(TPL_RECURSE_33(t, F))
#define TPL_RECURSE_33(t, F) F(TPL_RECURSE_32(t, F))
#define TPL_RECURSE_32(t, F) F(TPL_RECURSE_31(t, F))
#define TPL_RECURSE_31(t, F) F(TPL_RECURSE_30(t, F))
#define TPL_RECURSE_30(t, F) F(TPL_RECURSE_29(t, F))
#define TPL_RECURSE_29(t, F) F(TPL_RECURSE_28(t, F))
#define TPL_RECURSE_28(t, F) F(TPL_RECURSE_27(t, F))
#define TPL_RECURSE_27(t, F) F(TPL_RECURSE_26(t, F))
#define TPL_RECURSE_26(t, F) F(TPL_RECURSE_25(t, F))
#define TPL_RECURSE_25(t, F) F(TPL_RECURSE_24(t, F))
#define TPL_RECURSE_24(t, F) F(TPL_RECURSE_23(t, F))
#define TPL_RECURSE_23(t, F) F(TPL_RECURSE_22(t, F))
#define TPL_RECURSE_22(t, F) F(TPL_RECURSE_21(t, F))
#define TPL_RECURSE_21(t, F) F(TPL_RECURSE_20(t, F))
#define TPL_RECURSE_20(t, F) F(TPL_RECURSE_19(t, F))
#define TPL_RECURSE_19(t, F) F(TPL_RECURSE_18(t, F))
#define TPL_RECURSE_18(t, F) F(TPL_RECURSE_17(t, F))
#define TPL_RECURSE_17(t, F) F(TPL_RECURSE_16(t, F))
#define TPL_RECURSE_16(t, F) F(TPL_RECURSE_15(t, F))
#define TPL_RECURSE_15(t, F) F(TPL_RECURSE_14(t, F))
#define TPL_RECURSE_14(t, F) F(TPL_RECURSE_13(t, F))
#define TPL_RECURSE_13(t, F) F(TPL_RECURSE_12(t, F))
#define TPL_RECURSE_12(t, F) F(TPL_RECURSE_11(t, F))
#define TPL_RECURSE_11(t, F) F(TPL_RECURSE_10(t, F))
#define TPL_RECURSE_10(t, F) F(TPL_RECURSE_9(t, F))
#define TPL_RECURSE_9(t, F) F(TPL_RECURSE_8(t, F))
#define TPL_RECURSE_8(t, F) F(TPL_RECURSE_7(t, F))
#define TPL_RECURSE_7(t, F) F(TPL_RECURSE_6(t, F))
#define TPL_RECURSE_6(t, F) F(TPL_RECURSE_5(t, F))
#define TPL_RECURSE_5(t, F) F(TPL_RECURSE_4(t, F))
#define TPL_RECURSE_4(t, F) F(TPL_RECURSE_3(t, F))
#define TPL_RECURSE_3(t, F) F(TPL_RECURSE_2(t, F))
#define TPL_RECURSE_2(t, F) F(TPL_RECURSE_1(t, F))
#define TPL_RECURSE_1(t, F) F(TPL_RECURSE_0(t, F))
#define TPL_RECURSE_0(t, F) t

// FOR_EACH
#define TPL_FOR_EACH_64(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_63(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_63(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_62(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_62(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_61(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_61(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_60(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_60(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_59(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_59(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_58(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_58(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_57(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_57(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_56(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_56(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_55(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_55(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_54(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_54(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_53(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_53(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_52(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_52(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_51(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_51(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_50(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_50(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_49(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_49(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_48(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_48(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_47(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_47(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_46(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_46(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_45(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_45(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_44(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_44(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_43(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_43(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_42(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_42(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_41(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_41(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_40(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_40(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_39(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_39(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_38(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_38(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_37(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_37(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_36(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_36(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_35(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_35(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_34(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_34(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_33(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_33(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_32(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_32(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_31(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_31(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_30(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_30(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_29(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_29(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_28(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_28(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_27(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_27(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_26(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_26(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_25(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_25(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_24(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_24(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_23(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_23(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_22(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_22(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_21(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_21(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_20(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_20(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_19(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_19(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_18(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_18(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_17(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_17(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_16(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_16(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_15(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_15(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_14(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_14(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_13(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_13(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_12(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_12(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_11(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_11(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_10(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_10(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_9(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_9(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_8(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_8(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_7(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_7(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_6(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_6(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_5(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_5(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_4(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_4(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_3(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_3(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_2(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_2(t, F, a) (F(TPL_HEAD(t), a), TPL_TO_LIST(TPL_FOR_EACH_1(TPL_TAIL(t), F, a)))
#define TPL_FOR_EACH_1(t, F, a) (F(TPL_HEAD(t), a))
#define TPL_FOR_EACH_0(t, F, a) ()

// FOR_EACH_S_
#define TPL_FOR_EACH_S_64(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_63(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_63(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_62(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_62(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_61(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_61(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_60(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_60(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_59(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_59(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_58(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_58(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_57(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_57(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_56(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_56(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_55(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_55(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_54(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_54(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_53(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_53(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_52(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_52(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_51(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_51(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_50(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_50(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_49(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_49(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_48(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_48(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_47(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_47(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_46(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_46(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_45(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_45(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_44(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_44(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_43(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_43(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_42(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_42(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_41(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_41(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_40(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_40(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_39(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_39(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_38(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_38(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_37(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_37(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_36(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_36(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_35(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_35(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_34(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_34(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_33(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_33(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_32(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_32(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_31(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_31(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_30(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_30(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_29(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_29(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_28(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_28(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_27(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_27(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_26(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_26(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_25(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_25(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_24(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_24(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_23(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_23(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_22(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_22(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_21(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_21(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_20(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_20(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_19(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_19(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_18(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_18(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_17(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_17(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_16(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_16(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_15(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_15(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_14(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_14(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_13(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_13(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_12(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_12(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_11(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_11(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_10(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_10(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_9(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_9(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_8(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_8(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_7(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_7(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_6(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_6(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_5(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_5(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_4(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_4(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_3(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_3(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_2(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_2(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_1(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_1(t, F, a) F(TPL_HEAD(t), a) TPL_FOR_EACH_S_0(TPL_TAIL(t), F, a)
#define TPL_FOR_EACH_S_0(t, F, ...)

#endif // TPL_RECURSE_H_
