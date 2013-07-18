#include "ImageManager.h"

ImageManager* ImageManager::_singleton = NULL;

ImageManager* ImageManager::getInstance()
{
	if(NULL == _singleton)
	{
		std::cout << "creating singleton." << std::endl;
		_singleton =  new ImageManager;
	}
	else
	{
		std::cout << "singleton already created!" << std::endl;
	}

	return _singleton;
}

void ImageManager::kill()
{
	if (NULL != _singleton)
	{
		delete _singleton;
		_singleton = NULL;
	}
}

ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{
	//On détruit toutes les images restantes
	std::map<std::string, sf::Image*>::iterator it;
	for(it = Images.begin(); it != Images.end(); it++)
	{
		delete it->second;
	}
}

bool ImageManager::SearchImage(const std::string &ImageLink, sf::Image* &ImgTemp)
{
	std::map<std::string, sf::Image*>::iterator it;

	it = Images.find(ImageLink);

	if(it == Images.end())
	{
		return false;
	}
	else
	{
		ImgTemp = it->second;
	}

	return true;
}

sf::Image* ImageManager::CreateImage(const std::string &ImageLink)
{
	sf::Image *ImgTemp = new sf::Image();
	if(ImgTemp->LoadFromFile(ImageLink))
	{
		Images.insert(std::pair<std::string, sf::Image*>(ImageLink, ImgTemp));
		return ImgTemp;
	}
	else
	{
		delete ImgTemp;
	}

	return NULL;
}

sf::Image *ImageManager::GetImage(const std::string &ImageLink)
{
	sf::Image *ImgTemp;

	//Si l'image demandée n'existe pas déjà, on la créée
	if(!SearchImage(ImageLink, ImgTemp))
	{
		ImgTemp = CreateImage(ImageLink);
	}

	return ImgTemp;
}

void ImageManager::DeleteImage(sf::Image &Img)
{
	std::map<std::string, sf::Image*>::iterator it;

	//On cherche l'image demandée
	for(it = Images.begin(); it != Images.end(); it++)
	{
		//Si on la trouve, on la détruit et on la retire
		if(it->second == &Img)
		{
			delete &Img;
			Images.erase(it);
			break;
		}
	}
}


void ImageManager::DeleteImage(const std::string& ImageLink)
{
	std::map<std::string, sf::Image*>::iterator it;

	it = Images.find(ImageLink);

	if(it != Images.end())
	{
		if(it->second != NULL)
		{
			delete (it->second);
			Images.erase(it);
		}
	}
}
