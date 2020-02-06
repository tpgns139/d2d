#pragma once
#include"SingleTone.h"

class Render:public singletonBase<Render>
{
private:
	ID2D1Factory*			_D2DFactory ;
	ID2D1HwndRenderTarget*	_D2DRenderTaget;
public:
	Render();
	~Render();


	void initalizeD2D();
	void createRenderTarget(HWND hWnd);

	void initRenderTager(HWND hWnd);

	ID2D1HwndRenderTarget* getRenderTarget() { return _D2DRenderTaget; }

};

