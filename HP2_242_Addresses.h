// HP2_242_Addresses.h — patch addresses for nfshp2.exe v242
// Reverse-extracted from the compiled HP2WSFix.asi by walking InjectRes()/InitInjector()
// in source-line order and reading off the immediate operands. ImageBase 0x00400000.

#pragma once

// Resolution limiter ----------------------------------------------------------
#define LIMITRES_ADDRESS              0x0083EFAC
#define LIMITRES_ADDRESS_JMP1         0x0046F3A5  // patched with JMP rel32 ...
#define LIMITRES_ADDRESS_JMP2         0x0046F3F1  // ... going here

// Aspect ratio (4 floats originally containing 1.3333334f) --------------------
#define ASPECT_ADDRESS_1              0x0040C501
#define ASPECT_ADDRESS_2              0x0053EB84
#define ASPECT_ADDRESS_3              0x0053ED7C
#define ASPECT_ADDRESS_4              0x0065D900
// (ASPECT_ADDRESS_5/6 are HP2DEBUG-only; not present in v242 release)

// Resolution X/Y patch sites --------------------------------------------------
#define RESX_ADDRESS_01               0x00541610  // mov  imm32
#define RESY_ADDRESS_01               0x00541617
#define RESX_ADDRESS_02               0x00541489  // push imm32
#define RESY_ADDRESS_02               0x00541484
#define RESX_ADDRESS_03               0x005414A5  // push imm32
#define RESY_ADDRESS_03               0x005414A0
#define RESX_ADDRESS_04               0x005415F4  // push imm32
#define RESY_ADDRESS_04               0x005415EF
#define RESX_ADDRESS_05               0x004D6A39  // cmp  imm32
#define RESY_ADDRESS_05               0x004D6A42
#define RESX_ADDRESS_06               0x005414DD  // mov  imm32
#define RESY_ADDRESS_06               0x005414E4
#define RESX_ADDRESS_07               0x00541899  // cmp  imm32
#define RESY_ADDRESS_07               0x005418A1
#define RESX_ADDRESS_08               0x0069D004  // float
#define RESY_ADDRESS_08               0x0069D008  // float
#define RESX_ADDRESS_09               0x0069D014  // float
#define RESY_ADDRESS_09               0x0069D018  // float
// NOTE: RESX_10 / RESY_10 swapped vs naming convention — these are read by the
// MAD movie playback code (only xref site: 0x004D7BA1/0x004D7BB5). The address
// at 0x006639F0 originally holds 600.0f (screen HEIGHT) and 0x006639F4 holds
// 800.0f (screen WIDTH). With the mod's `RESX gets resX, RESY gets resY` rule,
// the X address must point at the width slot and the Y address at the height
// slot — hence the assignment below is the correction. Without this swap the
// movie destination rect comes out with W and H exchanged (the symptom in
// VIDEO_BUG.md).
#define RESX_ADDRESS_10               0x006639F4  // float — screen WIDTH slot
#define RESY_ADDRESS_10               0x006639F0  // float — screen HEIGHT slot
#define RESX_ADDRESS_11               0x0045A8EC  // float (FixHUD only)
#define RESY_ADDRESS_11               0x0045A8F3  // float (FixHUD only)

// Frontend 3D Y-scale (aspect_diff = 4/3 / aspect) ----------------------------
#define FE_3DYSCALE_ADDRESS_1         0x00445BE3  // map actor
#define FE_3DYSCALE_ADDRESS_2         0x0044D59D  // car actor
#define FE_3DYSCALE_ADDRESS_3         0x0049C3F3  // event tree actor

// Frontend scaling globals (referenced by hooks; not patched directly) --------
#define FE_FUNCTIONS_YSCALE_ADDRESS   0x006C2DB4
#define FE_FUNCTIONS_XSCALE_ADDRESS   0x006C2DB0
#define FE_XSCALE_ADDRESS             0x006C2DA8
#define FE_XPOS_ADDRESS               0x0084BC48
#define FE_YPOS_ADDRESS               0x0084BC4C

