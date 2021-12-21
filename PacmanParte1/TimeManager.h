#pragma once
#include <chrono>
class TimeManager
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
public:
	unsigned int frameCount; //unsigned no puede guardar numeros negativos
	float time;
	float deltaTime;

	static TimeManager& getInstance();
	void nexframe();
};

