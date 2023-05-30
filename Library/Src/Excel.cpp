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
	const char* x = "Halil Kural";
	const char* y = "windows-2723210a07c4e90162b26966a8jcdboe";
	m_pBook->setKey(x, y);
	m_pSheet = m_pBook->addSheet(strSheet);
	if (!m_pSheet)
		return false;
	
	return m_pBook->save(szExcelPath);
}


bool Excel::OpenExcel(const char  *m)
{
	m_pBook = xlCreateXMLBook();
	const char* x = "Halil Kural";
	const char* y = "windows-2723210a07c4e90162b26966a8jcdboe";
	m_pBook->setKey(x, y);
	return m_pBook->load(m);
}

const char  *Excel::GetCell(int row, int col)
{
	libxl::Format **format = 0;
	return m_pSheet->readStr(row, col, format);
}

bool Excel::Save(const char  *m){
	return m_pBook->save(m);
}

IExcel* NewExcel()
{
	return new Excel();
}