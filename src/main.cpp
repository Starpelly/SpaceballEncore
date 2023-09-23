#include "Spaceball/game.hpp"
#include <raylib.h>

int main(void)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1280, 720, "Spaceball");
	InitAudioDevice();

	Game game;

	while (!WindowShouldClose())
	{
		game.Update();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		game.Draw();

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}