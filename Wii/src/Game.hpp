#pragma once

#include "Engine.hpp"

#include <vector>
#include <iostream>

struct Baseball
{
	float beat;
	float randomStartRot;
};

class Game
{
public:
	Game();
	~Game();
	void Update();
	void Draw();
private:
	int currentEntity = 0;
	float songPosition = 0.0f;
	float songPositionInBeats = 0.0f;
	float bpm = 104.275;
	float secPerBeat = 60.0f / bpm;

	// Music musicBackgroundSong;

	// Sound sfxFall;

	GRRLIB_texImg* texProps;
	GRRLIB_texImg* texRoom;
	GRRLIB_texImg* texRef;

	std::vector<float> ballEvents;
	std::vector<Baseball> ballEntities;

	Vector3 GetPointOnBezierCurve(Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3, float t)
	{
		float u = 1.0f - t;
		float t2 = t * t;
		float u2 = u * u;
		float u3 = u2 * u;
		float t3 = t2 * t;

		float a = (3.0f * u2 * t);
		float b = (3.0f * u * t2);

		Vector3 result = {
			u3 * p0.x + a * p1.x + b * p2.x + t3 * p3.x,
			u3 * p0.y + a * p1.y + b * p2.y + t3 * p3.y,
			u3 * p0.z + a * p1.z + b * p2.z + t3 * p3.z
		};

		return result;
	}

	/*
	void DrawTile(Texture2D texture, int tileX, int tileY, float xpos, float ypos, float rot)
	{
		DrawTexturePro(texture, Rectangle{ 32.0f * tileX, 32.0f * tileY, 32.0f, 32.0f }, Rectangle{ xpos, ypos, 32.0f, 32.0f }, Vector2{ 16.0f, 16.0f }, rot, WHITE);
	}


	*/
};