#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>?


#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Gold5 ������ - ���Ʈ���� �˰���
/// ��ư 0~9������ ������ŭ �迭�� ����� �̸� ���峭 ��ư�� üũ�صд�.
/// �׸��� ä�� ���ۺ��� 100������ ���̸� �ּ� ������ Ƚ���� �����صΰ�
/// 0������ ä�� �ִ���� �÷�������, ä�� �ִ���� 0������ �����ö� �� ä�κ� �����̴� �ּ� Ƚ���� �����Ѵ�.
/// �̶� N�� �ִ� ������ 500000�̹Ƿ� ������ ���������� for���� 500000 * 2��ŭ ���������Ѵ�.
/// �׷��� �ش� i(ä�� ��)�� btn���� ���� �� �ִ��� ������ �Ǵ��ϸ鼭 minMove�� �����ذ���.
/// 
/// string�� index�ϳ��� char type���� char '0'�� ���ڷ� 48�̴�.
/// </summary>

using namespace std;

//0~9���� ��ư�� Ȱ��ȭ ���� �з�
vector<bool> btnInteractive(10, true);
int startChannel = 100; //�ʱ� ������ 100������

bool CheckButton(int curBtn)
{
	string btn = std::to_string(curBtn);
	for (int i = 0; i < btn.length(); i++)
	{
		int btnNum = btn[i] - 48;
		if (!btnInteractive[btnNum])
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	FastIO;

	int N(0), M(0); //�̵��Ϸ��� ä�� N, ���峭 ��ư ���� M
	std::cin >> N;
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		btnInteractive[temp] = false;
	}

	int minMoveChannel = std::abs(N - startChannel); //��ǥ ä�ΰ� ���� ä���� ���̸� ��Ƶд�.
	
	for (int i = 0; i <= 1000000; i++)
	{
		if (CheckButton(i))
		{
			int curChannel = std::abs(N - i) + std::to_string(i).length();
			minMoveChannel = std::min(minMoveChannel, curChannel);
		}
	}

	std::cout << minMoveChannel << "\n";
	return 0;
}