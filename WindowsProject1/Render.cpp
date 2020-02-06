#include "stdafx.h"
#include "Render.h"


Render::Render()
{
}


Render::~Render()
{
}
void Render::initalizeD2D()
{
	CoInitialize(NULL);

	HRESULT hr = E_FAIL;
	//-------------------------
	//	D2D Factory를 생성한다.
	//-------------------------
	hr = ::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&_D2DFactory);
	assert(hr == S_OK);
}

void Render::createRenderTarget(HWND hWnd)
{
	//------------------------------------
	//윈도우 클라이언트 영역을 얻는다.
	//------------------------------------
	RECT winRc;
	::GetClientRect(hWnd, &winRc);

	//윈도우 클라이언트 렉트의 사이즈를 얻는다.
	//								가로,세로하면 저절로 크기가 넘어감
	D2D1_SIZE_U size = D2D1::SizeU(winRc.right - winRc.left, winRc.bottom - winRc.top);

	HRESULT hr = _D2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
												D2D1::HwndRenderTargetProperties(hWnd,size),
												&_D2DRenderTaget);
	assert(hr == S_OK);
}

void Render::initRenderTager(HWND hWnd)
{
	CoInitialize(NULL);
	RENDER->initalizeD2D();
	RENDER->createRenderTarget(hWnd);
}
