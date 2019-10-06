#pragma once
#include <afx.h>
class CLine :
	public CObject
{
	CPoint m_From, m_To;
	int size;
	COLORREF m_col;

	
	DECLARE_SERIAL(CLine)
public:
	CLine() {}
	CLine(CPoint From, CPoint To, int size, COLORREF col);

	void Draw(CDC* pDC);
	
	void Serialize(CArchive& ar);
};
