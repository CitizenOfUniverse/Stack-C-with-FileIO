#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif
#include <stdio.h>
#include <conio.h>
#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <stdlib.h>
#endif
#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_
#include "error_handler.h"
#endif

// Deletes the top element and returns its data
int pop(stack_s* stack, stack_data_s* top_element){
	if (stack->size == 0){//Stack is empty...
		return 0;
	}
	else{//...or contains only one element
		node_s* newtop = stack->top->prev;//Saving previous node
		*top_element = stack->top->data;//Saving data of the now top
		free(stack->top);//Deleting the now top
		stack->size--;//Decreasing the size of the stack
		stack->top = newtop;//
		return 1;//Returning data
	}
}

// Pushes one element to the stack
void push(stack_s* stack, stack_data_s data){
	node_s* newtop = (node_s*)malloc(sizeof(node_s));//Allocating memory for a new top
	if (newtop == NULL){
		error_handler(ERR_ALLOC_MEM, stack);
	}
	newtop->data = data;//Adding data
	newtop->prev = stack->top;//Adding an address to an old top
	stack->top = newtop;//Setting new top to stack structure
	stack->size++;//Increasing size of stack
	return;
}

// Returns size of the stack
long size(stack_s* stack){
	return stack->size;
}
// Deletes all elements of the stack
void clear(stack_s* stack){
	while (stack->size > 0){
		node* now_node = stack->top;
		stack->top = stack->top->prev;
		free(now_node);
		stack->size--;
	}
}
//node* generate_test_data() {
//    node* item = (node*) malloc(sizeof(node));
//
//    item->data = 8888;
//    item->junk.mem_chunk = MEM_CHUNK_TEST_VALUE;
//    item->junk.ratio = RATIO_TEST_VALUE;
//    strncpy(item->junk.chunk_dump, CHUNK_DUMP_TEST_VALUE, DUMP_MAX_SIZE);
//    item->prev = NULL;
//
//    return item;
//}
//
//
//void delete_test_data(node *data) {
//    free(data);
//}
