#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze4 ������ - ���� �˰���
/// ������ (������ ���� * ������ ����)�� �ϳ��� �Է¹޾� ���ؼ� �����صд�.
/// �� �� �Է¹��� ������ �� �ݾ� X�� ���Ͽ� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int X = 0, N = 0; //�� �ݾ� X, ������ ������ ���� N
	std::cin >> X;
	std::cin >> N;

	int sum = 0; //������ ���� * ������ �� ���ؼ� ������ ����
	for ( int i = 0; i < N; i++ )
	{
		int a = 0, b = 0; //������ ���� a, ���� b
		std::cin >> a >> b;
		sum += (a * b);
	}

	if ( sum == X )
		std::cout << "Yes" << "\n";
	else
		std::cout << "No" << "\n";

	return 0;
}	