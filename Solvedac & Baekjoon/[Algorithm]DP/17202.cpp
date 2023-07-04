#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze1 핸드폰 번호 궁합 - DP 알고리즘
/// string으로 입력을 받은 뒤, 두 번호를 int로 바꿔 차례대로 phoneNums 벡터에 넣는다.
/// 그 후 while(true)를 돌면서 temp 벡터를 만들고 (phoneNums[i] + phoneNums[i+1]) % 10을 하여 temp에 넣고
/// 다 계산하면 phoneNums을 비운다음 temp값을 넣고, temp를 비우는 행위를 phoneNums.size()가 2가 될때까지 반복한다.
/// 
/// %10을 하는 이유는, string의 i번째를 int로 바꿔서 넣을 때 해당 자리수도 같이 오기 때문이다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	string strA, strB; //A와 B의 전화번호
	vector<int> phoneNums;

	std::cin >> strA;
	std::cin >> strB;

	int phoneNumSize = strA.size() + strB.size();

	for(int i = 0; i < strA.size(); i++)
	{
		int intA = strA[i] - '0';
		int intB = strB[i] - '0';

		phoneNums.push_back(intA);
		phoneNums.push_back(intB);
	}

	vector<int> temp;
	while( true )
	{
		for(int i = 0; i < phoneNums.size() - 1; i++)
		{
			temp.push_back((phoneNums[i] + phoneNums[i+1]) % 10);
		}
		phoneNums.clear();
		phoneNums = temp;
		temp.clear();

		if(phoneNums.size() == 2)
		{
			std::cout << phoneNums[0] << phoneNums[1] << "\n";
			break;
		}
	}
	return 0;
}