/*
 * Timer.h
 *
 *  Created on: 10 thg 2, 2017
 *      Author: MyPC
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "Singleton.h"
class Timer : public Singleton<Timer>{
	public:
		Timer();
		virtual ~Timer();
		void update();
		unsigned long delta();
		void resetTick();
	private:
		unsigned long _lastTick;
		unsigned long _currentTick;
};

#endif /* TIMER_H_ */
