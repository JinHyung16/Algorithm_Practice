#include<iostream>
#include<vector>
#include<queue>

/// <summary>
/// Silver3 ���� - Binary Search �˰���
/// �������� ���� Ƚ���� �ִ� �ʾ��̶� �ʾ����� MAX_INT ����
/// ���̳ʸ� ��ġ�� low+high���� ������ Ȯ���� �޶����� Ƚ���� ���ϴ� ���̴�.
/// �� �ٽ��� �迭�� �� �߾��� ������ ã���� �ϴ� ���� ���ϸ鼭 ã�´�.
/// </summary>

using namespace std;

const int MAX_INT = 1000000000;

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long gameNum(0), winGame(0); //���� Ƚ�� X�� �̱���� Y �ǹ�
	std::cin >> gameNum >> winGame;

	int winPercent(0); //�������� �·� Z �ǹ�
	winPercent = (winGame * 100) / gameNum;

	if (winPercent >= 99)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	int low(0), high = MAX_INT;
	int winResult = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int binaryResult = (100 * (winGame + mid)) / (gameNum + mid);
		if (winPercent >= binaryResult)
		{
			winResult = mid + 1;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	std::cout << winResult << std::endl;
	return 0;
}