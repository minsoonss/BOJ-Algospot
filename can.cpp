#include <stdio.h>

void calc(int a);
int main(){
	int a;
	scanf("%d",&a);
	for(int i = 0; i < a; i++){
		calc(i+1);
	}
	return 0;
}
void calc(int a){
	int white, black;
	scanf("%d %d",&black,&white);
	if(white%2 == 0)printf("testcase%d\nblack\n",a);
	else printf("#testcase%d\nwhite\n",a);

}