#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 �ܾ� ���� ��� - ���� �˰���
/// char�� �Է¹޾� for���� ���� ī���� �� �� ������
/// �� ���ϰ� string���� �޾� .size()�� ����Ѵ�.
/// </summary>


int main(void)
{
	FastIO;

	string input;
	cin >> input;

	cout << input.size() << "\n";

	return 0;
}