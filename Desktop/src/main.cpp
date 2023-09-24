#include "Engine.hpp"
#include "Game.hpp"

int main()
{
	InitWindow(1280, 720, "Spaceball");
	InitAudioDevice();

	Game game;

	while (!WindowShouldClose())
	{
		game.Update();

		BeginDrawing();

		game.Draw();

		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow();
	return 0;
}