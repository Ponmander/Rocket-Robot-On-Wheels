#include <include_asm.h>
#include <ultra64.h>


s32 func_80050860(s32 arg0) {
    return arg0;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_179", func_80050868);

s32 func_800508A4()
{
    return 0;
}

s32 func_800508AC()
{
    return 0;
}

struct unkfunc_800508B4 {
    u8 padding[0x10];
    struct unkfunc_800508B4 *unk10;
};

s32 func_800508B4(struct unkfunc_800508B4 *arg0)
{
    while (arg0->unk10)
    {
        arg0 = arg0->unk10;
    }
    return arg0;
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_179", func_800508D8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_179", func_800508FC);

INCLUDE_ASM(s32, "codeseg2/codeseg2_179", func_80050948);

INCLUDE_ASM(s32, "codeseg2/codeseg2_179", func_8005098C);
