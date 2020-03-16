#include "tests.h"


void MovieTest()
{
	Movie m1;
	char* title2 = new char[10];
	strcpy_s(title2, sizeof "aaa", "aaa");
	Movie m2(title2);
	Movie m3 = m2;
	assert(strcmp(m2.getTitle(),m3.getTitle())==0);
	char* title3 = new char[10];
	strcpy_s(title3, sizeof "bbb", "bbb");
	m3.setTitle(title3);
	assert(strcmp(m3.getTitle(),"bbb")==0);
	m1 = m2;
	assert(strcmp(m1.getTitle(), m2.getTitle()) == 0);
}

void RepoTest()
{
	char* title1 = new char[10];
	strcpy_s(title1, sizeof "aaa", "aaa");
	Movie m1(title1);
	char* title2 = new char[10];
	strcpy_s(title2, sizeof "bbb", "bbb");
	Movie m2(title2);
	Repo movies;
	movies.add(m1);
	movies.add(m2);
	assert(movies.getAll()[0] == m1);
	assert(movies.getAll()[1] == m2);
}

void tests()
{
	MovieTest();
	RepoTest();
}