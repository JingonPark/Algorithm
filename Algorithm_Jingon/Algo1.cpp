#include <iostream>
#include <string>
#include <vector>
using namespace std;

void main()
{
	int N = 0;
	cin >> N;
	int num = N;
	
	int result[20];
	int ilengthtemp = 0;
	for (int i = 0; 0 < num; i++)
	{
		result[i] = num % 2;
		num = num / 2;
		ilengthtemp++;
	}
	ilengthtemp--;

	for (int i = ilengthtemp; i >= 0; i--)
	{
		cout << result[i];
	}
	cout << endl;

	vector<int> vecTemp;

	while (ilengthtemp >= 0)
	{
		vecTemp.push_back(result[ilengthtemp]);
		ilengthtemp--;
	}

	int ivecTempLength = vecTemp.size();
	int iCount = 0;
	int iCountTemp = 0;
	bool bCountStart = false;

	for (auto iter = vecTemp.begin(); iter != vecTemp.end(); )
	{
		if (*iter == 0 && bCountStart == false)
		{
			//iter = vecTemp.erase(iter);
			++iter;
			continue;
		}
		else if (*iter == 1 && bCountStart == false)
		{
			bCountStart = true;
			iter++;
			continue;
		}

		if (*iter == 0 && bCountStart == true)
		{
			iCount++;
		}
		else if (*iter == 1 && bCountStart == true)
		{
			if (iCount > 0) //ī������ �ϰ��ִ� ���߿� 1�� ������
			{
				if (iCount > iCountTemp)//������ ī�����Ѱͺ��� �� ������
				{
					iCountTemp = iCount;
					iCount = 0;
					//ī�����ϴ��� �����ϰ� �ʱ�ȭ
				}
			}
			//ī�����ϴ����� �ƴϸ� �׳ɳѾ

		}
		iter++;
	}

	cout << iCountTemp << endl;




	system("pause");
	return;
}

