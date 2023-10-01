#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 ���ͺб��� - ���� �˰���
/// ���� ��� / (�Ǹ� ��� - ���� ���) + 1 �ϸ� �ȴ�.
/// ���� ���� ����� �Ǹ� ���ݺ��� ���ų� ũ�� -1�� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

    int fixed_money, other_money, sell_money; //���� ���, ���� ���, ��Ʈ�� �Ǹ� ����
    int count = 1;

    cin >> fixed_money >> other_money >> sell_money;

    //������ = �Ǹź�� - �������
    //����� ���� ��뺸�� �������� 1���̶� ���ƾ� ���� ���ؾ���
    if ( sell_money <= other_money )
    {
        cout << -1;
        return 0;
    }

    cout << fixed_money / (sell_money - other_money) + 1;

	return 0;
}	