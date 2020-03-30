#pragma once
#include <iostream>

using namespace std;

struct Date
{
	int d;
	int m;
	int y;
	Date()
	{
		this->d = 0;
		this->m = 0;
		this->y = 0;
	}
	Date(int newD, int newM, int newY)
	{
		this->d = newD;
		this->m = newM;
		this->y = newY;
	}
	Date(Date& date)
	{
		*this = date;
	}
	~Date()
	{
		this->d = 0;
		this->m = 0;
		this->y = 0;
	}
	bool operator<(Date& date)
	{
		return (365 * this->y + 30 * this->m + this->d < 365 * date.y + 30 * date.m + date.d);
	}
	bool operator>=(Date& date)
	{
		return !this->operator<(date);
	}
	bool operator>(Date& date)
	{
		return (365 * this->y + 30 * this->m + this->d > 365 * date.y + 30 * date.m + date.d);
	}
	bool operator<=(Date& d)
	{
		return !this->operator>(d);
	}
	bool operator==(Date& date)
	{
		return (this->operator<=(date) && this->operator>=(date));
	}
	Date& operator=(Date& date)
	{
		this->d = date.d;
		this->m = date.m;
		this->y = date.y;
		return *this;
	}
	friend ostream& operator<<(ostream& os, Date& date)
	{
		os << date.d << '/' << date.m << '/' << date.y;
		return os;
	}
};