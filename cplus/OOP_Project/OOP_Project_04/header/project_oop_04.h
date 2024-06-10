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
	Account(const Account& acc);
	void SetDeposit(int money);
	void SetWithdraw(int money);
	int GetAccID() const;
	int GetBalance() const;
	const char *GetName() const;
};

/**
 *  @fn Account()
 *  @brief Account 클래스 생성자
 *  @details Account 클래스의 생성자로 계좌번호, 입금 금액 이름명 값을 받아오며, 이름명 값에 대한 동적할당을 진행한다
 *  @param id 계좌번호
 *  @param money 입금 금액
 *  @param name 이름명
 *  @return void
 *  @throws void
 */
Account::Account(int id, int money, char* name): accID(id), balance(money)
{
    cusName = new char[NAME_LEN];
    strcpy(cusName,name);
}

/**
 *  @fn Account()
 *  @brief Account 클래스 복사 생성자
 *  @details Account 클래스의 복사 생성자로 계좌번호, 입금 금액 이름명 값을 받아오며, 이름명 값에 대한 동적할당을 진행한다
 *  @param id 계좌번호
 *  @param money 입금 금액
 *  @param name 이름명
 *  @return void
 *  @throws void
 */
Account::Account(const Account& acc) : accID(acc.accID), balance(acc.balance)
{
	cusName = new char[NAME_LEN];
    strcpy(cusName,acc.cusName);
}

/**
 *  @fn Account()
 *  @brief Account 클래스 소멸자
 *  @details Account 클래스의 소멸자로 동적으로 할당한 메모리를 해제 한다.
 *  @return void
 *  @throws void
 */
Account::~Account()
{
    delete []cusName;
}

/**
 *  @fn SetDeposit()
 *  @brief 계좌 입금 함수
 *  @details 계좌에 입금되는 금액을 처리하기 위해 사용되는 함수
 *  @param money 입금 금액값 
 *  @return void
 *  @throws void
 */
void Account::SetDeposit(int money) 
{
	balance += money;
}

/**
 *  @fn SetDeposit()
 *  @brief 계좌 출금 함수
 *  @details 계좌에 출금되는 금액을 처리하기 위해 사용되는 함수
 *  @param money 출금 금액값
 *  @return void
 *  @throws void
 */
void Account::SetWithdraw(int money)
{
	balance -= money;
}

/**
 *  @fn GetAccID()
 *  @brief 계좌번호 Get 함수
 *  @details 계좌번호 Get 함수
 *  @return accID
 *  @throws accID
 */
int Account::GetAccID() const
{
	return accID; 
}

/**
 *  @fn GetBalance()
 *  @brief 계좌 남은 금액 값 Get 함수
 *  @details 계좌 남은 금액 값 Get 함수
 *  @return balance
 *  @throws balance
 */
int Account::GetBalance() const
{
	return balance;
}

/**
 *  @fn GetName()
 *  @brief 계좌 이름명 Get 함수
 *  @details 계좌 이름명 Get 함수
 *  @return cusName
 *  @throws cusName
 */
const char* Account::GetName() const
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
	void ShowMenu(void) const;		// 메뉴 출력
    void MakeAccount(void);		// 계좌개설을 위한 함수
    void DepositMoney(void);	// 입금
    void WithdrawMoney(void);   // 출금
    void ShowAllAccInfo(void) const;	// 잔액 조회
};

/**
 *  @fn AccMnanger()
 *  @brief AccMnanger 클래스 생성자
 *  @details AccMnanger 클래스 생성자
 *  @return void
 *  @throws void
 */
AccMnanger::AccMnanger()
{

}

/**
 *  @fn AccMnanger()
 *  @brief AccMnanger 클래스 소멸자
 *  @details AccMnanger 클래스의 소멸자로 동적으로 할당한 메모리를 해제 한다.
 *  @return void
 *  @throws void
 */
AccMnanger::~AccMnanger()
{
	for(int i=0; i<accNum; i++){
		delete accArr[i];
	}
}

/**
 *  @fn ShowMenu()
 *  @brief 메뉴 출력 함수
 *  @details 메뉴 출력 함수
 *  @return void
 *  @throws void
 */
void AccMnanger::ShowMenu(void) const
{
	std::cout << "-----Menu------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌 정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

/**
 *  @fn MakeAccount()
 *  @brief 계좌 개설 함수
 *  @details 계좌 개설 함수로 계좌 ID, 이름 , 입금액을 입력받아 값을 저장한다.
 *  @return void
 *  @throws void
 */
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

/**
 *  @fn DepositMoney()
 *  @brief 입금 진행 함수
 *  @details 계좌ID와 입금 금액을 입력받아 해당 계좌에 돈을 입금하는 함수
 *  @return void
 *  @throws void
 */
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

/**
 *  @fn WithdrawMoney()
 *  @brief 출금 계좌 함수
 *  @details 계좌ID와 출금 금액을 입력받아 해당 계좌에 돈을 출금하는 함수
 *  @return void
 *  @throws void
 */
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

/**
 *  @fn ShowAllAccInfo()
 *  @brief 모든 계좌 내용 출력 함수
 *  @details 저장된 모든 계좌ID 이름 잔액 내용 출력 함수
 *  @return void
 *  @throws void
 */
void AccMnanger::ShowAllAccInfo(void) const
{
	//to do list 특정 계좌만 나올수 있도록 변경
	for (int i = 0; i < accNum; i++) {
		std::cout << "계좌 ID: " << accArr[i]->GetAccID() << std::endl;
		std::cout << "이름: " << accArr[i]->GetName() << std::endl;
		std::cout << "잔액: " << accArr[i]->GetBalance() << std::endl;
	}
}