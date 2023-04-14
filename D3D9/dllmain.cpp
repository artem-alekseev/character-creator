#include "dllmain.h"

/*
    Copyright © 2022, Artem Alekseev
    All rights reserved.
    For https://forum.ragezone.com/
*/

using namespace std;

HRESULT WINAPI hkPresent(LPDIRECT3DDEVICE9 pDev, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    if (!isContainsCurrentWinRect) {
        ResizeTabs();

        isContainsCurrentWinRect = true;
    }

    if (ViewClass) {
        if (!SptMenu) {
            D3DXCreateSprite(pDev, &SptMenu);
        }

        if (!ClassTexture) {
            D3DXCreateTextureFromFileA(pDev, "Data\\UI\\Theme1\\UI_Texture25.dds", &ClassTexture);
        }

        if (!DMClassTexture) {
            D3DXCreateTextureFromFileA(pDev, "Data\\UI\\Theme1\\UI_Texture55.dds", &DMClassTexture);
        }

        if (!EnterNameTexture) {
            D3DXCreateTextureFromFileA(pDev, "Data\\UI\\Theme1\\UI_Texture26.dds", &EnterNameTexture);
        }

        if (!hightFont) {
            D3DXCreateFontA(pDev, 32, NULL, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Roboto", &hightFont);
        }

        if (!font) {
            D3DXCreateFontA(pDev, 16, NULL, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Roboto", &font);
        }

        SptMenu->Begin(D3DXSPRITE_ALPHABLEND);

        DrawTextWithoutOffset(NameWeaponPossition, (char*)"Weapon");
        DrawTextWithoutOffset(NameStatsStrPossition, (char*)"STR");
        DrawTextWithoutOffset(NameStatsIntPossition, (char*)"INT");
        DrawTextWithoutOffset(NameStatsDexPossition, (char*)"DEX");

        if (CurrentClass == WA) {
            DrawClassTexture(CurrentCharacterNameWAInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Warrior");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"The best melee fighter who possesses powerful fencing skills");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Successors of 'the earliest Rules of the Force'. Training sticly focuses on physical strength, therefore preferring strong and reliable armours such as \n'Armor Suit Set' from the Midreth Continent.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Great Sword or Daikatana");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"24");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"3");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"8");
        }

        if (CurrentClass == BL) {
            DrawClassTexture(CurrentCharacterNameBLInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Blader");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"The deadly blade dancer, the fastest dual sword user");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Successors of 'the intermediate Rules of the Force' originated from ancient easten martial art focusing on speed. They either use one single-edged sword or two double-edger swords. Skills require them to move quickly and nimbly, thus they prefer light 'Martial Suit Set' from the Huan Continent as South.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Blade or Katana");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"16");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"3");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"16");
        }

        if (CurrentClass == GL) {
            DrawClassTexture(CurrentCharacterNameGLInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Gladiator");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"Strength gained by uprising rage");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Gladiator can control the anger towards their opponent, converting into a pure forn of rage to create a mighty force of strength. Specialized in hard trained physical abilities, they prefer 'Armor Suit Set' to pull their strenghts to the limits");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Chakrams");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"27");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"3");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"5");
        }

        if (CurrentClass == FB) {
            DrawClassTexture(CurrentCharacterNameFBInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Force Blader");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"Swordsman whose blade flares with the force");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Force Bladers are the final successors of the Rules of the Force. They use orb and one-handed sword to cast aggressive forms of the force and to physically attack at the same time. They value physical balance and coordination, \nthus prefer 'Battle Suit Set'.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Katana and Orb");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"12");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"12");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"11");
        }

        if (CurrentClass == FS) {
            DrawClassTexture(CurrentCharacterNameFSInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Force Shielder");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"The faithful warrior thet uses the force to shield others");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Force Shielders hold Crystals to manifest an 'Astral Shield' and use \none-handed sword to attack. Since they can equip the 'Astral Shield', they possess the highest defence among all the battle styles. Specialized in defending, Force Shields preger strong and reliable 'Armor Suit Set'");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Blade and Crystal");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"15");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"11");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"9");
        }

        if (CurrentClass == FA) {
            DrawClassTexture(CurrentCharacterNameFAInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Force Archer");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"The sniper that fires deadly force shots that cut through the wind");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Originated from Wizard faction, Wizard developed various ways of manifesting the force to attack from a distance. They mainly use Crystals as their weapons, however they also use 'Astral Bows' as the carriers of the force to control the force more efficiently. They prefer 'Battle Suit Set' from the Pastur Continent.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Crystals");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"6");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"17");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"12");
        }

        if (CurrentClass == WI) {
            DrawClassTexture(CurrentCharacterNameWIInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Wizard");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"Ultimate Destroyer, the Ruler of the Force");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Third seccessors inherited from the Sage Tower, who manifest the force in its purest form. \nThey use weapon called 'Force Amplifier - Orb', worn on both wrists. \nFor armors, they prefer light 'Martial Suit Set'.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Orbs");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"3");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"26");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"6");
        }

        if (CurrentClass == FG) {
            DrawClassTexture(CurrentCharacterNameFGInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Force Gunner");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"A genius mechanic and Force user");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Secret agents talented in using force and machines. They can make accurate shots bindfolded by maximizing the power of Astral Weapon and train to improve INT/DEX. Force Gunners prefers 'Battle Suit Set' for more balance.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Crystals or Orbs");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"5");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"25");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"5");
        }

        if (CurrentClass == DM) {
            DrawClassTexture(CurrentCharacterNameDMInDds, CurrentCharacterNamePosition);
            DrawHightTextWithoutOffset(NameTitleTextPossition, (char*)"Dark Mage");
            DrawTextWithoutOffset(NameDescriptionTextPossition, (char*)"Handler of twisted force");
            DrawTextWithoutOffsetGrey(NameFullDescriptionTextPossition, (char*)"Dark Mage combinds Soul and Force to create a new twisted force. They can neutralize enemies through power of souls. Souls are handled with orbs on both hands, and freffers light armors.");
            DrawTextWithoutOffsetGrey(NameWeaponTextPossition, (char*)"Skull and Sickle");

            DrawTextWithoutOffsetGrey(NameStatsStrTextPossition, (char*)"4");
            DrawTextWithoutOffsetGrey(NameStatsIntTextPossition, (char*)"26");
            DrawTextWithoutOffsetGrey(NameStatsDexTextPossition, (char*)"5");
        }

        if (ActiveClassTab == TabSW) {
            DrawTexture(imagePosDisactiveTabInDds, TabMAPos);
            DrawTexture(imagePosActiveTabInDds, TabSWPos);

            DrawTextWithOffset(classWATextPos, (char*)"Warrior");
            DrawTextWithOffset(classBLTextPos, (char*)"Blader");
            DrawTextWithOffset(classGLTextPos, (char*)"Gladiator");
            DrawTextWithOffset(classFBTextPos, (char*)"Force Blader");
            DrawTextWithOffset(classFSTextPos, (char*)"Force Shielder");

            if (CurrentClass == WA) {
                DrawTexture(imagePosWAActiveInDds, classWAPos);
            }
            else {
                DrawTexture(imagePosWAInDds, classWAPos);
            }

            if (CurrentClass == BL) {
                DrawTexture(imagePosBLActiveInDds, classBLPos);
            }
            else {
                DrawTexture(imagePosBLInDds, classBLPos);
            }

            if (CurrentClass == GL) {
                DrawTexture(imagePosGLActiveInDds, classGLPos);
            }
            else {
                DrawTexture(imagePosGLInDds, classGLPos);
            }

            if (CurrentClass == FB) {
                DrawTexture(imagePosFBActiveInDds, classFBPos);
            }
            else {
                DrawTexture(imagePosFBInDds, classFBPos);
            }

            if (CurrentClass == FS) {
                DrawTexture(imagePosFSActiveInDds, classFSPos);
            }
            else {
                DrawTexture(imagePosFSInDds, classFSPos);
            }
        }

        if (ActiveClassTab == TabMA) {
            DrawTexture(imagePosActiveTabInDds, TabMAPos);
            DrawTexture(imagePosDisactiveTabInDds, TabSWPos);

            DrawTextWithOffset(classFATextPos, (char*)"Force Archer");
            DrawTextWithOffset(classWITextPos, (char*)"Wizard");
            DrawTextWithOffset(classFGTextPos, (char*)"Force Gunner");
            DrawTextWithOffset(classDMTextPos, (char*)"Dark Mage");

            if (CurrentClass == FA) {
                DrawTexture(imagePosFAActiveInDds, classFAPos);
            }
            else {
                DrawTexture(imagePosFAInDds, classFAPos);
            }

            if (CurrentClass == WI) {
                DrawTexture(imagePosWIActiveInDds, classWIPos);
            }
            else {
                DrawTexture(imagePosWIInDds, classWIPos);
            }

            if (CurrentClass == FG) {
                DrawTexture(imagePosFGActiveInDds, classFGPos);
            }
            else {
                DrawTexture(imagePosFGInDds, classFGPos);
            }

            if (CurrentClass == DM) {
                DrawDMTexture(imagePosDMActiveInDds, classDMPos);
            }
            else {
                DrawDMTexture(imagePosDMInDds, classDMPos);
            }
        }

        DrawNameTexture(imageNamePosInDds, NamePosition);
        DrawTextWithOffset(NameTextPossition, (char*)"Character Name");

        DrawTextWithOffset(TabSWTextPos, (char*)"Physical");
        DrawTextWithOffset(TabMATextPos, (char*)"Magical");

        DrawMouse(pDev);

        SptMenu->End();
    }

    return oPresent(pDev, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

void Draw26ClassTexture(RECT imagePosInDds, D3DXVECTOR3 Position)
{
    SptMenu->Draw(EnterNameTexture, &imagePosInDds, NULL, &Position, 0xFFFFFFFF);
}

void DrawClassTexture(RECT imagePosInDds, D3DXVECTOR3 Position)
{
    SptMenu->Draw(ClassTexture, &imagePosInDds, NULL, &Position, 0xFFFFFFFF);
}

void DrawNameTexture(RECT imagePosInDds, D3DXVECTOR3 Position)
{
    Position.x += xPosOffset;
    Position.y += yPosOffset;

    SptMenu->Draw(EnterNameTexture, &imagePosInDds, NULL, &Position, 0xFFFFFFFF);
}

void DrawDMTexture(RECT imagePosInDds, D3DXVECTOR3 Position)
{
    Position.x += xPosOffset;
    Position.y += yPosOffset;

    SptMenu->Draw(DMClassTexture, &imagePosInDds, NULL, &Position, 0xFFFFFFFF);
}

void DrawTexture(RECT imagePosInDds, D3DXVECTOR3 Position)
{
    Position.x += xPosOffset;
    Position.y += yPosOffset;

    SptMenu->Draw(ClassTexture, &imagePosInDds, NULL, &Position, 0xFFFFFFFF);
}

void DrawHightTextWithOffset(RECT TextPos, char text[])
{
    TextPos.left += xPosOffset;
    TextPos.top += yPosOffset;
    TextPos.right += xPosOffset;
    TextPos.bottom += yPosOffset;

    hightFont->DrawTextA(SptMenu, text, -1, &TextPos, DT_VCENTER | DT_CENTER | DT_SINGLELINE, D3DCOLOR_ARGB(255, 220, 220, 220));
}

void DrawHightTextWithoutOffset(RECT TextPos, char text[])
{
    hightFont->DrawTextA(SptMenu, text, -1, &TextPos, DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void DrawTextWithOffset(RECT TextPos, char text[])
{
    TextPos.left += xPosOffset;
    TextPos.top += yPosOffset;
    TextPos.right += xPosOffset;
    TextPos.bottom += yPosOffset;

    font->DrawTextA(SptMenu, text, -1, &TextPos, DT_VCENTER | DT_CENTER | DT_SINGLELINE, D3DCOLOR_ARGB(255, 200, 200, 200));
}

void DrawTextWithoutOffset(RECT TextPos, char text[])
{
    font->DrawTextA(SptMenu, text, -1, &TextPos, DT_LEFT, D3DCOLOR_ARGB(255, 112, 178, 238));
}

void DrawTextWithoutOffsetGrey(RECT TextPos, char text[])
{
    font->DrawTextA(SptMenu, text, -1, &TextPos, DT_LEFT | DT_WORDBREAK, D3DCOLOR_ARGB(255, 175, 175, 175));
}

void ResizeTabs()
{
    GetWindowRect(GetActiveWindow(), &CurrentWindowRect);

    xPosOffset = (CurrentWindowRect.right - CurrentWindowRect.left) - 348;
    yPosOffset = (CurrentWindowRect.bottom - CurrentWindowRect.top) / 2 - 250;
}

HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pParam)
{
    HRESULT hr = NULL;

    ResizeTabs();

    if (SptMenu) {
        SptMenu->OnLostDevice();
    }

    if (font) {
        font->OnLostDevice();
    }

    if (hightFont) {
        hightFont->OnLostDevice();
    }
    
    hr = oReset(pDevice, pParam);

    if (SptMenu) {
        SptMenu->OnResetDevice();
    }

    if (font) {
        font->OnResetDevice();
    }

    if (hightFont) {
        hightFont->OnResetDevice();
    }

    return hr;
}

void DrawMouse(LPDIRECT3DDEVICE9 pDevice)
{
    GetCursorPos(&CursorPos);
    ScreenToClient(GetActiveWindow(), &CursorPos);

    if (GetKeyState(VK_LBUTTON) & 0x80)
    {
        if (ActiveClassTab == TabSW) {
            bool isWA = CheckClick(classWAPos, imagePosWAInDds);

            if (isWA && CurrentClass != WA) {
                Activate(WA);

                return;
            }

            bool isBL = CheckClick(classBLPos, imagePosBLInDds);

            if (isBL && CurrentClass != BL) {
                Activate(BL);
                
                return;
            }

            bool isGL = CheckClick(classGLPos, imagePosGLInDds);

            if (isGL && CurrentClass != GL) {
                Activate(GL);
                
                return;
            }

            bool isFB = CheckClick(classFBPos, imagePosFBInDds);

            if (isFB && CurrentClass != FB) {
                Activate(FB);
                
                return;
            }

            bool isFS = CheckClick(classFSPos, imagePosFSInDds);

            if (isFS && CurrentClass != FS) {
                Activate(FS);
                
                return;
            }

            bool isTabMA = CheckClick(TabMAPos, imagePosActiveTabInDds);

            if (isTabMA) {
                ActiveClassTab = TabMA;
            }
        }

        if (ActiveClassTab == TabMA) {
            bool isFA = CheckClick(classFAPos, imagePosFAInDds);

            if (isFA && CurrentClass != FA) {
                Activate(FA);
                
                return;
            }

            bool isWI = CheckClick(classWIPos, imagePosWIInDds);

            if (isWI && CurrentClass != WI) {
                Activate(WI);
                
                return;
            }

            bool isFG = CheckClick(classFGPos, imagePosFGInDds);

            if (isFG && CurrentClass != FG) {
                Activate(FG);
                
                return;
            }

            bool isDM = CheckClick(classDMPos, imagePosDMInDds);

            if (isDM && CurrentClass != DM) {
                Activate(DM);

                return;
            }

            bool isTabSW = CheckClick(TabSWPos, imagePosActiveTabInDds);

            if (isTabSW) {
                ActiveClassTab = TabSW;
            }
        }
    }
}

bool CheckClickWithoutOffset(D3DXVECTOR3 Pos, RECT ImagePos)
{
    if (
        (CursorPos.x > (Pos.x))
        && (CursorPos.x < (Pos.x + ImagePos.right - ImagePos.left))
        && (CursorPos.y > Pos.y)
        && (CursorPos.y < (Pos.y + ImagePos.bottom - ImagePos.top))
        ) {
        return true;
    }

    return false;
}

bool CheckClick(D3DXVECTOR3 Pos, RECT ImagePos)
{
    Pos.x += xPosOffset;
    Pos.y += yPosOffset;

    if (
        (CursorPos.x > (Pos.x))
        && (CursorPos.x < (Pos.x + ImagePos.right - ImagePos.left))
        && (CursorPos.y > Pos.y)
        && (CursorPos.y < (Pos.y + ImagePos.bottom - ImagePos.top))
        ) {
        return true;
    }

    return false;
}

void DX_Init(DWORD* table)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX),CS_CLASSDC,MsgProc,0L,0L,GetModuleHandle(NULL),NULL,NULL,NULL,NULL,L"DX",NULL };
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowA("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
    LPDIRECT3D9 pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    LPDIRECT3DDEVICE9 pd3dDevice;
    pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice);
    DWORD* pVTable = (DWORD*)pd3dDevice;
    pVTable = (DWORD*)pVTable[0];

    table[PR] = pVTable[17];
    table[RS] = pVTable[16];

    DestroyWindow(hWnd);
}

