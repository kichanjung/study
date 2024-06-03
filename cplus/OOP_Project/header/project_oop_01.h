#pragma once
#ifndef PROJECT_OOP_01_H
#define PROJECT_OOP_01_H
#include<iostream>
#include<cstring>

const int NAME_LEN = 20;

void ShowMenu(void);		// 메뉴 출력
void MakeAccount(void);		// 계좌개설을 위한 함수
void DepositMoney(void);	// 입금
void WithdrawMoney(void);   // 출금
void ShowAllAccInfo(void);	// 잔액 조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

// 자료 구조로 안되나? 
// to do 클래스화로 진행
// Account accArr[100];
// int accNum = 0;

#endif // PROJECT_OOP_01_H