#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/// <summary>
/// Silver4 올바른 배열 - 정렬 알고리즘
/// </summary>

int main(void)
{
	int continuous_count = 5; //옳바른 배열이기 위해 필요한 연속된 수

	int index_count = 0;
	int number = 0;
	vector<int> number_list;

	cin >> index_count;
	for (int i = 0; i < index_count; i++)
	{
		cin >> number;
		number_list.push_back(number);
	}

	//오름차순
	sort(number_list.begin(), number_list.end());

	
	int temp = 1;
	for (int i = 0; i < number_list.size(); i++)
	{
		int count = 1; //본인 기준부터 counting

		//i번째 기준 옳바른 배열이 되는 기준 개수만큼 돌리기
		for (int j = 1; j < number_list.size(); j++)
		{
			//앞 뒤 수의 차이보고 조건이 맞은경우 count 돌리기
			if (0 < (number_list[j] - number_list[i]) && (number_list[j] - number_list[i]) < 5)
			{
				count++;
			}
		}
		temp = std::max(temp, count);
	}

	if (temp > 5)
	{
		cout << 0;
	}
	else
	{
		cout << continuous_count - temp;
	}
	

	return 0;
}