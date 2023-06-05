#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ��ǥ��2 - ���� �˰���
/// ��� = ��ü �� / vector.size()�� �����Ѵ�.
/// �߾Ӱ��� ��� �������� ���� �� vector�� 3��° index �� vec[2]�� ȣ���ϸ� �ȴ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	vector<int> numVec(5, 0);
	int averageNum = 0;
	for (int i = 0; i < numVec.size(); i++)
	{
		std::cin >> numVec[i];
		averageNum += numVec[i];
	}

	averageNum /= numVec.size();
	std::sort(numVec.begin(), numVec.end());

	std::cout << averageNum << "\n" << numVec[2] << "\n";
	return 0;
}
