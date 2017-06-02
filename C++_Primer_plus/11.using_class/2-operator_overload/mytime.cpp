#include <iostream>
#include "mytime.h"

Time::Time()
{
	std::cout << "this is default construct\n";
	m_hours = 0;
	m_minutes = 0;
}

Time::Time(int h, int m)
{
	std::cout << "this is construct with two parameters, " << h << " " << m << "\n";
	m_hours = h;
	m_minutes = m;
}

Time Time::operator+ (const Time &t) const
{
	Time sum;

	sum.m_minutes = m_minutes + t.m_minutes;
	sum.m_hours = m_hours + t.m_hours + sum.m_minutes / 60;
	sum.m_minutes %= 60;

	std::cout << "operator +\n";

	return sum;
}

void Time::show() const
{
	std::cout << "hours " << m_hours << ", minutes " << m_minutes << "\n";
}
