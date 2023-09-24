#include "Engine.hpp"
#include "Game.hpp"

int main()
{
	Engine_Init("Spaceball");

	Game game;

	while (Engine_IsRunning())
	{
		game.Update();

		Engine_BeginDrawing();

		game.Draw();

		Engine_EndDrawing();
	}
	Engine_Release();
	return 0;
}