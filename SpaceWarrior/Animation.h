#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Animation
{
public:
	Sprite sprite;
	float Frame, speed;
	std::vector<IntRect> frames;
public:
	Animation();
	~Animation();
	Animation(Texture &t, int x, int y, int w, int h, int count, float Speed);
	void update();
	bool isEnd();
};

