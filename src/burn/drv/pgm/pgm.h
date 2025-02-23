#include "tiles_generic.h"
#include "m68000_intf.h"
#include "z80_intf.h"
#include "arm7_intf.h"


#define HARDWARE_IGS_JAMMAPCB		0x0002

// pgm_run
extern INT32 nPGM68KROMLen;
extern INT32 nPGMSPRColMaskLen;
extern INT32 nPGMSPRMaskMaskLen;
extern INT32 nPGMTileROMLen;
extern INT32 nPGMExternalARMLen;

extern UINT8 *PGM68KBIOS;
extern UINT8 *PGM68KRAM;
extern UINT8 *PGM68KROM;
extern UINT8 *PGMTileROM;
extern UINT8 *PGMTileROMExp;
extern UINT8 *PGMSPRColROM;
extern UINT8 *PGMSPRMaskROM;
extern UINT8 *PGMARMROM;
extern UINT8 *PGMUSER0;
extern UINT8 *PGMProtROM;
extern UINT8 *ICSSNDROM;
extern UINT8 *PGMARMRAM0;
extern UINT8 *PGMARMRAM1;
extern UINT8 *PGMARMRAM2;
extern UINT8 *PGMARMShareRAM;
extern UINT8 *PGMARMShareRAM2;
extern UINT16 *PGMRowRAM;
extern UINT16 *PGMPalRAM;
extern UINT16 *PGMZoomRAM;
extern UINT16 *PGMSprBuf;
extern UINT32 *PGMBgRAM;
extern UINT32 *PGMTxtRAM;
extern UINT32 *RamCurPal;
extern UINT8 nPgmPalRecalc;

extern UINT16 pgm_bg_scrollx;
extern UINT16 pgm_bg_scrolly;
extern UINT16 pgm_fg_scrollx;
extern UINT16 pgm_fg_scrolly;
extern UINT16 pgm_video_control;

extern UINT8 PgmJoy1[];
extern UINT8 PgmJoy2[];
extern UINT8 PgmJoy3[];
extern UINT8 PgmJoy4[];
extern UINT8 PgmBtn1[];
extern UINT8 PgmBtn2[];
extern UINT8 PgmInput[];
extern UINT8 PgmReset;

extern void (*pPgmInitCallback)();
extern void (*pPgmResetCallback)();
extern INT32 (*pPgmScanCallback)(INT32, INT32*);
extern void (*pPgmProtCallback)();
extern void (*pPgmTileDecryptCallback)(UINT8 *gfx, INT32 len);
extern void (*pPgmColorDataDecryptcallback)(UINT8 *gfx, INT32 len);

extern INT32 nPGMDisableIRQ4;
extern UINT32 nPgmAsicRegionHackAddress;
extern INT32 pgm_cave_refresh;

INT32 pgmInit();
INT32 pgmExit();
INT32 pgmFrame();
INT32 pgmScan(INT32 nAction, INT32 *pnMin);

// pgm_draw
void pgmInitDraw();
void pgmExitDraw();
INT32 pgmDraw();

// pgm_prot
void install_protection_asic3_orlegend();
void install_protection_asic25_asic12_dw2();
void install_protection_asic25_asic22_killbld();
void install_protection_asic25_asic22_drgw3();
void install_protection_asic25_asic28_olds();
void install_protection_asic27_kov();
void install_protection_asic27a_kovsh();
void install_protection_asic27a_martmast();
void install_protection_asic27a_oldsplus();
void install_protection_asic27a_puzlstar();
void install_protection_asic27a_svg();
void install_protection_asic27a_ketsui();
void install_protection_asic27a_ddp3();
void install_protection_asic27a_puzzli2();
void install_protection_asic27a_kovshp();
void install_protection_asic27a_py2k2();
void install_protection_asic27a_kovgsyx();

// pgm_crypt
void pgm_decrypt_kov();
void pgm_decrypt_kovsh();
void pgm_decrypt_kovshp();
void pgm_decrypt_puzzli2();
void pgm_decrypt_dw2();
void pgm_decrypt_photoy2k();
void pgm_decrypt_puzlstar();
void pgm_decrypt_dw3();
void pgm_decrypt_killbld();
void pgm_decrypt_dfront();
void pgm_decrypt_ddp2();
void pgm_decrypt_martmast();
void pgm_decrypt_dwpc();
void pgm_decrypt_kov2();
void pgm_decrypt_kov2p();
void pgm_decrypt_theglad();
void pgm_decrypt_killbldp();
void pgm_decrypt_oldsplus();
void pgm_decrypt_svg();
void pgm_decrypt_svgpcb();
void pgm_decrypt_happy6();
void pgm_decrypt_dw2001();
void pgm_decrypt_py2k2();
void pgm_decrypt_espgaluda();
void pgm_decrypt_ketsui();
void pgm_decrypt_pgm3in1();

void pgm_descramble_happy6_data(UINT8 *gfx, INT32 len);

void pgm_decode_kovqhsgs_gfx(UINT8 *gfx, INT32 len);
void pgm_decode_kovqhsgs_tile_data(UINT8 *gfx, INT32 len);
void pgm_decrypt_kovqhsgs();
void pgm_decrypt_kovlsqh2();
void pgm_decrypt_kovassgplus();
void pgm_decrypt_kovassge();
void pgm_decrypt_kovassgn();
void pgm_decrypt_kovlsqho();
void pgm_decrypt_kovgsyx();


