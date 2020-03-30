#include "tests.h"


void MovieTest()
{
	Movie m;
	char title1[10] = "aaa";
	Date date1(1, 1, 2000);
	char genre1[10] = "aa";
	Movie m1(title1, date1, genre1);
	Movie m2(m1);
	m.setTitle(title1);
	m.setDate(date1);
	m.setGenre(genre1);
	assert(strcmp(m1.getTitle(), m.getTitle()) == 0);
	assert(m1.getDate() == m.getDate());
	assert(strcmp(m1.getGenre(), m.getGenre()) == 0);
	assert(m1 == m);
	Date date2(2, 2, 2000);
	m2.setDate(date2);
	assert(m2 != m1);
}

void RepoTest()
{
	char title[10] = "aaa";
	Date date(1, 1, 1);
	char genre[10] = "aa";
	Movie m(title, date, genre);
	Movie m1(m);
	Date date2(2, 2, 2);
	Movie m2(m);
	m2.setDate(date2);
	Repo repo1;
	repo1.add(m1);
	repo1.add(m1);
	Repo repo2 = repo1;
	assert(repo1 == repo2);
	repo2.mod(m1, m2);
	assert(repo2.find_by_title(title) == 0);
	repo2.del(m1);
	assert(repo2.find(m2) == 0);
	assert(repo1.getAll()[0] == m1);
	assert(repo2.getNo() == 1);
	assert(repo2.getAll()[0] == m2);
	assert(repo1 != repo2);
}

void ServiceTest()
{
	Service s;
	char title[10] = "aaa";
	Date date(1, 1, 1);
	char genre[10] = "aa";
	char titleMod[10] = "bbb";
	s.addMovie(title, date, genre);
	s.addMovie(title, date, genre);
	s.modMovie(title, titleMod, date, genre);
	assert(s.getNo() == 2);
	s.delMovie(titleMod);
	assert(s.getNo() == 1);
	Movie m(title, date, genre);
	assert(s.getAll()[0] == m);
	char genre1[10] = "av";
	Date date1(1, 2, 3);
	Movie m1(title, date1, genre1);
	Movie m2(title, date1, genre);
	s.addMovie(title, date1, genre1);
	s.addMovie(title, date1, genre);
	Repo r;
	r.add(m);
	r.add(m2);
	assert(s.oneGenre(genre) == r);
	Date del(1, 2, 1);
	s.delBeforeDate(del);
	assert(s.getNo() == 2);
	s.undo();
	assert(s.getNo() == 3);
}

void tests()
{
	MovieTest();
	RepoTest();
	ServiceTest();
}