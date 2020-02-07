#pragma once
#include"SingleTone.h"

class Render:public singletonBase<Render>
{
private:
	ID2D1Factory*			_D2DFactory ;
	ID2D1HwndRenderTarget*	_D2DRenderTaget;
	IWICImagingFactory*		_WICFactory;
	IWICFormatConverter*	_ConvertedSrcBmp;
	ID2D1Bitmap*			_D2DBitmap;
public:
	Render();
	~Render();


	void initalizeD2D();
	void createRenderTarget(HWND hWnd);

	void initRenderTager(HWND hWnd);

	ID2D1HwndRenderTarget* getRenderTarget() { return _D2DRenderTaget; }
	IWICImagingFactory*	getImageFactory() { return _WICFactory; }
	IWICFormatConverter* getSrcBmp() { return _ConvertedSrcBmp; }
	ID2D1Bitmap* getBitmap() { return _D2DBitmap; }


};

