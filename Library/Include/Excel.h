#ifndef _EXCEL_H_
#define _EXCEL_H_

#if defined(_WIN32)
#pragma comment(lib,"../../ThirdLibWin/libxl/libx64/libxl.lib")
#endif

#include "IExcel.h"
#include "libxl.h"

class CROSS_PLATFORM_API Excel : public IExcel
{
public:
	Excel();
	~Excel();
	bool CreateExcel(const char  *szExcelPath, const char  *strSheet = "sheet1");
	bool OpenExcel(const char  *m);
	const char  *GetCellStr(int row, int col);
	bool SetCellStr(int row, int col, const char *m);
	bool Save(const char *m);

protected:
	libxl::Book* m_pBook;
	libxl::Sheet* m_pSheet;
};

#endif