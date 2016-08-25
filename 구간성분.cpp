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
	if(compare == firstlength){ //처음들어온 문자열이 짧을경우
		compareStr(first,second);
	}
	else{ //처음들어온 문자열이 길 경우
		compareStr(second,first);
	}

	return 0;
}
void compareStr(char *first, char * second){

}