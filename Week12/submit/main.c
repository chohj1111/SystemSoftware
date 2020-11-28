#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"
//initialize linked list 
LIST *head_T = NULL;  // for "TEXT"
LIST *head_M=NULL; // for "Modification Records"


int main(int argc, char *argv[]) {
	//throw error when don't input file name
	if (argc < 2) {
		printf("Enter the FILE's name");
		exit(1);
	}
	FILE *fp = fopen(argv[1], "r");
	// length : object program length
	// startAddress : randomly generated start address
	// line : for getting line from the file
	int length,startAddress;
	char line[70]; 	
	
	//get first line of object file
	fgets(line, sizeof(line), fp);

	// when line is "Header"
	// get length of object program
	if (line[0] == 'H') {
		//row 14~19 : length of object program
		char *length_hex = malloc(sizeof(char)*6);
		substr(line, length_hex, 13, 19);
		length=(int)strtol(length_hex,NULL,16);
		free(length_hex);
	}
	// get start address
	startAddress = randomStartAddress(length);
	printf("start address: %d\n",startAddress);

	//read the line until end line
	while (fgets(line, sizeof(line), fp)!=0) {
		int line_length= (int)strlen(line); // length of one line
		line[line_length-1]='\0'; // avoid duplicate open characters
		// "TEXT"
		if (line[0] == 'T') {
			// temp_end: end index of "TEXT" line
			// row 10~(69 or less) : Byte Codes 
			int temp_end = (line_length<70)?line_length:70;
			char temp[70];			
			// add to linked list for "TEXT"
			// per one byte		
			char twoLetters[2];
			for(int i=9;i+2<temp_end;i+=2){
				substr(line, twoLetters, i, i+2);
				addToList_T(twoLetters);
			}			
		}
		// "Modification Record"
		else if (line[0] == 'M') {
			// row 2~7 : relative start address
			char temp[6];
			substr(line, temp, 1, 7);
			addToList_M(temp);
		}
	}
	
	printf("Before modification:\n");
	// relative address to the start
	int relativeAddress = 0;
	LIST* M_node;
	// traversal Linked List for "Modification Record"
	for (M_node = head_M; M_node; M_node = M_node->next) {
		// store hex as int 
		relativeAddress = strtol(M_node->data,NULL,16);	
		// jump to relativeAddress with Linked List for "TEXT"
		LIST *traversal= head_T;
		for(int i=0;i<relativeAddress;i++){
			traversal= traversal->next;
		}
		// print Byte Codes before modification
		for(int j=0;j<3;j++){
			int ModificationAddress = relativeAddress+startAddress+j;
			printf("%d: ",ModificationAddress);
			printf("%s\n", traversal->data);
			traversal= traversal->next;
		} 		
	}

	M_node=NULL;
	relativeAddress = 0;
	printf("After modification:\n");
	for (M_node = head_M; M_node; M_node = M_node->next) {
		// store hex as int 
		relativeAddress = strtol(M_node->data,NULL,16);	
		// jump to relativeAddress with Linked List for "TEXT"
		LIST *traversal= head_T;
		for(int i=0;i<relativeAddress;i++){
			traversal= traversal->next;
		}
		// hexCodes : hex byte codes 
		char hexCodes[6];
		hexCodes[0] = '\0';
		for(int j=0;j<3;j++){
			strcat (hexCodes,traversal->data);
			traversal = traversal->next; 
		} 		
		// decCodes : convert 'hexCodes' to DECIMAL
		// decCodesToString : convert decCodes to string
		// "%06X" to handle hex values that have less than 6 digits
		int decCodes = strtol(hexCodes,NULL,16)+startAddress;
		char decCodesToString[6];
		decCodesToString[0]='\0';
		sprintf(decCodesToString, "%06X", decCodes);
		// print Byte Codes after modification
		for(int k=0;k<3;k++){
			int ModificationAddress = relativeAddress+startAddress+k;
			char printValue[2];
			substr(decCodesToString, printValue, k*2, (k*2)+2);
			printf("%d: %s\n",ModificationAddress,printValue);
		}
	}
	//free 
	fclose(fp); 
}
