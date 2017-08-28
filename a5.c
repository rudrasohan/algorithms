//heapify code 

#include <stdio.h>
#include <stdlib.h>


void print(int *A, int n);
void maxheapify(int *A, int *Q1, int n, int i);
void minheapify(int *A, int *Q2, int n, int i);
void makemaxheap(int *A, int *Q1, int n);
void makeminheap(int *A, int *Q2, int n);
void prepareI(int *Q, int *I, int s);
void heapsort(int *H, int *Q, int s);
int getmin(int *A, int *Q2);
int getmax(int *A, int *Q1);
void maxreplace(int *a, int *q1, int *q2, int *i1, int *i2,int v, int s);
void minreplace(int *a, int *q1, int *q2, int *i1, int *i2,int v, int s);
int update_arr(int *M, int *L, int *R, int *a, int *H,int *q1, int *q2, int *i1, int *i2,int n,int s);
void copy_arr(int *M,int *L,int *R,int *H,int n_L,int s, int n_R,int n);
void quicksort(int *M, int n, int s);
void swap1(int a, int b);

void main()
{
	printf("Give me the number of elements in your array: ");
	int n;
	scanf("%d", &n);
	int i;
	int *M=(int*)malloc(n*sizeof(int));
	printf("Please enter your array: \n");
	
	for(i=0;i<n;i++)
	{
		//printf("Enter element no. %d: ", i+1);
		scanf("%d",&M[i]);
	}
	
	int s;
	printf("Enter the memory of your RAM (Not more than 100): ");
	scanf("%d", &s);
	
	quicksort(M,n,s);
}

void swap1(int a, int b)
{
	int swap=a;
	a=b;
	b=swap;
}

void print(int *A, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d |", *(A+i));
	}
	
	printf("\n");
}

int getmin(int *A, int *Q2)
{
	return(A[Q2[0]]);
}

int getmax(int *A, int *Q1)
{
	return(A[Q1[0]]);
}


void makemaxheap(int *A, int *Q1, int n)
{
	int i;
	for(i=(n/2)-1; i>=0; i--)
	{
		maxheapify(A,Q1,n,i);
	}
}

void makeminheap(int *A, int *Q2, int n)
{
	int i;
	for(i=(n/2)-1; i>=0; i--)
	{
		minheapify(A,Q2,n,i);
	}
}

void prepareI(int *Q, int *I, int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		I[Q[i]]=i;
	}
}


void maxheapify(int *A, int *Q1, int n, int i)
{
	int largest=i;
	int a=2*(i)+1;
	int b=2*(i)+2;
	
	int l=-99;
	int r=-99;
	
	if (a<n)
	{
		l=a;
	}
	
	if (b<n)
	{
		r=b;
	}
	
		

	if (l!=-99 && *(A+Q1[l])>*(A+Q1[largest]))
		largest = l;
	if (r!=-99 && *(A+Q1[r])>*(A+Q1[largest]))
		largest = r;
	if (largest !=  i)
	{
		int swap = *(Q1+i);
		*(Q1+i) = *(Q1+largest);
		*(Q1+largest) = swap;
		maxheapify(A, Q1, n, largest);
	}
}

void minheapify(int *A, int *Q2, int n, int i)
{
	int smallest=i;
	int a=2*(i)+1;
	int b=2*(i)+2;
	
	int l=-99;
	int r=-99;
	
	if (a<n)
	{
		l=a;
	}
	if (b<n)
	{
		r=b;
	}
	
	if (l!=-99 && *(A+Q2[l])<*(A+Q2[smallest]))
		smallest = l;
	if (r!=-99 && *(A+Q2[r])<*(A+Q2[smallest]))
		smallest = r;
	if (smallest != i)
	{
		int swap = *(Q2+i);
		*(Q2+i) = *(Q2+smallest);
		*(Q2+smallest) = swap;
		minheapify(A, Q2, n, smallest);
	}
}

void heapsort(int *H, int *Q, int s)
{
	int i;
		
 	int *x=(int*)malloc(s*sizeof(int));
 	
    for (i=s-1; i>=0; i--)
    {
        int swap = H[Q[0]];
        H[Q[0]]=H[Q[i]];
        H[Q[i]]=swap;
        
        maxheapify(H, Q, i, 0);
        x[i]=H[Q[i]];
    }
    
    for(i=0;i<s;i++)
	{
		H[i]=x[i];
	}
}


