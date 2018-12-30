// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <khala/base/macro_helper.hh>
#include <khala/base/string_ref.hh>

#include <array>
#include <type_traits>

#define __MAKE_ARG_LIST_1(op, arg, ...) op(arg)
#define __MAKE_ARG_LIST_2(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_1(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_3(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_2(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_4(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_3(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_5(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_4(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_6(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_5(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_7(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_6(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_8(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_7(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_9(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_8(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_10(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_9(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_11(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_10(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_12(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_11(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_13(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_12(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_14(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_13(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_15(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_14(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_16(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_15(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_17(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_16(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_18(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_17(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_19(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_18(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_20(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_19(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_21(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_20(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_22(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_21(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_23(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_22(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_24(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_23(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_25(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_24(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_26(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_25(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_27(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_26(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_28(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_27(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_29(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_28(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_30(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_29(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_31(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_30(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_32(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_31(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_33(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_32(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_34(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_33(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_35(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_34(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_36(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_35(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_37(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_36(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_38(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_37(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_39(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_38(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_40(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_39(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_41(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_40(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_42(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_41(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_43(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_42(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_44(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_43(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_45(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_44(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_46(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_45(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_47(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_46(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_48(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_47(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_49(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_48(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_50(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_49(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_51(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_50(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_52(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_51(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_53(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_52(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_54(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_53(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_55(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_54(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_56(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_55(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_57(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_56(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_58(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_57(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_59(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_58(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_60(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_59(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_61(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_60(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_62(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_61(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_63(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_62(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_64(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_63(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_65(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_64(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_66(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_65(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_67(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_66(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_68(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_67(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_69(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_68(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_70(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_69(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_71(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_70(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_72(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_71(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_73(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_72(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_74(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_73(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_75(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_74(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_76(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_75(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_77(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_76(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_78(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_77(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_79(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_78(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_80(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_79(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_81(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_80(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_82(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_81(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_83(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_82(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_84(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_83(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_85(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_84(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_86(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_85(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_87(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_86(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_88(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_87(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_89(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_88(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_90(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_89(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_91(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_90(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_92(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_91(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_93(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_92(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_94(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_93(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_95(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_94(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_96(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_95(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_97(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_96(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_98(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_97(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_99(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_98(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_100(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_99(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_101(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_100(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_102(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_101(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_103(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_102(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_104(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_103(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_105(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_104(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_106(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_105(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_107(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_106(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_108(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_107(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_109(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_108(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_110(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_109(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_111(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_110(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_112(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_111(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_113(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_112(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_114(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_113(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_115(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_114(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_116(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_115(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_117(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_116(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_118(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_117(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_119(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_118(op, __VA_ARGS__))
#define __MAKE_ARG_LIST_120(op, arg, ...) \
  op(arg), EXPAND_MACRO(__MAKE_ARG_LIST_119(op, __VA_ARGS__))

