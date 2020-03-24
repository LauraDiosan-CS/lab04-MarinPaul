#pragma once

struct Date
{
	int day;
	int month;
	int year;
	Date()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	Date(int newDay, int newMonth, int newYear)
	{
		this->day = newDay;
		this->month = newMonth;
		this->year = newYear;
	}
	Date(const Date& d)
	{
		*this = d;
	}
	~Date()
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	bool operator<(const Date& d)
	{
		return (365 * this->year + 30 * this->month + this->day < 365 * d.year + 30 * d.month + d.day);
	}
	bool operator>=(const Date& d)
	{
		return !this->operator<(d);
	}
	bool operator>(const Date& d)
	{
		return (365 * this->year + 30 * this->month + this->day > 365 * d.year + 30 * d.month + d.day);
	}
	bool operator<=(const Date& d)
	{
		return !this->operator>(d);
	}
	bool operator==(const Date& d)
	{
		return (this->operator<=(d) && this->operator>=(d));
	}
	Date& operator=(const Date& d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
		return *this;
	}
};