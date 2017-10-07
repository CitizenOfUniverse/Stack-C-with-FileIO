/**
* File contains definitions of stack database structures and
* operations on database file
*/

#include <stdio.h>

#define FILE_NAME_MAX_LEN 60


typedef struct db_file_s {
	FILE *file_ptr;
	char file_name[FILE_NAME_MAX_LEN];
} DBFile;


DBFile* initialize(const char *db_file_name);


void open_db_read(DBFile *db);
void open_db_write(DBFile *db);


void close_db(DBFile *db);


void save_stack_to_db(DBFile *db, stack_s* stack);


// void read_from_db(DBFile *db);


void free_db(DBFile* db);

void load_stack_from_file(DBFile *db, stack_s* stack);