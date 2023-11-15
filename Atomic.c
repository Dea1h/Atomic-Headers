#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct AtomicString{
	char* data;
	size_t len;
}AtomicString;

int allocAtomicString(AtomicString* str,const char* initialContent){
	unsigned int counter = 0;
	while (true) {
		if(*(initialContent + counter) == '\0'){
			str->len = counter;
			break;
		}
		counter++;
	}
	str->data = (char*)malloc((counter + 1) * sizeof(char));
	if(str->data == NULL){
		fprintf(stderr,"Memory allocation failed\n");
		return -1;
	}
	for(int i = 0;i<counter;i++){
		*(str->data + i) = *(initialContent + i);
	}
	*(str->data + (counter+1)) = '\0';
	return 0;
}
void freeAtomicString(AtomicString* str){
	free(str->data);
	if(str->data != NULL){
		fprintf(stderr,"Failed to free memory\n");
	}
}
int concatAtomicString(AtomicString* result,const AtomicString* str1,const AtomicString* str2){
	result->data = (char*)malloc((((str1->len) + (str2->len)) + 1)  * sizeof(char));
	if(result->data == NULL){
		fprintf(stderr,"Memory allocation failed\n");
		return -1;
	}
	int counter = 0;

	for(int i=0;i < (str1->len);i++){
		counter++;
		*(result->data + i) = *(str1->data + i);
	}

	for(int i=counter;i<((str1->len)+(str2->len));i++){
		*(result->data + i) = *(str2->data +i);
	}
	*(result->data + ((str1->len)+(str2->len) + 1)) = '\0';
	return 0;
}
void substringAtomicString(AtomicString* result,const AtomicString* str,size_t start,size_t end){
	for(int i=0;i<str->len;i++){
		if(i > start && i < end){
			*(result->data + i) = *(str->data + i);
		}
	}
}
int resizeAtomicString(AtomicString* str,const char* content){
	int counter = 0;
	while(true){
		if(*(content + counter) == '\0'){
			str->len = counter;
			break;
		}
		counter++;
	}
	free(str->data);
	str->data = (char*)malloc((counter+1) * sizeof(char));
	if(str->data == NULL){
		fprintf(stderr,"Memory allocation failed \n");
		return -1;
	}
	for(int i=0;i<counter;i++){
		*(str->data + i) = *(content + i);
	}
	*(str->data + (counter + 1)) = '\0';
	return 0;
}
size_t lenAtomicString(const AtomicString* str){
	return str->len;
}
