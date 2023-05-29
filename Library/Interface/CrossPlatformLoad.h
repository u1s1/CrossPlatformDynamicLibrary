#ifndef _CROSSPLATFORMLOAD_H_
#define _CROSSPLATFORMLOAD_H_

#include "IMessage.h"

#if defined(_WIN32)
    #include <windows.h>
    typedef HMODULE  MODULE_HANDLE;
    MODULE_HANDLE hModule = LoadLibrary("CrossPlatformLib.dll");
#else
    #include <dlfcn.h>
    typedef void *  MODULE_HANDLE;
    MODULE_HANDLE hModule = dlopen("./libCrossPlatformLib.so", RTLD_NOW | RTLD_GLOBAL);
#endif

void *glo_GetModule(const char *pfname)
{
   if(hModule)
   {
#if defined(_WIN32)
        return (void *)GetProcAddress(hModule, pfname);
#else
        return dlsym(hModule,pfname);
#endif
    }
    return 0;
};

typedef void (*_VOID_)();
typedef IMessage *(_IMessage_)(const char* m);

_VOID_ hello = (_VOID_)glo_GetModule("hello");
_IMessage_* Message=(_IMessage_ *)glo_GetModule("NewMessage");

#endif
