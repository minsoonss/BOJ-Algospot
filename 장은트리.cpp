#include<stdio.h>


FILE *input;
FILE *output;

int preorder[100000];
int inorder[100000];
int postorder[100000];
int time;
int bigsize;
int LR;
int lnum;
int rnum;
int index[100000];
int search(int post[], int x, int n)
{
	int i;
    for ( i = 0; i < n; i++){
      if (post[i] == x)
         return i;
	}
    return -1;
}

void Madepost(int in[], int pre[], int n)
{
    int r = search(in, pre[0], n);
 
   if (r != 0)
      Madepost(in, pre+1, r);
 
   if (r != n-1)
      Madepost(in+r+1, pre+r+1, n-r-1);
 
	fprintf(output,"%d\n",pre[0]);
	printf("%d\n",pre[0]);
}



void madepost(int start,int finish,int size,int inside[100000])
{
   
   int i=0;
   int point;
   int inpoint;
   

   inpoint = preorder[time++];
   while(inpoint != inorder[i++])
   {
      point = i;
   }

   if(i==1)
   {
	  
	 point = size;
	 size=0;
      for(i=start+1; i<point; i++)
      {
         inside[size++] = inorder[i];
      }
     
	  madepost(start+2,point,size,inside);

	  fprintf(output,"%d\n",inpoint);
      printf("%d\n",inpoint);
      return;
   }
   if(start==finish)
   {
      fprintf(output,"%d\n",inpoint);
      printf("%d\n",inpoint);
      return;
   }

   if((point > start && point < finish) && point!=finish-1)
   {
      size=0;
      for(i=start; i<point; i++)
      {
         inside[size++] = inorder[i];
      }
      madepost(start,point-1,size,inside);
      size=0;
      for(i=point+1; i<=finish; i++)
      {
         inside[size++] = inorder[i];

      }
      madepost(point+1,finish,size,inside);
      fprintf(output,"%d\n",inpoint);
      printf("%d\n",inpoint);
      return;
   
   }
   
   if(point==finish-1);
   {
      size=0;

      for(i=start; i<point-1; i++)
      {
         inside[size++] = inorder[i];
      }
      madepost(start,point-1,size,inside);
      fprintf(output,"%d\n",inpoint);
      printf("%d\n",inpoint);
      return;
   }

}
void madepre(int start,int finish,int size,int pre[100000],int in[100000])//,int inside[10000])
{
	int inpoint;
	int postpoint;
	int point;
	int i,j,k;
	int rsize=0;
	int lsize=0;
	int leftpre[10000];
	int leftin[10000];
	int rightpre[10000];
	int rightin[10000];

	if(start == finish)
	{
 		fprintf(output,"%d\n",pre[0]);
		printf("%d\n",pre[0]);
		return;
	}
	if(3 == finish-start+1 && LR==1)
	{
 		fprintf(output,"%d\n",pre[2]);
		printf("%d\n",pre[2]);
		fprintf(output,"%d\n",pre[0]);
		printf("%d\n",pre[0]);
		return;
	}

	if(start == finish-1)
	{
		if(LR==0)
		{
		fprintf(output,"%d\n",pre[1]);
		printf("%d\n",pre[1]);
		fprintf(output,"%d\n",pre[0]);
		printf("%d\n",pre[0]);
		}
		else if(LR==1)
		{
		fprintf(output,"%d\n",pre[0]);
		printf("%d\n",pre[0]);
		fprintf(output,"%d\n",pre[1]);
		printf("%d\n",pre[1]);
						
		}return;
	
	}
	if(LR==0)
	{
	point = pre[size-1];
	postpoint = size-1;
	}
	else if(LR==1)
	{
	point = pre[0]; //²¿·Ò
	postpoint = finish-1;
	}//time++;
	for(i=0; i<bigsize-1; i++)
	{
		if(point == inorder[i])
		{
			inpoint = i;
			break;
		}
		inpoint = -1;
		//break;
	}

	if(inpoint == finish)
	{
		fprintf(output,"%d\n",point);
		printf("%d\n",point);
		lnum=0;
		for(j=start; j<inpoint; j++)
		{
			leftpre[lsize] = postorder[lnum++];
			leftin[lsize++] = inorder[j];
		}
		madepre(start,inpoint-1,lsize,leftpre,leftin);//pnum++;
		return;
	}

	if(inpoint >start  &&  inpoint< finish)
	{
		fprintf(output,"%d\n",point);
		printf("%d\n",point);
		lnum=0;

		
		for(j=start; j<inpoint; j++)
		{
			leftpre[lsize] = postorder[j];//¿ø·¡ lnum;
			leftin[lsize++] = inorder[j];
		}
		for(j=inpoint+1; j<=finish; j++)
		{
			//rightpre[rsize] = postorder[finish-j];
			rightin[rsize++] = inorder[j];
		}
		for(k=0; k<finish-inpoint; k++)
		{
			//rightin[k] = inorder[j];
			rightpre[k] = postorder[--postpoint];
		}
		LR=0;
 		madepre(start,inpoint-1,lsize,leftpre,leftin);//pnum++;
		LR=1;
		madepre(inpoint+1,finish,rsize,rightpre,rightin);

	}





}

