#include "stdafx.h"
#include "Animation.h"


void Animation::setSprite(Sprite s)
{
	this->sprite = s;
}

Sprite& Animation::getSprite()
{
	return this->sprite;
}

Animation::Animation()
{

}

Animation::Animation(Texture &t, FloatRect position, int count, float Speed, Vector2f scale)
{
	FloatRect in_position = position;
	frame = 0;
	speed = Speed;
	for (int i = 0; i<count; i++)
		frames.push_back(IntRect(in_position.left + i*in_position.width, in_position.top, in_position.width, in_position.height));
	//frames.push_back(IntRect(x + i*w, y, w, h));
	sprite.setTexture(t);
	sprite.setOrigin(in_position.width / 2, in_position.height / 2);
	sprite.setTextureRect(frames[0]);
	sprite.scale(scale);
}

bool Animation::isEnd()
{
	return frame + speed >= frames.size();
}

void Animation::update()
{
	frame += speed;
	int n = frames.size();
	if (frame >= n) frame -= n;
	if (n>0) sprite.setTextureRect(frames[int(frame)]);
}


Animation::~Animation()
{
}
