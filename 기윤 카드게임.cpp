//#include <stdio.h>
//int n;
//int arr[1001];
//int table[1001][1001];
//int process()
//{
//	int i , j,sum, base = 0;
//	for( i = 1 ; i <= n; i ++)
//	{
//		table[i][i] = arr[i];
//	}
//	for( i = 1 ; i < n; i ++ )
//	{
//		base += arr[i];
//		sum = base;
//		for( j = 1 ;j+i <= n; j ++ ) // j ~ j + i
//		{
//			sum = sum - arr[j-1] + arr[j+i];
//			if(table[j][j+i-1] < table[j+1][j+i])
//				table[j][j+i] = sum - table[j][j+i-1];
//			else //if(table[j][j+i-1] > table[j+1][j+i-1])
//				table[j][j+i] = sum - table[j+1][j+i];
//		}
//	}
//	return table[1][n];
//}
//int main()
//{
//	int testcase;
//	int iCount;
//	int i = 0;
//
//	scanf("%d",&testcase);
//	for( iCount = 0 ; iCount < testcase; iCount ++ )
//	{
//
//		scanf("%d",&n);
//		for( i = 0 ; i < n ; i ++ )
//		{
//
//			scanf("%d",&arr[i+1]);
//		}
//
//		printf("%d\n",process());
//	}
//	return 0;
//}