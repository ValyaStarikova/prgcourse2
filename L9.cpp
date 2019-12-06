#include "pch.h"
#include "L9.h"


using namespace std;

int SetofInt::SettoInt() const {
	int n = 0;
	for (int i = 31; i > -1; i--) {
		if ((set >> i) & 1) {
			n += pow(2, i);
		}
	}
	return n;
}

void SetofInt::InttoSet(const int& j) {
	for (int i = 31; i >= 0; i--) {
		if ((1 << i) & j) {
			set = set | (1 << i);
		}
		else {
			set = set & ~(1 << i);
		}
	}
	return;
}

SetofInt::SetofInt(int x) {
	if (x != NULL) {
		set = 1u;
		set = set << (x - 1);
	}
	else {
		set = 0u;
	}
}

SetofInt::SetofInt(const SetofInt& s, const int& bord) {
	set = (s.Value() & ~(0xFFFFFFFF << (bord - 1)));
}

SetofInt::~SetofInt() {}

unsigned SetofInt::Value() const {
	return set;
}

bool SetofInt::Find(const int& i) const {
	unsigned buf = 1u;
	buf = buf << (i - 1);
	return !((buf & set) == 0u);
}

void SetofInt::Union(const SetofInt& s) {
	for (int i = 0; i < 32; i++) {
		if ((s.Value() >> i) & 1) {
			set = set | (1 << i);
		}
	}
	return;
}

void SetofInt::Intersection(const SetofInt& s) {
	for (int i = 0; i < 32; i++) {
		if (((s.Value() >> i) & 1) && ((set >> i) & 1)) {
			set = set | (1 << i);
		}
		else {
			set = set & ~(1 << i);
		}
	}
	return;
}

void SetofInt::Difference(const SetofInt& s) {
	for (int i = 0; i < 32; i++) {
		if (((s.Value() >> i) & 1) != ((set >> i) & 1)) {
			set = set | (1 << i);
		}
		else {
			set = set & ~(1 << i);
		}
	}
	return;
}

SetofInt SetofInt:: operator = (SetofInt s){
	if (this == &s)
		return *this;
	set = s.Value();
	return *this;
}
void SetofInt::Push(int i) {
	set = set | (1 << i);
	return;
}
void SetofInt::Delete(int i) {
	set = set & ~(1 << i);

	return;
}

SetofInt SetofInt:: operator + (SetofInt s){
	SetofInt s3 (*this, 0);
	for (int i = 0; i < 32; i++) {
		if ((s.Value() >> i) & 1) {
			s3.Push(i);
		}
	}
	return s3;
}


SetofInt SetofInt:: operator * (SetofInt s){
	SetofInt s3(*this, 0);
    for (int i = 0; i < 32; i++) {
		if (!(((s.Value() >> i) & 1) && ((s3.Value() >> i) & 1))) {
           s3.Delete(i);
		}
	}
	return s3;
}
SetofInt SetofInt:: operator - (SetofInt s){
	SetofInt s3(*this, 0);
	for (int i = 0; i < 32; i++) {
		if (!(((s.Value() >> i) & 1) != ((s3.Value() >> i) & 1))) {
		    s3.Delete(i);
		}
	}
	return s3;
}
SetofInt SetofInt:: operator += (const int& i){
	set = set|(1<< (i - 1));
	return *this;
}
SetofInt SetofInt:: operator -= (const int& i){
	unsigned u = 1u;
	u = (u <<(i - 1));
	set = set & ~u;
	return *this;
}
bool SetofInt:: operator == (SetofInt s){
	bool fl = true;
	int i = 0;
	while (i < 31 && fl) {
		if (((s.Value() >> i) & 1) != ((set >> i) & 1)) {
			fl = false;
		}
	}
	return fl;
}
bool SetofInt:: operator != (SetofInt s){
	bool fl = false;
	int i = 0;
	while (i < 31 && !fl) {
		if (((s.Value() >> i) & 1) != ((set >> i) & 1)) {
			fl = true;
		}
	}
	return fl;
}

