#pragma once

#include <raylib.h>

typedef Texture2D EngineTexture2D;

void Engine_Init(const char* title);
void Engine_Release();
bool Engine_IsRunning();

void Engine_BeginDrawing();
void Engine_EndDrawing();

EngineTexture2D Engine_LoadTexture(const char* fileName);
void Engine_UnloadTexture(EngineTexture2D texture);
