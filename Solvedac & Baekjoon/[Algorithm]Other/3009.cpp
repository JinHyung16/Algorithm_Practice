#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze3 �� ��° �� - ���� �˰���
/// ���簢���� �� ��° ���� ��ǥ�� ���Ϸ���
/// �־��� 3���� ��ǥ���� x�� y���� ���Ͽ� ������ 2�� ���Դٸ�
/// ���� ��ǥ�� �ش� �� ��° ��ǥ�� �Ǿ�� �Ѵ�.
/// </summary>


int main(void)
{
	FastIO;

	int arrX[3] = { 0, };
	int arrY[3] = { 0, };

	int x = 0, y = 0;
	for ( int i = 0; i < 3; i++ )
	{
		cin >> arrX[i] >> arrY[i];
	}

	if ( arrX[0] == arrX[1] )
		x = arrX[2];
	else if ( arrX[1] == arrX[2] )
		x = arrX[0];
	else
		x = arrX[1];

	if ( arrY[0] == arrY[1] )
		y = arrY[2];
	else if ( arrY[1] == arrY[2] )
		y = arrY[0];
	else
		y = arrY[1];

	cout << x << " " << y << "\n";
	return 0;
}