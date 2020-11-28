#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

LIST* tail_T = NULL;
LIST* tail_M = NULL;

void addToList_T(char* _data) {
	LIST* new_node = (LIST*)malloc(sizeof(LIST));
	new_node->data=malloc(strlen(_data));
	strcpy(new_node->data, _data);
	new_node->next = NULL;
	// Check if list is empty
	if (head_T == NULL) {
		head_T = new_node;
		tail_T = new_node;
	}
	else {
		tail_T->next = new_node;
		tail_T = new_node;
	}
}

void addToList_M(char* _data) {
	LIST* new_node = (LIST*)malloc(sizeof(LIST));
	new_node->data=malloc(strlen(_data));
	strcpy(new_node->data, _data);
	new_node->next = NULL;
	// Check if list is empty
	if (head_M == NULL) {
		head_M = new_node;
		tail_M = new_node;
	}
	else {
		tail_M->next = new_node;
		tail_M = new_node;
	}
}


// slice string to buffer
void substr(char * str, char * buffer, int start, int end){
	int j = 0;
	
	for (int i = start; i < end; i++) {
		if(str[j]==EOF) break;
		buffer[j] = str[i];
		j++;
		
	}
	buffer[j] = '\0';
}


// to get start address;
// (start address)+length <= 32758
// start address <= 32758-length
int randomStartAddress(int _length){
	 srand( time(NULL) );
	 return rand()% (32758-_length+1);
}