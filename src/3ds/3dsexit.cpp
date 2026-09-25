// 1. 標準ライブラリと競合するマクロを一度完全に消去する
#undef _NOTHROW
#undef __alloc_size
#undef __alloc_size2

// 2. この安全な状態で標準ライブラリをすべて読み込ませる
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 3. 読み込みが終わったら、エミュレータ側の元の仕様に戻す
#define _NOTHROW

#include <3ds.h>

#include "3dsexit.h"

aptHookCookie hookCookie;
int appExiting = 0;

void setExitFlag(APT_HookType hook, void* param)
{
    if (hook == APTHOOK_ONEXIT) {
        appExiting = 1;
    }
}

void enableExitHook() {
    aptHook(&hookCookie, setExitFlag, NULL);
}
