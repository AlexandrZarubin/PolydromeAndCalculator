#include<iostream>
//#include<windows.h>
//#define POLYDROME;//���������
#define CALCULATOR ; //�����������
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef POLYDROME
	
	int Polindrom =0, Temp = 0;
	cout << "������� ����� ��� ��������\n"; cin >> Polindrom;
	int PolindromCopy = Polindrom;
	while(Polindrom)//����� ����� ���� ��������� ����� ������� � ��������� ����� � ������ �������
	{
		int Buffer = Polindrom % 10;//�������� ��������� �����
		Temp = Temp * 10 + Buffer;// ����� ����� �������� �� 10 � ���������� ��������� �����- ������ ����� 0
		Polindrom = Polindrom / 10;// ������� ���������� ����� �� ��������
	}
	if (PolindromCopy == Temp)cout << "����� �������� ���������\t" << Temp << endl;
	else cout << "����� �� �������� ���������\t" << PolindromCopy <<" - " << Temp << endl;
#endif	//POLYDROME

#ifdef CALCULATOR
	char Key=' ';
	double NumberA = 0, NumberB = 0 ;
	do
	{
		
			system("cls");
		cout << R"(
����������� �������� �� �������:
��������:                    �+�
���������:                   �-�
���������:                   �*�
�������:                     �/�
)";
		cin >> NumberA >> Key >> NumberB;
			while (cin.fail())
			{
				system("cls");
				cout << R"(
����������� �������� �� �������:
��������:                    �+�
���������:                   �-�
���������:                   �*�
�������:                     �/�
)";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//cin.ignore(1000,'\n');
		cin >> NumberA >> Key >> NumberB;
			}
		
		//����� ������� � switch...case
		if (Key == '+')cout << "��������� ����� " << NumberA + NumberB << endl;
		else if (Key == '-')cout << "��������� ����� " << NumberA - NumberB << endl;
		else if (Key == '*')cout << "��������� ����� " << NumberA * NumberB << endl;
		else if (Key == '/') 
		{
			if (NumberB == 0)cout << "\x1b[31m�� ���� ������ ������, ������� \"A/0 = 0*B=A\" \x1b[0m\n";
			else cout << "��������� ����� " << NumberA / NumberB << endl;
		}
		cout << "���������� ���������� ������� (Y/N),(�/�) "; cin >> Key;
	} while (Key == 'Y' || Key == 'y' || Key == '�' || Key == '�');
#endif //CALCULATOR
}