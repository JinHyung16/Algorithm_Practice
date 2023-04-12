#include<iostream>
#include<vector>
#include<queue>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver3 패션왕 신해빈 - 수학 알고리즘
/// 
/// 주어진 옷 종류를 보고 '상의, 하의, 모자류, 안경류 등'으로 분리한다.
/// 입력이 '옷의 이름 + 옷 종류'로 들어오므로, 각 옷 종류의 개수 + 1을 한다음 서로 다른 종류끼리 곱하고 -1 한다.
/// 즉 headgear -> hat과 turban, eyewear -> sunglasses가 있으니 (headgear류 개수 + 1) * (eyewear류 개수 + 1) - 1한다.
/// -1하는 이유는 headgear류와 eyewear류 둘 다 안입는 경우를 의미한다.
/// 
/// vector를 이용할 경우 중복된 경우에 대해선 개수만 증가 시켜야한다.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	int T(0), N(0); //test case T, 가진 의상의 수 N
	string clothName, cloth;
	vector<pair<string, int>> clothVec;
	int combinationCnt(0);

	std::cin >> T;
	while (T--)
	{
		std::cin >> N;
		combinationCnt = 1;

		for (int i = 0; i < N; i++)
		{
			std::cin >> clothName >> cloth;

			//맨 처음만 저장하고 바로 패스
			if (i == 0)
			{
				clothVec.push_back({ cloth, 1 });
				continue; //아래 for문 생략
			}

			for (int j = 0; j < clothVec.size(); j++)
			{
				if (clothVec[j].first == cloth)
				{
					clothVec[j].second ++;
					break;
				}

				//만약 같지 않다면, clothVec.size() -1 값과 j가 같을 것이다. 왜냐면 위에 if문이 실행 안되었기 때문
				if (j == clothVec.size() - 1)
				{
					clothVec.push_back({ cloth, 0 });
				}
			}	
		}
		for (int i = 0; i < clothVec.size(); i++)
		{
			combinationCnt *= (clothVec[i].second + 1);
		}

		//마지막에 둘 다 안입는 경우 빼주기
		std::cout << combinationCnt - 1 << "\n";
		clothVec.clear();
	}
	return 0;
}