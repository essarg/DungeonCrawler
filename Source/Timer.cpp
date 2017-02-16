#include "Timer.h"
#include "DarkSDK.h"


Timer::Timer(void):
paused(true), prevTime(0), currentTime(0)
{

}

Timer::~Timer(void)
{
}

void Timer::Pause()
{
	paused = true;
}

void Timer::Start()
{
	paused = false;
	prevTime = dbTimer();
	currentTime = prevTime;
}

float Timer::UpdateTimer()
{
	
	if(!paused)
	{
		prevTime = currentTime;
		currentTime = dbTimer();

		return(currentTime - prevTime) / 1000.0;
	}else return 0;
}


