#include <stdio.h>
#include <queue>
using namespace std;
   int index[1000][1000];
int v[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int main(){


   int x,y;
   scanf("%d %d",&x,&y);
   int gar;
   int cnt=0;

   queue <pair<int,int>> q;
   int count=0,ret=0;
   
   int check=0;
   for(int i=0;i<y;i++){
      for(int j=0;j<x;j++){
         scanf("%d",&index[i][j]);
         if(index[i][j] == 1){
            q.push(make_pair(i,j));
            cnt++;
            check++;
         }
         else if(index[i][j] == 0)
            index[i][j] = -2;
         else check++;
      }
   }
   if(check == x*y)
      printf("0");
   else{
      while(!q.empty()){

         int cnt2=cnt;
         cnt=0;
         for(int j=0;j<cnt2;j++){
            for(int i=0;i<4;i++){
               if(index[q.front().first+v[i][0]][q.front().second+v[i][1]] == -2){
                  q.push(make_pair(q.front().first+v[i][0],q.front().second+v[i][1]));
                  index[q.front().first+v[i][0]][q.front().second+v[i][1]] = 1;
                  check++;
                  cnt++;
               }
            }
            q.pop();
         }
         if(q.empty())
            break;
         count++;
      }
   
   if(count == 0)
      printf("-1");
   else
      printf("%d",count);
   }
   return 0;
}