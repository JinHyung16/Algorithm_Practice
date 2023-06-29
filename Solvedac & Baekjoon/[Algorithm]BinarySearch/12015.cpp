#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold2 ���� �� �����ϴ� �κ� ���� 2 - �̺� Ž�� �˰���
/// lower_bound�� ������ Ȱ���� �ذ��Ѵ�.
/// lower_bound�� ���� Ž������ ���Ҹ� Ž���ϴµ� ã������ key������ ���ų� ū ���ڰ� �迭 �� ��°���� ó�� �����ϴ��� ã�� �� ����.
/// ���� sequence ���͸� �����, std::cin >> a�� ���� ���� �Է� �޴´�.
/// 1) sequence.empty() || sequence.back() < a �� sequence.push_back(a)�� ���� ���� �ִ´�.
/// 2) sequence�� ���� �ִµ� sequence.back() > a�� lower_bound�� ���� a������ �۰ų� ���� ���� ��� �ִ��� �������� �ش� ��ġ�� ���� a�� �ٲ۴�.
/// 2-1) lower_bound(sequence.begin(), sequence.end(), a) - sequence.begin();�� ���� index ���� ���Ѵ�.
/// 
/// ex) N = 6, A = {10, 20, 30, 25, 15, 60} �� ��, ���� �� �߰��ϴ� �κ� ������ ã�� ����� ������ ����.
/// 1) sequence = {10, 20, 30}�� ��Ȳ���� 25�� ������
/// 2) sequence.back() = 30 > 25 �̹Ƿ�
/// 3) lower_bound�� ���� 25���� ���ų� ū ���ڰ� �迭 �� �� °�� ó�� �������� ��ȯ�� �� ������ ���� ->int index = 2;
/// 4) sequence[index] = 25�� �ٲٱ�.
/// </summary>

using namespace std;

vector<int> sequence;

int main(void)
{
	FastIO;

	int N = 0; //���� A�� ũ�� N

	std::cin >> N;
	for(int i = 0; i < N; i++)
	{
		int a = 0;
		std::cin >> a;
		if(sequence.empty() || sequence.back() < a)
		{
			sequence.push_back(a);
		}
		else
		{
			int index = std::lower_bound(sequence.begin(), sequence.end(), a) - sequence.begin();
			sequence[index] = a;
		}
	}

	std::cout << sequence.size() << "\n";
	return 0;
}