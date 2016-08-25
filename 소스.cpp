#include <stdio.h>

FILE *input;
FILE *output;
int point;
int Btodtime;
char reBarray[200][200];


void BtoD(int startrow, int startcol, int row, int col, char Barray[200][200])
{
	int i,j,k;
	int check0=0;
	int check1=0;
	int evenrow;
	int evencol;
	char temp;




	if(startrow == row || startcol == col)
	{
		return;
	}
	for(i=startrow; i<row; i++)
	{
		for(j=startcol; j<col; j++)
		{

			if(i==startrow && j==startcol)
			{
				temp = Barray[startrow][startcol];
			}
			else
			{
				if(temp == Barray[i][j])
				{
					check0 = 0;
					check1 = 0;
					continue;
				}
				else
				{
					check1 = 1;
					break;
				}


			}
		}
		if(check0 != check1)
		{
			break;
		}
	}//for




	if(check0 == check1)
	{
		Btodtime++;
		if(Btodtime==50 ||  Btodtime==100 || Btodtime==150 || Btodtime==200 || Btodtime==250 || Btodtime==300 || Btodtime==350 || Btodtime==400 || Btodtime==450 || Btodtime==500 || Btodtime==550|| Btodtime==600)
		{
			fprintf(output,"\n");
			printf("\n");
			Btodtime=0;
		}
		fprintf(output,"%c",Barray[startrow][startcol]);
		printf("%c",Barray[startrow][startcol]);
	}



	else
	{
		fprintf(output,"D");
		printf("D");
		if((row-startrow)%2==0)
		{
			evenrow = 0;
		}
		else
		{
			evenrow = 1;
		}
		if((col-startcol)%2==0)
		{
			evencol = 0;
		}
		else
		{
			evencol = 1;
		}

		if(evenrow==0 && evencol==0)
		{
			/* BtoD(startrow,startcol,row/2,col/2,Barray);
			BtoD(startrow,col/2,row/2,col,Barray);
			BtoD(row/2,startcol,row,col/2,Barray);
			BtoD(row/2,col/2,row,col,Barray); */

			BtoD(startrow,startcol,(startrow+row)/2,(startcol+col)/2,Barray);
			BtoD(startrow,(startcol+col)/2,(startrow+row)/2,col,Barray);
			BtoD((startrow+row)/2,startcol,row,(startcol+col)/2,Barray);
			BtoD((startrow+row)/2,(startcol+col)/2,row,col,Barray);



		}
		else if(evenrow==1 && evencol==0)
		{

			BtoD(startrow,startcol,((startrow+row)/2)+1,(startcol+col)/2,Barray);
			BtoD(startrow,(startcol+col)/2,((startrow+row)/2)+1,col,Barray);
			BtoD(((startrow+row)/2)+1,startcol,row,(startcol+col)/2,Barray);
			BtoD(((startrow+row)/2)+1,(startcol+col)/2,row,col,Barray);


		}
		else if(evenrow==0 && evencol==1)
		{

			BtoD(startrow,startcol,(startrow+row)/2,((startcol+col)/2)+1,Barray);
			BtoD(startrow,((startcol+col)/2)+1,(startrow+row)/2,col,Barray);
			BtoD((startrow+row)/2,startcol,row,((startcol+col)/2)+1,Barray);
			BtoD((startrow+row)/2,((startcol+col)/2)+1,row,col,Barray);

		}
		else if(evenrow==1 && evencol==1)
		{
			BtoD(startrow,startcol,((startrow+row)/2)+1,((startcol+col)/2)+1,Barray);
			BtoD(startrow,((startcol+col)/2)+1,((startrow+row)/2)+1,col,Barray);
			BtoD(((startrow+row)/2)+1,startcol,row,((startcol+col)/2)+1,Barray);
			BtoD(((startrow+row)/2)+1,((startcol+col)/2)+1,row,col,Barray);
		}


	}//else
	return;

}

