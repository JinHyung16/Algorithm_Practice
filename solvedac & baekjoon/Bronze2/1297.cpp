#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int rd(0), w(0), h(0); // ���� �밢��, ���� ����, ���� ����
	cin >> rd >> w >> h;

	// d : rd = w : rw
	// d : rd = h : rh
	// ��ʽ��� ����� ������ ���� ������ ���� ���ٸ� �̿�
	double d = sqrt(w * w + h * h); // ��Ÿ����� ���� �밢�� ���ϴ� ��
	double rw = (rd * w) / d; // ���� ���� ���ϴ� ��
	double rh = (rd * h) / d; // ���� ���� ���ϴ� ��

	cout << (int)rw << " " << (int)rh;
	return 0;
}