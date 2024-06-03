#include "project_oop_01.h"

void ShowMenu(void) // 메뉴 출력
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌 정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void MakeAccount(void) // 계좌개설을 위한 함수
{
	int id = 0;
	char name[NAME_LEN];
	int money = 0;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "이름 : ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> money;

	accArr[accNum].accID = id;
	accArr[accNum].balance = money;
	strcpy(accArr[accNum].cusName,name);
	accNum++;
}

void DepositMoney(void) // 입금
{
	int money = 0;
	int id = 0;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			std::cout << "입금완료" << std::endl;
			return;
		}
	}
	std::cout<< "유효하지 않은 ID 입니다."<<std::endl;
}

void WithdrawMoney(void) // 출금
{
	int money = 0;
	int id = 0;
	std::cout << "[출금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "출금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				std::cout << "잔액 부족" << std::endl;
				return;
			}
			accArr[i].balance -= money;
			std::cout << "출금 완료" << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID 입니다. " << std::endl;
}

void ShowAllAccInfo(void) // 잔액 조회
{
	//to do list 특정 계좌만 나올수 있도록 변경
	for (int i = 0; i < accNum; i++) {
		std::cout << "계좌 ID: " << accArr[i].accID << std::endl;
		std::cout << "이름: " << accArr[i].cusName << std::endl;
		std::cout << "잔액: " << accArr[i].balance << std::endl;
	}
}
