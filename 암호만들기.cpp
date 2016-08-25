#include <stdio.h>

char password[15];
char result[15];
int the_number_of_input;
int the_number_of_output;
int index;
int check;
void bubble();
bool calc(int index1, int index2);
int main(){
	char enter;
	scanf("%d %d%c",&the_number_of_output,&the_number_of_input,&enter);
	for(int i = 0; i < the_number_of_input; i++){
		scanf("%c%c",&password[i],&enter);
	}
	bubble();
	calc(0,0);

	return 0;
}
void bubble(){
	char temp;
	for(int i = 0; i < the_number_of_input-1; i++){
		for(int j = 0; j < the_number_of_input-1; j++){
			if(password[j] > password[j+1]){
				temp = password[j];
				password[j] = password[j+1];
				password[j+1] = temp;
			}
		}
	}
}
bool calc(int index1, int index2){
	int nullcheck = 0;
	check = 0;
	if(index1 == the_number_of_output-1){
		result[index1] = password[index2];
		for(int i = 0; i < the_number_of_output; i++){
			if(result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o'|| result[i] == 'u'){
				check++;
			}
			/*if(result[i] == NULL){
				nullcheck++;
			}*/
		}
		//if(nullcheck > 0)return true;
		if(check < 1 || check > the_number_of_output-2)return true;
		for(int i = 0; i < the_number_of_output; i++){
			printf("%c",result[i]);
		}printf("\n");
		if(index2 < the_number_of_input-1){
			calc(index1,index2+1);
		}
		else{
			return true;
		}
	}
	/*else{
	for(; index2+index1 <= the_number_of_input; index2++){
	result[index1] = password[index2];
	calc(index1+1,index2+1);
	}
	}*/
	else{
		for(; index2 <= the_number_of_input - (the_number_of_output-index1); index2++){
			result[index1] = password[index2];
			if(index2<the_number_of_input-1){
				calc(index1+1,index2+1);
			}
		}
	}
}