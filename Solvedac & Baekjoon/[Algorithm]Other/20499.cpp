#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze4 Darius님 한타 안 함? - 구현 알고리즘
/// string으로 입력을 받는다.
/// 그 후 for문을 돌면서 /나올때까지 다른 string에 저장한다
/// 그래야 십의 자리 이상을 받을 수 있다.
/// / 나오면 저장한 string을 int로 변환하여 배열에 순서대로 kda순으로 넣는다.
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	vector<int> kda; // 순서대로 kda 저장
	string temp;
	for ( int i = 0; i < input.size(); i++ )
	{
		if ( input[i] == '/' )
		{
			kda.push_back(stoi(temp));
			temp = "";
			continue;
		}
		temp += input[i];
	}
	kda.push_back(stoi(temp)); // 마지막 숫자 처리

	if ( kda[0] + kda[2] < kda[1] || kda[1] == 0)
		cout << "hasu" << "\n";
	else
		cout << "gosu" << "\n";
	return 0;
}