#include <stdio.h>
int arr[21][21];
int AllCount = 0 ;
int result = 0;
void search(int a, int b,int n,int m,int Count)
{
	int i , j ;
	for(i = a ; i < n ; i ++ )
	{
		for( j = i==a?b:0  ; j< m ; j ++ )
		{
			if(!arr[i][j]){//朔牒析 凶
				if(j>0 && i < n-1 && !arr[i+1][j] && !arr[i+1][j-1]){  //  け
					arr[i][j] = arr[i+1][j] = arr[i+1][j-1] = Count+1; //けけ
					if(Count+1 == AllCount)result++;
					else search(i,j,n,m,Count+1);
					arr[i][j] = arr[i+1][j] = arr[i+1][j-1] = 0;
				}
				if(j<m-1 && i < n-1 && !arr[i+1][j] && !arr[i+1][j+1]){ //け
					arr[i][j] = arr[i+1][j] = arr[i+1][j+1] = Count+1;  //けけ

					if(Count+1 == AllCount)result++;
					else search(i,j,n,m,Count+1);
					arr[i][j] = arr[i+1][j] = arr[i+1][j+1] = 0;
				}
				if(j<m-1 && i < n-1 && !arr[i][j+1] && !arr[i+1][j+1]){ //けけ
					arr[i][j] = arr[i][j+1] = arr[i+1][j+1] = Count+1;  //  け
					if(Count+1 == AllCount)result++;
					else search(i,j,n,m,Count+1);
					arr[i][j] = arr[i][j+1] = arr[i+1][j+1] = 0;
				}
				if(j<m-1 && i < n-1  && !arr[i][j+1] && !arr[i+1][j]){ //けけ
					arr[i][j] = arr[i][j+1] = arr[i+1][j] = Count+1;   //け
					if(Count+1 == AllCount)result++;
					else search(i,j,n,m,Count+1);
					arr[i][j] = arr[i][j+1] = arr[i+1][j] = 0;
				}
				return;
			}
		}
	}
}
int main()
{
	int testcase = 0 ;
	int iCount = 0 ;
	int n , m ; 
	int i,j;
	int empty = 0;
	char temp = 0;
	char buf;
	scanf("%d",&testcase);

	for(iCount = 0 ; iCount < testcase ; iCount ++ )
	{

		scanf("%d %d\n",&n,&m);
		result = 0;
		empty = 0;
		for( i = 0 ; i < n ; i ++ )
		{
			for( j = 0 ; j < m ; j ++ )
			{
				scanf("%c",&temp);
				if(temp=='#'){
					arr[i][j] = 1;
				}
				else{
					arr[i][j] = 0;
					empty++;
				}
			}
			scanf("%c",&buf);

		}
		if(empty%3!=0)printf("%d\n",0);
		else {
			AllCount = (empty/3);
			search(0,0,n,m,0);
			printf("%d\n",result);
		}
	}
	return 0;
}