void quicksort(int *M, int n, int s)
{
	int *A=(int *)malloc(s*sizeof(int));
	int *Q1=(int *)malloc(s*sizeof(int));
	int *I1=(int *)malloc(s*sizeof(int));
	int *Q2=(int *)malloc(s*sizeof(int));
	int *I2=(int *)malloc(s*sizeof(int));
	int *H=(int *)malloc(s*sizeof(int));
	int *L =(int *)malloc((n-s)*sizeof(int));
	int *R =(int *)malloc((n-s)*sizeof(int));
	int i;
	for(i=0;i<s;i++)
	{
		A[i]=M[i];
		Q1[i]=i;
		I1[i]=i;
		Q2[i]=i;
		I2[i]=i;
	}
	
	makemaxheap(A,Q1,s);
	prepareI(Q1,I1,s);
	makeminheap(A,Q2,s);
	prepareI(Q2,I2,s);
	
	
	int n_L=update_arr(M,L,R,A,H,Q2,Q1,I1,I2,n,s);
    int n_R=n-(n_L+s);
    
    heapsort(H,Q2,s);
    
    copy_arr(M,L,R,H, n_L, s, n_R, n);
    
    free(A);
    free(H);
    free(Q1);
   	free(Q2);
    free(I1);
    free(I2);
    free(L);
    free(R);
    
    quicksort(M,n_L,s);
    quicksort(M+n_L+s,n_R,s);
}

int update_arr(int *M, int *L, int *R, int *a, int *H,int *q1, int *q2, int *i1, int *i2,int n,int s)
{
  int mini=getmin(a,q1);
  int maxi=getmax(a,q2);
  
  int l=0,r=0;
  
  for(int i=s;i<n;i++)
  {
    if(M[i]<=mini)
    {
      L[l++]=M[i];
    }
    else if(M[i]>=maxi)
    {
      R[r++]=M[i];
    }
    else

    {
       if(l<r)
      {
        L[l++]=mini;
        minreplace( a, q1, q2, i1, i2, M[i],s);
        mini=getmin(a,q1);
      }
      else
      {
        R[r++]=maxi;
        maxreplace( a, q1, q2, i1, i2, M[i],s);
        maxi=getmax(a,q2);
      }
    }
   }
   
   for(int i=0;i<s;i++)
    {
      H[i]=a[i];
    }
   
      return l;
}


void minreplace(int *a, int *q1, int *q2, int *i1, int *i2,int v, int s)
{
  int i = q1[0];
  
  a[i]  = v;
  
  int j = i2[i];
  
  minheapify(a,q1,s,0);
  
  
  while((j>0)&&(a[q2[(j-1)/2]]<a[q2[j]]))
  {
    swap1(q2[(j-1)/2],q2[j]);
    j=(j-1)/2;
  }
  for(i=0;i<s;i++)
  {
    j=q1[i];
    i1[j]=i;
  }
  for(i=0;i<s;i++)
  {
    j=q2[i];
    i2[j]=i;
  }

}



void maxreplace(int *a, int *q1, int *q2, int *i1, int *i2,int v, int s)
{
  int i = q2[0];
  
  a[i]  = v;
  
  int j = i1[i];
  
  maxheapify(a,q2,s,0);
  
  while((j>0)&&(a[q1[(j-1)/2]]>a[q1[j]]))
  {
    swap1(q1[(j-1)/2],q1[j]);
    j=(j-1)/2;
  }
  
  for(i=0;i<s;i++)
  {
    j=q2[i];
    i2[j]=i;
  }
  
  for(i=0;i<s;i++)
  {
    j=q1[i];
    i1[j]=i;
  }
}


void copy_arr(int *M,int *L,int *R,int *H,int n_L,int s, int n_R,int n)
{
  int l=0,h=0,r=0,i=0;
  
  while(l<n_L)
    M[i++]=L[l++];
  
  while(h<s)
    M[i++]=H[h++];
  
  while(r<n_R)
    M[i++]=R[r++];
}
