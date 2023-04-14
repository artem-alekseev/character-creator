#pragma once
#include <windows.h>
#include <sstream>
#include <d3d9.h>
#include <d3dx9.h>
#include <detours.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "ws2_32.lib")

typedef void(WINAPI* tCreateCharacter)();
typedef void(WINAPI* tExitCreateCharacter)();
typedef void(WINAPI* tExitAfterCreateCharacter)();
typedef void(WINAPI* tAnimationCreateCharacter)(DWORD* className);

extern "C" typedef HRESULT(WINAPI* tPresent) (LPDIRECT3DDEVICE9, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
extern "C" typedef HRESULT(WINAPI* tReset)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
tPresent oPresent = NULL;
tReset oReset = NULL;
tCreateCharacter oCreateCharacter = NULL;
tExitCreateCharacter oExitCreateCharacter = NULL;
tExitAfterCreateCharacter oExitAfterCreateCharacter = NULL;
tAnimationCreateCharacter oAnimationCreateCharacter = NULL;

#define PR  1
#define RS  2

LRESULT CALLBACK MsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hwnd, uMsg, wParam, lParam); }
void DrawTexture(RECT imagePosInDds, D3DXVECTOR3 Position);
void DrawDMTexture(RECT imagePosInDds, D3DXVECTOR3 Position);
void DrawNameTexture(RECT imagePosInDds, D3DXVECTOR3 Position);
void Draw26ClassTexture(RECT imagePosInDds, D3DXVECTOR3 Position);
void DrawClassTexture(RECT imagePosInDds, D3DXVECTOR3 Position);
void DrawHightTextWithOffset(RECT TextPos, char text[]);
void DrawHightTextWithoutOffset(RECT TextPos, char text[]);
void DrawTextWithOffset(RECT TextPos, char text[]);
void DrawTextWithoutOffset(RECT TextPos, char text[]);
void DrawTextWithoutOffsetGrey(RECT TextPos, char text[]);
void DrawMouse(LPDIRECT3DDEVICE9 pDevice);
void Patch(DWORD dst, BYTE* src, const intptr_t size);
bool CheckClick(D3DXVECTOR3 classPos, RECT imagePosInDds);
bool CheckClickWithoutOffset(D3DXVECTOR3 Pos, RECT ImagePos);
void ResizeTabs();
void Activate(BYTE classByte);

bool ViewClass = false;

RECT CurrentWindowRect;
BOOL isContainsCurrentWinRect = false;
LPD3DXSPRITE SptMenu;
LPDIRECT3DTEXTURE9 ClassTexture;
LPDIRECT3DTEXTURE9 DMClassTexture;
LPDIRECT3DTEXTURE9 EnterNameTexture;
tagPOINT CursorPos;
ID3DXFont* font;
ID3DXFont* hightFont;

INT xPosOffset = 10;
INT yPosOffset = 10;

RECT imagePosWAInDds = { 0 , 296 , 281 , 354 };
RECT imagePosBLInDds = { 0 , 365 , 281 , 423 };
RECT imagePosGLInDds = { 0 , 434 , 281 , 492 };
RECT imagePosFBInDds = { 0 , 503 , 281 , 561 };
RECT imagePosFSInDds = { 0 , 571 , 281 , 629 };

RECT imagePosFAInDds = { 0 , 640 , 281 , 698 };
RECT imagePosWIInDds = { 0 , 709 , 281 , 767 };
RECT imagePosFGInDds = { 0 , 778 , 281 , 836 };
RECT imagePosDMInDds = { 12 , 676 , 295 , 734 };

RECT imagePosWAActiveInDds = { 292 , 296 , 573 , 354 };
RECT imagePosBLActiveInDds = { 292 , 365 , 573 , 423 };
RECT imagePosGLActiveInDds = { 292 , 434 , 573 , 492 };
RECT imagePosFBActiveInDds = { 292 , 503 , 573 , 561 };
RECT imagePosFSActiveInDds = { 292 , 571 , 573 , 629 };

RECT imagePosFAActiveInDds = { 292 , 640 , 573 , 698 };
RECT imagePosWIActiveInDds = { 584 , 296 , 865 , 354 };
RECT imagePosFGActiveInDds = { 584 , 365 , 865 , 423 };
RECT imagePosDMActiveInDds = { 13 , 745 , 296 , 803 };

RECT imagePosActiveTabInDds = { 0 , 245 , 125 , 286 };
RECT imagePosDisactiveTabInDds = { 135 , 245 , 260 , 286 };

D3DXVECTOR3 TabSWPos = { float(0), float(0), 0.0f };
D3DXVECTOR3 TabMAPos = { float(155), float(0), 0.0f };

RECT TabSWTextPos = { 0, 0, 125, 41 };
RECT TabMATextPos = { 155, 0, 280, 41 };

