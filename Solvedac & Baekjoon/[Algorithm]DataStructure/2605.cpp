#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 줄 세우기 - 자료구조 알고리즘
/// students 벡터에 학생들 번호를 초기화 해놓는다.
/// 그 후 학생이 뽑은 번호를 입력받으면
/// 그 번호만큼 for문을 돌면서 자리 바꾸기를 시도한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //학생의 수
	std::cin >> N;
	
	vector<int> students(N, 0);

	for ( int i = 0; i < N; i++ )
	{
		students[i] = i + 1;
	}

	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;

		//자리를 바꿔준다.
		for ( int j = 0; j < input; j++ )
		{
			int temp = students[i];
			students[i] = students[j + i - input];
			students[j + i - input] = temp;
		}
	}

	for ( int i = 0; i < N; i++ )
	{
		std::cout << students[i] << " ";
	}
	std::cout << "\n";
	return 0;
}