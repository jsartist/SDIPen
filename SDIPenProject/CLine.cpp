#include "pch.h"
#include "CLine.h"

IMPLEMENT_SERIAL(CLine, CObject, 1)

CLine::CLine(CPoint From, CPoint To, int size, COLORREF col) : m_From(From), m_To(To), size(size), m_col(col) {}

void CLine::Draw(CDC* pDC) {
	CPen pen(PS_SOLID, size, m_col);
	pDC->SelectObject(&pen);
	pDC->MoveTo(m_From);
	pDC->LineTo(m_To);
}

void CLine::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << m_From << m_To << size << m_col;
	}
	else
	{
		ar >> m_From >> m_To >> size >> m_col;
	}
}