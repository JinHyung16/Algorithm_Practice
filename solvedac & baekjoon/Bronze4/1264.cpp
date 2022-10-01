#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char c[256];
	int count(0);
	while (true)
	{
		cin.getline(c, 256);
		if (c[0] == '#')
		{
			break;
		}

		for (unsigned int i = 0; i < strlen(c) - 1; i++)
		{
			if (c[i] == 'a' || c[i] == 'A')
			{
				count++;
			}
			if (c[i] == 'i' || c[i] == 'I')
			{
				count++;
			}
			if (c[i] == 'e' || c[i] == 'E')
			{
				count++;
			}
			if (c[i] == 'o' || c[i] == 'O')
			{
				count++;
			}
			if (c[i] == 'u' || c[i] == 'U')
			{
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
	}
	return 0;
}