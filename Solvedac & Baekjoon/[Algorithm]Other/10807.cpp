#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 ���� ���� - ���� �˰���
/// numVec�� �Է��� �޾Ƶΰ�, for���� ���鼭 v�� �������� ī�����Ѵ�.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0, v = 0; //N���� ������ �־��� ��, ���� v ���� ã��
	cin >> N;
	vector<int> numVec(N, 0);
	for ( int i = 0; i < N; i++ )
	{
		cin >> numVec[i];
	}
	cin >> v;

	int cnt = 0;
	for ( int i = 0; i < N; i++ )
	{
		if ( numVec[i] == v )
			cnt++;
	}

	cout << cnt << "\n";
	return 0;
}