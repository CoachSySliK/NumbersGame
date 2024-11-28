#include <iostream>
#include <string>
#include <conio.h>
#include "functions.h"

using namespace std;

void thinkNumber(string player, string number, int *nums, const int C) {
	bool rightNumber = false;
	do {
		cout << player << endl;
		cout << "Загадайте 4-ёх значное число: ";
		cin >> number;
		cin.ignore(100, '\n');
		if (number.length() != C) {
			cout << "Ошибка1, введите 4 цифры!\n";
			continue;
		}
		for (int i = 0; i < C; i++) {
			nums[i] = number[i] - 48;
		}
		for (int i = 0; i < C; i++) {
			if (nums[i] < 0 || nums[i] > 9) {
				cout << "Ошибка2, введите 4 цифры!\n";
				rightNumber = false;
				break;
			}	
			rightNumber = true;
		}
	} while (!rightNumber);
}

void inputNumber(string player, string number, int *nums, const int C) {
	bool rightNumber = false;
	do {
		cout << player << "," << endl;
		cout << "Отгадайте 4-ёх значное число: ";
		cin >> number;
		cin.ignore(100, '\n');
		if (number.length() != C) {
			cout << "Ошибка1, введите 4 цифры!\n";
			continue;
		}
		for (int i = 0; i < C; i++) {
			nums[i] = number[i] - 48;
		}
		for (int i = 0; i < C; i++) {
			if (nums[i] < 0 || nums[i] > 9) {
				cout << "Ошибка2, введите 4 цифры!\n";
				rightNumber = false;
				break;
			}	
			rightNumber = true;
		}
	} while (!rightNumber);
}

int cowNumber(int *tnums, int *fnums, const int C) {
	int tNumber = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (tnums[i] != fnums[i] && tnums[i] == fnums[j])
				++tNumber;
				continue;
		}
	}
	return tNumber;
}

int bullNumber(int *tnums, int *fnums, const int C) {
	int tPlace = 0;
	for (int i = 0; i < C; i++) {
		if (tnums[i] == fnums[i])
			++tPlace;
	}
	return tPlace;
}

int findNumber(string player, string number, int *tnums, int *fnums, const int C) {
	bool find = false;
	int bull = 0;
	int cow = 0;
	int counter = 0;
	do {
		inputNumber(player, number, fnums, 4);
			
		cout << endl;
		cow = cowNumber(tnums, fnums, C);
		bull = bullNumber(tnums, fnums, C);
		if (bull + cow > 4) 
			cow = 4 - bull;
		cout << "Быков: " << bull << " ";
		cout << "Коров: " << cow << endl;	
		cout << endl;
		
		++counter;
		if (bull == 4) {
			cout << player << ", Вы угадали за " << counter << ending(counter, 109) << "!" << endl;
			find = true;
			cout << "Нажмите Enter что бы продолжить";
			cin.ignore();
			//getch();
		}
	} while (!find);
	
	return counter;
}

int main(void)
{	
	const int C = 4;
	string player1 = "Игрок 1";
	string player2 = "Игрок 2";
	string number = "0000";
	
	cout << player1 << " Введите имя: ";
	cin >> player1;
	cin.ignore(100, '\n');
	cout << player2 << " Введите имя: ";
	cin >> player2;
	cin.ignore(100, '\n');
	
	int tnums1[C] = {0};
	int tnums2[C] = {0};
	int *ptrtNums1 = tnums1;
	int *ptrtNums2 = tnums2;
	
	int fnums1[C] = {0};
	int fnums2[C] = {0};
	int *ptrfNums1 = fnums1;
	int *ptrfNums2 = fnums2;
	
	int counterMove1 = 0;
	int counterMove2 = 0;
	
	/*string test;
	cin >> test;
	cout << test.length();*/
	
	clrscr();
	
	thinkNumber(player1, number, ptrtNums1, C);
	clrscr();
	
	thinkNumber(player2, number, ptrtNums2, C);
	clrscr();
	
	counterMove1 = findNumber(player1, number, ptrtNums2, ptrfNums1, C);
	clrscr();
	
	counterMove2 = findNumber(player2, number, ptrtNums1, ptrfNums2, C);
	clrscr();
	
	if (counterMove1 < counterMove2) {
		cout << player1 << ", Выиграл!!!";
	} else {
		cout << player2 << ", Выиграл!!!";
	}	
	
	return 0;
}