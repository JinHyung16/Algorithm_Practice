#include<iostream>
#include<vector>
#include<algorithm>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze1 팀 이름 정하기 - 정렬 알고리즘
/// vector<pair<int,string>> 을 통해 이길 확률과 팀명을 저장받는다.
/// 그 후 LOVE를 개수를 연두 이름과 팀명을 받아 카운팅 한다.
/// 그리고 카운팅 된 값을 기준으로 확률을 연산하여 pair의 first값에 해당 팀명에 맞춰 저장한다
/// 그리고 fill(arr, arr+n, 0)을 통해 love를 카운팅한 배열을 초기화 하고
/// 다음 팀명과 연두 이름을 넣어 계산한다.
/// </summary>

int loveArry[4] = { 0, }; // 순서대로 LOVE 개수

void CountLove(string name, string teamName)
{
	for (int i = 0; i < name.size(); i++)
	{
		switch (name[i])
		{
		case 'L':
			loveArry[0]++;
			break;
		case 'O':
			loveArry[1]++;
			break;
		case 'V':
			loveArry[2]++;
			break;
		case 'E':
			loveArry[3]++;
			break;
		}
	}

	for (int i = 0; i < teamName.size(); i++)
	{
		switch (teamName[i])
		{
		case 'L':
			loveArry[0]++;
			break;
		case 'O':
			loveArry[1]++;
			break;
		case 'V':
			loveArry[2]++;
			break;
		case 'E':
			loveArry[3]++;
			break;
		}
	}
}

int CalWinPercent()
{
	return (loveArry[0] + loveArry[1]) * (loveArry[0] + loveArry[2]) * (loveArry[0] + loveArry[3]) * (loveArry[1] + loveArry[2]) * (loveArry[1] + loveArry[3]) * (loveArry[2] + loveArry[3]) % 100;
}


bool Compare(const pair<int, string>& a, const pair<int, string>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}


int main(void)
{
	FastIO;
	
	int N = 0; // 팀 이름 후보 N개
	string name;

	cin >> name;
	cin >> N;
	vector<pair<int, string>> team;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		team.push_back(make_pair(-1, input));
	}

	for (int i = 0; i < N; i++)
	{
		CountLove(name, team[i].second);
		team[i].first = CalWinPercent();
		fill(loveArry, loveArry + 4, 0);
	}

	sort(team.begin(), team.end(), Compare);
	cout << team[0].second << "\n";
	return 0;
}