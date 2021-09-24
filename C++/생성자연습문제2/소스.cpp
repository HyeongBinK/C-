#include"Computer.h"


void main()
{
	int iSelect;
	bool bPowerStatus = true;
	Computer C1;

	while (bPowerStatus)
	{
		C1.ShowBasicMenu();

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			C1.ShowComputerStatus();
			break;
		case 2:
			C1.PlayTool();
			break;
		case 3:
			C1.PowerOff();
			bPowerStatus = false;
		}
	}
}


