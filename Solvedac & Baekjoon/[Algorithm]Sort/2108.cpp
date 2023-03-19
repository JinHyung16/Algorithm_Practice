#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 통계학 - 정렬 알고리즘
/// 1)산술평균: N개의 수들의 합을 N으로 나눈 값
/// 2)중앙값: N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치한 값
/// 3)최빈값: N개의 수들 중 가장 많이 나타나는 값
/// 4)범위: N개의 수들 중 최댓값과 최솟값의 차이
/// 
/// 구해야하는 1)~4)을 보면 결국 오름차순 정렬을하고 문제에 접근하면 해결하기 쉽다.
/// 최빈값을 구하려면, 배열을 만들어 해당 배열 index의 count를 증가시켜 가장 많이 나온 count들을 비교하면 쉽다.
/// 문제는 배열의 범위를 잡아야하는데 문제에서 N의 절댓값은 4000을 넘지 않는다고 했으므로, 8000 + 1크기의 배열을 만들어
/// 음수는 1~4000에, 양수는 4001~8000의 저장하면 된다.
/// </summary>

using namespace std;

//산술 평균 구하기
int Mean(int n, vector<int> vec)
{
	double temp = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		temp += vec[i];
	}

	int result = round(temp / n);
	return result;
}

//중앙값 구하기
int Median(int n, vector<int> vec)
{
	int index = (n - 1) / 2;	
	return vec[index];
}

//최빈값 구하기
int Mode(int n, vector<int> vec)
{
	vector<int> modeVec(8001, 0);
	for (int i = 0; i < n; i++)
	{
		modeVec[(vec[i] + 4000)] ++;
	}

	int maxCnt(0);
	for (int i = 0; i < modeVec.size(); i++)
	{
		maxCnt = std::max(maxCnt, modeVec[i]);
	}
	
	int sameCnt(0); //maxCnt랑 같은게 얼마나 존재하는지
	int result(0);
	for (int i = 0; i < modeVec.size(); i++)
	{
		if (maxCnt == modeVec[i])
		{
			sameCnt++;
			result = (i - 4000);
		}

		if (sameCnt == 2)
		{
			break;
		}
	}

	return result;
}

//범위 구하기
int Range(int n, vector<int> vec)
{
	int result = vec[n - 1] - vec[0];
	return result;
}

int main(void)
{
	FastIO;

	int N(0); // 수의 개수 N, N은 홀수
	std::cin >> N;

	vector<int> numVec(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> numVec[i];
	}

	std::sort(numVec.begin(), numVec.end()); //오름차순 정렬

	std::cout << Mean(N, numVec) << "\n" << Median(N, numVec) << "\n" 
		<< Mode(N, numVec) << "\n" << Range(N, numVec) << "\n";
	
	return 0;
}