#include<iostream>
#include<vector>

#define FastIO ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;

/// <summary>
/// Bronze5 ������ - ���� �˰���
/// ������ �־��� ���Ǵ�� ����Ѵ�.
/// </summary>

int main(void)
{
	FastIO;
	
	int A = 0, B = 0, C = 0; //�Է¹��� �� �� A, B, C
	std::cin >> A >> B >> C;
	
	std::cout << (A + B) % C << "\n";
	std::cout << ((A % C) + (B % C)) % C << "\n";
	std::cout << (A * B) % C << "\n";
	std::cout << ((A % C) * (B % C)) % C << "\n";

	return 0;
}