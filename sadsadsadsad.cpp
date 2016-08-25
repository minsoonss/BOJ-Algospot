//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[8]={0,};
//    int selected[5]={0,};
//    int max = 0, index = 0 , sum =0;
//    for( i = 0 ; i < 8 ; i ++ )
//    {
//        scanf("%d",&arr[i]);
//    }
//    for(int k = 0 ; k < 5; k ++ )
//    {
//        max = 0;
//        for(i = 0 ; i < 8; i ++ )
//        {
//            if(arr[i] > max)
//            {
//                max = arr[i];
//                index = i;
//            }
//        }
//        sum += arr[index];
//        arr[index] = -1;
//         
//    }
//    printf("%d\n",sum);
//    for(i = 0 ; i < 8; i ++)if(arr[i]<0)printf("%d ",i+1);
//    return 0;
//}