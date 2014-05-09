#ifndef CPU_TIMER_H
#define CPU_TIMER_H

/* Copyright (c) Glyn Adgie 2012
 *
 *
 */

#include <sys/time.h>


class CPUTimer {
public:
	CPUTimer()
	{
		start();
	}

	void start()
	{
		gettimeofday(&start_time, NULL);
	}

	double usecs()
	{
		struct timeval end_time;
		gettimeofday(&end_time, NULL);
		return 1e6 * static_cast<double>(end_time.tv_sec
				- start_time.tv_sec)
			+ end_time.tv_usec - start_time.tv_usec;
	}

	double msecs()
	{
		return usecs() * 1e-3;
	}

	double secs()
	{
		return usecs() * 1e-6;
	}

private:
	struct timeval start_time;
};

#endif // CPU_TIMER_H
