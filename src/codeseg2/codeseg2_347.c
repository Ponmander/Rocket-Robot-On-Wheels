#include <include_asm.h>
#include <ultra64.h>

struct unkfunc_80081E20 {
    u8 padding[0x64];
    void (*unk64)(struct unkfunc_80081E20 **, s32 *);
};

void func_80081E20(struct unkfunc_80081E20 **arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 var[3];
    var[0] = arg1;
    var[1] = arg2;
    var[2] = arg3;

    (*arg0)->unk64(arg0, var);
}

INCLUDE_ASM(s32, "codeseg2/codeseg2_347", func_80081E54);

INCLUDE_ASM(s32, "codeseg2/codeseg2_347", func_80081F04);

INCLUDE_ASM(s32, "codeseg2/codeseg2_347", func_80081FB8);

INCLUDE_ASM(s32, "codeseg2/codeseg2_347", func_8008208C);

INCLUDE_ASM(s32, "codeseg2/codeseg2_347", func_80082414);
