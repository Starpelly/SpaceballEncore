#include <raylib.h>
#include "player.h"

Player::Player()
{
	sprite = LoadTexture("resources/player_1.png");
}

Player::~Player()
{
	UnloadTexture(sprite);
}

void Player::Draw()
{
	DrawTexturePro(sprite, Rectangle{ 0, 0, 100, 54 }, Rectangle{0, 0, 20, 20}, Vector2{0, 0}, 0, WHITE);
}