#include <include_asm.h>
#include <ultra64.h>
#include <PR/sched.h>

struct unkD_800A6380 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u16 unkC;
};

extern struct unkD_800A6380 D_800A6380;
extern u32 D_800A638C;
extern u32 D_8009FE10;
extern u32 D_8009F094;
extern u32 D_800AB9C8;

// static bss
extern OSThread gThread1; // 0x800AF860
extern OSThread D_800AFA10; // 0x800AFA10 // thread 6
extern OSThread D_800AFBC0; // 0x800AFBC0 // thread 7
extern u8 gIdleThreadStack[0x1000]; // 0x800AFD70
extern u8 gThread6Stack[0x1000]; // 0x800B0D70
extern u8 gThread7Stack[0x8000]; // 0x800B1D70
extern OSMesg D_800B9D70[8]; // 0x800B9D70
extern OSMesg D_800B9D90[200]; // 0x800B9D90
extern OSMesgQueue D_800BA0B0; // 0x800BA0B0
extern OSMesg D_800BA0C8; // 0x800BA0C8
extern OSMesg D_800BA0CC; // 0x800BA0CC
extern u8 gSchedStack[OS_SC_STACKSIZE]; // 0x800BA0D0
extern OSScClient D_800BC0D0; // 0x800BC0D0
// end static bss (0x800BC0D8, padded to 0x800BC0E0)

// bss
extern u32 D_80017DE0; // 0x80017DE0
extern OSMesgQueue D_80017DE4; // 0x80017DE4
extern OSMesgQueue D_80017DFC; // 0x80017DFC
extern OSMesgQueue *gSchedMesgQueue; // 0x80017E14
extern OSSched gScheduler; // 0x80017E18
extern OSMesgQueue D_800180A0; // 0x800180A0
// end bss (0x800180B8, padded to 0x800180C0)


extern u8 _bssStart[];
extern u8 _bssEnd[];
extern u8 D_800F6AA0[];
extern u8 _dataRomEndCart[];
extern u8 D_80100000[];

void thread1_idle(void *);

// TODO regalloc
// void func_80000DD0()
// {
//     s32 diff;
//     s32 diff2;
//     bzero(_bssEnd, D_800F6AA0 - _bssEnd);
//     diff = _bssStart - D_80100000;
//     diff2 = _dataRomEndCart - diff;
//     if (diff > 0)
//     {
//         osInvalDCache(D_80100000, diff2);
//         osPiRawStartDma(0, _dataRomEndCart, 0x80100000, diff2);
//         while (osPiGetStatus() & 5);
//     }
// }

INCLUDE_ASM(s32, "codeseg0/codeseg0", func_80000DD0);

// TODO regalloc (same as func_80000DD0)
// void game_init()
// {
//     s32 diff;
//     s32 diff2;
//     osInitialize();
//     bzero(_bssEnd, D_800F6AA0 - _bssEnd);
//     diff = _bssStart - D_80100000;
//     diff2 = _dataRomEndCart - diff;
//     if (diff > 0)
//     {
//         osInvalDCache(D_80100000, diff2);
//         osPiRawStartDma(0, _dataRomEndCart, 0x80100000, diff2);
//         while (osPiGetStatus() & 5);
//     }
//     osCreateThread(&gThread1, 1, thread1_idle, NULL, &gIdleThreadStack[0x1000], 10);
//     osStartThread(&gThread1);
// }

INCLUDE_ASM(s32, "codeseg0/codeseg0", game_init);


void thread6_unk(void *);

void thread1_idle(void *arg0)
{
    osCreatePiManager(0x96, &D_800BA0B0, D_800B9D90, 200);
    osCreateThread(&D_800AFA10, 6, thread6_unk, NULL, &gThread6Stack[0x1000], 9);
    osStartThread(&D_800AFA10);
    osSetThreadPri(NULL, 0);
    while (1);
}

INCLUDE_ASM(s32, "codeseg0/codeseg0", thread6_unk);

void func_8001DE00(void);
void func_80041908(void);
void func_800638EC(s32);
void func_800954FC(void);
void func_8008FC1C(void);

void func_80061C18(void);
void func_80099A34(void);

void func_8004E64C(void);
void func_80046CBC(void);
void func_80037E60(void *, s32);
void func_8007F22C(void *);

void func_80075100(f32);
void func_80074ADC(void *, f32);
void func_8004ED04(void);
void func_8004E60C(void);



extern f32 D_80000500; // 1.0f / 6.0f

// TODO float load
// void func_80001248(void *arg0)
// {
//     f32 f20;
//     s16 sp10[2];
//     s32 *sp18; // OSMesg

//     func_8001DE00();
//     func_80041908();
//     func_800638EC(0);
//     sp10[0] = 0xFF;
//     osSendMesg(&D_80017DE4, &sp10, OS_MESG_BLOCK);
//     f20 = D_80000500;
//     while (1)
//     {
//         osRecvMesg(&D_800180A0, &sp18, OS_MESG_BLOCK);
//         if (sp18[0] != 0)
//         {
//             if (sp18[0] == 1)
//             {
//                 func_800954FC();
//             }
//         }
//         else
//         {
//             func_8008FC1C();
//             if (D_800A6380.unkC)
//             {
//                 func_80099A34();
//             }
//             func_80061C18();
//             if (sp18[2] == 0)
//             {
//                 func_8004E64C();
//                 func_80046CBC();
//                 func_80037E60(&D_8009FE10, sp18[1]);
//                 func_8007F22C(&D_8009F094);
//             }
//             func_80075100(sp18[1] * f20);
//             func_80074ADC(&D_800AB9C8, sp18[1] * f20);
//             func_8004ED04();
//             func_8004E60C();
//         }
//         sp10[0] = 0xFF;
//         osSendMesg(&D_80017DE4, &sp10, OS_MESG_BLOCK);
//     }
//     return;
// }

INCLUDE_ASM(s32, "codeseg0/codeseg0", func_80001248);

void create_scheduler()
{
    s32 tmp;

    osCreateMesgQueue(&D_80017DFC, &D_800BA0C8, 1);
    osCreateMesgQueue(&D_80017DE4, D_800B9D70, 8);
    switch (osTvType)
    {
        case OS_TV_PAL:
            tmp = OS_VI_PAL_LAN1;
            break;
        case OS_TV_NTSC:
            tmp = OS_VI_NTSC_LAN1;
            break;
        default:
            tmp = OS_VI_MPAL_LAN1;
            break;
    }
    osCreateScheduler(&gScheduler, &gSchedStack[OS_SC_STACKSIZE], 0xf, tmp, 1);
    osScAddClient(&gScheduler, &D_800BC0D0, &D_80017DE4);
    gSchedMesgQueue = osScGetCmdQ(&gScheduler);
    return;
}
