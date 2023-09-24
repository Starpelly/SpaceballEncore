#pragma once

#include <raylib.h>

typedef Texture2D EngineTexture2D;

EngineTexture2D Engine_LoadTexture(const char* fileName);
void Engine_UnloadTexture(EngineTexture2D texture);
