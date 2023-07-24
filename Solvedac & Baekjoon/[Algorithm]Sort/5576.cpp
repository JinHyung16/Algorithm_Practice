#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 콘테스트 - Sort 알고리즘
/// 풀이1)
/// 0~9까지 총 10개는 W대학에 10~19까지 총 10개는 K대학에 입력 받는다.
/// 그 후 sort(vector.rbegin(), vector.rend());를 통해 내림차순 정렬한다.
/// for i to 3을 통해 3명의 점수 합을 출력한다.
/// 
/// 풀이2)
/// pair<int,int>를 통해 W와 K의 구분 값을 first로 점수를 second로 사용해서
/// bool Compare(int a, int b)를 통해 second값으로 내림차순 하여 비교해도 된다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int sumW = 0, sumK = 0; //W대학의 가장 높은 3명 총점 합, K대학의 가장 높은 3명 총점 합
	//W대학 점수와 K대학 점수 담을 vector
	vector<int> W;
	vector<int> K;
	for ( int i = 0; i < 20; i++ )
	{
		int input = 0;
		std::cin >> input;
		if ( i <= 9 )
		{
			W.push_back(input);
		}
		else
		{
			K.push_back(input);
		}
	}

	std::sort(W.rbegin(), W.rend());
	std::sort(K.rbegin(), K.rend());

	for ( int i = 0; i < 3; i++ )
	{
		sumW += W[i];
		sumK += K[i];
	}

	std::cout << sumW << " " << sumK << "\n";
	return 0;
}