// Language flag ---------------------------------------------------------------
#define LANGUAGE_ADDRESS              0x0084313C

// FOV ini-read hooks (16) -----------------------------------------------------
#define READINI_FLOAT_ADDRESS_01      0x0040EC2F
#define READINI_FLOAT_ADDRESS_02      0x0040ED5C
#define READINI_FLOAT_ADDRESS_03      0x0040EE83
#define READINI_FLOAT_ADDRESS_04      0x0040F624
#define READINI_FLOAT_ADDRESS_05      0x0040F751
#define READINI_FLOAT_ADDRESS_06      0x0040F878
#define READINI_FLOAT_ADDRESS_07      0x0040FF33
#define READINI_FLOAT_ADDRESS_08      0x0040FFFC
#define READINI_FLOAT_ADDRESS_09      0x004100C5
#define READINI_FLOAT_ADDRESS_10      0x004105E4
#define READINI_FLOAT_ADDRESS_11      0x00410626
#define READINI_FLOAT_ADDRESS_12      0x00410668
#define READINI_FLOAT_ADDRESS_13      0x00411092
#define READINI_FLOAT_ADDRESS_14      0x004110EA
#define READINI_FLOAT_ADDRESS_15      0x00411142
#define READINI_FLOAT_ADDRESS_16      0x00410D9B

// User-directory hooks (38) ---------------------------------------------------
#define GETUSERDIR_HOOK_ADDR_01       0x00437F4D
#define GETUSERDIR_HOOK_ADDR_02       0x00438027
#define GETUSERDIR_HOOK_ADDR_03       0x00446896
#define GETUSERDIR_HOOK_ADDR_04       0x004472DF
#define GETUSERDIR_HOOK_ADDR_05       0x00447316
#define GETUSERDIR_HOOK_ADDR_06       0x00447F90
#define GETUSERDIR_HOOK_ADDR_07       0x004487CE
#define GETUSERDIR_HOOK_ADDR_08       0x00448BAA
#define GETUSERDIR_HOOK_ADDR_09       0x0044FCE8
#define GETUSERDIR_HOOK_ADDR_10       0x004567B1
#define GETUSERDIR_HOOK_ADDR_11       0x00457075
#define GETUSERDIR_HOOK_ADDR_12       0x0045756F
#define GETUSERDIR_HOOK_ADDR_13       0x00457F2F
#define GETUSERDIR_HOOK_ADDR_14       0x00458662
#define GETUSERDIR_HOOK_ADDR_15       0x00458740
#define GETUSERDIR_HOOK_ADDR_16       0x0045882E
#define GETUSERDIR_HOOK_ADDR_17       0x00458A77
#define GETUSERDIR_HOOK_ADDR_18       0x004CF7B1
#define GETUSERDIR_HOOK_ADDR_19       0x004CFBF3
#define GETUSERDIR_HOOK_ADDR_20       0x004CFC19
#define GETUSERDIR_HOOK_ADDR_21       0x004CFC79
#define GETUSERDIR_HOOK_ADDR_22       0x004D6A4E
#define GETUSERDIR_HOOK_ADDR_23       0x004D9F8F
#define GETUSERDIR_HOOK_ADDR_24       0x004DA035
#define GETUSERDIR_HOOK_ADDR_25       0x004DA32F
#define GETUSERDIR_HOOK_ADDR_26       0x004DA3D5
#define GETUSERDIR_HOOK_ADDR_27       0x004DA4EE
#define GETUSERDIR_HOOK_ADDR_28       0x004EFDE4
#define GETUSERDIR_HOOK_ADDR_29       0x004F0363
#define GETUSERDIR_HOOK_ADDR_30       0x00507497
#define GETUSERDIR_HOOK_ADDR_31       0x00507AF6
#define GETUSERDIR_HOOK_ADDR_32       0x005133BA
#define GETUSERDIR_HOOK_ADDR_33       0x0051341F
#define GETUSERDIR_HOOK_ADDR_34       0x00514341
#define GETUSERDIR_HOOK_ADDR_35       0x00540ECE
#define GETUSERDIR_HOOK_ADDR_36       0x005410EE
#define GETUSERDIR_HOOK_ADDR_37       0x00549D7A
#define GETUSERDIR_HOOK_ADDR_38       0x00549F55

