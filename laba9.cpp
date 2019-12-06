#include <iostream>
#include "L9.h"

using namespace std;

int main()
{
	SetofInt a(5);
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	cout << a.SettoInt() << endl;

	SetofInt b;
	cout << b.SettoInt() << endl;

	SetofInt d(a, 3);
	cout << d.SettoInt() << endl;
	SetofInt c(a, 6);
	cout << c.SettoInt() << endl;

	

	SetofInt f(6);
	a.Union(f); cout << "a+f;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	a.Intersection(b); cout << "a*b;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	a.Difference(f); cout << "a-f;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;
	a -= 6; cout << "a -= 6;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl; //a 5
    a += 5; cout << "a += 5;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl; //a 5 6
	a = a + f; cout << "a = a + f" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl;//a 5 6 
	d = d * b; cout << "d = d * b;" << endl;
	cout << "Find 5 - " << d.Find(5) << " Find 6 - " << d.Find(6) << endl;// d
	a = a - f; cout << "a = a - f;" << endl;
	cout << "Find 5 - " << a.Find(5) << " Find 6 - " << a.Find(6) << endl; //a 5
	

	SetofInt p(5);
    if (a == p) cout << "true"<<endl; else cout << "false"<<endl; //true
	if (a != f) cout << "true"<<endl; else cout << "false"<<endl; //true

	return 0;
}