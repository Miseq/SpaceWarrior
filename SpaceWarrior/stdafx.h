// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "targetver.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <tchar.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <time.h>
#include <list>
#include <cmath>
#include "Animation.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Entity.h"
#include "Player.h"
#include "Singleton.h"
#include "Enemy.h"
#include "MaintenceClass.h"
#include "Score.h"
#include "Colision.h"

const int W = 600;
const int H = 800;



static Clock* timer = new Clock;
static Time* gameTime = new Time;
static Clock* Playertimer = new Clock;