// WriteRenderCaps hooks (3) ---------------------------------------------------
#define WRITERENDERCAPS_ADDRESS_1     0x0046F0EC
#define WRITERENDERCAPS_ADDRESS_2     0x0046FE53
#define WRITERENDERCAPS_ADDRESS_3     0x004D656E

// Memory-pool sizes -----------------------------------------------------------
#define RENDERMEMORYSIZE_ADDR_1       0x0053BA84
#define RENDERMEMORYSIZE_ADDR_2       0x0053BA7D
#define RENDERMEMORYSIZE_ADDR_3       0x0053B8DD
#define GENERALMEMORYSIZE_ADDR_1      0x0053BBC2
#define GENERALMEMORYSIZE_ADDR_2      0x0053BBD1
#define AUDIOMEMORYSIZE_ADDR_1        0x0053B9EE
#define AUDIOMEMORYSIZE_ADDR_2        0x0053B849
#define TRACKMEMORYSIZE_ADDR_1        0x0053BA04
#define TRACKMEMORYSIZE_ADDR_2        0x0053B86E
#define LEVELMEMORYSIZE_ADDR_1        0x0053BA1A
#define LEVELMEMORYSIZE_ADDR_2        0x0053B893
#define UIMEMORYSIZE_ADDR_1           0x0053BA27
#define UIMEMORYSIZE_ADDR_2           0x0053BA35
#define UIMEMORYSIZE_ADDR_3           0x0053B993
#define CARSMEMORYSIZE_ADDR_1         0x0053BA59
#define CARSMEMORYSIZE_ADDR_2         0x0053B8B8
#define CHARACTERMEMORYSIZE_ADDR_1    0x0053BA9D
#define CHARACTERMEMORYSIZE_ADDR_2    0x0053B902
#define REPLAYMEMORYSIZE_ADDR_1       0x0053BAB3
#define REPLAYMEMORYSIZE_ADDR_2       0x0053B927
#define INIFILEMEMORYSIZE_ADDR_1      0x0053BADC
#define INIFILEMEMORYSIZE_ADDR_2      0x0053B96E

// FE/HUD hooks (FixHUD) -------------------------------------------------------
#define HOOK_ADDRESS_1                0x0045A8DC  // sub_59B840 hook (FixHUD)
#define HOOK_ADDRESS_2                0x0059410A  // sub_59B840_hook_2 (FixHUD>1)
#define HOOK_ADDRESS_3                0x00596F6A  // sub_59BAE0_hook (FixHUD>1)
#define HOOK_ADDRESS_4                0x005980D8  // sub_59BAE0_hook (FixHUD>1)
#define HOOK_ADDRESS_5                0x00462FDF  // sub_5954A0 hook (FixHUD)
#define HOOK_ADDRESS_6                0x00463501  // sub_5954A0 hook (FixHUD)

// Cuffometer mBounds NOPs (FixHUD>1) ------------------------------------------
#define CUFFOMETER_FIX_ADDR_1         0x00453C95
#define CUFFOMETER_FIX_ADDR_2         0x00453C16
#define CUFFOMETER_FIX_ADDR_3         0x00453C1F
#define CUFFOMETER_FIX_ADDR_4         0x00453C98

// Frontend scale/pos NOPs (FixHUD) --------------------------------------------
#define FE_XSCALENOP_ADDR             0x00595304
#define FE_YFUNCSCALENOP_ADDR         0x00595351
#define FE_XFUNCSCALENOP_ADDR         0x0059533F
#define FE_CURSORPOS_HOOK_ADDR        0x005A15A4
#define FE_XPOSNOP_ADDR               0x00595324

// Console printf hook (bEnableConsole) ----------------------------------------
#define PRINTF_HOOK_ADDR              0x00538140
