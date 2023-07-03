#ifndef _IMESSAGE_H_
#define _IMESSAGE_H_

#include "MacroDefine.h"

class CROSS_PLATFORM_API IMessage
{
public:
	virtual void ShowMsg() = 0; // 将调用方需要调用的成员函数声明成纯虚函数
    virtual void SetStr(const char* m) = 0;
    virtual const char* GetStr() = 0;
};

extern "C" CROSS_PLATFORM_API IMessage* CALLING NewMessage(const char* m);

extern "C" CROSS_PLATFORM_API void CALLING hello();

#endif     //_IMESSAGE_H_
