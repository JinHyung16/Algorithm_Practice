#include<iostream>
#include<algorithm>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Bronze2 손익분기점 - 수학 알고리즘
/// 고정 비용 / (판매 비용 - 가변 비용) + 1 하면 된다.
/// 만약 가변 비용이 판매 가격보다 같거나 크면 -1을 출력한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

    int fixed_money, other_money, sell_money; //고정 비용, 가변 비용, 노트북 판매 가격
    int count = 1;

    cin >> fixed_money >> other_money >> sell_money;

    //순이익 = 판매비용 - 가변비용
    //결론은 고정 비용보다 순이익이 1원이라도 높아야 함을 구해야함
    if ( sell_money <= other_money )
    {
        cout << -1;
        return 0;
    }

    cout << fixed_money / (sell_money - other_money) + 1;

	return 0;
}	