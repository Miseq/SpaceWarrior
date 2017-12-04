#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Animation
{
private:
	Sprite sprite;
	float Frame, speed;
	std::vector<IntRect> frames;
public:
	Animation();
	~Animation();
	Animation() {}
	void update();
	bool isEnd();
};

