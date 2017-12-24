#pragma once
#include <SFML\Graphics.hpp>
#include "stdafx.h"
using namespace sf;

class Animation : public Transformable
{

public:
	Sprite sprite;
	float Frame, speed;
	std::vector<IntRect> frames;
	FloatRect position;
public:
	Animation();
	~Animation();
	Animation(Texture &t, int x, int y, int w, int h, int count, float Speed, Vector2f scale = { 1,1 });
	void update();
	bool isEnd();
};

