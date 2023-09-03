#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 �Ҹ����� - �ڷᱸ�� �˰���
/// map�� �̿��� �ش� string�� key������ value �� �Է¹��� ������ŭ ������Ų��.
/// �� �� 5���ΰ� �ϳ��� �ִٸ� YES�� �ƴϸ� NO�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	int N = 0; //������ ī���� ���� N
	std::cin >> N;

	map<string, int> fruit;
	
	for ( int i = 0; i < N; i++ )
	{
		//���� ������ ��Ÿ���� ���ڿ� S�� ������ ���� ���� ���� X
		string S = " ";
		int X = 0;
		std::cin >> S >> X;
		fruit[S] += X;
	}

	if ( fruit["STRAWBERRY"] == 5 || fruit["BANANA"] == 5 || fruit["LIME"] == 5 || fruit["PLUM"] == 5 )
	{
		std::cout << "YES" << "\n";
		return 0;
	}

	std::cout << "NO" << "\n";
	return 0;
}