#include "stdafx.h"
#include "Image.h"


Image::Image()
{
}


Image::~Image()
{
}
//					뿌릴 x위치,뿌릴 y위치,너비,높이
void Image::render(float x, float y, float sizeX, float sizeY)
{
	::D2D1_RECT_F dxArea = ::D2D1::RectF(x- sizeX* 0.5f, y- sizeY * 0.5f ,x+ sizeX* 0.5f, y+sizeY * 0.5f);

	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x+sizeX*0.5f, y + sizeY * 0.5f);

	RENDER->getRenderTarget()->SetTransform( trans);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);
}
//					뿌릴 x위치,뿌릴 y위치,너비,높이
void Image::render(float x, float y, float sizeX, float sizeY,float Degree)
{
	::D2D1_RECT_F dxArea = ::D2D1::RectF(x - sizeX * 0.5f, y - sizeY * 0.5f, x + sizeX * 0.5f, y + sizeY * 0.5f);

	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x+sizeX*0.5f, y+sizeY*0.5f);
	Matrix3x2F rot = Matrix3x2F::Rotation(Degree);

	RENDER->getRenderTarget()->SetTransform(rot * trans);

	RENDER->getRenderTarget()->DrawBitmap(_image, dxArea, 1.0f);
}

void Image::frameRender(float x, float y, float sizeX, float sizeY,int frameX,int frameY)
{
	::D2D1_RECT_F dxArea = 
		::D2D1::RectF
	(
		x - (sizeX )* 0.5f,
		y - (sizeY) * 0.5f,
		x + (sizeX) * 0.5f,
		y + (sizeY) * 0.5f
	);

	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x + sizeX * 0.5f, y + sizeY * 0.5f);
	float width = _image->GetSize().width / _maxFrameX;
	float height = _image->GetSize().height / _maxFrameY;
	RENDER->getRenderTarget()->SetTransform(trans);
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*width,frameY*height,(frameX+1)*width, (frameY+1)*height);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f, 
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, 
		frameRect
	);
}

void Image::frameRender(float x, float y, float sizeX, float sizeY, float Degree, int frameX, int frameY)
{
	::D2D1_RECT_F dxArea =
		::D2D1::RectF
		(
			x - (sizeX)* 0.5f,
			y - (sizeY) * 0.5f,
			x + (sizeX) * 0.5f,
			y + (sizeY) * 0.5f
		);

	using namespace D2D1;
	Matrix3x2F trans = Matrix3x2F::Translation(x + sizeX * 0.5f, y + sizeY * 0.5f);
	Matrix3x2F rot = Matrix3x2F::Rotation(Degree, Point2F(x,y));
	float width = _image->GetSize().width / _maxFrameX;
	float height = _image->GetSize().height / _maxFrameY;
	RENDER->getRenderTarget()->SetTransform(rot*trans);
	::D2D1_RECT_F frameRect = ::D2D1::RectF(frameX*width, frameY*height, (frameX + 1)*width, (frameY + 1)*height);

	RENDER->getRenderTarget()->DrawBitmap(
		_image,
		dxArea,
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		frameRect
	);
}
