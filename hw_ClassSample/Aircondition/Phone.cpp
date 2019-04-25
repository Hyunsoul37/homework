#include <iostream>
using namespace std;
class Phone
{
public:
	Phone(const char * Maker, const char * Moduler, const char * Color)
		: m_pMaker(Maker), m_pModuler(Moduler), m_nColor(Color)	{ }

	~Phone()
	{
		m_nColor   = nullptr;
		m_pMaker   = nullptr;
		m_pModuler = nullptr;

		delete m_nColor;
		delete m_pMaker;
		delete m_pModuler;
	}

	void Info() const
	{
		cout << "Maker : " << m_pMaker << endl;
		cout << "Moduler : " << m_pModuler << endl;
		cout << "Color : " << m_nColor << endl;
		cout << "Power : " << m_nPower << endl;

		cout << endl;
	}
	
	void SetPower()	{ m_nPower = !m_nPower;	}

	
private:
	bool m_nPower = false;
	const char * m_nColor = nullptr;
	const char * m_pMaker = nullptr;
	const char * m_pModuler = nullptr;
	
};

int main()
{
	Phone phone ("Apple", "iPhone X", "Black");
	Phone phone1 ("Samsung", "galaxy S10", "White");

	phone.Info();
	phone1.Info();

	phone.SetPower();

	phone.Info();
	phone1.Info();

	getchar();
	return 0;
}