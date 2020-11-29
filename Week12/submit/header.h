#ifndef HEADER_H
#define HEADER_H


// for Linked List 
struct list {
	char* data;
	struct list *next;
};
typedef struct list LIST;
extern LIST* head_T; extern LIST* tail_T;  // for "TEXT"
extern LIST* head_M; extern LIST* tail_M; // for "Modification Record"

void addToList_T(char* _data); // add node to Linked List for "TEXT"
void addToList_M(char* _data); // add node to Linked List for "Modification Record"

void substr(char * str, char * buffer, int start, int end); // slice string

int randomStartAddress(int _length); // to get start address;

#endif