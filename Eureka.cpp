#include <stdio.h>
int arr[1001];
int num[50];
void search(int sum,int max,int index)
{
	int i = 0 ;
	for(i = 0 ;i < max ; i ++ )
	{
		if(num[i]+sum<=1000 && index == 2 ){
			arr[ (num[i]+sum) ] = 1;
		}
		if(index < 2){
			search((num[i]+sum) , max,index+1);
		}
	}
}
int main()
{
	int n;
	int i = 0 ;
	int result = 0;
	int target = 0 ;
	scanf("%d",&n);
	for( i = 1 ; 1 ; i ++ )
	{
		result += i;
		if(result>1000)break;
		num[i-1] = result;
	}
	search(0,i-1,0);

	for( i = 0 ; i < n; i ++ ){
		scanf("%d",&target);
		printf("%d\n",arr[target]);
	}


	return 0;
}