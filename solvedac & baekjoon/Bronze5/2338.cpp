#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

// �տ� 0�� ���� ���ڵ� �� ���� ex) 01 -> 1�� ������
string GetNonZeroFront(string s)
{
	unsigned int nonZeroIndex = s.size();

	for (unsigned int i = 0; i < nonZeroIndex; i++)
	{
		if (s[i] != '0')
		{
			nonZeroIndex = i;

			break;
		}
	}

	if (nonZeroIndex == s.size())
	{
		return "0";
	}

	return s.substr(nonZeroIndex);
}

// ���� ���� �� ū�� ������ �Ǵ�
bool ComparisonBigNum(string a, string b)
{
	if (a.size() != b.size())
	{
		return a.size() > b.size();
	}

	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}

		return a[i] > b[i];
	}
	return false;
}

string Add(string a, string b)
{
	string add(max(a.size(), b.size()), '0');

	bool carry = false;

	for (unsigned int i = 0; i < add.size(); i++)
	{
		int temp = carry;
		carry = false;

		if (i < a.size())
		{
			temp += a[a.size() - i - 1] - '0';
		}

		if (i < b.size())
		{
			temp += b[b.size() - i - 1] - '0';
		}

		if (temp >= 10)
		{
			carry = true;
			temp -= 10;
		}

		add[add.size() - i - 1] = temp + '0';
	}

	// �� ����� �� �������� ĳ���� �ִٸ� �ڸ��� �ϳ� �� �ø���
	if (carry)
	{
		add.insert(add.begin(), '1');
	}

	return GetNonZeroFront(add);
}

string Subtract(string a, string b)
{
	if (ComparisonBigNum(a, b) == false)
	{
		swap(a, b);
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string sub = a;

	int carry = 0;

	for (unsigned int i = 0; i < sub.size(); i++)
	{
		int tempCarry = carry;
		carry = 0;

		// if carry
		int temp = (a[i] - '0') - tempCarry;

		// if signed number, have a carry
		if (temp < 0)
		{
			carry = 1;
			temp += 10;
		}

		if (i < b.size())
		{
			temp -= (b[i] - '0');

			if (temp < 0)
			{
				carry = 1;
				temp += 10;
			}
		}

		sub[i] = temp + '0';
	}

	// if carry, last number - 1
	if (carry)
	{
		int lastDigit = sub[sub.size() - 1];
		lastDigit--;

		sub[sub.size() - 1] = lastDigit + '0';
	}

	reverse(sub.begin(), sub.end());

	return GetNonZeroFront(sub);
}

string Multiply(string a, string b)
{
	string multi = "0";

	for (unsigned int i = 0; i < b.size(); i++)
	{
		string line(a);
		int carry = 0;
		
		for (int j = a.size() - 1; j >= 0; j--)
		{
			int temp = carry;
			carry = 0;

			temp += (a[j] - '0') * (b[b.size() - (i + 1)] - '0');

			if (temp >= 10)
			{
				carry = temp / 10;
				temp %= 10;
			}

			line[j] = temp + '0';
		}

		if (carry > 0)
		{
			line.insert(line.begin(), carry + '0');
		}

		// ���� ������ ���� �ڿ� 0�� ���̴� ������ �����.
		line += string(i, '0');

		multi = Add(multi, line);
	}

	return GetNonZeroFront(multi);
}

int main()
{
	string a, b;
	
	cin >> a >> b;

	int aNum = a[0] != '-';
	int bNum = b[0] != '-';

	if (aNum && bNum) // �Ѵ� ����ΰ��
	{
		cout << Add(a, b) << "\n";

		if (ComparisonBigNum(a, b) == false && a != b)
		{
			cout << "-";
		}
		cout << Subtract(a, b) << "\n";

		cout << Multiply(a, b) << "\n";
	}
	else if (aNum == false && bNum == false) // �Ѵ� �����ΰ��
	{
		cout << "-" << Add(a.substr(1), b.substr(1)) << "\n";

		if (ComparisonBigNum(a.substr(1), b.substr(1)))
		{
			cout << "-";
		}
		cout << Subtract(a.substr(1), b.substr(1)) << "\n";

		cout << Multiply(a.substr(1), b.substr(1)) << "\n";
	}
	else if (aNum && bNum == false) // ���, ������ ���
	{
		// ���� ����
		string temp = Subtract(a, b.substr(1));

		if (ComparisonBigNum(a, b.substr(1)) || temp == "0")
		{
			cout << temp << "\n";
		}
		else
		{
			cout << "-" << temp << "\n";
		}

		// ���� ����
		cout << Add(a, b.substr(1)) << "\n";
		
		// ���� ����
		cout << "-" << Multiply(a, b.substr(1)) << "\n";
		
	}
	else if (aNum == false && bNum) // ����, ����� ���
	{
		// ���� ����
		string temp = Subtract(a.substr(1), b);

		if (ComparisonBigNum(a.substr(1), b) && temp != "0")
		{
			cout << "-" << temp << "\n";
		}
		else
		{
			cout << temp << "\n";
		}

		// ���� ����
		cout << "-" << Add(a.substr(1), b) << "\n";

		// ���� ����
		cout << "-" << Multiply(a.substr(1), b) << "\n";
	}

	return 0;
} 