#define __ADD_STRING_REF(ele) ::khala::base::StringRef(#ele)
#define __GEN_STRING_REF_1(ele, ...) __ADD_STRING_REF(ele)
#define __GEN_STRING_REF_2(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_1(__VA_ARGS__))
#define __GEN_STRING_REF_3(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_2(__VA_ARGS__))
#define __GEN_STRING_REF_4(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_3(__VA_ARGS__))
#define __GEN_STRING_REF_5(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_4(__VA_ARGS__))
#define __GEN_STRING_REF_6(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_5(__VA_ARGS__))
#define __GEN_STRING_REF_7(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_6(__VA_ARGS__))
#define __GEN_STRING_REF_8(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_7(__VA_ARGS__))
#define __GEN_STRING_REF_9(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_8(__VA_ARGS__))
#define __GEN_STRING_REF_10(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_9(__VA_ARGS__))
#define __GEN_STRING_REF_11(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_10(__VA_ARGS__))
#define __GEN_STRING_REF_12(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_11(__VA_ARGS__))
#define __GEN_STRING_REF_13(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_12(__VA_ARGS__))
#define __GEN_STRING_REF_14(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_13(__VA_ARGS__))
#define __GEN_STRING_REF_15(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_14(__VA_ARGS__))
#define __GEN_STRING_REF_16(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_15(__VA_ARGS__))
#define __GEN_STRING_REF_17(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_16(__VA_ARGS__))
#define __GEN_STRING_REF_18(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_17(__VA_ARGS__))
#define __GEN_STRING_REF_19(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_18(__VA_ARGS__))
#define __GEN_STRING_REF_20(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_19(__VA_ARGS__))
#define __GEN_STRING_REF_21(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_20(__VA_ARGS__))
#define __GEN_STRING_REF_22(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_21(__VA_ARGS__))
#define __GEN_STRING_REF_23(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_22(__VA_ARGS__))
#define __GEN_STRING_REF_24(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_23(__VA_ARGS__))
#define __GEN_STRING_REF_25(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_24(__VA_ARGS__))
#define __GEN_STRING_REF_26(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_25(__VA_ARGS__))
#define __GEN_STRING_REF_27(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_26(__VA_ARGS__))
#define __GEN_STRING_REF_28(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_27(__VA_ARGS__))
#define __GEN_STRING_REF_29(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_28(__VA_ARGS__))
#define __GEN_STRING_REF_30(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_29(__VA_ARGS__))
#define __GEN_STRING_REF_31(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_30(__VA_ARGS__))
#define __GEN_STRING_REF_32(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_31(__VA_ARGS__))
#define __GEN_STRING_REF_33(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_32(__VA_ARGS__))
#define __GEN_STRING_REF_34(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_33(__VA_ARGS__))
#define __GEN_STRING_REF_35(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_34(__VA_ARGS__))
#define __GEN_STRING_REF_36(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_35(__VA_ARGS__))
#define __GEN_STRING_REF_37(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_36(__VA_ARGS__))
#define __GEN_STRING_REF_38(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_37(__VA_ARGS__))
#define __GEN_STRING_REF_39(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_38(__VA_ARGS__))
#define __GEN_STRING_REF_40(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_39(__VA_ARGS__))
#define __GEN_STRING_REF_41(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_40(__VA_ARGS__))
#define __GEN_STRING_REF_42(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_41(__VA_ARGS__))
#define __GEN_STRING_REF_43(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_42(__VA_ARGS__))
#define __GEN_STRING_REF_44(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_43(__VA_ARGS__))
#define __GEN_STRING_REF_45(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_44(__VA_ARGS__))
#define __GEN_STRING_REF_46(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_45(__VA_ARGS__))
#define __GEN_STRING_REF_47(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_46(__VA_ARGS__))
#define __GEN_STRING_REF_48(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_47(__VA_ARGS__))
#define __GEN_STRING_REF_49(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_48(__VA_ARGS__))
#define __GEN_STRING_REF_50(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_49(__VA_ARGS__))
#define __GEN_STRING_REF_51(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_50(__VA_ARGS__))
#define __GEN_STRING_REF_52(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_51(__VA_ARGS__))
#define __GEN_STRING_REF_53(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_52(__VA_ARGS__))
#define __GEN_STRING_REF_54(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_53(__VA_ARGS__))
#define __GEN_STRING_REF_55(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_54(__VA_ARGS__))
#define __GEN_STRING_REF_56(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_55(__VA_ARGS__))
#define __GEN_STRING_REF_57(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_56(__VA_ARGS__))
#define __GEN_STRING_REF_58(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_57(__VA_ARGS__))
#define __GEN_STRING_REF_59(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_58(__VA_ARGS__))
#define __GEN_STRING_REF_60(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_59(__VA_ARGS__))
#define __GEN_STRING_REF_61(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_60(__VA_ARGS__))
#define __GEN_STRING_REF_62(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_61(__VA_ARGS__))
#define __GEN_STRING_REF_63(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_62(__VA_ARGS__))
#define __GEN_STRING_REF_64(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_63(__VA_ARGS__))
#define __GEN_STRING_REF_65(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_64(__VA_ARGS__))
#define __GEN_STRING_REF_66(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_65(__VA_ARGS__))
#define __GEN_STRING_REF_67(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_66(__VA_ARGS__))
#define __GEN_STRING_REF_68(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_67(__VA_ARGS__))
#define __GEN_STRING_REF_69(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_68(__VA_ARGS__))
#define __GEN_STRING_REF_70(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_69(__VA_ARGS__))
#define __GEN_STRING_REF_71(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_70(__VA_ARGS__))
#define __GEN_STRING_REF_72(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_71(__VA_ARGS__))
#define __GEN_STRING_REF_73(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_72(__VA_ARGS__))
#define __GEN_STRING_REF_74(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_73(__VA_ARGS__))
#define __GEN_STRING_REF_75(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_74(__VA_ARGS__))
#define __GEN_STRING_REF_76(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_75(__VA_ARGS__))
#define __GEN_STRING_REF_77(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_76(__VA_ARGS__))
#define __GEN_STRING_REF_78(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_77(__VA_ARGS__))
#define __GEN_STRING_REF_79(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_78(__VA_ARGS__))
#define __GEN_STRING_REF_80(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_79(__VA_ARGS__))
#define __GEN_STRING_REF_81(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_80(__VA_ARGS__))
#define __GEN_STRING_REF_82(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_81(__VA_ARGS__))
#define __GEN_STRING_REF_83(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_82(__VA_ARGS__))
#define __GEN_STRING_REF_84(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_83(__VA_ARGS__))
#define __GEN_STRING_REF_85(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_84(__VA_ARGS__))
#define __GEN_STRING_REF_86(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_85(__VA_ARGS__))
#define __GEN_STRING_REF_87(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_86(__VA_ARGS__))
#define __GEN_STRING_REF_88(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_87(__VA_ARGS__))
#define __GEN_STRING_REF_89(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_88(__VA_ARGS__))
#define __GEN_STRING_REF_90(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_89(__VA_ARGS__))
#define __GEN_STRING_REF_91(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_90(__VA_ARGS__))
#define __GEN_STRING_REF_92(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_91(__VA_ARGS__))
#define __GEN_STRING_REF_93(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_92(__VA_ARGS__))
#define __GEN_STRING_REF_94(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_93(__VA_ARGS__))
#define __GEN_STRING_REF_95(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_94(__VA_ARGS__))
#define __GEN_STRING_REF_96(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_95(__VA_ARGS__))
#define __GEN_STRING_REF_97(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_96(__VA_ARGS__))
#define __GEN_STRING_REF_98(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_97(__VA_ARGS__))
#define __GEN_STRING_REF_99(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_98(__VA_ARGS__))
#define __GEN_STRING_REF_100(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_99(__VA_ARGS__))
#define __GEN_STRING_REF_101(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_100(__VA_ARGS__))
#define __GEN_STRING_REF_102(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_101(__VA_ARGS__))
#define __GEN_STRING_REF_103(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_102(__VA_ARGS__))
#define __GEN_STRING_REF_104(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_103(__VA_ARGS__))
#define __GEN_STRING_REF_105(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_104(__VA_ARGS__))
#define __GEN_STRING_REF_106(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_105(__VA_ARGS__))
#define __GEN_STRING_REF_107(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_106(__VA_ARGS__))
#define __GEN_STRING_REF_108(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_107(__VA_ARGS__))
#define __GEN_STRING_REF_109(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_108(__VA_ARGS__))
#define __GEN_STRING_REF_110(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_109(__VA_ARGS__))
#define __GEN_STRING_REF_111(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_110(__VA_ARGS__))
#define __GEN_STRING_REF_112(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_111(__VA_ARGS__))
#define __GEN_STRING_REF_113(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_112(__VA_ARGS__))
#define __GEN_STRING_REF_114(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_113(__VA_ARGS__))
#define __GEN_STRING_REF_115(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_114(__VA_ARGS__))
#define __GEN_STRING_REF_116(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_115(__VA_ARGS__))
#define __GEN_STRING_REF_117(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_116(__VA_ARGS__))
#define __GEN_STRING_REF_118(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_117(__VA_ARGS__))
#define __GEN_STRING_REF_119(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_118(__VA_ARGS__))
#define __GEN_STRING_REF_120(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_119(__VA_ARGS__))
#define __GEN_STRING_REF_121(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_120(__VA_ARGS__))
#define __GEN_STRING_REF_122(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_121(__VA_ARGS__))
#define __GEN_STRING_REF_123(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_122(__VA_ARGS__))
#define __GEN_STRING_REF_124(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_123(__VA_ARGS__))
#define __GEN_STRING_REF_125(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_124(__VA_ARGS__))
#define __GEN_STRING_REF_126(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_125(__VA_ARGS__))
#define __GEN_STRING_REF_127(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_126(__VA_ARGS__))
#define __GEN_STRING_REF_128(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_127(__VA_ARGS__))
#define __GEN_STRING_REF_129(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_128(__VA_ARGS__))
#define __GEN_STRING_REF_130(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_129(__VA_ARGS__))
#define __GEN_STRING_REF_131(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_130(__VA_ARGS__))
#define __GEN_STRING_REF_132(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_131(__VA_ARGS__))
#define __GEN_STRING_REF_133(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_132(__VA_ARGS__))
#define __GEN_STRING_REF_134(ele, ...) \
  __ADD_STRING_REF(ele), EXPAND_MACRO(__GEN_STRING_REF_133(__VA_ARGS__))

