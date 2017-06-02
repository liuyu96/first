#ifndef _MYTIME_H_
#define _MYTIME_H_

class Time
{
private:
	int m_hours;
	int m_minutes;
public:
	Time();
	Time(int h, int m = 0);
	Time operator+ (const Time &t) const;
	void show(void) const;
};



#endif
