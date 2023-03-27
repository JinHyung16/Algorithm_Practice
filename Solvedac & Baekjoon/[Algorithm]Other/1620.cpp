#include<iostream>
#include<vector>
#include<string>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 나는야 포켓몬 마스터 이다솜 - 자료구조 알고리즘
/// map은 (key, value)로 저장해 key값을 통해 value를 찾으니 빠르다. 
/// 포켓몬 이름이 들어오면 key로 사용해 빠르게 도감 번호를 찾는다.
/// 포켓몬 도감 번호가 들어오면 따로 이름만을 저장해놓은 배열을 만들어 번호를 넣어 이름을 출력한다.
/// </summary>

using namespace std;

vector<string> bookString; //도감 번호가 주어지면 여기서 포켓몬 이름 출력
map<string, int> bookInt; //포켓몬 이름이 주어지면 그걸 key로 도감 번호 출력

int main(void)
{
	FastIO;

	int N(0), M(0); //도감에 등록되 포켓몬 수N, 내가 맞춰야 하는 문제의 개수M
	std::cin >> N >> M;
	string input; //도감 번호와 포켓몬 이름 둘 다 받을 수 있게
	vector<string> result;

	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		bookString.push_back(input);
		bookInt.insert(make_pair(input, i + 1)); //실제 도감 시작은 1이므로
	}
	
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		if (65 <= input[0] && input[0] <= 90)
		{
			//포켓몬 이름의 맨 앞글자는 대문자 이므로 아스키로 대문자 A=60, Z=90이다.
			result.push_back(to_string(bookInt[input]));
		}
		else
		{
			//bookString의 시작은 0번째 이므로 도감 번호와 1차이가 난다.
			int index = stoi(input) - 1;
			result.push_back(bookString[index]);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}