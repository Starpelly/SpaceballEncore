#include "game.hpp"
#include "pellymath.hpp"

Game::Game()
{
	musicBackgroundSong = LoadMusicStream("resources/spaceball.wav");
	PlayMusicStream(musicBackgroundSong);

	sfxFall = LoadSound("resources/fall.wav");
	sfxShoot = LoadSound("resources/shoot.wav");

	texProps = LoadTexture("resources/props.png");
	texRoom = LoadTexture("resources/room.png");
	texRef = LoadTexture("resources/ref.png");

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
	UnloadMusicStream(musicBackgroundSong);

	UnloadSound(sfxFall);
	UnloadSound(sfxShoot);

	UnloadTexture(texProps);
	UnloadTexture(texRoom);
	UnloadTexture(texRef);
}

void Game::Update()
{
	UpdateMusicStream(musicBackgroundSong);

	// songPosition += GetFrameTime();
	songPosition = GetMusicTimePlayed(musicBackgroundSong);
	songPositionInBeats = songPosition / secPerBeat;

	if (currentEntity < ballEvents.size())
	{
		if (songPositionInBeats >= ballEvents[currentEntity])
		{
			Baseball ball;
			ball.beat = ballEvents[currentEntity];
			ball.randomStartRot = GetRandomValue(0, 360);

			ballEntities.push_back(ball);

			PlaySound(sfxShoot);

			currentEntity++;
		}
	}
}

void Game::Draw()
{
	DrawTexture(texRoom, 0, 0, WHITE);

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
			DrawTile(texProps, 0, 3, (pos.x * multiply) + 140, (-pos.y * multiply) + 173, ballRot + ball.randomStartRot);
		}
		else
		{
			PlaySound(sfxFall);

			ballEntities.erase(ballEntities.begin() + i);
		}
	}

	DrawTexture(texRef, 0, 95, Color { 255, 255, 255, 150 });
}