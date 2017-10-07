#ifndef _STDIO_H_
#define _STDIO_H_
#include "stdio.h"
#endif
#ifndef _ERROR_TYPES_H_
#define _ERROR_TYPES_H_
#include "error_types.h"
#endif
#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif
#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <stdlib.h>
#endif

void view_error_message(err_type err){
	switch (err){
	case ERR_ALLOC_MEM:
		printf("ERROR! Couldn't allocate memory\n");
		break;
	case ERR_OPEN_FILE:
		printf("ERROR! Couldn't open file\n");
	case ERR_WRITE_FILE:
		printf("ERROR! Couldn't write info to file\n");
	default:
		break;
	}
}
void error_handler(err_type err, stack_s* stack){
	view_error_message(err);
	clear(stack);
	exit(1);
}
void error_handler(err_type err){
	view_error_message(err);
	exit(1);
}