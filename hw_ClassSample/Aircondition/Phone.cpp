#include <iostream>
#include <vld.h>
using namespace std;
class Phone
{
public:
	Phone(const char * Maker, const char * Moduler, const char * Color)
		: m_pMaker(Maker), m_pModuler(Moduler), m_nColor(Color)	{ }			//생성할때 모든정보를 저장합니다.

	~Phone()												//포인터 값 초기화 및 할당시 free시켜줍니다.
	{
		m_nColor   = nullptr;
		m_pMaker   = nullptr;
		m_pModuler = nullptr;

		delete m_nColor;
		delete m_pMaker;
		delete m_pModuler;
	}

	void Info() const										//출력만 하는 함수라 const 붙혔습니다.
	{														//정보를 출력해 줍니다.
		cout << "Maker : " << m_pMaker << endl;
		cout << "Moduler : " << m_pModuler << endl;
		cout << "Color : " << m_nColor << endl;
		cout << "Power : " << m_nPower << endl;

		cout << endl;
	}
	
	void SetPower()	{ m_nPower = !m_nPower;	}				//power를 반대로 만들어 주는 함수입니다.

	
private:
	bool m_nPower = false;									//기본으로 OFF되어있고 true는 ON입니다.
	const char * m_nColor = nullptr;
	const char * m_pMaker = nullptr;
	const char * m_pModuler = nullptr;
	
};

int main()
{
	Phone phone ("Apple", "iPhone X", "Black");				//아이폰 짱짱 아이폰 쓰세여
	Phone phone1 ("Samsung", "galaxy S10", "White");

	phone.Info();
	phone1.Info();

	phone.SetPower();

	phone.Info();
	phone1.Info();

	getchar();												//화이팅
	return 0;
}