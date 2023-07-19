#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �� ����� - �ڷᱸ�� �˰���
/// students ���Ϳ� �л��� ��ȣ�� �ʱ�ȭ �س��´�.
/// �� �� �л��� ���� ��ȣ�� �Է¹�����
/// �� ��ȣ��ŭ for���� ���鼭 �ڸ� �ٲٱ⸦ �õ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //�л��� ��
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

		//�ڸ��� �ٲ��ش�.
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