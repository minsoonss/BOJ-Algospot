//#pragma warning(disable:4996)
#include<iostream>
//#include<queue>

using namespace std;
//배열로 만들기

//queue<int> q;

int n=0;
int m=0;
int start=0;
int a[1000][1000];
bool check_bfs[1000];
bool check_dfs[1000];


struct Queue
{
   int data[10000];
   int head, tail;
   Queue()
   {
      head = 0;
      tail = 0;
   }
   void push(int num)
   {
      data[tail++] = num;
   }
   bool empty()
   {
      return head == tail;
   }
   int size()
   {
      return tail-head;
   }
   int front()
   {
      return data[head];
   }
   int back()
   {
      return data[tail-1];
   }
   void pop()
   {
      head++;
   }

};

Queue q;

void input()
{
   
   cin >> n >> m >> start ;

   if(n>=1&&n<=1000
      &&m>=1&&m<=10000){
      for(int i=0; i<m; i++)  //이차원 배열에 정점들의 연결선 입력하기
      {
         int u,v;
         cin >> u;
         cin >> v;
         a[u][v] = a[v][u] = 1;
      }//2차원 배열 완성
   }
}

void dfs(int x)
{
   check_dfs[x] =  true;
   cout << x << " ";
   for(int i=1; i<=m; i++)
   {
      if(a[x][i] == 1 && check_dfs[i] == false)
      {
         dfs(i);
      }
   }
   

}

void bfs(int x)
{
   check_bfs[x] = true;
   q.push(x);
   while (!q.empty())
   {
      int x = q.front();
      q.pop();
      cout << x << " ";

      for(int i=1; i<= m ; i++)
      {
         if(a[x][i] == 1&&check_bfs[i] == false)
         {
            check_bfs[i] = true;
            q.push(i);
         }

      }
   }
   
}
int main()
{
   
   input();
   dfs(start);
   cout <<"\n";
   bfs(start);
   cout <<"\n";
}