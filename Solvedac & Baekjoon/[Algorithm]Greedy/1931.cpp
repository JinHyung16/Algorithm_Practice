#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver1 ȸ�ǽ� ���� - Greedy �˰���
/// ����� �� �ִ� ȸ���� ���� ���������� �ᱹ ������ �ð��� �������� �ݴ�� ä�������� �ȴ�.
/// �� ȸ�� �ð��� {start, end}������ �־��ٸ� �������� ������
/// {end, start}�� �־��ٸ� �������� ������ �Ͽ� ������ �ð��� �������� ������ �ǰ� �ٲ۴�.
/// 
/// Ʋ�ȴ� ����)�� ���� �ݷ�
/// �� ó�� ȸ�ǿ� ���ؼ� �ѹ� �� ����� �ȴ�.
/// N=5 -> {2,2}, {3,2}, {4,2}, {5,1}, {1,7} ������ 5�� ���´�.
/// ������ {5,1} -> {2,2} -> {3,2} -> {4,2} �̷��� �����ϹǷ� 4�� ���;��Ѵ�.
/// </summary>

using namespace std;

vector<pair<int, int>> meetingSchedule;

bool CompareEndTime(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void)
{
	FastIO;
	
	int N(0); //ȸ���� ��
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		std::cin >> start >> end;
		meetingSchedule.push_back(make_pair(start, end));
	}

	std::sort(meetingSchedule.begin(), meetingSchedule.end(), CompareEndTime);

	int time = meetingSchedule[0].second; //���� �ð��� ���� ���� ȸ�Ǹ� ��´�.
	int meetingCnt(1);

	//Ʋ�ȴ� ����) for�� ������ 0���� ���� �� �������� �����.
	for (int i = 1; i < N; i++)
	{
		if (time <= meetingSchedule[i].first)
		{
			//�ι�° ȸ���� ���� �ð��� ù ��° ȸ���� ����������� ũ�ų� ���ٸ�
			time = meetingSchedule[i].second;
			meetingCnt += 1;
		}
	}

	std::cout << meetingCnt << "\n";
	return 0;
}