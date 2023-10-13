#include<iostream>
#include<vector>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 크로아티아 알파벳 - 문자열 알고리즘
/// 미리 string 배열의 변환할 알파벳을 저장해둔다.
/// 이때 string alpha[]로 string들의 array형식으로 사용시
/// length의 경우 alpha의 전체 크기 / string 첫 번째 요소의 크기를 해야 제대로 나온다.
/// c++에서 배열의 길이를 얻는 일반적인 방법이니 기억하자.
/// </summary>

int main(void)
{
	FastIO;
	
	string alpha[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string s;
	int count = 0;
	int length = sizeof(alpha) / sizeof(*alpha);
	cin >> s;
	for (int i = 0; i < length; i++) {
		count = s.find(alpha[i]);
		while (true) {
			count = s.find(alpha[i]);
			if (count == string::npos) {
				break;
			}
			s.replace(count, alpha[i].length(), "!");
		}
	}
	cout << s.size();

	return 0;
}