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
	//	D2D Factory�� �����Ѵ�.
	//-------------------------
	hr = ::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&_D2DFactory);
	assert(hr == S_OK);
	//--------------------------------------
	//Windows Imagind Component Factory ����
	//--------------------------------------
	hr = ::CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_WICFactory));
	assert(hr == S_OK);
	
}

void Render::createRenderTarget(HWND hWnd)
{
	//------------------------------------
	//������ Ŭ���̾�Ʈ ������ ��´�.
	//------------------------------------
	RECT winRc;
	::GetClientRect(hWnd, &winRc);

	//������ Ŭ���̾�Ʈ ��Ʈ�� ����� ��´�.
	//								����,�����ϸ� ������ ũ�Ⱑ �Ѿ
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

void Render::Rectangle(D2D1_RECT_F rc, D2D1_COLOR_F color)
{
	ID2D1SolidColorBrush *brush = 0;
	_D2DRenderTaget->CreateSolidColorBrush(color, &brush);
	_D2DRenderTaget->DrawRectangle(rc, brush);
	RENDER->getRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
}
