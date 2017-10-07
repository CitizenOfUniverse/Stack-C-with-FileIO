/*
* main.cpp - Main project file. Contains only main function.
*/

//Preventing double including of file "stddef.h". File is needed for NULL constant
#ifndef _STDDEF_H_
#define _STDDEF_H_
#include "stddef.h"
#endif
#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif
#include "stackdbio.h"
#include <conio.h>

//Debug code in C++
////#include <iostream>
//
//using namespace std;


const char *db_file_name = "stack_db_file.bin\0";

int main(){

	DBFile* db = initialize(db_file_name);
	open_db_read(db);
	stack_s stack;
	load_stack_from_file(db, &stack);
	//Debug code in C++
	//setlocale(LC_ALL, "Russian");
	//int commandNum = 0;
	//
	//while (true){
	//	switch (commandNum){
	//	case 0:
	//		cout << "��������� �������:\n" <<
	//			"0 - ����������� ����\n" <<
	//			"1 - ������� ������� ����� � ������� ��\n" <<
	//			"2 - �������� � ���� �����\n" <<
	//			/*"3 - ������� ������� �����\n" <<*/
	//			"4 - ������� ������ �����\n" <<
	//			"5 - �����\n" <<
	//			"������� ����� �������: ";
	//		cin >> commandNum;
	//		break;
	//	case 1:
	//		stack_data_s tmp;
	//		if (pop(&stack, &tmp)){
	//			cout << "������� �����: " << tmp.num << endl;
	//		}
	//		else{
	//			cout << "���� ��� ����.\n";
	//		}
	//		cout << "\n������� �������: ";
	//		cin >> commandNum;
	//		break;
	//	case 2:
	//		int newNum;
	//		cout << "������� �����: ";
	//		cin >> newNum;
	//		push(&stack, { newNum });
	//		cout << "������� �������: ";
	//		cin >> commandNum;
	//		break;
	//	/*case 3:
	//		pop(&item);
	//		cout << "������� �������: ";
	//		cin >> commandNum;
	//		break;*/
	//	case 4:
	//		cout << "������ �����: " << size(&stack);
	//		cout << "\n������� �������: ";
	//		cin >> commandNum;
	//		break;
	//	case 5:
	//		cout << "������� �� ������������� ���������.\n";
	//		break;
	//	default:
	//		cout << "�������� ����� �������.";
	//		cout << "\n������� �������: ";
	//		cin >> commandNum;
	//		break;
	//	}
	//	if (commandNum == 5){
	//		cin.get();
	//		cin.get();
	//		break;
	//	}
	//}

	open_db_write(db);
	save_stack_to_db(db, &stack);
	close_db(db);
	free_db(db);
	_getch();

	return 0;
}