#define __MAKE_META_DATA_NAME(STRUCT_NAME, N, ...)                         \
  struct __arr_##STRUCT_NAME {                                             \
    constexpr static std::array<::khala::base::StringRef, N> Value() {     \
      return std::array<::khala::base::StringRef, N>{                      \
          {EXPAND_MACRO(MACRO_CONCAT(__GEN_STRING_REF, N)(__VA_ARGS__))}}; \
    }                                                                      \
  };

#define __MAKE_META_DATA_IMPL(STRUCT_NAME, ...)                             \
  struct __reflect_members_##STRUCT_NAME {                                  \
    constexpr decltype(std::make_tuple(__VA_ARGS__)) static apply_impl() {  \
      return std::make_tuple(__VA_ARGS__);                                  \
    }                                                                       \
    using type = void;                                                      \
    using size_type =                                                       \
        std::integral_constant<uint32_t, GET_ARG_COUNT(__VA_ARGS__)>;       \
    constexpr static ::khala::base::StringRef Name() {                      \
      return ::khala::base::StringRef{#STRUCT_NAME};                        \
    }                                                                       \
    constexpr static size_t Value() { return size_type::value; }            \
    constexpr static std::array<::khala::base::StringRef, size_type::value> \
    Arr() {                                                                 \
      return __arr_##STRUCT_NAME::Value();                                  \
    }                                                                       \
  };                                                                        \
  constexpr __reflect_members_##STRUCT_NAME __reflect_members(              \
      STRUCT_NAME const&) {                                                 \
    return __reflect_members_##STRUCT_NAME{};                               \
  }

