#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 Hashing - 문자열,해싱 알고리즘
/// 소문자 알파벳 시작은 97이다. 따라서 해당 알파벳 - 96하면 정수가 된다.
/// 나머지는 문제에 주어진 식을 변환하면 된다.
/// 
/// mod 연산의 속성은 다음과 같다. (a+b) mod m = {(a mod m)+(b mod m)} mod m이다
/// 이때 +가 아닌 -와 *의 대해서도 동일하다.
/// 
/// 해당 문제는 (ai * r^i) mod M이므로 이는 {(ai mod M) * (b mod M)} mod M으로 변경 가능.
/// 1)a*r mod M을 먼저 식 세운다음
/// 2)pow(r,n)을 계산한다.
/// 이때 해당 식들을 mod의 속성에 맞춰 변경하기
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int L(0); //문자열의 길이
	int R(31); // 문제에 주어진 소수 31
	long long M(1234567891); //문제에 주어진 서로소 M
	string input;

	std::cin >> L;
	std::cin >> input;

	long long hash(0);
	long long r(1); //문제에서 R의 몇 승 이렇게 올라가는데 그걸 의미
	int a(0);
	for (int i = 0; i < L; i++)
	{
		a = (input[i] - 96);
		hash = (hash + (a * r)) % M; // 앞서 구한 H값 + (a mod M * (b mod M)) mod M
		r = (r * R) % M; //r mod M
	}

	std::cout << hash << "\n";

	return 0;
}