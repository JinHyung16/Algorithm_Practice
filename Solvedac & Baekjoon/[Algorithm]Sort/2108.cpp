#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 ����� - ���� �˰���
/// 1)������: N���� ������ ���� N���� ���� ��
/// 2)�߾Ӱ�: N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�� ��
/// 3)�ֺ�: N���� ���� �� ���� ���� ��Ÿ���� ��
/// 4)����: N���� ���� �� �ִ񰪰� �ּڰ��� ����
/// 
/// ���ؾ��ϴ� 1)~4)�� ���� �ᱹ �������� �������ϰ� ������ �����ϸ� �ذ��ϱ� ����.
/// �ֺ��� ���Ϸ���, �迭�� ����� �ش� �迭 index�� count�� �������� ���� ���� ���� count���� ���ϸ� ����.
/// ������ �迭�� ������ ��ƾ��ϴµ� �������� N�� ������ 4000�� ���� �ʴ´ٰ� �����Ƿ�, 8000 + 1ũ���� �迭�� �����
/// ������ 1~4000��, ����� 4001~8000�� �����ϸ� �ȴ�.
/// </summary>

using namespace std;

//��� ��� ���ϱ�
int Mean(int n, vector<int> vec)
{
	double temp = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		temp += vec[i];
	}

	int result = round(temp / n);
	return result;
}

//�߾Ӱ� ���ϱ�
int Median(int n, vector<int> vec)
{
	int index = (n - 1) / 2;	
	return vec[index];
}

//�ֺ� ���ϱ�
int Mode(int n, vector<int> vec)
{
	vector<int> modeVec(8001, 0);
	for (int i = 0; i < n; i++)
	{
		modeVec[(vec[i] + 4000)] ++;
	}

	int maxCnt(0);
	for (int i = 0; i < modeVec.size(); i++)
	{
		maxCnt = std::max(maxCnt, modeVec[i]);
	}
	
	int sameCnt(0); //maxCnt�� ������ �󸶳� �����ϴ���
	int result(0);
	for (int i = 0; i < modeVec.size(); i++)
	{
		if (maxCnt == modeVec[i])
		{
			sameCnt++;
			result = (i - 4000);
		}

		if (sameCnt == 2)
		{
			break;
		}
	}

	return result;
}

//���� ���ϱ�
int Range(int n, vector<int> vec)
{
	int result = vec[n - 1] - vec[0];
	return result;
}

int main(void)
{
	FastIO;

	int N(0); // ���� ���� N, N�� Ȧ��
	std::cin >> N;

	vector<int> numVec(N, 0);
	for (int i = 0; i < N; i++)
	{
		std::cin >> numVec[i];
	}

	std::sort(numVec.begin(), numVec.end()); //�������� ����

	std::cout << Mean(N, numVec) << "\n" << Median(N, numVec) << "\n" 
		<< Mode(N, numVec) << "\n" << Range(N, numVec) << "\n";
	
	return 0;
}