# SDIPen

## CLine Class 생성 및 추가할 내용
```c++
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
```
```c++
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
```
## Doc.h에 추가할 내용
```c++
public:
    CObArray m_oa;
```
## Doc.cpp에 수정할 내용
```c++
BOOL CMy4thclass2Doc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
    return FALSE;

    int n = m_oa.GetSize();

    for (int i = 0; i < n; i++)
        delete m_oa[i];

        m_oa.RemoveAll();
        // TODO: 여기에 재초기화 코드를 추가합니다.
        // SDI 문서는 이 문서를 다시 사용합니다.
        return TRUE;
}
```
## View.h에 추가할 내용
```c++
public:
    CPoint pnt;
    int size = 10;
    COLORREF col = RGB(255,255,255);
```
## View.cpp에 추가할 내용
```c++
void CMy4thclass2View::OnMouseMove(UINT nFlags, CPoint point)
{
    if (nFlags == MK_LBUTTON) {
        CLine* p = new CLine(pnt, point, size, col);
        GetDocument()->m_oa.Add(p);
        Invalidate(false);
    }
    pnt = point;
    CView::OnMouseMove(nFlags, point);
}

void CMy4thclass2View::OnSelCol()
{
    CColorDialog cdlg;
    if (cdlg.DoModal() == IDOK) {
        col = cdlg.GetColor();
    }
}

void CMy4thclass2View::OnSize1()
{
    size = 1;
}

void CMy4thclass2View::OnSize16()
{
    size = 16;
}

void CMy4thclass2View::OnSize64()
{
    size = 64;
}
```