#define __FIELD(t) t

#define __MAKE_META_DATA(STRUCT_NAME, N, ...)                          \
  __MAKE_META_DATA_NAME(STRUCT_NAME, N, __VA_ARGS__)                   \
  __MAKE_META_DATA_IMPL(STRUCT_NAME, MACRO_CONCAT(__MAKE_ARG_LIST, N)( \
                                         &STRUCT_NAME::__FIELD, __VA_ARGS__))

#define REFLECTION(STRUCT_NAME, ...) \
  __MAKE_META_DATA(STRUCT_NAME, GET_ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

namespace khala::base {

template <typename T>
using ReflectMembers = decltype(__reflect_members(std::declval<T>()));

template <typename T, typename = void>
struct ReflectionInfo : std::false_type {};

template <typename T>
struct ReflectionInfo<T, std::void_t<typename ReflectMembers<T>::type>>
    : std::true_type {
  using ArrType = decltype(ReflectMembers<T>::Arr());
};

template <typename T>
constexpr bool HasReflection_v = ReflectionInfo<T>::value;

namespace reflect {

template <typename T>
constexpr const ::khala::base::StringRef ClassName = ReflectMembers<T>::Name();

template <typename T>
struct Size : std::integral_constant<size_t, ReflectMembers<T>::Value()> {};

template <typename T>
constexpr size_t Size_v = Size<T>::value;

template <typename T>
constexpr const ::khala::base::StringRef MemberName(size_t i) {
  return static_cast<typename ReflectionInfo<T>::ArrType const&>(
      ReflectMembers<T>::Arr())[i];
}

template <uint32_t I, typename T>
using MemberType = decltype(std::move(std::declval<T>()).*
                            (std::get<I>(ReflectMembers<T>::apply_impl())));

template <size_t Idx, typename T>
constexpr auto&& MemberValue(T&& t) {
  return std::forward<T>(t).*(std::get<Idx>(ReflectMembers<T>::apply_impl()));
}

}  // namespace reflect

}  // namespace khala::base

