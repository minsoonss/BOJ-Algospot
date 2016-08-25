#include <stdio.h>

FILE *input;
FILE *output;

long long byair[105][105][105];
long long list[3][105];
long long list2[3][105];
long long inp[105][6];
long long total=0;
int num;
long long a,b,c,d,e,f;
long long i,j,k,l,m;
long long list2size=0;
long long list2size2=0;
long long list2size3=0;
long long temp1=0;
long long temp2=0;
long long temp3=0;

void swap(long long *a, long long *b)
{   

	//long long temp;
	long long tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}
long long partition(long long list[], long long left, long long right)
{
	long long pivot;
	long long low,high;
	//long long temp;
	low = left;
	high = right+1;
	pivot = list[left];

	do{
		do low++;
		while(list[low] <pivot);
		do high--;
		while(list[high]>pivot);

		if(low<high)
			swap(&list[low],&list[high]);
	}while(low<high);

	swap(&list[left],&list[high]);
	return high;
}
void quicksort(long long list[],long long left,long long right)
{
	if(left<right){
		long long pivot = partition(list,left,right);

		quicksort(list,left,pivot-1);
		quicksort(list,pivot+1,right);
	}
}



int main()
{

	input = fopen("air.inp","r");
	output = fopen("air.out","w");

	fscanf(input,"%d",&num);

	for(i=0; i<num; i++)
	{
		fscanf(input,"%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f);
		inp[i][0] = a;
		inp[i][1] = b;
		inp[i][2] = c;
		inp[i][3] = d;
		inp[i][4] = e;
		inp[i][5] = f;
	}


	for(i=0; i<(num); i++)
	{
		list[0][temp1++] = inp[i][0];
		list[0][temp1++] = inp[i][3];
	}

	for(i=0; i<(num); i++)
	{
		list[1][temp2++] = inp[i][1];
		list[1][temp2++] = inp[i][4];
	}
	for(i=0; i<(num); i++)
	{
		list[2][temp3++] = inp[i][2];
		list[2][temp3++] = inp[i][5];
	}


	quicksort(list[0],0,num*2);
	quicksort(list[1],0,num*2);
	quicksort(list[2],0,num*2);




	for(i=1; i<=num*2; i++)
	{
		if(list[0][i] == list[0][i+1])
		{
			continue;
		}
		else
		{
			list2[0][list2size++] = list[0][i];
		}
	}

	for(i=1; i<=num*2; i++)
	{
		if(list[1][i] == list[1][i+1])
		{
			continue;
		}
		else
		{
			list2[1][list2size2++] = list[1][i];
		}
	}

	for(i=1; i<=num*2; i++)
	{
		if(list[2][i] == list[2][i+1])
		{
			continue;
		}
		else
		{
			list2[2][list2size3++] = list[2][i];
		}
	}


	//¿Å°Ü´ã±â 


	for(i=0; i<num; i++)
	{
		for(j=0; j<(list2size); j++)
		{
			if(inp[i][0] == list2[0][j])
			{
				a = j;
				break;
			}
		}
		for(j=0; j<(list2size); j++)
		{
			if(inp[i][3] == list2[0][j])
			{
				d = j;
				break;
			}
		}
		for(j=0; j<(list2size2) ; j++)
		{
			if(inp[i][1] == list2[1][j])
			{
				b = j;
				break;
			}
		}
		for(j=0; j<(list2size2) ; j++)
		{
			if(inp[i][4] == list2[1][j])
			{
				e = j;
				break;
			}
		}

		for(j=0; j<(list2size3) ; j++)
		{
			if(inp[i][2] == list2[2][j])
			{
				c = j;
				break;
			}
		}
		for(j=0; j<(list2size3) ; j++)
		{
			if(inp[i][5] == list2[2][j])
			{
				f = j;
				break;
			}
		}
		for(k=a; k<d; k++)
		{
			for(l=b; l<e; l++)
			{
				for(m=c; m<f; m++)
				{
					byair[k][l][m]++;
				}
			}
		}//¼ýÀÚ Âï³¢ 
	}

	for(i=0; i<list2size; i++){
		for(j=0; j<list2size2; j++){
			for(k=0; k<list2size3; k++){
				if(byair[i][j][k] >= 2){
					total += (list2[0][i+1] -list2[0][i]) * (list2[1][j+1] -list2[1][j]) * (list2[2][k+1] -list2[2][k]);
				}
			}
		}

	}
	fprintf(output,"%lld\n",total);// %d %d\n",total,part,none);
	printf("%lld\n",total);

}