#pragma once

const double math_pi = 3.1415926535897;

float Pelly_Clamp(float value, float min, float max)
{
	float result = (value < min) ? min : value;

	if (result > max) result = max;

	return result;
}

float Pelly_Clamp01(float value)
{
	return Pelly_Clamp(value, 0, 1);
}

float Pelly_Normalize(float val, float min, float max)
{
	return Pelly_Clamp01((val - min) / (max - min));
}

float Pelly_NormalizeUnclamped(float val, float min, float max)
{
	return (val - min) / (max - min);
}

float Pelly_Lerp(float a, float b, float t)
{
	return a + (b - a) * Pelly_Clamp01(t);
}

float Pelly_LerpUnclamped(float a, float b, float t)
{
	return a + (b - a) * t;
}

