#include <stdio.h>
#include <string>

void compareStr(char *first, char * second);
int main(){
	char first[1501];
	char second[1501];
	int firstlength;
	int secondlength;
	scanf("%s",first);
	scanf("%s",second);

	firstlength = strlen(first);
	secondlength = strlen(second);

	int compare = firstlength < secondlength ? firstlength : secondlength;
	printf("%d",compare);
	if(compare == firstlength){ //ó������ ���ڿ��� ª�����
		compareStr(first,second);
	}
	else{ //ó������ ���ڿ��� �� ���
		compareStr(second,first);
	}

	return 0;
}
void compareStr(char *first, char * second){

}