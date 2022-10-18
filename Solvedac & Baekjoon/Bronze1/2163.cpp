#include<iostream>

using namespace std;

int main(void)
{
	int size_N = 0, size_M = 0;

	int divide_size = 1 * 1; //나눠주려는 크기 1*1
	int divide_count = 0; //나눠주는 횟수
	
	cin >> size_N >> size_M;

	//N을 가로, M을 세로라 생각
	//ex)2*2(=N*M)의 경우 가로 1번 자르면 1*2사이즈 초콜릿 2개 생김, 1*2사이즈 2번 잘라야 함
	//최소 횟수 = N-1 + N*(M-1) 이 됨
	
	divide_count = (size_N)-1 + size_N * (size_M - 1);

	cout << divide_count;

	return 0;
}