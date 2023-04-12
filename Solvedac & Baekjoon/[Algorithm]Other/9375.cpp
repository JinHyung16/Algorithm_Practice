#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 �мǿ� ���غ� - ���� �˰���
/// 
/// �־��� �� ������ ���� '����, ����, ���ڷ�, �Ȱ�� ��'���� �и��Ѵ�.
/// �Է��� '���� �̸� + �� ����'�� �����Ƿ�, �� �� ������ ���� + 1�� �Ѵ��� ���� �ٸ� �������� ���ϰ� -1 �Ѵ�.
/// �� headgear -> hat�� turban, eyewear -> sunglasses�� ������ (headgear�� ���� + 1) * (eyewear�� ���� + 1) - 1�Ѵ�.
/// -1�ϴ� ������ headgear���� eyewear�� �� �� ���Դ� ��츦 �ǹ��Ѵ�.
/// 
/// vector�� �̿��� ��� �ߺ��� ��쿡 ���ؼ� ������ ���� ���Ѿ��Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T(0), N(0); //test case T, ���� �ǻ��� �� N
	string clothName, cloth;
	vector<pair<string, int>> clothVec;
	int combinationCnt(0);

	std::cin >> T;
	while (T--)
	{
		std::cin >> N;
		combinationCnt = 1;

		for (int i = 0; i < N; i++)
		{
			std::cin >> clothName >> cloth;

			//�� ó���� �����ϰ� �ٷ� �н�
			if (i == 0)
			{
				clothVec.push_back({ cloth, 1 });
				continue; //�Ʒ� for�� ����
			}

			for (int j = 0; j < clothVec.size(); j++)
			{
				if (clothVec[j].first == cloth)
				{
					clothVec[j].second ++;
					break;
				}

				//���� ���� �ʴٸ�, clothVec.size() -1 ���� j�� ���� ���̴�. �ֳĸ� ���� if���� ���� �ȵǾ��� ����
				if (j == clothVec.size() - 1)
				{
					clothVec.push_back({ cloth, 0 });
				}
			}	
		}
		for (int i = 0; i < clothVec.size(); i++)
		{
			combinationCnt *= (clothVec[i].second + 1);
		}

		//�������� �� �� ���Դ� ��� ���ֱ�
		std::cout << combinationCnt - 1 << "\n";
		clothVec.clear();
	}
	return 0;
}