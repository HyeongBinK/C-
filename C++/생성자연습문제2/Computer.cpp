#include "Computer.h"

Computer::Computer()
{
	PowerOn();
	SetComputerStatus("Atents", "On", "GTX990", "I7", 8);
}

void Computer::ShowBasicMenu()
{
	system("cls");
	cout << "===== 환 영 합 니 다 =====" << endl;
	cout << "1.컴퓨터 상태" << endl;
	cout << "2.기 능" << endl;
	cout << "3.전원OFF" << endl;
	cout << "선택 : ";
}

void Computer::PowerOn()
{
	cout << "컴퓨터 두둥등장";
	Sleep(1000);
}

void Computer::PowerOff()
{
	for (int i = 5; i > 0; i--)
	{
		cout << "컴퓨터종료까지" << i << "초전" << endl;
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
	cout << "제 품 명 : " << m_strComputerName << endl;
	cout << "현재 상태 : " << m_strPower << endl;
	cout << "그래픽카드 : " << m_strGraphicCard << endl;
	cout << "CPU : " << m_strCpuName << endl;
	cout << "메 모 리 : " << m_iMemory << 'G' << endl;


	system("pause");
}

void Computer::ShowToolMenu()
{
	system("cls");
	cout << "1.계 산 기" << endl;
	cout << "2.메 모 장" << endl;
	cout << "3.그 림 판" << endl;
	cout << "4.돌아가기" << endl;
	cout << "선택 : ";
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

Computer::~Computer()
{
}
