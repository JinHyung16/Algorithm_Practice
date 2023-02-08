#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 줄번호 - 문자열 알고리즘
/// 공백을 포함해서 입력을 받기위해 getline을 사용했다.
/// 문제는 줄수를 입력받은 후 문자열을 넣을때 cin의 개행문자가 차있어 출력시 처음은 공백으로만 나온다.
/// 그러므로 ignore을 통해 cin 버퍼를 비우고 입력 받고 난 뒤 clear로 cin의 오류비트를 지워준다.
/// </summary>

using namespace std;


int main(void)
{
	FastIO;

	int N(0); //줄의 수 N
	std::cin >> N;

	vector<string> stringVec;

	std::cin.ignore(); //cin버퍼 개행문자 지우기
	while (N--)
	{
		string input;
		std::getline(cin, input);
		std::cin.clear();
		stringVec.push_back(input);
	}

	for (int i = 0; i < stringVec.size(); i++)
	{
		std::cout << i + 1 << ". " << stringVec[i] << "\n";
	}
	return 0;
}