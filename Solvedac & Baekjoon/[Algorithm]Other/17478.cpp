#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 재귀함수가 뭔가요? - 재귀 알고리즘
/// 출력시 문구에 "" 이게 있을 시 출력하는 방법에 대해 잘 봐놓자.
/// </summary>


string underBar;

void Recur(int n)
{
	string temp = underBar;
	cout << temp << "\"재귀함수가 뭔가요?\"" << "\n";
	if (n == 0)
	{
		cout << temp << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
	}
	else
	{
		cout << temp << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << "\n";
		cout << temp << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << "\n";
		cout << temp << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << "\n";
		underBar += "____";
		Recur(n - 1);
	}
	cout << temp << "라고 답변하였지." << "\n";
}

int main(void)
{
	FastIO;

	int N = 0; // 재귀 횟수 N
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
	Recur(N);

	return 0;
}