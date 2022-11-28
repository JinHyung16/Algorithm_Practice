#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Gold5 주사위 - Greedy 알고리즘
/// N짜리 주사위 주워지면 만드는건 N^3개 짜리 만듦
/// 마주보는 두 면중 보이는 면에 최솟값이 들어가면 된다
/// 그림을 참고하면 A-F / E-B / D-C가 마주보는 면
/// N값이 2이상부턴 3면이 보이는 블럭들 최솟값 = (3개면 적힌값) * 4, 
/// 2면이 보이는 블럭들 최솟값 = (2개면 적힌값) * 4*(N-1) + 4*(N-2),
/// 1면이 보이는 블럭들 최솟값 = (1면면 적힌값) * 4*((N-1)*(N-2)) + (N-2)*(N-2)
/// </summary>

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long n = 0;
	std::cin >> n;

	vector<int> dice(6, 0); //기본적으로 주사위는 6면보다 1개더 많게 만들기 그래야 vector의 i+1에서 오류 안남
	long long allSum = 0;
	int maxNum = 0;

	for (int i = 0; i < 6; i++)
	{
		std::cin >> dice[i]; //순서대로 A,B,C,D,E,F -> index 번호로 0,1,2,3,4,5 라고 가정
		allSum += dice[i];
		maxNum = std::max(maxNum, dice[i]);
	}

	if (n == 1)
	{
		//1일땐, 다 더하고 가장 큰 숫자 한개만 빼주면 된다
		std::cout << allSum - maxNum;
		return 0;
	}
	allSum = 0;
	maxNum = 0;

	dice[0] = std::min(dice[0], dice[5]);
	dice[1] = std::min(dice[1], dice[4]);
	dice[2] = std::min(dice[2], dice[3]);

	//dice의 0~2번째 index까지 총 3개에 최소값넣고 보면 되니깐 sort해준다
	//가장 작은 값 부터 3면, 2면, 1면에 들어가도록 배치
	//그래야 3개면 합 + 2개면 합 + 1개면 합의 값이 최솟값이 되기 때문
	std::sort(dice.begin(), dice.begin() + 3);
	int view1 = dice[0];
	int view2 = view1 + dice[1];
	int view3 = view2 + dice[2];

	allSum += view3 * 4;
	allSum += view2 * (4 * (n - 2) + 4 * (n - 1));
	allSum += view1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
	std::cout << allSum << std::endl;
	return 0;
}