#pragma once
#include <iostream>
using namespace std;

class SetofInt {
public:
	int SettoInt() const;
	void InttoSet(const int& i);

	SetofInt(int x = NULL);                      //constructor
	SetofInt(const SetofInt& s, const int& bord);//copy constructor
	~SetofInt();                                 //destructor

	unsigned Value() const;
	bool Find(const int& i) const;
	void Push(int i);
	void Delete (int i);
	void Union(const SetofInt& s);
	void Intersection(const SetofInt& s);
	void Difference(const SetofInt& s);

	SetofInt operator=(SetofInt s);
	SetofInt operator+(SetofInt s);
	SetofInt operator*(SetofInt s);
	SetofInt operator-(SetofInt s);
	SetofInt operator+=(const int& i);
	SetofInt operator-=(const int& i);
	bool operator==(SetofInt s);
	bool operator!=(SetofInt s);





private:
	unsigned set;
};
