#include<iostream>
//#include<windows.h>
//#define POLYDROME;//Полиндром
#define CALCULATOR ; //Калькулятор
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef POLYDROME
	
	int Polindrom =0, Temp = 0;
	cout << "введите число для проверки\n"; cin >> Polindrom;
	int PolindromCopy = Polindrom;
	while(Polindrom)//смысл цикла надо разобрать число начиная с последней цифпы и заного собрать
	{
		int Buffer = Polindrom % 10;//получаем послденее число
		Temp = Temp * 10 + Buffer;// берем число умнажаем на 10 и прибовляем последнее число- первое число 0
		Polindrom = Polindrom / 10;// убераем последниее число из основной
	}
	if (PolindromCopy == Temp)cout << "Число является пондромом\t" << Temp << endl;
	else cout << "Число не является пондромом\t" << PolindromCopy <<" - " << Temp << endl;
#endif	//POLYDROME

#ifdef CALCULATOR
	char Key=' ';
	double NumberA = 0, NumberB = 0 ;
	do
	{
		
			system("cls");
		cout << R"(
Используйте действия по образцу:
Сложение:                    А+В
Вычитание:                   А-В
Умножение:                   А*В
Деление:                     А/В
)";
		cin >> NumberA >> Key >> NumberB;
			while (cin.fail())
			{
				system("cls");
				cout << R"(
Используйте действия по образцу:
Сложение:                    А+В
Вычитание:                   А-В
Умножение:                   А*В
Деление:                     А/В
)";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//cin.ignore(1000,'\n');
		cin >> NumberA >> Key >> NumberB;
			}
		
		//можно загнать в switch...case
		if (Key == '+')cout << "Результат равен " << NumberA + NumberB << endl;
		else if (Key == '-')cout << "Результат равен " << NumberA - NumberB << endl;
		else if (Key == '*')cout << "Результат равен " << NumberA * NumberB << endl;
		else if (Key == '/') 
		{
			if (NumberB == 0)cout << "\x1b[31mНа ноль делить нельзя, формула \"A/0 = 0*B=A\" \x1b[0m\n";
			else cout << "Результат равен " << NumberA / NumberB << endl;
		}
		cout << "Продолжить вычисление Введите (Y/N),(Д/Н) "; cin >> Key;
	} while (Key == 'Y' || Key == 'y' || Key == 'Д' || Key == 'д');
#endif //CALCULATOR
}