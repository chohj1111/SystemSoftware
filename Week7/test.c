#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linked list
struct list {
	char string[70];
	struct list *next;

};

typedef struct list LIST;

// slice string to buffer
void substr(const char * str, char * buffer, int start, int end){
	int j = 0;
	for (int i = start; i < end; i++) {
		buffer[j] = str[i];
		j++;
	}
	buffer[j] = '\0';
}
// change HEX into DEC
void CodesToIncodes(char * codes,size_t size){
  char* p = codes;
  for(int i=0;i<size;i++){
    char target[2];
    substr(p,target,i,i+1);
    printf("%d ", (int)strtol(target, NULL, 16));
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
	//throw error when don't input file name
	if (argc < 2) {
		printf("Enter the FILE's name");
		exit(1);
	}
	FILE *fp = fopen(argv[1], "r");
	// for getting line from the file
	char line[70];
	// initialize linked list
	LIST *current, *head;
	head = current = NULL;

	//read the line until end line
	while (fgets(line, sizeof(line), fp)) {
		// avoid duplicate open characters
    line[strlen(line)-1]='\0';
		// new node
		LIST *node = (LIST*)malloc(sizeof(LIST));
		// when line is "TEXT"
		if (line[0] == 'T') {
			char temp[70];
			//slice string for separting codes from TEXT line
			substr(line, temp, 9, 60);
			strcpy(node->string, temp);
		}
		// x : flag
		else strcpy(node->string, "X");
		// initialize 'next' pointer
		node->next = NULL;
		// when 'node' is first node of list
		if (head == NULL) {
			head = node;
			current = node;
		}
		// next node of 'current' is 'node'
		else {
			current->next = node;
			current = node;
		}
		//initialize line
		line[0] = '\0';
	}
	fclose(fp);
	//traversal linked list for print codes
	printf("Codes: \n");
	for (current = head->next; current; current = current->next) {
		if(strcmp(current->string,"X")!=0) printf("%s\n", current->string);
	}
	//traversal linked list for print incodes
  printf("\n\nEncoded codes : \n");
  for (current = head->next; current; current = current->next) {
		if(strcmp(current->string,"X")!=0) CodesToIncodes(current->string,strlen(current->string));
	}
	return 0;
}
