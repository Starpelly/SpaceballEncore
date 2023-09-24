#include "Engine.hpp"

void Engine_Init(const char* title)
{
	InitWindow(1280, 720, title);
	InitAudioDevice();
}

void Engine_Release()
{
	CloseAudioDevice();
	CloseWindow();
}

bool Engine_IsRunning()
{
	return !WindowShouldClose();
}

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
