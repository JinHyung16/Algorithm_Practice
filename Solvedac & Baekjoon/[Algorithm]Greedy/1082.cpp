#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

/// <summary>
/// Gold3 �� ��ȣ - Greedy �˰���
/// ���� �Ž��� �ִ� ������ ����� ���δ�.
/// pair�� �̿��� ���ȣ�� ������ �����ص���
/// pair sort�� ������ �� ���� �� second������ ���� Compair�Լ� ����������
/// �����ϱ� �������� (���ȣ, �氡��) -> (�氡��, ���ȣ) ������ �ٲٱ�
/// Room[0]�� �� ��ȣ�� 0�̸� ��ü ���ڰ� 0�� �ȵǵ���
/// Room[1]�� �� ��ȣ�� �ǵ��� ����� �Ѵ�.
/// �ʱ� vector�� ������ �� �����ص״µ�, ������ ��½� �ð��� �� ��ƸԾ� ������ �ʿ��ߴ�.
/// </summary>


using namespace std;

bool Compair(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second; //second���� �� ������ ������ ����
	}
	else if (a.first < b.first)
	{
		return a.second < b.second;
	}
	else if (a.first > b.first)
	{
		return a.second > b.second;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n(0), m(0); //���汸���� �Ĵ� ���� �ִ� ���� n-1, �غ��� �ݾ�
	vector<int> Price(10, 0); //�� ������ ���ݵ� ����
	vector<pair<int, int>> Room; //�� ȣ�� ����

	std::cin >> n;
	for (int i = 0; i < n; i++) 
	{ 
		std::cin >> Price[i];
		Room.push_back(make_pair(Price[i], i)); //���ȣ, �� ���� ������� ����
	}
	std::cin >> m;

	std::sort(Room.begin(), Room.end()); //pair�� first�������� �������� ����, first������ second�� �������� ������
	//std::sort(Room.begin(), Room.end(), Compair);

	if (n == 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	string purchaseMax;
	if (Room[0].second != 0)
	{
		//���� �� �����̶�� ���� ��־� �Ѵ�
		int cnt = m / Room[0].first;
		for (int i = 0; i < cnt; i++)
		{
			purchaseMax += to_string(Room[0].second);
		}
		m -= (cnt * Room[0].first);
	}
	else
	{
		int temp = m - Room[1].first;
		if (temp < 0)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
		purchaseMax += to_string(Room[1].second);
		int cnt = temp / Room[0].first;
		for (int i = 0; i < cnt; i++)
		{
			purchaseMax += to_string(Room[0].second);
		}
		m = temp - (cnt * Room[0].first);
	}

	for (int i = 0; i < purchaseMax.size(); i++)
	{
		bool IsPriced = false;
		int cur = Price[purchaseMax[i] - '0'];
		for (int j = n - 1; j >= 0; j--)
		{
			if (m - (Price[j] - cur) >= 0)
			{
				m -= (Price[j] - cur);
				IsPriced = true;
				purchaseMax[i] = j + '0';
			}

			if (IsPriced)
			{
				break;
			}
		}

		if (!IsPriced)
		{
			break;
		}
	}

	std::cout << purchaseMax.c_str() << std::endl;
	return 0;
}