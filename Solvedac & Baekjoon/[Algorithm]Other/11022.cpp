#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 A+B-8 - ���� �˰���
/// �ܼ� ������ ���� ����Ͽ� �˰����� Ǭ��.
/// </summary>

int main(void)
{
	FastIO;

	int T = 0; //�׽�Ʈ ���̽�
	int A = 0, B = 0;

	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
	}
	return 0;
}