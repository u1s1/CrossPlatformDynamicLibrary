#ifndef _CROSSPLATFORMLOAD_H_
#define _CROSSPLATFORMLOAD_H_

#include "ModuleLoad.h"
#include "IMessage.h"

typedef void (*_VOID_)();
typedef IMessage *(_IMessage_)(const char* m);

_VOID_ hello = (_VOID_)glo_GetModule("hello");
_IMessage_* Message=(_IMessage_ *)glo_GetModule("NewMessage");

#endif          //_CROSSPLATFORMLOAD_H_
