#include"PhoneNumber.h"

void main()
{

	bool b = true;
	
	while (b)
	{
		PhoneNumber P;
		b = P.CheckPhoneNumber();

		if (b == false)
		{
			P.RemakePhoneNumber();
			P.Display();
			P.Deletem_chReMakePhoneNumber();
		}
	}
}