
// 4th_class2View.cpp: CMy4thclass2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "4th_class2.h"
#endif

#include "4th_class2Doc.h"
#include "4th_class2View.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy4thclass2View
#include "CLine.h"
IMPLEMENT_DYNCREATE(CMy4thclass2View, CView)

BEGIN_MESSAGE_MAP(CMy4thclass2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SEL_COL, &CMy4thclass2View::OnSelCol)
	ON_COMMAND(ID_SIZE_1, &CMy4thclass2View::OnSize1)
	ON_COMMAND(ID_SIZE_16, &CMy4thclass2View::OnSize16)
	ON_COMMAND(ID_SIZE_64, &CMy4thclass2View::OnSize64)
END_MESSAGE_MAP()

// CMy4thclass2View 생성/소멸

CMy4thclass2View::CMy4thclass2View() noexcept
{
}

CMy4thclass2View::~CMy4thclass2View()
{
}

BOOL CMy4thclass2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy4thclass2View 그리기
COLORREF col;
void CMy4thclass2View::OnDraw(CDC* pDC)
{
	CMy4thclass2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int n = pDoc->m_oa.GetSize();
	CLine* p;
	for (int i = 0; i < n; i++) {
		p = (CLine*)pDoc->m_oa[i];
		p->Draw(pDC);
	}
}


// CMy4thclass2View 인쇄

BOOL CMy4thclass2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy4thclass2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy4thclass2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy4thclass2View 진단

#ifdef _DEBUG
void CMy4thclass2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4thclass2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4thclass2Doc* CMy4thclass2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4thclass2Doc)));
	return (CMy4thclass2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4thclass2View 메시지 처리기

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
