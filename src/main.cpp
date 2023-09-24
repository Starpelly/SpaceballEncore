#include "Engine/Engine.hpp"
#include "Spaceball/game.hpp"

int main(void)
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
}