#include <iostream>
#include "L8.h"

using namespace std;

int main()
{
	SetofInt a(5);
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	cout << a.SettoInt() << endl;


	SetofInt d(a, 3);
	cout << d.SettoInt() << endl;
	SetofInt c(a, 6);
	cout << c.SettoInt() << endl;

	SetofInt newset;
	newset.InttoSet(16);
	cout << "Find 5 - " << newset.Find(5) << " Find 6 - " << newset.Find(6) << endl;

	SetofInt f(6);
	a.Union(f);
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	a.Intersection(newset);
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	a.Difference(f);
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;

	return 0;
}