#pragma once
class TimeManager
{
public:
	int variable;
	static TimeManager& getInstance() {
		static TimeManager timeManager;
		return timeManager;
	
	};
};

