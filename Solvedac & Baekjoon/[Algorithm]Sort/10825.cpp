#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 국영수 - 정렬 알고리즘
/// 1)국어 점수가 감소하는 순서로 -> 국어 성적 내림차순
/// 2)국어 점수가 같으면 영어 점수가 증가하는 순서로 -> 영어 성적 오름차순
/// 3)국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로 -> 수학 성적 내림차순
/// 4)모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로(단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.) -> 이름 사전순 오름 차순
/// 
/// 구조체를 만들어 이름, 국어 성적, 영어 성적, 수학 성적을 받아, vector<구주체>로 저장해둔다.
/// 그 후 Compare를 만들어 각 조건에 맞게 return시켜 sort한 뒤 Name을 출력한다.
/// </summary>

using namespace std;


struct Student
{
	string Name;
	int KoreanScore;
	int EnglishScore;
	int MathScore;
};

bool CompareStudent(Student a, Student b)
{
	if (a.KoreanScore == b.KoreanScore && a.EnglishScore == b.EnglishScore && a.MathScore == b.MathScore) //이름 사전순 증가하는 순서로
	{
		return a.Name < b.Name;
	}
	if (a.KoreanScore == b.KoreanScore && a.EnglishScore == b.EnglishScore) //수학 점수가 감소하는 순서로
	{
		return b.MathScore < a.MathScore;
	}
	if (a.KoreanScore == b.KoreanScore) //영어 점수가 증가하는 순서로
	{
		return a.EnglishScore < b.EnglishScore;
	}
	return b.KoreanScore < a.KoreanScore; //기본적으론 국어 점수가 감소하는 순서로
}

int main(void)
{
	FastIO;
	
	int N(0); //반 학생 N명
	std::cin >> N;

	vector<Student> studentVec(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> studentVec[i].Name >> studentVec[i].KoreanScore >> studentVec[i].EnglishScore >> studentVec[i].MathScore;
	}

	std::sort(studentVec.begin(), studentVec.end(), CompareStudent);

	for (int i = 0; i < studentVec.size(); i++)
	{
		std::cout << studentVec[i].Name << "\n";
	}

	return 0;
}
