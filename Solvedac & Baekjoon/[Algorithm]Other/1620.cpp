#include<iostream>
#include<vector>
#include<string>
#include<map>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

/// <summary>
/// Silver4 ���¾� ���ϸ� ������ �̴ټ� - �ڷᱸ�� �˰���
/// map�� (key, value)�� ������ key���� ���� value�� ã���� ������. 
/// ���ϸ� �̸��� ������ key�� ����� ������ ���� ��ȣ�� ã�´�.
/// ���ϸ� ���� ��ȣ�� ������ ���� �̸����� �����س��� �迭�� ����� ��ȣ�� �־� �̸��� ����Ѵ�.
/// </summary>

using namespace std;

vector<string> bookString; //���� ��ȣ�� �־����� ���⼭ ���ϸ� �̸� ���
map<string, int> bookInt; //���ϸ� �̸��� �־����� �װ� key�� ���� ��ȣ ���

int main(void)
{
	FastIO;

	int N(0), M(0); //������ ��ϵ� ���ϸ� ��N, ���� ����� �ϴ� ������ ����M
	std::cin >> N >> M;
	string input; //���� ��ȣ�� ���ϸ� �̸� �� �� ���� �� �ְ�
	vector<string> result;

	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		bookString.push_back(input);
		bookInt.insert(make_pair(input, i + 1)); //���� ���� ������ 1�̹Ƿ�
	}
	
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		if (65 <= input[0] && input[0] <= 90)
		{
			//���ϸ� �̸��� �� �ձ��ڴ� �빮�� �̹Ƿ� �ƽ�Ű�� �빮�� A=60, Z=90�̴�.
			result.push_back(to_string(bookInt[input]));
		}
		else
		{
			//bookString�� ������ 0��° �̹Ƿ� ���� ��ȣ�� 1���̰� ����.
			int index = stoi(input) - 1;
			result.push_back(bookString[index]);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << "\n";
	}
	return 0;
}