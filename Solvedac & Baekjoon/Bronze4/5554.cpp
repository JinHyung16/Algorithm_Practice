#include<iostream>

using namespace std;


int main(void)
{
	int move_count = 4; //움직이는 횟수
	int move_time = 0;

	int min = 0, sec = 0;

	for (int i = 0; i < move_count; i++)
	{
		cin >> move_time;
		sec += move_time;
	}

	min = sec / 60;
	sec = sec % 60;

	cout << min << "\n" << sec;

	return 0;
}