#include <include_asm.h>
#include <ultra64.h>


s32 func_80004AB0(u8 *arg0, s32 arg1)
{
    arg0[0xB7] = 1; // TODO probably a struct
    return arg1;
}
