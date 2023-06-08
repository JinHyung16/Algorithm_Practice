#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 신입 사원 - 정렬 알고리즘
/// 먼저 서류 점수 순서로 오름차순 한다.
/// 그 후 서류 점수를 기준으로 정렬된 두 사람을 비교해 가면서 면접 점수를 통해 비교한다.
/// 앞사람의 면접 점수가 내 면접 점수보다 높으면 result 값을 증가시켜 합격자 수를 늘려간다.
/// </summary>

using namespace std;

struct Applicant //지원자
{
	int PapperScore; //서류 점수
	int InterviewScore; //면접 점수
};

bool CompareApplicant(Applicant a, Applicant b)
{
	return a.PapperScore < b.PapperScore;
}

int main(void)
{
	FastIO;

	int T(0), N(0); //테스트 케이스 T, 지원자수 N
	std::cin >> T;


	while (T--)
	{
		std::cin >> N;

		vector<Applicant> scoreVec; //지원자들의 점수를 담은 vector

		int papperScore(0), interviewScore(0);
		for (int n = 0; n < N; n++)
		{
			std::cin >> papperScore >> interviewScore;
			Applicant applicant = { papperScore, interviewScore };
			scoreVec.push_back(applicant);
		}
		std::sort(scoreVec.begin(), scoreVec.end(), CompareApplicant);


		//temp를 이용해 이중 for문과 비슷한 효과를 내고 있습니다.
		int result(1);
		int temp(0);
		for (int i = 1; i < N; i++)
		{
			if (scoreVec[i].InterviewScore < scoreVec[temp].InterviewScore)
			{
				result++;
				temp = i; //temp 를 i로 바꿔서 서로 비교하기
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}
