#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ���� ��� - ���� �˰���
/// ���� ���� ���� ������ �������� �Ѵ�.
/// �� �� ���� ������ �������� ���ĵ� �� ����� ���� ���鼭 ���� ������ ���� ���Ѵ�.
/// �ջ���� ���� ������ �� ���� �������� ������ result ���� �������� �հ��� ���� �÷�����.
/// </summary>

using namespace std;

struct Applicant //������
{
	int PapperScore; //���� ����
	int InterviewScore; //���� ����
};

bool CompareApplicant(Applicant a, Applicant b)
{
	return a.PapperScore < b.PapperScore;
}

int main(void)
{
	FastIO;

	int T(0), N(0); //�׽�Ʈ ���̽� T, �����ڼ� N
	std::cin >> T;


	while (T--)
	{
		std::cin >> N;

		vector<Applicant> scoreVec; //�����ڵ��� ������ ���� vector

		int papperScore(0), interviewScore(0);
		for (int n = 0; n < N; n++)
		{
			std::cin >> papperScore >> interviewScore;
			Applicant applicant = { papperScore, interviewScore };
			scoreVec.push_back(applicant);
		}
		std::sort(scoreVec.begin(), scoreVec.end(), CompareApplicant);


		//temp�� �̿��� ���� for���� ����� ȿ���� ���� �ֽ��ϴ�.
		int result(1);
		int temp(0);
		for (int i = 1; i < N; i++)
		{
			if (scoreVec[i].InterviewScore < scoreVec[temp].InterviewScore)
			{
				result++;
				temp = i; //temp �� i�� �ٲ㼭 ���� ���ϱ�
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}
