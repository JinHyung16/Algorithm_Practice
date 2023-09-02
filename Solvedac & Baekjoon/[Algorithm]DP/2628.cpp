#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 종이자르기 - DP 알고리즘
/// 가로, 세로를 입력받아 정렬 후 제일 큰 값을 꺼내 곱한다.
/// 이때 Set에 넣어, 중복 값을 지운다. 사실 같은 값이면 길이가 0으로 선택은 안될테니 상관없다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int width = 0, height = 0; //가로와 세로의 길이
	int dotCnt = 0; //칼로 잘라야하는 점선의 개수
	set<int> wid;
	set<int> hei;

	std::cin >> width >> height;
	std::cin >> dotCnt;
	for ( int i = 0; i < dotCnt; i++ )
	{
		int c1 = 0, c2 = 0;
		std::cin >> c1 >> c2;
		if ( c1 == 0 )
		{
			wid.insert(c2);
		}
		else
		{
			hei.insert(c2);
		}
	}

	wid.insert(0);
	wid.insert(height);
	hei.insert(0);
	hei.insert(width);

	vector<int> widVec(wid.begin(), wid.end());
	vector<int> heiVec(hei.begin(), hei.end());

	std::sort(widVec.begin(), widVec.end());
	std::sort(heiVec.begin(), heiVec.end());

	int maxWidth = 0, maxHeight = 0;
	for ( int i = 0; i < widVec.size() - 1; i++ )
	{
		maxWidth = std::max(maxWidth, widVec[i + 1] - widVec[i]);
	}
	for ( int i = 0; i < heiVec.size() - 1; i++ )
	{
		maxHeight = std::max(maxHeight, heiVec[i + 1] - heiVec[i]);
	}

	std::cout << maxWidth * maxHeight << "\n";
	return 0;
}