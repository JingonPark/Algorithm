#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
2016��
*/
string Day(int a, int b) {
	
	string answer = "";
	int monthMaxDay[12] = { 31,     29,    31,    30,    31,    30,      31,    31,    30,     31,    30,   31 };
	//string firstDay[12] = { "FRI", "MON", "TUE", "FRI", "SUN", "WED", "FRI", "MON", "THU",  "SAT", "WED", "THU" };
	int firstDay[12] = { 4, 0, 1, 4,  6, 2, 4, 0, 3, 5, 1, 3 };

	int finalDay = firstDay[a - 1] + b-1;


	if (finalDay > 7)
	{
		finalDay = finalDay % 7;
	}
	
	switch (finalDay)
	{
	case 0:
		answer = "MON";
		break;
	case 1:
		answer = "TUE";
		break;
	case 2:
		answer = "WED";
		break;
	case 3:
		answer = "THU";
		break;
	case 4:
		answer = "FRI";
		break;
	case 5:
		answer = "SAT";
		break;
	case 6:
		answer = "SUN";
		break;
	}

	cout << answer << endl;

	return answer;
}

/*
���� ���ڴ� �Ⱦ�
*/
vector<int> solution2(vector<int> arr)
{
	vector<int> answer;
	int preNum = -1;

	for (int num : arr)
	{
		if (preNum != num)
		{
			answer.emplace_back(num);
			preNum = num;
		}
	}

	return answer;
}

/*
�� ���� ������ ��
*/
long long solution3(int a, int b) 
{
	long long answer = 0;
	int midNum = 0;

	if (a == b)
	{
		answer = a;
	}
	else
	{
		if (a < b)
		{
			for (int i = a; i <= b; ++i)
			{
				answer += i;
			}
		}
		else
		{
			for (int i = b; i <= a; ++i)
			{
				answer += i;
			}
		}
	}

	return answer;
}

/*
���ڿ� �� p�� y�� ����
*/
size_t findString(char pFindChar, string s)
{
	size_t findPos = 0;
	size_t count = 0;
	while (findPos != s.npos)
	{
		if ((findPos = s.find(pFindChar, findPos)) != s.npos)
		{
			++count;
			findPos += 1;
		}
	}
	return count;
}

bool solution4(string s)
{
	bool answer = true;

	size_t pCount = 0;
	size_t yCount = 0;

	pCount += findString('p', s);
	pCount += findString('P', s);
	yCount += findString('y', s);
	yCount += findString('Y', s);

	if (pCount == 0 && yCount == 0)
	{
		return true;
	}
	else if (pCount == yCount)
	{
		return true;
	}
	else if (pCount != yCount)
	{
		return false;
	}

	return answer;
}

/*
���ڿ� �ٷ�� �⺻
*/
bool solution5(string s) {
	
	bool answer = true;

	if (s.length() != 4 && s.length() != 6)
	{
		return false;
	}

	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
		//	size_t tmep = s[i];
			answer = true;
		//	cout << tmep << endl;
		}
		else
		{
			answer = false;
			return answer;
		}
	}

	return answer;
}

/*
�Ҽ� ã��
*/
int solution6(int n) {

	int answer = 0;
	bool bPrime = true;

	for (size_t i = 2; i <= n; ++i)
	{
		if (i == 2)
		{
			bPrime = true;
		}
		else if (i > 2)
		{
			if (i % 2 == 0)
			{
				bPrime = false;
				continue;
			}
			else
			{
				bPrime = true;
				for (size_t j = 3; j*j <= i; )
				{
					if (i % j == 0)
					{
						bPrime = false;
						break;
					}
					else
					{
						bPrime = true;
					}
					j += 2;
				}
			}
		}

		if (bPrime)
		{
			++answer;
		}
	}

	return answer;
}


void main()
{
	//bool  a = solution5("a234");
	//cout << a << endl;
	cout << solution6(15) << endl;
}