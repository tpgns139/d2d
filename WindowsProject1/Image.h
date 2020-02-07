#pragma once
class Image
{
private:
	ID2D1Bitmap* _image;
	int _frameX,_frameY,_maxFrameX,_maxFrameY;
	float _width, _height;
	float _frameWidth, _frameHegith;

public:
	Image();
	~Image();

	void setMaxFrameX(int maxX) { _maxFrameX = maxX; }
	int getMaxFrameX() { return _maxFrameX; }

	void setMaxFrameY(int maxY) { _maxFrameY = maxY; }
	int getMaxFrameY() { return _maxFrameY; }

	void setImage(ID2D1Bitmap* image) { _image = image; }
	void render(float x,float y,float sizeX,float sizeY);
	void render(float x, float y, float sizeX, float sizeY, float Degree);


	void frameRender(float x, float y, float sizeX, float sizeY, int frameX, int frameY);
	void frameRender(float x, float y, float sizeX, float sizeY,float Degree,int frameX, int frameY);
};

