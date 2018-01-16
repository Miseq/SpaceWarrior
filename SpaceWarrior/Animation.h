#pragma once
#include <SFML\Graphics.hpp>
#include "stdafx.h"
using namespace sf;

class Animation : public Transformable
{

protected:
	Sprite sprite;
	float frame, speed;
	std::vector<IntRect> frames;
	FloatRect in_position;
public:
	void setSprite(Sprite s);
	Sprite& getSprite();
	Animation();
	~Animation();
	Animation(Texture &t, FloatRect in_position, int count, float Speed, Vector2f scale = { 1,1 });
	virtual void update();
	bool isEnd();
};

