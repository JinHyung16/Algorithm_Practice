#include<iostream>
#include<vector>
#include<stack>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Silver5 기술 연계마스터 임스 - 자료구조 알고리즘
/// SK와 LR은 연계 스킬이다.
/// 즉 S가 먼저 있어야 K 사용이 가능하고 L이 먼저 있어야 R이 가능하다.
/// 그러므로 두개의 stack을 만들어 하나는 SR 스킬용 하나는 LR 스킬용으로 사용한다.
/// string을 통해 입력을 받아 S와 L의 경우 선 스킬로 무조건 각 stack의 넣는다.
/// 그 후 K와 R이 나오면 해당 stack의 비어있는 유무를 판단하여 진행한다.
/// </summary>


int main(void)
{
	FastIO;
	
	int N = 0; // 총 기술 사용 횟수 N
	cin >> N;
	string skill;
	cin >> skill;

	stack<char> lrCombo;
	stack<char> skCombo;
	int skillUseCnt = 0;
	for ( int i = 0; i < skill.size(); i++ )
	{
		if ( skill[i] == 'L' )
		{
			lrCombo.push(skill[i]);
		}
		else if ( skill[i] == 'S' )
		{
			skCombo.push(skill[i]);
		}
		else if ( skill[i] == 'K' )
		{
			if ( !skCombo.empty() )
			{
				skillUseCnt++;
				skCombo.pop();
			}
			else
				break;
		}
		else if ( skill[i] == 'R' )
		{
			if ( !lrCombo.empty() )
			{
				skillUseCnt++;
				lrCombo.pop();
			}
			else
			{
				break;
			}
		}
		else
		{
			skillUseCnt++;
		}	
	}

	cout << skillUseCnt << "\n";
	return 0;
}