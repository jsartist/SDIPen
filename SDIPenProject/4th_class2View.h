
// 4th_class2View.h: CMy4thclass2View 클래스의 인터페이스
//

#pragma once


class CMy4thclass2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy4thclass2View() noexcept;
	DECLARE_DYNCREATE(CMy4thclass2View)

// 특성입니다.
public:
	CMy4thclass2Doc* GetDocument() const;
	CPoint pnt;
	int size = 10;
	COLORREF col = RGB(255,255,255);
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy4thclass2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelCol();
	afx_msg void OnSize1();
	afx_msg void OnSize16();
	afx_msg void OnSize64();
};

#ifndef _DEBUG  // 4th_class2View.cpp의 디버그 버전
inline CMy4thclass2Doc* CMy4thclass2View::GetDocument() const
   { return reinterpret_cast<CMy4thclass2Doc*>(m_pDocument); }
#endif

