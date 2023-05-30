#ifndef _CROSSPLATFORMLOAD_H_
#define _CROSSPLATFORMLOAD_H_

#include "ModuleLoad.h"
#include "IMessage.h"
#include "IExcel.h"

typedef void (*_VOID_)();
typedef IMessage *(_IMessage_)(const char* m);
typedef IExcel *(_IExcel_)();

_VOID_ hello = (_VOID_)glo_GetModule("hello");
_IMessage_ *Message = (_IMessage_ *)glo_GetModule("NewMessage");
_IExcel_ *Excel = (_IExcel_ *)glo_GetModule("NewExcel");

#endif          //_CROSSPLATFORMLOAD_H_
