#ifndef _3DSEXIT_H_
#define _3DSEXIT_H_

// 一番上の行から追記して、標準ライブラリの読み込み時だけマクロを消滅させる
#undef _NOTHROW
#undef __alloc_size
#undef __alloc_size2

#include <stdlib.h>

// 読み込みが終わったら、エミュレータ側の元の仕様に戻す
#define _NOTHROW

#include <3ds.h>

extern aptHookCookie hookCookie;
extern int appExiting;

void setExitFlag(APT_HookType hook, void* param);
void enableExitHook();

#endif
