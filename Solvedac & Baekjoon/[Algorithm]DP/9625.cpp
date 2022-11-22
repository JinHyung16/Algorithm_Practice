#include<iostream>
#include<vector>

using namespace std;

/// <summary>
/// Silver5 - dp 알고리즘
/// A -> B / B -> BA로 변환
/// ex)k=3, A => B->BA->BAB, A : B = 1 : 2
/// ex)k=4, BAB->BABBA, A : B = 2 : 3
/// ex)k=5, BABBA->BABBABAB, A : B = 3 : 5
/// 즉, k가 2이상일 때 부턴, A의 개수=이전 k에서 B의 개수 / B의 개수=이전 k에서 A의 개수 + B의 개수
/// </summary>


int main(void)
{
	int k = 0; //버튼 누르는 횟수
	cin >> k;
	
	vector<int> dpA(k + 1, 0);
	vector<int> dpB(k + 1, 0);

	dpA[0] = 1;
	dpA[1] = 0;
	dpB[0] = 0;
	dpB[1] = 1;

	for (int i = 2; i <= k; i++)
	{
		dpA[i] = dpB[i - 1];
		dpB[i] = dpA[i - 1] + dpB[i - 1];
	}

	std::cout << dpA[k] << " " << dpB[k] << std::endl;

	return 0;
}