#include "stdafx.h"
#include "ImageManager.h"
#include"Render.h"

ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}

Image* ImageManager::addImage(std::string key, std::string path)
{
	//--------------------------------------
	//디코더를 생성한다.
	//--------------------------------------
	IWICBitmapDecoder*	decoderPtr = nullptr;
	HRESULT hr = E_FAIL;

	std::wstring _wString = std::wstring(path.begin(), path.end());
	LPCWSTR FilePath = _wString.c_str();


	hr = RENDER->getImageFactory()->CreateDecoderFromFilename(FilePath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoderPtr);
	assert(hr == S_OK);

	
	//디코더에서 프레임을 얻는다
	IWICBitmapFrameDecode* framePtr = nullptr;
	hr = decoderPtr->GetFrame(0, &framePtr);
	assert(hr == S_OK);
	//프레임을 기반으로 해서 포맷 컨버터를 만든다.
	IWICFormatConverter* converter = RENDER->getSrcBmp();
	//SafeRelease(converter);
	hr = RENDER->getImageFactory()->CreateFormatConverter(&converter);
	assert(hr == S_OK);

	hr = converter->Initialize(
		framePtr,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);
	//컨버트된 데이터를 기반으로 해서 실제 비트맵을 만든다.
	ID2D1Bitmap* bitmap = RENDER->getBitmap();
	SafeRelease(bitmap);
	hr = RENDER->getRenderTarget()->CreateBitmapFromWicBitmap
	(
		converter,
		nullptr,
		&bitmap
	);
	assert(hr == S_OK);
	SafeRelease(decoderPtr);
	SafeRelease(framePtr);
	Image* image = new Image;
	image->setImage(bitmap);
	_imageMap.insert(std::make_pair(key, image));
	return image;

}

Image * ImageManager::addFrameImage(std::string key, std::string path, int maxFrameX, int maxFrameY)
{

	//--------------------------------------
	//디코더를 생성한다.
	//--------------------------------------
	IWICBitmapDecoder*	decoderPtr = nullptr;
	HRESULT hr = E_FAIL;

	std::wstring _wString = std::wstring(path.begin(), path.end());
	LPCWSTR FilePath = _wString.c_str();


	hr = RENDER->getImageFactory()->CreateDecoderFromFilename(FilePath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoderPtr);
	assert(hr == S_OK);


	//디코더에서 프레임을 얻는다
	IWICBitmapFrameDecode* framePtr = nullptr;
	hr = decoderPtr->GetFrame(0, &framePtr);
	assert(hr == S_OK);
	//프레임을 기반으로 해서 포맷 컨버터를 만든다.
	IWICFormatConverter* converter = RENDER->getSrcBmp();
	//SafeRelease(converter);
	hr = RENDER->getImageFactory()->CreateFormatConverter(&converter);
	assert(hr == S_OK);

	hr = converter->Initialize(
		framePtr,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0.0f,
		WICBitmapPaletteTypeCustom
	);
	assert(hr == S_OK);
	//컨버트된 데이터를 기반으로 해서 실제 비트맵을 만든다.
	ID2D1Bitmap* bitmap = RENDER->getBitmap();
	SafeRelease(bitmap);
	hr = RENDER->getRenderTarget()->CreateBitmapFromWicBitmap
	(
		converter,
		nullptr,
		&bitmap
	);
	assert(hr == S_OK);
	SafeRelease(decoderPtr);
	SafeRelease(framePtr);
	Image* image = new Image;
	image->setImage(bitmap);
	image->setMaxFrameX(maxFrameX);
	image->setMaxFrameY(maxFrameY);
	_imageMap.insert(std::make_pair(key, image));
	return image;
}

Image * ImageManager::findImage(std::string key)
{
	for (_iTImageMap = _imageMap.begin(); _iTImageMap != _imageMap.end(); _iTImageMap++)
	{
		if (_iTImageMap->first == key)
		{
			return _iTImageMap->second;
		}
	}
	return nullptr;
}
