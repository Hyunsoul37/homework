#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

class Airconditional
{
public:
	Airconditional() { }

	bool PowerCheck() const { return power; }		// 전원 ON / OFF 확인합니다.
	void SetPower() { power = !power; }				// 전원을 반대로 만듭니다.

	void SetDegree(int C) { degree = C; }
	int GetDegree() const { return degree; }		//출력만 하기에 const를 붙혔습니다.

	void DegreeControl()							//에어컨이 켜지면 일정 시간 뒤 온도가 내려가도록 했습니다.
	{
		bool power = PowerCheck();

		if (power == false)							//전원이 OFF면 작동하지 않습니다.
		{
			return;
		}

		while (1)
		{
			if (GetTickCount() % 10000 == 0)		//쓰는법은 잘모르나 검색해서 썼습니다.
			{
				system("cls");
				cout << "Now Degree : " << degree << endl;
				degree--;
			}
		}

	}


private:
	bool power = false;								//false면 OFF, true면 ON으로 설정 했습니다.
	int degree = 0;
	size_t Time = 0;								//시간 값인데 마이너스는 안나올꺼같아 size_t로 선언 했습니다.
};

int main()
{
	Airconditional air;

	air.SetDegree(20);								
	air.SetPower();
	air.DegreeControl();


	getchar();										//화이팅!
	return 0;
}