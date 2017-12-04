#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
{
}

Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
	Frame = 0;
	speed = Speed;

	for (int i = 0; i<count; i++)
		frames.push_back(IntRect(x + i*w, y, w, h));

	sprite.setTexture(t);
	sprite.setOrigin(w / 2, h / 2);
	sprite.setTextureRect(frames[0]);
}

bool Animation::isEnd()
{
	return Frame + speed >= frames.size();
}

void Animation::update()
{
	Frame += speed;
	int n = frames.size();
	if (Frame >= n) Frame -= n;
	if (n>0) sprite.setTextureRect(frames[int(Frame)]);
}


Animation::~Animation()
{
}
