#include "tests.h"


void MovieTest()
{
	Movie m1;
	char* title2 = new char[10];
	strcpy_s(title2, sizeof "aaa", "aaa");
	char* genre2 = new char[10];
	strcpy_s(genre2, sizeof "aa", "aa");
	Date date2(1, 1, 2000);
	Movie m2(title2, date2, genre2);
	Movie m3 = m2;
	assert(strcmp(m2.getTitle(), m3.getTitle()) == 0);
	assert(strcmp(m2.getGenre(), m3.getGenre()) == 0);
	char* title3 = new char[10];
	strcpy_s(title3, sizeof "bbb", "bbb");
	char* genre3 = new char[10];
	strcpy_s(genre3, sizeof "bb", "bb");
	m3.setTitle(title3);
	m3.setGenre(genre3);
	Date date3(2, 3, 2001);
	m3.setDate(date3);
	assert(strcmp(m3.getTitle(), "bbb") == 0);
	assert(strcmp(m3.getGenre(), "bb") == 0);
	assert(m3.getDate() == date3);
	m1 = m2;
	assert(m1 == m2);
}

void RepoTest()
{
	char* title1 = new char[10];
	strcpy_s(title1, sizeof "aaa", "aaa");
	char* genre1 = new char[10];
	strcpy_s(genre1, sizeof "aa", "aa");
	Date date1(1, 1, 1);
	Movie m1(title1, date1, genre1);
	char* title2 = new char[10];
	strcpy_s(title2, sizeof "bbb", "bbb");
	char* genre2 = new char[10];
	strcpy_s(genre2, sizeof "bb", "bb");
	Date date2(2, 2, 2);
	Movie m2(title2, date2, genre2);
	Repo movies;
	movies.add(m1);
	movies.add(m2);
	assert(movies.getAll()[0] == m1);
	assert(movies.getAll()[1] == m2);
	assert(movies.getNo() == 2);
	assert(movies.find(m1) == 0);
	assert(movies.find_by_title(title2) == 1);
	Date date3(3, 3, 3);
	Movie m3(title2, date3, genre2);
	movies.mod(movies.getAll()[movies.find_by_title(title2)], m3);
	assert(movies.getAll()[1] == m3);
	movies.del(movies.getAll()[movies.find_by_title(title2)]);
	assert(movies.getNo() == 1);
}

void ServiceTest()
{
	Service service;
	char* title1 = new char[10];
	strcpy_s(title1, sizeof "aaa", "aaa");
	char* genre1 = new char[10];
	strcpy_s(genre1, sizeof "aa", "aa");
	Date date1(1, 1, 1);
	Movie m1(title1, date1, genre1);
	service.addMovie(title1, date1, genre1);
	assert(service.getAll()[0] == m1);
	char* title2 = new char[10];
	strcpy_s(title2, sizeof "bbb", "bbb");
	char* genre2 = new char[10];
	strcpy_s(genre2, sizeof "0", "0");
	Date date2(2, 2, 2);
	service.modMovie(title1, title2, date2, genre2);
	Movie m3(title2, date2, genre1);
	assert(service.getAll()[0] == m3);
	service.delMovie(title2);
	
}

void tests()
{
	MovieTest();
	RepoTest();
	ServiceTest();
}