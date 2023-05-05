#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 내려가기 - DP 알고리즘
/// 1차원 배열 dp에 N개의 줄에 따라 들어오는 값을 넣는게 아니라
/// 값이 들어왔을 때, dp배열의 0번째, 1번째, 2번째에서 각 번째에서 갈 수 있는 곳에서 가장 큰 혹은 가장 작은값들을 더해 최댓값과 최솟값을 구한다.
/// 
/// 이때 maxdp랑 mindp를 구할때 [1]번째 즉 중앙에 위차한 값을 가장 마지막에 update해야한다. 
/// 왜냐면 가장 왼쪽과 가장 오른쪽은 본인 바로 위 말고도 이전층 중앙에서 값을 가져올 수 있기 때문이다.
/// 
/// 1층 -> [1-0] [1-1] [2-1]
/// 2층 -> [2-0] [2-1] [2-2]   => ex) 2-0의 값은 [1-0] 또는 [1-1]중 선택 + [2-0] 이렇게 좌우 사용하고 중앙 update하기
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N(0); //N개의 줄
	std::cin >> N;
	
	vector<int> input(3, 0);
	vector<int> mindp(3, 0);
	vector<int> maxdp(3, 0);

	int one(0), three(0);
	std::cin >> maxdp[0] >> maxdp[1] >> maxdp[2]; //처음 dp배열에 값을 넣는다.
	mindp[0] = maxdp[0];
	mindp[1] = maxdp[1];
	mindp[2] = maxdp[2];

	for(int i = 1; i < N; i++)
	{
		std::cin >> input[0] >> input[1] >> input[2];
		one = maxdp[0];
		three = maxdp[2];

		//그 다음줄 기준으로 들어온 값들에대해 최댓값을 기록한다.
		maxdp[0] = std::max(maxdp[0], maxdp[1]) + input[0]; //0번째는 0과 1번째에서 값을 가져올 수 있다.
		maxdp[2] = std::max(maxdp[1], maxdp[2]) + input[2]; //2번째는 2번째와 1번째에서 값을 가져올 수 있다.
		maxdp[1] = std::max(std::max(one, maxdp[1]), three) + input[1]; //1번째는 모든 곳에서 값을 가져올 수 있다.

		one = mindp[0];
		three = mindp[2];
		mindp[0] = std::min(mindp[0], mindp[1]) + input[0];
		mindp[2] = std::min(mindp[1], mindp[2]) + input[2];
		mindp[1] = std::min(std::min(one, mindp[1]), three) + input[1];
	}

	int maxResult = std::max(std::max(maxdp[0], maxdp[1]), maxdp[2]);
	int minResult = std::min(std::min(mindp[0], mindp[1]), mindp[2]);

	std::cout << maxResult << " " << minResult << "\n";
	return 0;
}