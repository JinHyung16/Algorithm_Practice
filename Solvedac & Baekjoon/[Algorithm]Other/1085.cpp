#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze3 ���簢������ Ż�� - ���� �˰���
/// (0,0)���� (w,h)���� ���簢���� �׸��� ���δ� w, ���δ� h��.
/// ������ ��ġ (x,y)���� �� ���簢�� ���� ���������� ���� �׸��� ���� ª�� ���̸� ã���� �ȴ�.
/// 1)x ��
/// 2)y ��
/// 3)h-y��
/// 4)w-x��
/// �̷��� 4���� �ּڰ��� ã�´�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int x(0), y(0), w(0), h(0);
	std::cin >> x >> y >> w >> h;

	int widthMin = std::min(x, w - x);
	int heightMin = std::min(y, h - y);

	int result = std::min(widthMin, heightMin);
	std::cout << result << "\n";
	return 0;
}