void fill(int startrow,int startcol, int row, int col, char Darray[200],char reBarray[200][200])
{
	int i,j,k;
	if(Darray[point+2]=='D')
	{
		for(i=startrow ; i<row; i++)
		{
			for(j=startcol ;  j<col ; j++)
			{
				reBarray[i][j] = Darray[point+1];
			}
		}
		point=point+2;
	}
	else
	{
		for(i=startrow ; i<row; i++)
		{
			for(j=startcol ;  j<col ; j++)
			{
				reBarray[i][j] = Darray[point++];
			}
		}

	}



}
void DtoB(int startrow, int startcol, int row, int col,char  Darray[200],int sizeD, char reBarray[200][200])
{
	int i,j,k;
	int check0=0;
	int check1=0;
	int evenrow;
	int evencol;
	int nextD;

	//   for(point=0; point<sizeD; point++)
	//   {

	if((row==startrow ))//&& row-startrow==1 || col==startcol) || (row-startrow==1 || col-startcol==1))
	{   
		return;
	}
	else if(col==startcol)
	{
		return;
	}

	if(Darray[point]=='D')
	{
		point++;
		if((row-startrow)%2==0)
		{
			evenrow = 0;
		}
		else
		{
			evenrow = 1;
		}
		if((col-startcol)%2==0)
		{
			evencol = 0;
		}
		else
		{
			evencol = 1;
		}

		if(evenrow==0 && evencol==0)
		{

			DtoB(startrow,startcol,(startrow+row)/2,(startcol+col)/2,Darray,sizeD,reBarray);
			DtoB(startrow,(startcol+col)/2,(startrow+row)/2,col,Darray,sizeD,reBarray);
			DtoB((startrow+row)/2,startcol,row,(startcol+col)/2,Darray,sizeD,reBarray);
			DtoB((startrow+row)/2,(startcol+col)/2,row,col,Darray,sizeD,reBarray);



		}
		else if(evenrow==1 && evencol==0)
		{
			DtoB(startrow,startcol,((startrow+row)/2)+1,(startcol+col)/2,Darray,sizeD,reBarray);
			DtoB(startrow,(startcol+col)/2,((startrow+row)/2)+1,col,Darray,sizeD,reBarray);
			DtoB(((startrow+row)/2)+1,startcol,row,(startcol+col)/2,Darray,sizeD,reBarray);
			DtoB(((startrow+row)/2)+1,(startcol+col)/2,row,col,Darray,sizeD,reBarray);


		}
		else if(evenrow==0 && evencol==1) //여기 문제
		{
			if(row-startrow==2 && col-startcol==3)
			{
				DtoB(startrow,startcol,row,((startcol+col)/2)+1,Darray,sizeD,reBarray);
				DtoB(startrow,((startcol+col)/2)+1 ,row ,col,Darray,sizeD,reBarray);
				return;
			}
			DtoB(startrow,startcol,(startrow+row)/2,((startcol+col)/2)+1,Darray,sizeD,reBarray);
			DtoB(startrow,((startcol+col)/2)+1,(startrow+row)/2,col,Darray,sizeD,reBarray);
			if(col!=3)
			{
				DtoB((startrow+row)/2,startcol,row,((startcol+col)/2)+1,Darray,sizeD,reBarray);
				DtoB((startrow+row)/2,((startcol+col)/2)+1,row,col,Darray,sizeD,reBarray);
			}
		}

		else if(evenrow==1 && evencol==1)
		{
			DtoB(startrow,startcol,((startrow+row)/2)+1,((startcol+col)/2)+1,Darray,sizeD,reBarray);
			DtoB(startrow,((startcol+col)/2)+1,((startrow+row)/2)+1,col,Darray,sizeD,reBarray);
			DtoB(((startrow+row)/2)+1,startcol,row,((startcol+col)/2)+1,Darray,sizeD,reBarray);
			DtoB(((startrow+row)/2)+1,((startcol+col)/2)+1,row,col,Darray,sizeD,reBarray);
		}

	}//if(D일떄)
	else if(Darray[point]!='D')
	{
		/*   if(row-startrow ==1 && col-startcol==1)
		{
		reBarray[startrow][startcol]=Darray[point];
		point++;
		return;
		}
		*/

		if(Darray[point+1]=='D')
		{
			for(i=startrow;i<row;i++)
			{
				for(j=startcol; j<col; j++)
				{
					reBarray[i][j]=Darray[point];
				}
			}
			point++;
		}//if

		else //뒤가 바로 D가 아닐떄
		{
			if(row-startrow ==1 && col-startcol ==1)
			{
				for(i=startrow;i<row;i++)
				{
					for(j=startcol; j<col; j++)
					{
						reBarray[i][j]=Darray[point++];
					}
				}
				return;
			}
			else //if(row-startrow ==1 || col-startcol ==1)
			{
				for(i=startrow;i<row;i++)
				{
					for(j=startcol; j<col; j++)
					{
						reBarray[i][j]=Darray[point];
					}
				}
				point++;
				return;
			}
		}//else

	}//else

	//}

	return;


}
int main()
{
	int row,col;
	char BD;
	int i,j,k;
	char Barray[200][200];
	char Darray[200];
	//   char reBarray[200][200];
	char blank;
	int sizeD;
	int blanktime[20];
	int time=0;
	input = fopen("bitmap.inp","r");
	output = fopen("bitmap.out","w");

	while(1)
	{

		fscanf(input,"%c",&BD);

		if(BD=='#')
		{
			break;
		}
		fscanf(input,"%d %d",&row,&col);
		fscanf(input,"%c",&blank);

		if(BD=='B')
		{
			for(i=0; i<row; i++)
			{
				for(j=0; j<col; j++)
				{
					fscanf(input,"%c",&blank);
					if(blank=='\n')
					{
						j--;
						continue;
					}
					else
					{

						Barray[i][j] = blank;
					}
					///fscanf(input,"%c",&Barray[i][j]);
				}
			}
			fprintf(output,"D%4d%4d\n",row,col);
			BtoD(0,0,row,col,Barray);
			Btodtime=0;
			fprintf(output,"\n");
			printf("\n");
			fscanf(input,"%c",&blank);

		}//if

		else if(BD=='D')
		{
			reBarray[200][200]=NULL;

			for(i=0; i<row*col; i++)
			{     
				fscanf(input,"%c",&blank);
				if(blank=='\n')
				{
					sizeD = i;
					break;
				}
				Darray[i] = blank;
			}

			fprintf(output,"B%4d%4d\n",row,col);
			DtoB(0,0,row,col,Darray,sizeD,reBarray);
			//fscanf(input,"%c",&blank);


			for(i=0; i<row; i++)
			{
				for(j=0; j<col; j++)
				{
					fprintf(output,"%c",reBarray[i][j]);
					printf("%c",reBarray[i][j]);
					time++;
					if(time==50 ||  time==100 || time==150 || time==200 || time==250 || time==300 || time==350 || time==400 || time==450 || time==500 || time==550|| time==600)
					{
						fprintf(output,"\n");
						printf("\n");
						time=0;
					}

				}
				if(i==(row-1) && j==(col))
				{
					fprintf(output,"\n");
					printf("\n");
				}

			}
			time=0;
			//printf("\n");





		}// else if

	}//while




}