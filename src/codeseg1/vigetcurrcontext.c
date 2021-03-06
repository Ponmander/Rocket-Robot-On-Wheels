#include <include_asm.h>
#include <ultra64.h>

typedef struct
{
    /* 0x0 */ f32 factor;
    /* 0x4 */ u16 offset;
    /* 0x8 */ u32 scale;
} __OSViScale;

typedef struct
{
    /* 0x0 */ u16 state;
    /* 0x2 */ u16 retraceCount;
    /* 0x4 */ void *framep;
    /* 0x8 */ OSViMode *modep;
    /* 0xC */ u32 control;
    /* 0x10 */ OSMesgQueue *msgq;
    /* 0x14 */ OSMesg msg;
    /* 0x18 */ __OSViScale x;
    /* 0x24 */ __OSViScale y;
} __OSViContext; // 0x30 bytes

extern __OSViContext *__osViCurr;

// TODO libultra compiler
// __OSViContext *__osViGetCurrentContext(void)
// {
//     return __osViCurr;
// }

INCLUDE_ASM(s32, "codeseg1/vigetcurrcontext", __osViGetCurrentContext);
