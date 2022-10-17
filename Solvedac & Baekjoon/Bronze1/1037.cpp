#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int divisor_count = 0; //약수 갯수
	int divisor = 0; //약수 입력받기
	vector<int> divisor_vector; //입력받은 약수(들) 저장 리스트
	int find_num = 0; //찾아야 할 수

	cin >> divisor_count;

	for (int i = 0; i < divisor_count; i++)
	{
		cin >> divisor;
		divisor_vector.push_back(divisor);
	}

	//제일 작은수와 제일 큰 수 찾는다
	//오름차순으로 sort하기
	sort(divisor_vector.begin(), divisor_vector.end());
	
	//divisor = (제일 작은 수) * (제일 큰 수) -> sort후 (맨앞 수) * (맨끝 수)
	find_num = divisor_vector[0]*divisor_vector[divisor_count-1];
	std::cout << find_num;
	 
	return 0;
}