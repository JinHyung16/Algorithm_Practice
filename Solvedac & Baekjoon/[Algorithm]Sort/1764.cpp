#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �躸�� - ���� �˰���
/// ó���� �赵 ���� ������ ���� ���� ������� �迭�� ���� �־� ���ߴ��� Ʋ�ȴ�.
/// �̿� �赵 ���� ����� �ְ� �� �� ���� ���� ����� ������ �ִ��� �Ǻ��ϴ� ������� �����ߴ�.
/// ������ vector�� �̿��� find�Լ��� üũ�ϴٺ��� �ð��ʰ��� ���Դ�.
/// ���⼭ �ذ���� binary search�� �̿��� �����ϰų�
/// stl�� map�� ����ϴ°��ε�, ���� binary search�� �̿��ߴ�. �׷��� binary search�� ������ �ʼ���.
/// </summary>

using namespace std;

vector<string> noListen;

int main(void)
{
	FastIO;
	
	int N(0), M(0); //�赵 ���� �� N, ���� ���� �� M
	int noLookListendCnt(0); //�赵 ���� ���� ����
	vector<string> result;

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		std::cin >> input;
		noListen.push_back(input);
	}

	std::sort(noListen.begin(), noListen.end());
	for (int i = 0; i < M; i++)
	{
		string input;
		std::cin >> input;
		if (binary_search(noListen.begin(), noListen.end(), input))
		{
			result.push_back(input);
			noLookListendCnt++;
		}
	}

	std::sort(result.begin(), result.end());
	std::cout << noLookListendCnt << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}