#pragma once
#include"Image.h"
#include"SingleTone.h"
class ImageManager:public singletonBase<ImageManager>
{
private:
	std::unordered_map<std::string, Image*> _imageMap;
	std::unordered_map<std::string, Image*>::iterator _iTImageMap;
public:
	ImageManager();
	~ImageManager();

	Image* addImage(std::string key,std::string path);
	Image* addFrameImage(std::string key, std::string path,int maxFrameX,int maxFrameY);
	Image* findImage(std::string key);
};

