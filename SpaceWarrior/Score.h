#pragma once
#include <sstream>>
class Score 
{
	std::ostringstream oss;
	int valueOfAsteriod = 50;
	int valueOfEnemy = 100;
	int playerScore = 0;
	Font* font = new Font;
	Text score;
	Color* textColor = new Color;
	Text Immortality;
public:

	void setPlayerScore(int score);
	Text getPlayerScoreAsText();
	int getPlayerScoreAsInt();
	Text getImmortalityText();
	void AddValueToPlayerScore(Entity& e);
	Score();
	~Score();
};




