#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 �Ѽ� - ���Ʈ���� �˰���
/// 1���� N���� �� �ڸ��� ���� �� 1�� �ڸ� ���ڷ� �ٲ� ��, ���̸� �̿��� ������ ���Ѵ�.
/// N�� 100 �̸��̸� �Ѽ��� �ش� N��ŭ �ִ°Ŵ� N�� 100 �̻��϶��� ���ؼ� �����Ѵ�.
/// 
/// N�� 100 �̸��̸� ����� N�� ���� �״�� �Ѵ�.
/// N�� 100 �̻��� �� 2�� for���� ���� 100���� N���� �ݺ��ϸ鼭
/// ���� for������ �ٱ��� for���� ���� ���� string���� �ٲ� �ش� ���̸�ŭ ���鼭 �Ѽ� ������ �����ϴ��� �ƴ��� �Ǵ���
/// �����Ѵٸ� result�� ������Ű�鼭 ����.
/// 
/// �̶� result�� 99�� �ʱ�ȭ �صδµ�, ������ N�� 100 �̸��϶� �Ѽ��� �ִ� ������ 99�̱� �����̴�.
/// </summary>

using namespace std;

int main(void)
{
	FastIO;
	
	string input;
	std::cin >> input;

	int n = std::stoi(input);

	int result = 99;
	for(int i = 100; i <= n; i++)
	{
		string temp = std::to_string(i);
		bool isHanso = true;
		for(int j = 1; j < temp.size() - 1; j++)
		{
			if(temp[j] - temp[j-1] != temp[j+1] - temp[j])
			{
				isHanso = false;
			}
		}
		if(isHanso)
		{
			result ++;
		}
	}

	if(n < 100)
	{
		std::cout << n << "\n";
		return 0;
	}
	std::cout << result << "\n";
	return 0;
}