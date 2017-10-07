#ifndef _STDDEF_H_
#define _STDDEF_H_
#include "stddef.h"
#endif

// Data of the stack's node. May be various
struct stack_data_s {
	int num;
};

// One node of the stack
struct node_s{
	stack_data_s data;//Useful data of node
	node_s* prev;//Address of the previous node
};
typedef node_s node;

// Stack descriptor
struct stack_s{
	node_s* top = NULL;//Address of the stack's top
	long size = 0;//Size of the stack
};

//
int pop(stack_s* stack, stack_data_s* top_element);//Deletes the top element and returns its data
void push(stack_s* stack, stack_data_s data);//Pushes one element to the stack
long size(stack_s* stack);//Returns size of the stack
void clear(stack_s* stack);//Deletes all elements of the stack