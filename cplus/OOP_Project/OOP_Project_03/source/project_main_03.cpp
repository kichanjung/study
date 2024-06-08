#include "project_oop_03.h"

int main()
{
	int selete = 0;
	AccMnanger manager;

	while (1) {
		manager.ShowMenu();
		std::cout << "선택: ";
		std::cin >> selete;

		switch (selete)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
	return 0;
}