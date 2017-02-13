#pragma once

class Timer
{
public:
	Timer(void);
	~Timer(void);
	void Start();
	void Pause();
	
	float UpdateTimer();

private:
	int prevTime, currentTime;
	bool paused;
};
