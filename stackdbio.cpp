#define _CRT_SECURE_NO_WARNINGS
#ifndef _STDDEF_H_
#define _STDDEF_H_
#include "stddef.h"
#endif
#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_
#include "error_handler.h"
#endif
#include <stdlib.h>
#include <string.h>
#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif
#include "stackdbio.h"
#include <conio.h>

// Initialises "database" - Creates a v
DBFile* initialize(const char *db_file_name){
	DBFile *db_file = (DBFile *)malloc(sizeof(DBFile));
	if (db_file == NULL){
		printf("ERROR! Couldn't allocate memory. Sorry");
		_getch();
		exit(-1);
	}
	db_file->file_ptr = NULL;
	strncpy(db_file->file_name, db_file_name, FILE_NAME_MAX_LEN);
	return db_file;
}

// Opens database file for reading 
void open_db_read(DBFile *db){
	db->file_ptr = fopen(db->file_name, "rb+");//Opening file
	if (db->file_ptr == NULL){//Printing error message and closing program if file wasn't opened
		printf("ERROR! Couldn't open file. Sorry\n");
		_getch();
		exit(-1);//Exiting program
	}
}
// Opens database file for writing 
void open_db_write(DBFile *db){
	db->file_ptr = fopen(db->file_name, "wb+");//Opening file
	if (db->file_ptr == NULL){//Printing error message and closing program if file wasn't opened
		error_handler(ERR_OPEN_FILE);
	}
}
// Loads a full stack from file. Adds every element from file to the top of the stack in reading order.
// Note: file contains a stack in reversed order
void load_stack_from_file(DBFile *db, stack_s* stack){
	stack_data_s now_element;//Temporary varible for a new element
	while(fread(&now_element, sizeof(stack_data_s), 1, db->file_ptr) == 1){//Cycle exit point is error of reading file or end of file
		push(stack,now_element);//Pushing a new element to stack
	}
}

// Closes the opened database file. Doesn't free the database pointer
void close_db(DBFile *db){
	//TODO
	fclose(db->file_ptr);
}
// Saves stack in reversed order to database. 
// Note: file contains a stack in reversed order
void save_stack_to_db(DBFile *db, stack_s* stack){
	while (stack->size > 0){
		node* now_node = stack->top;
		if (fwrite(&(now_node->data), sizeof(stack_data_s), 1, db->file_ptr) != 1){
			error_handler(ERR_WRITE_FILE, stack);
		}
		stack->top = stack->top->prev;
		free(now_node);
		stack->size--;
	}
}
// Deallocates memory for a databse
void free_db(DBFile *db){
	free(db);
}

//void error_function(){
//
//}