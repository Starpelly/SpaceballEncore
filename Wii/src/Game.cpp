#include "Game.hpp"
#include "PellyMath.hpp"

#include "props_png.h"
#include "ref_png.h"
#include "room_png.h"

#include "shoot_ogg.h"

Game::Game()
{
	/*musicBackgroundSong = LoadMusicStream("resources/spaceball.wav");
	PlayMusicStream(musicBackgroundSong);

	sfxFall = LoadSound("resources/fall.wav");
	sfxShoot = LoadSound("resources/shoot.wav");*/

	texProps = GRRLIB_LoadTexture(props_png);
	texRoom = GRRLIB_LoadTexture(room_png);
	texRef = GRRLIB_LoadTexture(ref_png);

	GRRLIB_InitTileSet(texProps, 32, 32, 0);
	GRRLIB_SetHandle(texProps, 16, 17);

	ballEvents.push_back(4.0f);
	ballEvents.push_back(6.0f);
	ballEvents.push_back(8.0f);
	ballEvents.push_back(10.0f);
	ballEvents.push_back(12.0f);
	ballEvents.push_back(14.0f);
	ballEvents.push_back(16.0f);
	ballEvents.push_back(18.0f);
}

Game::~Game()
{
	/*UnloadMusicStream(musicBackgroundSong);

	UnloadSound(sfxFall);
	UnloadSound(sfxShoot);*/

	GRRLIB_FreeTexture(texProps);
	GRRLIB_FreeTexture(texRoom);
	GRRLIB_FreeTexture(texRef);
}

void Game::Update()
{
	songPosition += 1.0f / 60.0f;
	songPositionInBeats = songPosition / secPerBeat;

	if (currentEntity < (int)ballEvents.size())
	{
		if (songPositionInBeats >= ballEvents[currentEntity])
		{
			Baseball ball;
			ball.beat = ballEvents[currentEntity];

			ballEntities.push_back(ball);

			// PlaySound(sfxShoot);
			PlayOgg(shoot_ogg, shoot_ogg_size, 0, OGG_ONE_TIME);

			currentEntity++;
		}
	}

	/*
	UpdateMusicStream(musicBackgroundSong);

	// songPosition += GetFrameTime();
	songPosition = GetMusicTimePlayed(musicBackgroundSong);


	*/
}

void Game::Draw()
{
	GRRLIB_DrawImg(0, 0, texRoom, 0, 1, 1, WHITE);

	for (int i = 0; i < ballEntities.size(); i++)
	{
		Baseball ball = ballEntities[i];

		float normalizedPitchAnim = Pelly_Normalize(songPositionInBeats, ball.beat, ball.beat + 1.175f);

		if (normalizedPitchAnim < 1.0f)
		{
			float addPos = 0.77f;
			float addPosY = 1.35f;

			float ballRot = normalizedPitchAnim * 240.0f * addPosY;

			Vector3 pos = GetPointOnBezierCurve(
				Vector3{ -0.55f, -0.4f, 0 },
				Vector3{ -0.55f + (addPos * 0.5f) - 0.2f, -0.53f + addPosY },
				Vector3{ -0.55f + (addPos * 0.5f) + 0.1f, -0.53f + addPosY },
				Vector3{ -0.55f + addPos, -0.62f },
				normalizedPitchAnim);

			float multiply = 90;

			float x = (pos.x * multiply) + 127;
			float y = (-pos.y * multiply) + 163;

			GRRLIB_DrawTile(x, y, texProps, ballRot + ball.randomStartRot, 1, 1, WHITE, 24);
			// GRRLIB_DrawPart(x, y, 32 * 0, 32 * 3, 32, 32, texProps, ballRot + ball.randomStartRot, 1, 1, WHITE);

			// DrawTile(texProps, 0, 3, (pos.x * multiply) + 140, (-pos.y * multiply) + 173, ballRot + ball.randomStartRot);
		}
		else
		{
			// PlaySound(sfxFall);

			ballEntities.erase(ballEntities.begin() + i);
		}
	}
	
	GRRLIB_DrawImg(0, 95, texRef, 0, 1, 1, 0xFFFFFFAA);

	/*
	DrawTexture(texRoom, 0, 0, WHITE);

	

	*/
}