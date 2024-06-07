#pragma once
#include<iostream>
#include<cstring>

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
int NAME_LEN =20;
int accNum = 0;

class Account
{
private:
    int accID;
	int balance;
	char* cusName;
public:
	Account(int id, int money, char* name);
	~Account();
	void SetDeposit(int money);
	void SetWithdraw(int money);
	int GetAccID();
	int GetBalance();
	const char *GetName();
};

//계좌번호
Account::Account(int id, int money, char* name): accID(id), balance(money)
{
    cusName = new char[NAME_LEN];
    strcpy(cusName,name);
}

Account::~Account()
{
    delete []cusName;
}

void Account::SetDeposit(int money)
{
	balance += money;
}

void Account::SetWithdraw(int money)
{
	balance -= money;
}


int Account::GetAccID()
{
	return accID; 
}

int Account::GetBalance()
{
	return balance;
}

const char* Account::GetName()
{
	return cusName;
}

class AccMnanger
{
private:
	Account* accArr[100];
public:
	AccMnanger();
	~AccMnanger();
	void ShowMenu(void);		// 메뉴 출력
    void MakeAccount(void);		// 계좌개설을 위한 함수
    void DepositMoney(void);	// 입금
    void WithdrawMoney(void);   // 출금
    void ShowAllAccInfo(void);	// 잔액 조회
};

AccMnanger::AccMnanger()
{

}

AccMnanger::~AccMnanger()
{
	for(int i=0; i<accNum; i++){
		delete accArr[i];
	}
}

void AccMnanger::ShowMenu(void)
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌 정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void AccMnanger::MakeAccount(void)
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

	accArr[accNum++]=new Account(id,money,name);
}

void AccMnanger::DepositMoney(void)
{
	int money = 0;
	int id = 0;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "입금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->SetDeposit(money);
			std::cout << "입금완료" << std::endl;
			return;
		}
	}
	std::cout<< "유효하지 않은 ID 입니다."<<std::endl;
}

void AccMnanger::WithdrawMoney(void)
{
	int money = 0;
	int id = 0;
	std::cout << "[출금]" << std::endl;
	std::cout << "계좌ID: "; std::cin >> id;
	std::cout << "출금액: "; std::cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->GetBalance() < money) {
				std::cout << "잔액 부족" << std::endl;
				return;
			}
			accArr[i]->SetWithdraw(money);
			std::cout << "출금 완료" << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID 입니다. " << std::endl;
}

void AccMnanger::ShowAllAccInfo(void)
{
	//to do list 특정 계좌만 나올수 있도록 변경
	for (int i = 0; i < accNum; i++) {
		std::cout << "계좌 ID: " << accArr[i]->GetAccID() << std::endl;
		std::cout << "이름: " << accArr[i]->GetName() << std::endl;
		std::cout << "잔액: " << accArr[i]->GetBalance() << std::endl;
	}
}