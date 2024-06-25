#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

class AccountExecption
{
public:
	virtual void ShowExceptionReason() = 0;
};

// 예외 클래스
class DepositException : public AccountExecption
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money)
	{}
	void ShowExceptionReason()
	{
		std::cout << "[예외 메시지: " << reqDep << "는 입금 불가" << std::endl;
	}
};

// 예외 클래스
class WithdreawException : public AccountExecption
{
private:
	int balance;
public:
	WithdreawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		std::cout << "[예외 메시지: 잔액" << balance << ", 잔액부족" << std::endl;
	}
};


class Account
{
private:
	char accNum[50];
	int balance;

public:
	Account(const char* acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountExecption)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Widthdraw(int money) throw (AccountExecption)
	{
		if (money > balance)
			throw WithdreawException(balance);
		balance -= money;
	}
	void ShowMyMoney()
	{
		std::cout << "잔고: " << balance << std::endl << std::endl;
	}
};

int main01()
{
	Account myAcc("56789-12345", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (DepositException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Widthdraw(3500);
		myAcc.Widthdraw(4500);
	}
	catch (WithdreawException& expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}