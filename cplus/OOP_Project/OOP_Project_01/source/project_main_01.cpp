#include "project_oop_01.h"

int main()
{
	int selete = 0;
	
	while (1) {
		ShowMenu();
		std::cout << "선택: ";
		std::cin >> selete;

		switch (selete)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
	return 0;
}