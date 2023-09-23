#pragma once

#include <vector>

class Player
{
public:
	Player();
	~Player();
	void Draw();
private:
	Texture2D sprite;
};