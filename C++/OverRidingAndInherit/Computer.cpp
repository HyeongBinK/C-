#include "Computer.h"

Computer::Computer()
{
	//PowerOn();
	SetComputerStatus("Atents", "On", "GTX1060Ti", "I9", 16);
}

void Computer::ShowBasicMenu()
{
	system("cls");
	cout << "===== ȯ �� �� �� �� =====" << endl;
	cout << "1.��ǻ�� ����" << endl;
	cout << "2.�� ��" << endl;
	cout << "3.ȸ�� ����" << endl;
	cout << "4.ȸ�� ��������" << endl;
	cout << "5.OFF" << endl;
	cout << "�Է� >>" << endl;
}

void Computer::PowerOn()
{
	cout << "��ǻ�� ON";
	Sleep(1000);
}

void Computer::PowerOff()
{
	for (int i = 5; i > 0; i--)
	{
		cout << "��ǻ���������" << i << "����" << endl;
		Sleep(500);
	}

	return;
}

void Computer::SetComputerStatus(string ComputerName, string Power, string GraphicCard, string CpuName, int Memory)
{
	m_strComputerName = ComputerName;
	m_strPower = Power;
	m_strGraphicCard = GraphicCard;
	m_strCpuName = CpuName;
	m_iMemory = Memory;

}

void Computer::ShowComputerStatus()
{
	system("cls");
	cout << "�� ǰ �� : " << m_strComputerName << endl;
	cout << "���� ���� : " << m_strPower << endl;
	cout << "�׷���ī�� : " << m_strGraphicCard << endl;
	cout << "CPU : " << m_strCpuName << endl;
	cout << "�� �� �� : " << m_iMemory << 'G' << endl;


	system("pause");
}

void Computer::ShowToolMenu()
{
	system("cls");
	cout << "1.�� �� ��" << endl;
	cout << "2.�� �� ��" << endl;
	cout << "3.�� �� ��" << endl;
	cout << "4.���ư���" << endl;
	cout << "���� : ";
}

void Computer::PlayTool()
{
	int iSelect;
	bool bSectionEndStatus = true;

	while (bSectionEndStatus)
	{
		ShowToolMenu();

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		case 4:
			bSectionEndStatus = false;
		}
	}
}

void Computer::PlayComputer()
{
	int Select;

	while (1)
	{
		bPowerStatus = true;

		system("cls");
		FirstMenu();
		cin >> Select;
		switch (Select)
		{
		case 1:
			MakeData();
			break;
		case 2:
			CheckID();
			
			PowerOn();
			while (bPowerStatus)
			{
				system("cls");
				ShowBasicMenu();

				cin >> Select;

				switch (Select)
				{
				case 1:
					ShowComputerStatus();
					break;
				case 2:
					PlayTool();
					break;
				case 3:
					ShowInformation();
					system("pause");
					break;
				case 4:
					DataChange();
					break;
				case 5:
					PowerOff();
					bPowerStatus = false;
				}
			}
			break;
		case 3:
			return;
		}
	}
}

Computer::~Computer()
{
}
