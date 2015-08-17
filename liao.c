#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(const void* a, const void* b){
	char a2 = *((char*)a);
	char b2 = *((char*)b);
	if (a2 > b2)
		return -1;
	if (b2 > a2)
		return 1;
	return 0;
}

int comp(const void* a, const void* b){
	char a2 = *((char*)a);
	char b2 = *((char*)b);
	if (a2 > b2)
		return 1;
	if (b2 > a2)
		return -1;
	return 0;
}

int main(int argc, char* argv[]){
	int bufferSize = 256;
	char buffer[bufferSize];
	while (fgets(buffer, bufferSize, stdin) != NULL){
        if (*(buffer+strlen(buffer)-1) == '\n'){
            *(buffer+strlen(buffer)-1) = '\0';
        }
        int len = strlen(buffer);
        char* copy = (char*)malloc(len*sizeof(char));
        char* revered = (char*)malloc(len*sizeof(char));
        strncpy(copy, buffer, len);
        strncpy(revered, buffer, len);
        qsort(copy, len, sizeof(char), comp);
        qsort(revered, len, sizeof(char), reverse);

        if (strcmp(buffer, copy) == 0){
        	printf("%s IN ORDER\n", buffer);
        }
        else if (strcmp(buffer, revered) == 0){
        	printf("%s REVERSE ORDER\n", buffer);
        }
        else {
        	printf("%s NOT IN ORDER\n", buffer);
        }
	}
}