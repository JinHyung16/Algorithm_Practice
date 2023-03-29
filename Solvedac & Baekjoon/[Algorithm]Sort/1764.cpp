#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 듣보잡 - 정렬 알고리즘
/// 처음엔 듣도 못한 사람들과 보도 못한 사람들을 배열에 각각 넣어 비교했더니 틀렸다.
/// 이에 듣도 못한 사람을 넣고 난 뒤 보도 못한 사람을 넣을때 있는지 판별하는 방식으로 수정했다.
/// 문제는 vector를 이용해 find함수로 체크하다보니 시간초과가 나왔다.
/// 여기서 해결법은 binary search를 이용해 개선하거나
/// stl중 map을 사용하는것인데, 나는 binary search를 이용했다. 그러면 binary search전 정렬은 필수다.
/// </summary>

using namespace std;

vector<string> noListen;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //듣도 못한 수 N, 보도 못한 수 M
	int noLookListendCnt(0); //듣도 보도 못한 개수
	vector<string> result;

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		std::cin >> input;
		noListen.push_back(input);
	}

	std::sort(noListen.begin(), noListen.end());
	for (int i = 0; i < M; i++)
	{
		string input;
		std::cin >> input;
		if (binary_search(noListen.begin(), noListen.end(), input))
		{
			result.push_back(input);
			noLookListendCnt++;
		}
	}

	std::sort(result.begin(), result.end());
	std::cout << noLookListendCnt << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}