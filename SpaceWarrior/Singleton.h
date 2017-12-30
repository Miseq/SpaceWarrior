#pragma once
#include "Animation.h"


class Singleton :public Animation
{
private:
	Singleton();
	~Singleton();
	static Singleton* instance;
	
public:
	std::map<std::string, Animation*> Animacje;
	static Singleton* getInstance();
};