RECT imageNamePosInDds = { 564, 673, 943, 772 };
D3DXVECTOR3 NamePosition = { float(-81), float(-170), 0.0f };
RECT NameTextPossition = { -81, -150, 298, -130 };
RECT NameTitleTextPossition = { 120, 60, 345, 110 };
RECT NameDescriptionTextPossition = { 120, 90, 645, 130 };
RECT NameFullDescriptionTextPossition = { 45, 130, 550, 230 };
RECT NameWeaponPossition= { 45, 240, 120, 340 };
RECT NameWeaponTextPossition = { 120, 240, 450, 340 };

RECT NameStatsStrPossition = { 45, 260, 120, 360 };
RECT NameStatsStrTextPossition = { 120, 260, 450, 360 };

RECT NameStatsIntPossition = { 45, 280, 120, 380 };
RECT NameStatsIntTextPossition = { 120, 280, 450, 380 };

RECT NameStatsDexPossition = { 45, 300, 120, 400 };
RECT NameStatsDexTextPossition = { 120, 300, 450, 400 };

D3DXVECTOR3 CurrentCharacterNamePosition = { float(35), float(50), 0.0f };
RECT CurrentCharacterNameWAInDds = { 935 , 107 , 1000 , 171 };
RECT CurrentCharacterNameBLInDds = { 935 , 179 , 1000 , 243 };
RECT CurrentCharacterNameGLInDds = { 935 , 611 , 1000 , 675 };
RECT CurrentCharacterNameFBInDds = { 935 , 465 , 1000 , 529 };
RECT CurrentCharacterNameFSInDds = { 935 , 321 , 1000 , 385 };
RECT CurrentCharacterNameFAInDds = { 935 , 393 , 1000 , 457 };
RECT CurrentCharacterNameWIInDds = { 935 , 250 , 1000 , 314 };
RECT CurrentCharacterNameFGInDds = { 935 , 539 , 1000 , 603 };
RECT CurrentCharacterNameDMInDds = { 935 , 752 , 1000 , 816 };

D3DXVECTOR3 classWAPos = { float(0), float(46), 0.0f };
D3DXVECTOR3 classBLPos = { float(0), float(115), 0.0f };
D3DXVECTOR3 classGLPos = { float(0), float(184), 0.0f };
D3DXVECTOR3 classFBPos = { float(0), float(253), 0.0f };
D3DXVECTOR3 classFSPos = { float(0), float(321), 0.0f };

D3DXVECTOR3 classFAPos = { float(0), float(46), 0.0f };
D3DXVECTOR3 classWIPos = { float(0), float(115), 0.0f };
D3DXVECTOR3 classFGPos = { float(0), float(184), 0.0f };
D3DXVECTOR3 classDMPos = { float(0), float(253), 0.0f };

RECT classWATextPos = { 0, 46, 200, 104 };
RECT classBLTextPos = { 0, 115, 200, 173 };
RECT classGLTextPos = { 0, 184, 200, 242 };
RECT classFBTextPos = { 0, 253, 200, 311 };
RECT classFSTextPos = { 0, 321, 200, 379 };

RECT classFATextPos = { 0, 46, 200, 104 };
RECT classWITextPos = { 0, 115, 200, 173 };
RECT classFGTextPos = { 0, 184, 200, 242 };
RECT classDMTextPos = { 0, 253, 200, 311 };

const BYTE WA = 0x01;
const BYTE BL = 0x02;
const BYTE GL = 0x03;
const BYTE FB = 0x04;
const BYTE FS = 0x05;
const BYTE FA = 0x06;
const BYTE WI = 0x07;
const BYTE FG = 0x08;
const BYTE DM = 0x09;

DWORD WAANIE = 0x31;
DWORD BLANIE = 0x32;
DWORD GLANIE = 0x31;
DWORD FBANIE = 0x36;
DWORD FSANIE = 0x35;
DWORD FAANIE = 0x34;
DWORD WIANIE = 0x33;
DWORD FGANIE = 0x34;
DWORD DMANIE = 0x33;

BYTE CurrentClass = WA;

const BYTE TabSW = 0x01;
const BYTE TabMA = 0x02;

BYTE ActiveClassTab = TabSW;

BYTE WA_ITEMS[20] = {
    0xCF, 0x03, 0x00, 0x00,
    0xD5, 0x03, 0x00, 0x00,
    0xDB, 0x03, 0x00, 0x00,
    0x66, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

BYTE GL_ITEMS[20] = {
    0xCF, 0x03, 0x00, 0x00,
    0xD5, 0x03, 0x00, 0x00,
    0xDB, 0x03, 0x00, 0x00,
    0xAF, 0x0F, 0x00, 0x00,
    0xAF, 0x0F, 0x00, 0x00,
};

BYTE WI_ITEMS[20] = {
    0xD4, 0x03, 0x00, 0x00,
    0xDA, 0x03, 0x00, 0x00,
    0xE0, 0x03, 0x00, 0x00,
    0x1B, 0x00, 0x00, 0x00,
    0x1B, 0x00, 0x00, 0x00,
};

BYTE DM_ITEMS[20] = {
    0xD4, 0x03, 0x00, 0x00,//item980
    0xDA, 0x03, 0x00, 0x00,
    0xE0, 0x03, 0x00, 0x00,
    0x88, 0x04, 0x00, 0x00,
    0x89, 0x04, 0x00, 0x00,
};