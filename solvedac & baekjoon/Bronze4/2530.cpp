#include<iostream>
using namespace std;

int main()
{
	int h(0), m(0), s(0), is(0);
	int a(0), b(0);
	cin >> h >> m >> s;
	cin >> is;
	
	s = s + is;
	if (s > 59)
	{
		a = s / 60;
		b = s % 60;
		s = b;
		b = 0;
	}

	m = m + a;
	a = 0;
	if (m > 59)
	{
		a = m / 60;
		b = m % 60;
		m = b;
		b = 0;
	}

	h = h + a;
	a = 0;
	if (h > 23)
	{
		a = h % 24;
		h = a;
		b = 0;
	}
	
	cout << h << " " << m << " " << s;
	return 0;
}