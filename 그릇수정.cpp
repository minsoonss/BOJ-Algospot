#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main(void)
{
    char arr[100];
    char ch;
    int height = 10, count = 0;
 
    while (scanf("%c",&ch) == 1)
    {
		if(ch == '\n')break;
        arr[count] = ch;
        count++;
    }
 
    for (int i = 1; i < count; i++)
    {
        if (arr[i] == arr[i-1])
            height = height + 5;
        else
            height = height + 10;
    }
 
    cout << height << endl;
}