void Mpre(int start, int end, int start2, int end2){
    int position;
	int root;
		if(start > end) 
		return;
    root = postorder[end2];
    printf("%d ",root);
	fprintf(output,"%d ",root);
	position = index[root];
    Mpre(start,position-1,start2,start2 + (position-1-start));
    Mpre(position+1,end,start2+position-start,end2-1);
}


int main()
{
   int size;
   int a,b;
   int i,j,k,m;
   int ordercase=0;
   int bb;

   input = fopen("tree.inp","r");
   output = fopen("tree.out","w");
      
   fscanf(input,"%d",&size);
   bigsize=size;
	//strcpy(rnum,bigsize);
   fscanf(input,"%d",&a);
   

   if(a==-1 )
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&preorder[k]);
   }
   
   }
   else if(a==0 )
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&inorder[k]);
	  index[inorder[k]] = k;

   }
   
   }
   else if(a==1 )
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&postorder[k]);
   }
      
   }


   fscanf(input,"%d",&b);

   if( b==-1)
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&preorder[k]);
   }
   
   }
   else if( b==0)
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&inorder[k]);
	  index[inorder[k]] = k;
   }
   
   }
   else if( b==1)
   {
   for(k=0; k<size; k++)
   {
      fscanf(input,"%d",&postorder[k]);
   }
      
   }

   if(a==-1 && b==0)
   {
	Madepost(inorder, preorder, bigsize);
//   madepost(0,size-1,size,postorder);
   }



   else if(a==0 && b==-1)
  {
	  Madepost(inorder, preorder, bigsize);
//   madepost(0,size-1,size-1,postorder);
   }
   
   else if(a==1 && b==0)
   {
	  //  Madepre(inorder, 0,preorder,0, bigsize);

//		   madepre(0,size-1,size,postorder,0);//,preorder);
   Mpre(0,size-1,0,size-1);
   }


   else if(a==0 && b==1)
   {
	//   Madepre(inorder, preorder, bigsize);
	  // madepre(0,size-1,size-1,0,0);//,preorder);
    Mpre(0,size-1,0,size-1);
   }



}







/*

#include <cstdio>
#include <cstring>
 
int l;
int str1[100005], str2[100005], find_root[100005];
 
void f(int s, int e, int s2, int e2){
    if(s > e) return;
    int root = str2[e2];
    printf("%d ",root);
    int pos = find_root[root];
    f(s,pos-1,s2,s2 + (pos-1-s));
    f(pos+1,e,s2+pos-s,e2-1);
}
int main(){
    scanf("%d",&l);
    for (int i=0; i<l; i++) {
        scanf("%d",&str1[i]);
        find_root[str1[i]] = i;
    }
    for (int i=0; i<l; i++) {
        scanf("%d",&str2[i]);
    }
    f(0,l-1,0,l-1);
}


*/