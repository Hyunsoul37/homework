#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

class Airconditional
{
public:
	Airconditional() { }

	bool PowerCheck() const { return power; }
	void SetPower() { power = !power; }

	void SetDegree(int C) { degree = C; }
	int GetDegree() const { return degree; }

	void DegreeControl()
	{
		bool power = PowerCheck();

		if (power == false)
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 10000 == 0)
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree--;
			}
		}

	}


private:
	bool power = false;
	int degree = 0;
	size_t Time = 0;
};

int main()
{
	Airconditional air;

	air.SetDegree(20);
	air.SetPower();
	air.DegreeControl();


	getchar();
	return 0;
}