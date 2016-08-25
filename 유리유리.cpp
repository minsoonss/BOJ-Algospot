#include<stdio.h>   
typedef struct D{
	int value; //값
	int num; //들어온순서
}D;
void BubbleSort(D *a,D *b){
	D temp=*a;
	*a=*b;
	*b=temp;
}
void show(int sum,D a[8]){
	printf("%d\n",sum);
	for(int i=0;i<5;i++)
		printf("%d ",a[i].num);
}
int main(void){
	int sum=0;
	int count=0;

	D a[8]={0,};

	for (int i = 0; i < 8; i++){ 
		scanf("%d",&a[i].value);//값 입력
		count+=1;
		a[i].num=count;
	} 

	for(int i=0;i<8;i++){
		for (int j = i + 1; j < 8; j++){ 
			if(a[i].value<a[j].value){ 
				BubbleSort(&a[i],&a[j]);
			} //점수 높은 순 버블정렬
			else if(a[i].value == a[j].value){
				if(a[i].num > a[j].num)
					BubbleSort(&a[i],&a[j]);
			}
		}
	}

	for(int i=0;i<5;i++){
		sum+=a[i].value;
	}//정렬된 함수에서 높은 점수 5개 합

	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(a[i].num>a[j].num)
				BubbleSort(&a[i],&a[j]);
		}
	}
	show(sum,a);//출력
	return 0;
}