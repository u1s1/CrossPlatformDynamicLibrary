#ifndef _IEXCEL_H_
#define _IEXCEL_H_

#include "MacroDefine.h"

class CROSS_PLATFORM_API IExcel
{
public:
    virtual bool CreateExcel(const char  *szExcelPath, const char  *strSheet = "sheet1") = 0; // 将调用方需要调用的成员函数声明成纯虚函数
    virtual bool OpenExcel(const char  *m) = 0;
    virtual const char *GetCellStr(int row, int col) = 0;
    virtual bool SetCellStr(int row, int col, const char *m) = 0;
    virtual bool Save(const char  *m) = 0;
};

extern "C" CROSS_PLATFORM_API IExcel* CALLING NewExcel();

#endif     //_IEXCEL_H_