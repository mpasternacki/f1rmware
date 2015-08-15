/* -*- c -*- */
#include <stdint.h>

static const uint8_t __morse_nil[] = { 0 }; /* no code */
static const uint8_t __morse_20[] = { 4, 0, 0, 0, 0 }; /* space */
static const uint8_t __morse_33[] = { 19, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* ! -.-.-- */
static const uint8_t __morse_34[] = { 15, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* " .-..-. */
static const uint8_t __morse_35[] = { 0,  }; /* #  */
static const uint8_t __morse_36[] = { 17, 255, 0, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* $ ...-..- */
static const uint8_t __morse_37[] = { 0,  }; /* %  */
static const uint8_t __morse_38[] = { 11, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255 }; /* & .-... */
static const uint8_t __morse_39[] = { 19, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* ' .----. */
static const uint8_t __morse_40[] = { 15, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* ( -.--. */
static const uint8_t __morse_41[] = { 19, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* ) -.--.- */
static const uint8_t __morse_42[] = { 0,  }; /* *  */
static const uint8_t __morse_43[] = { 13, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* + .-.-. */
static const uint8_t __morse_44[] = { 19, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* , --..-- */
static const uint8_t __morse_45[] = { 15, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* - -....- */
static const uint8_t __morse_46[] = { 17, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* . .-.-.- */
static const uint8_t __morse_47[] = { 13, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* / -..-. */
static const uint8_t __morse_48[] = { 19, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* 0 ----- */
static const uint8_t __morse_49[] = { 17, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* 1 .---- */
static const uint8_t __morse_50[] = { 15, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* 2 ..--- */
static const uint8_t __morse_51[] = { 13, 255, 0, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* 3 ...-- */
static const uint8_t __morse_52[] = { 11, 255, 0, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* 4 ....- */
static const uint8_t __morse_53[] = { 9, 255, 0, 255, 0, 255, 0, 255, 0, 255 }; /* 5 ..... */
static const uint8_t __morse_54[] = { 11, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255 }; /* 6 -.... */
static const uint8_t __morse_55[] = { 13, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255 }; /* 7 --... */
static const uint8_t __morse_56[] = { 15, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* 8 ---.. */
static const uint8_t __morse_57[] = { 17, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* 9 ----. */
static const uint8_t __morse_58[] = { 17, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 0, 255 }; /* : ---... */
static const uint8_t __morse_59[] = { 17, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* ; -.-.-. */
static const uint8_t __morse_60[] = { 0,  }; /* <  */
static const uint8_t __morse_61[] = { 13, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* = -...- */
static const uint8_t __morse_62[] = { 0,  }; /* >  */
static const uint8_t __morse_63[] = { 15, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* ? ..--.. */
static const uint8_t __morse_64[] = { 17, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* @ .--.-. */
static const uint8_t __morse_65[] = { 5, 255, 0, 255, 255, 255 }; /* A .- */
static const uint8_t __morse_66[] = { 9, 255, 255, 255, 0, 255, 0, 255, 0, 255 }; /* B -... */
static const uint8_t __morse_67[] = { 11, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* C -.-. */
static const uint8_t __morse_68[] = { 7, 255, 255, 255, 0, 255, 0, 255 }; /* D -.. */
static const uint8_t __morse_69[] = { 1, 255 }; /* E . */
static const uint8_t __morse_70[] = { 9, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* F ..-. */
static const uint8_t __morse_71[] = { 9, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* G --. */
static const uint8_t __morse_72[] = { 7, 255, 0, 255, 0, 255, 0, 255 }; /* H .... */
static const uint8_t __morse_73[] = { 3, 255, 0, 255 }; /* I .. */
static const uint8_t __morse_74[] = { 13, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* J .--- */
static const uint8_t __morse_75[] = { 9, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* K -.- */
static const uint8_t __morse_76[] = { 9, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* L .-.. */
static const uint8_t __morse_77[] = { 7, 255, 255, 255, 0, 255, 255, 255 }; /* M -- */
static const uint8_t __morse_78[] = { 5, 255, 255, 255, 0, 255 }; /* N -. */
static const uint8_t __morse_79[] = { 11, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* O --- */
static const uint8_t __morse_80[] = { 11, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* P .--. */
static const uint8_t __morse_81[] = { 13, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* Q --.- */
static const uint8_t __morse_82[] = { 7, 255, 0, 255, 255, 255, 0, 255 }; /* R .-. */
static const uint8_t __morse_83[] = { 5, 255, 0, 255, 0, 255 }; /* S ... */
static const uint8_t __morse_84[] = { 3, 255, 255, 255 }; /* T - */
static const uint8_t __morse_85[] = { 7, 255, 0, 255, 0, 255, 255, 255 }; /* U ..- */
static const uint8_t __morse_86[] = { 9, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* V ...- */
static const uint8_t __morse_87[] = { 9, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* W .-- */
static const uint8_t __morse_88[] = { 11, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* X -..- */
static const uint8_t __morse_89[] = { 13, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* Y -.-- */
static const uint8_t __morse_90[] = { 11, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* Z --.. */
static const uint8_t __morse_91[] = { 0,  }; /* [  */
static const uint8_t __morse_92[] = { 0,  }; /* \  */
static const uint8_t __morse_93[] = { 0,  }; /* ]  */
static const uint8_t __morse_94[] = { 0,  }; /* ^  */
static const uint8_t __morse_95[] = { 17, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* _ ..--.- */
static const uint8_t __morse_96[] = { 19, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* ` .----. */
static const uint8_t __morse_97[] = { 5, 255, 0, 255, 255, 255 }; /* a .- */
static const uint8_t __morse_98[] = { 9, 255, 255, 255, 0, 255, 0, 255, 0, 255 }; /* b -... */
static const uint8_t __morse_99[] = { 11, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* c -.-. */
static const uint8_t __morse_100[] = { 7, 255, 255, 255, 0, 255, 0, 255 }; /* d -.. */
static const uint8_t __morse_101[] = { 1, 255 }; /* e . */
static const uint8_t __morse_102[] = { 9, 255, 0, 255, 0, 255, 255, 255, 0, 255 }; /* f ..-. */
static const uint8_t __morse_103[] = { 9, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* g --. */
static const uint8_t __morse_104[] = { 7, 255, 0, 255, 0, 255, 0, 255 }; /* h .... */
static const uint8_t __morse_105[] = { 3, 255, 0, 255 }; /* i .. */
static const uint8_t __morse_106[] = { 13, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* j .--- */
static const uint8_t __morse_107[] = { 9, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* k -.- */
static const uint8_t __morse_108[] = { 9, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* l .-.. */
static const uint8_t __morse_109[] = { 7, 255, 255, 255, 0, 255, 255, 255 }; /* m -- */
static const uint8_t __morse_110[] = { 5, 255, 255, 255, 0, 255 }; /* n -. */
static const uint8_t __morse_111[] = { 11, 255, 255, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* o --- */
static const uint8_t __morse_112[] = { 11, 255, 0, 255, 255, 255, 0, 255, 255, 255, 0, 255 }; /* p .--. */
static const uint8_t __morse_113[] = { 13, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255, 255, 255 }; /* q --.- */
static const uint8_t __morse_114[] = { 7, 255, 0, 255, 255, 255, 0, 255 }; /* r .-. */
static const uint8_t __morse_115[] = { 5, 255, 0, 255, 0, 255 }; /* s ... */
static const uint8_t __morse_116[] = { 3, 255, 255, 255 }; /* t - */
static const uint8_t __morse_117[] = { 7, 255, 0, 255, 0, 255, 255, 255 }; /* u ..- */
static const uint8_t __morse_118[] = { 9, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* v ...- */
static const uint8_t __morse_119[] = { 9, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* w .-- */
static const uint8_t __morse_120[] = { 11, 255, 255, 255, 0, 255, 0, 255, 0, 255, 255, 255 }; /* x -..- */
static const uint8_t __morse_121[] = { 13, 255, 255, 255, 0, 255, 0, 255, 255, 255, 0, 255, 255, 255 }; /* y -.-- */
static const uint8_t __morse_122[] = { 11, 255, 255, 255, 0, 255, 255, 255, 0, 255, 0, 255 }; /* z --.. */
static const uint8_t* morse_t[] = {
    __morse_20,
    __morse_33,
    __morse_34,
    __morse_35,
    __morse_36,
    __morse_37,
    __morse_38,
    __morse_39,
    __morse_40,
    __morse_41,
    __morse_42,
    __morse_43,
    __morse_44,
    __morse_45,
    __morse_46,
    __morse_47,
    __morse_48,
    __morse_49,
    __morse_50,
    __morse_51,
    __morse_52,
    __morse_53,
    __morse_54,
    __morse_55,
    __morse_56,
    __morse_57,
    __morse_58,
    __morse_59,
    __morse_60,
    __morse_61,
    __morse_62,
    __morse_63,
    __morse_64,
    __morse_65,
    __morse_66,
    __morse_67,
    __morse_68,
    __morse_69,
    __morse_70,
    __morse_71,
    __morse_72,
    __morse_73,
    __morse_74,
    __morse_75,
    __morse_76,
    __morse_77,
    __morse_78,
    __morse_79,
    __morse_80,
    __morse_81,
    __morse_82,
    __morse_83,
    __morse_84,
    __morse_85,
    __morse_86,
    __morse_87,
    __morse_88,
    __morse_89,
    __morse_90,
    __morse_91,
    __morse_92,
    __morse_93,
    __morse_94,
    __morse_95,
    __morse_96,
    __morse_97,
    __morse_98,
    __morse_99,
    __morse_100,
    __morse_101,
    __morse_102,
    __morse_103,
    __morse_104,
    __morse_105,
    __morse_106,
    __morse_107,
    __morse_108,
    __morse_109,
    __morse_110,
    __morse_111,
    __morse_112,
    __morse_113,
    __morse_114,
    __morse_115,
    __morse_116,
    __morse_117,
    __morse_118,
    __morse_119,
    __morse_120,
    __morse_121,
    __morse_122};