void DrawAnimationCreateCharacter() {
    
    switch (CurrentClass)
    {
        case WA:
            oAnimationCreateCharacter(&WAANIE);
            break;
        case BL:
            oAnimationCreateCharacter(&BLANIE);
            break;
        case GL:
            oAnimationCreateCharacter(&GLANIE);
            break;
        case FB:
            oAnimationCreateCharacter(&FBANIE);
            break;
        case FS:
            oAnimationCreateCharacter(&FSANIE);
            break;
        case FA:
            oAnimationCreateCharacter(&FAANIE);
            break;
        case WI:
            oAnimationCreateCharacter(&WIANIE);
            break;
        case FG:
            oAnimationCreateCharacter(&FGANIE);
            break;
        case DM:
            oAnimationCreateCharacter(&DMANIE);
            break;
        default:
            oAnimationCreateCharacter(&WAANIE);
    }
}

void Activate(BYTE classByte)
{
    BYTE dmbytes[4] = { 0x00, 0x00, 0x00, 0x00 };
    DWORD handle = (DWORD)GetModuleHandleA("cabalmain.exe");

    DWORD* BaseAddress = (DWORD*)(handle + 0xC7BF5C);
    DWORD offsetAddress = (*BaseAddress + 0x41A8);

    std::memcpy(dmbytes, (PVOID)offsetAddress, 4);
    
    bool gender = false;

    if (dmbytes[3] == 0x04 || dmbytes[3] == 0x24 || dmbytes[3] == 0x34 || dmbytes[3] == 0x44)
    {
        gender = true;
    }

    switch (classByte)
    {
        case WA:
            dmbytes[3] = gender ? 0x04 : 0x00;
            std::memcpy((PVOID)0x107C868, WA_ITEMS, 20);
            break;
        case BL:
            dmbytes[3] = gender ? 0x04 : 0x00;
            break;
        case GL:
            dmbytes[3] = gender ? 0x24 : 0x20;
            std::memcpy((PVOID)0x107C868, GL_ITEMS, 20);
            break;
        case FB:
            dmbytes[3] = gender ? 0x04 : 0x00;
            break;
        case FS:
            dmbytes[3] = gender ? 0x04 : 0x00;
            break;
        case FA:
            dmbytes[3] = gender ? 0x04 : 0x00;
            break;
        case WI:
            dmbytes[3] = gender ? 0x04 : 0x00;
            std::memcpy((PVOID)0x0107C910, WI_ITEMS, 20);
            break;
        case FG:
            dmbytes[3] = gender ? 0x34 : 0x30;
            break;
        case DM:
            dmbytes[3] = gender ? 0x44 : 0x40;
            std::memcpy((PVOID)0x0107C910, DM_ITEMS, 20);
            break;
        default:
            dmbytes[3] = gender ? 0x04 : 0x00;
    }
    
    Patch(offsetAddress, dmbytes, 4);

    CurrentClass = classByte;

    DrawAnimationCreateCharacter();
}

