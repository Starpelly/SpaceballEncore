#include "Engine.hpp"

void Engine_Init(const char* title)
{
#ifdef ENGINE_RAYLIB
	InitWindow(1280, 720, title);
	InitAudioDevice();
#endif
}

void Engine_Release()
{
#ifdef ENGINE_RAYLIB
	CloseAudioDevice();
	CloseWindow();
#endif
}

bool Engine_IsRunning()
{
#if ENGINE_RAYLIB
	return !WindowShouldClose();
#endif
}

void Engine_BeginDrawing()
{
#if ENGINE_RAYLIB
	BeginDrawing();
#endif
}

void Engine_EndDrawing()
{
#if ENGINE_RAYLIB
	EndDrawing();
#endif
}

EngineTexture2D Engine_LoadTexture(const char* fileName)
{
#ifdef ENGINE_RAYLIB
	return LoadTexture(fileName);
#endif
}

void Engine_UnloadTexture(EngineTexture2D texture)
{
#ifdef ENGINE_RAYLIB
	UnloadTexture(texture);
#endif
}
