#include "stdafx.h"
#include "Score.h"



void Score::setPlayerScore(int score)
{
	playerScore = score;
}

Text Score::getPlayerScoreAsText()
{
	oss.str(std::string());
	oss << "score: " << playerScore;
	score.setString(oss.str());
	return score;
}

int Score::getPlayerScoreAsInt()
{
	return playerScore;
}

Text Score::getImmortalityText()
{
	return Immortality;
}

void Score::AddValueToPlayerScore(Entity& e)
{
	if (e.getName() == "asteroid") playerScore += valueOfAsteriod;
	else if (e.getName() == "enemy") playerScore += valueOfEnemy;
}


Score::Score()
{
	font->loadFromFile("assets/waltographUI.ttf");
	score.setFont(*font);
	score.setCharacterSize(24);
	score.setFillColor(textColor->Yellow);
	score.setPosition({ 0,0 });
	Immortality.setFont(*font);
	Immortality.setCharacterSize(24);
	Immortality.setFillColor(textColor->Green);
	Immortality.setPosition({ 200,0 });
	Immortality.setString("IMMORTALITY!");

}


Score::~Score()
{
}
