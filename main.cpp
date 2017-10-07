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
	//		cout << "Доступные команды:\n" <<
	//			"0 - стандартное меню\n" <<
	//			"1 - вывести вершину стека и удалить ее\n" <<
	//			"2 - добавить в стек число\n" <<
	//			/*"3 - удалить вершину стека\n" <<*/
	//			"4 - вывести размер стека\n" <<
	//			"5 - выход\n" <<
	//			"Введите номер команды: ";
	//		cin >> commandNum;
	//		break;
	//	case 1:
	//		stack_data_s tmp;
	//		if (pop(&stack, &tmp)){
	//			cout << "Вершина стека: " << tmp.num << endl;
	//		}
	//		else{
	//			cout << "Стек уже пуст.\n";
	//		}
	//		cout << "\nВведите команду: ";
	//		cin >> commandNum;
	//		break;
	//	case 2:
	//		int newNum;
	//		cout << "Введите число: ";
	//		cin >> newNum;
	//		push(&stack, { newNum });
	//		cout << "Введите команду: ";
	//		cin >> commandNum;
	//		break;
	//	/*case 3:
	//		pop(&item);
	//		cout << "Введите команду: ";
	//		cin >> commandNum;
	//		break;*/
	//	case 4:
	//		cout << "Размер стека: " << size(&stack);
	//		cout << "\nВведите команду: ";
	//		cin >> commandNum;
	//		break;
	//	case 5:
	//		cout << "Спасибо за использование программы.\n";
	//		break;
	//	default:
	//		cout << "Неверный номер команды.";
	//		cout << "\nВведите команду: ";
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

