#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ������ - ���� �˰���
/// 1)���� ������ �����ϴ� ������ -> ���� ���� ��������
/// 2)���� ������ ������ ���� ������ �����ϴ� ������ -> ���� ���� ��������
/// 3)���� ������ ���� ������ ������ ���� ������ �����ϴ� ������ -> ���� ���� ��������
/// 4)��� ������ ������ �̸��� ���� ������ �����ϴ� ������(��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.) -> �̸� ������ ���� ����
/// 
/// ����ü�� ����� �̸�, ���� ����, ���� ����, ���� ������ �޾�, vector<����ü>�� �����صд�.
/// �� �� Compare�� ����� �� ���ǿ� �°� return���� sort�� �� Name�� ����Ѵ�.
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
	if (a.KoreanScore == b.KoreanScore && a.EnglishScore == b.EnglishScore && a.MathScore == b.MathScore) //�̸� ������ �����ϴ� ������
	{
		return a.Name < b.Name;
	}
	if (a.KoreanScore == b.KoreanScore && a.EnglishScore == b.EnglishScore) //���� ������ �����ϴ� ������
	{
		return b.MathScore < a.MathScore;
	}
	if (a.KoreanScore == b.KoreanScore) //���� ������ �����ϴ� ������
	{
		return a.EnglishScore < b.EnglishScore;
	}
	return b.KoreanScore < a.KoreanScore; //�⺻������ ���� ������ �����ϴ� ������
}

int main(void)
{
	FastIO;
	
	int N(0); //�� �л� N��
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
