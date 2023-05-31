#include "Excel.h"

Excel::Excel()
	:m_pBook(nullptr)
	, m_pSheet(nullptr)
{

}

Excel::~Excel()
{
	if (m_pBook)
		m_pBook->release();
}

bool Excel::CreateExcel(const char *szExcelPath, const char *strSheet)
{
	m_pBook = xlCreateXMLBook();
	if (!m_pBook)
		return false;
#ifdef _WIN32   //用于判断是否是win平台
	const char* x = "Halil Kural";
	const char* y = "windows-2723210a07c4e90162b26966a8jcdboe";
	m_pBook->setKey(x, y);
#endif
	m_pSheet = m_pBook->addSheet(strSheet);
	if (!m_pSheet)
		return false;
	
	return m_pBook->save(szExcelPath);
}


bool Excel::OpenExcel(const char  *m)
{
	m_pBook = xlCreateXMLBook();
#ifdef _WIN32   //用于判断是否是win平台
	const char* x = "Halil Kural";
	const char* y = "windows-2723210a07c4e90162b26966a8jcdboe";
	m_pBook->setKey(x, y);
#endif
	return m_pBook->load(m);
}

const char  *Excel::GetCellStr(int row, int col)
{
	return m_pSheet->readStr(row, col);
}

bool Excel::SetCellStr(int row, int col, const char *m)
{
	return m_pSheet->writeStr(row, col, m);
}

bool Excel::Save(const char  *m){
	return m_pBook->save(m);
}

IExcel* NewExcel()
{
	return new Excel();
}