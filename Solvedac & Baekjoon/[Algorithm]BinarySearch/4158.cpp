#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver5 CD - �̺� Ž�� �˰���
/// �� ����� CD ��ȣ�� ���ؼ� ��ü�������� ���Ͽ� ����� ����Ѵ�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;

	while ( true )
	{
		int N = 0, M = 0; //������� CD �� N, �������� CD �� M
		vector<int> nVec, mVec;
		int nCnt = 0, mCnt = 0, result = 0;
		int input = 0;

		std::cin >> N >> M;
		if ( N == 0 && M == 0 )
		{
			break;
		}

		for ( int i = 0; i < N; i++ )
		{
			std::cin >> input;
			nVec.push_back(input);
		}

		for ( int i = 0; i < M; i++ )
		{
			std::cin >> input;
			mVec.push_back(input);
		}

		while ( true )
		{
			if ( nCnt == nVec.size() || mCnt == mVec.size() )
			{
				break;
			}
			else if ( nVec[nCnt] < mVec[mCnt] )
			{
				nCnt++;
			}
			else if ( mVec[mCnt] < nVec[nCnt] )
			{
				mCnt++;
			}
			else
			{
				nCnt++;
				mCnt++;
				result++;
			}
		}	
		std::cout << result << "\n";
	}

	return 0;
}