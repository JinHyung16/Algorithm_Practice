#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ��Ÿ ���� - �̺� Ž�� �˰���
/// �ּ� ��ȭ �ð��� 1�̰� �ִ�� N�� �Է¹��� �ð����� �����̴�.
/// ���� 1���� high���� �̺� Ž���� �����Ѵ�.
/// ���� ��緹�� ������ ���� ���Ǹ� ��� ���� ���Ѵٸ� �� ��緹�� ���
/// ���� ��緹�� ������ ��緹�� �ʱ� ũ��� �ٲٸ鼭 ī�����Ѵ�.
/// �� �� ���� ��緹�� �������� ���� �ð���ŭ ���ش�.
/// 
/// ��緹�� ������ M���� ũ�� ��緹�� �ʱ� ũ�⸦ �ٽ� �÷��ְ�
/// �ƴϸ� ��緹�� ũ�� ���� ���� �� ��� ���� ũ�⸦ �ٿ� �ٽ� Ž�� ����
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int N = 0, M = 0; //������ �� N�� M
	int low = 1, mid = 0, high = 0;
	int total = 0, result = 0;

	std::cin >> N >> M;
	vector<int> video(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		int input = 0;
		std::cin >> input;
		video[i] = input;
		high += input;
	}
	
	while ( low <= high )
	{
		mid = (low + high) / 2;
		total = mid;
		bool canRecord = true;
		int cnt = 1; //��緹�� ���� 1��
		for ( int i = 0; i < N; i++ )
		{
			if ( mid < video[i] )
			{
				canRecord = false;
				break;
			}
			if ( total < video[i] )
			{
				total = mid;
				cnt++; //���ο� ��緹�� ���
			}
			total -= video[i];
		}
		if ( M < cnt || !canRecord )
		{
			low = mid + 1;
		}
		else if ( cnt <= M )
		{
			high = mid - 1;
			result = mid;
		}
	}
	std::cout << result << "\n";
	return 0;
}