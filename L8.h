#pragma once
#include <iostream>
using namespace std;

class SetofInt {
public:
	int SettoInt() const;
	void InttoSet( int i);

	SetofInt(int x = NULL);                      //constructor
	SetofInt(const SetofInt& s, const int& bord);//copy constructor
	~SetofInt();                                 //destructor

	unsigned Value() const;
	bool Find(const int& i) const;

	void Union(const SetofInt& s);
	void Intersection(const SetofInt& s);
	void Difference(const SetofInt& s);

private:
	unsigned set;
};