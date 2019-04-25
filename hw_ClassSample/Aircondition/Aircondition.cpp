#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

class Airconditional
{
public:
	Airconditional() { }

	bool PowerCheck() const { return power; }		// ���� ON / OFF Ȯ���մϴ�.
	void SetPower() { power = !power; }				// ������ �ݴ�� ����ϴ�.

	void SetDegree(int C) { degree = C; }
	int GetDegree() const { return degree; }		//��¸� �ϱ⿡ const�� �������ϴ�.

	void DegreeControl()							//�������� ������ ���� �ð� �� �µ��� ���������� �߽��ϴ�.
	{
		bool power = PowerCheck();

		if (power == false)							//������ OFF�� �۵����� �ʽ��ϴ�.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 10000 == 0)		//���¹��� �߸𸣳� �˻��ؼ� ����ϴ�.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree--;
			}
		}

	}


private:
	bool power = false;								//false�� OFF, true�� ON���� ���� �߽��ϴ�.
	int degree = 0;
	size_t Time = 0;								//�ð� ���ε� ���̳ʽ��� �ȳ��ò����� size_t�� ���� �߽��ϴ�.
};

int main()
{
	Airconditional air;

	air.SetDegree(20);								
	air.SetPower();
	air.DegreeControl();


	getchar();										//ȭ����!
	return 0;
}