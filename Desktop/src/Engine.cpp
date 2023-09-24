#include "Engine.hpp"


void Engine_BeginDrawing()
{
	BeginDrawing();
}

void Engine_EndDrawing()
{
	EndDrawing();
}

EngineTexture2D Engine_LoadTexture(const char* fileName)
{
	return LoadTexture(fileName);
}

void Engine_UnloadTexture(EngineTexture2D texture)
{
	UnloadTexture(texture);
}
