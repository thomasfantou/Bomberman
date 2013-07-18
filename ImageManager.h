#ifndef IMAGEMANAGER_HPP_INCLUDED
#define IMAGEMANAGER_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class ImageManager
{
private:
	// Attributes
	static ImageManager* _singleton;
	std::map<std::string, sf::Image*> Images;

	// Methods
	ImageManager();
	~ImageManager();

	sf::Image *CreateImage(const std::string &ImageLink);
	bool SearchImage(const std::string &ImageLink, sf::Image* &ImgTemp);

public:
	// Methods
	static ImageManager* getInstance();
	static void kill();

	sf::Image* GetImage(const std::string &ImageLink);

	void DeleteImage(sf::Image &Img);
	void DeleteImage(const std::string& ImageLink);
};

#endif // IMAGEMANAGER_HPP_INCLUDED