void hkCreateCharacter()
{
    ViewClass = true;
    Activate(WA);
    ActiveClassTab = TabSW;

    oCreateCharacter();
}

void hkExitCreateCharacter()
{
    ViewClass = false;

    oExitCreateCharacter();
}

void hkExitAfterCreateCharacter()
{
    ViewClass = false;

    oExitAfterCreateCharacter();
}

DWORD WINAPI SetHook(LPVOID lpParam)
{
    DWORD VTable[3] = { 0, 0, 0 };
    HMODULE d3d9 = NULL;

    while (d3d9 == NULL) {
        d3d9 = GetModuleHandleA("d3d9.dll");
        Sleep(250);
    }

    DX_Init(VTable);

    oPresent = (tPresent)((PVOID*)(VTable[PR]));
    oReset = (tReset)((PVOID*)(VTable[RS]));
    oCreateCharacter = (tCreateCharacter)((PVOID*)(0x66CF11));
    oExitCreateCharacter = (tExitCreateCharacter)((PVOID*)(0x736667));
    oExitAfterCreateCharacter = (tExitAfterCreateCharacter)((PVOID*)(0x763A5B));
    oAnimationCreateCharacter = (tAnimationCreateCharacter)((PVOID*)(0x735CE2));

    DetourRestoreAfterWith();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)oPresent, hkPresent);
    DetourAttach(&(PVOID&)oReset, hkReset);
    DetourAttach(&(PVOID&)oCreateCharacter, hkCreateCharacter);
    DetourAttach(&(PVOID&)oExitCreateCharacter, hkExitCreateCharacter);
    DetourAttach(&(PVOID&)oExitAfterCreateCharacter, hkExitAfterCreateCharacter);
    if (DetourTransactionCommit() != NO_ERROR) {
        MessageBox(NULL, L"ERROR", L"Hook", 0);
    }

    return 0;
}

void Patch(DWORD dst, BYTE* src, const intptr_t size)
{
    DWORD oldprotect;

    VirtualProtect((PVOID)dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
    std::memcpy((PVOID)dst, src, size);
    VirtualProtect((PVOID)dst, size, oldprotect, &oldprotect);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, SetHook, 0, 0, 0);
    }

    return TRUE;
}