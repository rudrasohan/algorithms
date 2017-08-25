#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* My teacher did not supply me the inputs, so I generated the service
   times randomly */
int *genjobs ( int n )
{
   int *t, i;

   t = (int *)malloc(n * sizeof(int));
   for (i=0; i<n; ++i) {
      t[i] = 1 + rand() % 30;
      printf("%3d", t[i]);
      if (i % 25 == 24) printf("\n");
   }
   if (n % 25) printf("\n");
   return t;
}

/* Returns the running time of the kth counter having schedule s */
int runtime ( int *t, int *s, int k )
{
   int i, T = 0;

   for (i=0; i<k; ++i) T += t[s[i]];
   return T;
}

/* Returns the maximum of the running times of the p processors */
int makespan ( int *t, int **S, int p )
{
   int i, ms = -1, rt;

   for (i=0; i<p; ++i) {
      rt = runtime(t,S[i]+1,S[i][0]);
      if (rt > ms) ms = rt;
   }
   return ms;
}

/* Returns the total waiting time of customers scheduled to counter k */
int waittime ( int *t, int *s, int k )
{
   int i, rt = 0, wt = 0;

   for (i=0; i<k; ++i) {
      wt += rt;
      rt += t[s[i]];
   }
   return wt;
}

/* Returns the sum of waittime() for all k */
int totalwaittime ( int *t, int **S, int p )
{
   int i, wt = 0;

   for (i=0; i<p; ++i) wt += waittime(t,S[i]+1,S[i][0]);
   return wt;
}

/* Function to neatly print the schedule S on p counters. S contains
   only the token numbers, so t also needs to be passed. */
void printschedule ( int **S, int p, int *t )
{
   int i, j;

   for (i=0; i<p; ++i) {
      printf("Counter %2d: ", i);
      for (j=1; j<=S[i][0]; ++j) {
         printf("%3d (%2d) ", S[i][j], t[S[i][j]]);
         if ((j < S[i][0]) && (j % 7 == 0)) printf("\n            ");
      }
      printf("\n");
   }
}

int **schedule1 ( int *t, int n, int p )
{
   int **S, *freeat, i, j, min, minidx;

   /* Allocate memory to S */
   S = (int **)malloc(p * sizeof(int *));
   for (j=0; j<p; ++j) {
      /* No more than n entries are necessary for each processor including
         the count at index zero. In fact, an allocation size of
         1+(n-(p-1)) is safe. */
      S[j] = (int *)malloc(n * sizeof(int));
      S[j][0] = 0;
   }

   /* Array to store the f_j vales */
   freeat = (int *)malloc(p * sizeof(int));
   for (j=0; j<p; ++j) freeat[j] = 0;

   for (i=0; i<n; ++i) {
      /* Compute p-fold minimum. This takes O(p) time. This can be improved
         to O(log p) time by using a min priority queue. But it is difficult
         to break ties using a min priority queue in the fashion described
         in the assignment. */
      min = freeat[0]; minidx = 0;
      for (j=1; j<p; ++j) {
         if (freeat[j] < min) {
            min = freeat[j];
            minidx = j;
         }
      }
      ++S[minidx][0];
      S[minidx][S[minidx][0]] = i;
      freeat[minidx] += t[i];
   }

   free(freeat);

   return S;
}

/* We want to merge sort t[] in the non-increasing order. But relocation
   of elements in t[] lets us lose the initial association of the token
   number i with t[i]. So we do not change t[] at all. We instead look
   into t[] via the index array idx[]. Initially, we have idx[i] = i for
   all i. When merge sort wants to relocate t[i] to index j, we put
   idx[j] = i. This means that t[idx[j]] is supposed to contain t[i].
   At the end, t[idx[0]], t[idx[1]], ..., t[idx[n-1]] is the desired
   sorted sequence. */

void mergesort ( int *t, int L, int R, int *idx )
{
   int L1, R1, L2, R2, i, j, k, *idxcpy;

   if (R <= L) return;
   L1 = L; R1 = (L + R) / 2; L2 = R1 + 1; R2 = R;
   mergesort(t,L1,R1,idx);
   mergesort(t,L2,R2,idx);
   idxcpy = (int *)malloc((R - L + 1) * sizeof(int));
   i = L1; j = L2; k = 0;
   while ((i <= R1) && (j <= R2)) {
      if (t[idx[i]] >= t[idx[j]]) {
         idxcpy[k] = idx[i];
         ++i;
      } else {
         idxcpy[k] = idx[j];
         ++j;
      }
      ++k;
   }
   while (i <= R1) {
      idxcpy[k] = idx[i];
      ++i; ++k;
   }
   while (j <= R2) {
      idxcpy[k] = idx[j];
      ++j; ++k;
   }
   for (i=0; i<=R-L; ++i) idx[L+i] = idxcpy[i];
   free(idxcpy);
}

/* This is same as schedule1() with the exception that we look into t[]
   via the index array idx[]. */
int **schedule2 ( int *t, int n, int p )
{
   int **S, *freeat, *idx, i, j, min, minidx;

   idx =  (int *)malloc(n * sizeof(int));
   for (i=0; i<n; ++i) idx[i] = i;
   mergesort(t,0,n-1,idx);

   S = (int **)malloc(p * sizeof(int *));
   for (j=0; j<p; ++j) {
      S[j] = (int *)malloc(n * sizeof(int));
      S[j][0] = 0;
   }

   freeat = (int *)malloc(p * sizeof(int));
   for (j=0; j<p; ++j) freeat[j] = 0;

   for (i=0; i<n; ++i) {
      min = freeat[0]; minidx = 0;
      for (j=1; j<p; ++j) {
         if (freeat[j] < min) {
            min = freeat[j];
            minidx = j;
         }
      }
      ++S[minidx][0];
      S[minidx][S[minidx][0]] = idx[i];
      freeat[minidx] += t[idx[i]];
   }

   free(freeat);

   return S;
}

/* Modifies the schedule of Part 2 inline */
void schedule3 ( int **S, int p )
{
   int i, j, tmp;

   /* Reverse the schedule of each counter */
   for (i=0; i<p; ++i) {
      for (j=1; j<=S[i][0]/2; ++j) {
         tmp = S[i][j];
         S[i][j] = S[i][S[i][0]+1-j];
         S[i][S[i][0]+1-j] = tmp;
      }
   }
}

/* Courtesy */
void freeall ( int **S1, int **S2, int p, int *t )
{
   int i;

   for (i=0; i<p; ++i) {
      free(S1[i]);
      free(S2[i]);
   }
   free(S1);
   free(S2);
   free(t);
}

int main ( int argc, char *argv[] )
{
   int n, p;
   int *t;
   int **S1, **S2;

   srand((unsigned int)time(NULL));
   if (argc >= 3) {
      n = atoi(argv[1]); p = atoi(argv[2]);
   } else {
      printf("Enter n and p: ");
      scanf("%d%d", &n, &p);
   }

   printf("\nn = %d\np = %d\n\nEnter customer times:\n\n", n, p);
   t = genjobs(n);

   printf("\n+++ Schedule 1\n");
   S1 = schedule1(t,n,p);
   printschedule(S1,p,t);
   printf("+++ Bank finishes at time %d\n", makespan(t,S1,p));
   printf("+++ Total waiting time = %d\n", totalwaittime(t,S1,p));

   printf("\n+++ Schedule 2\n");
   S2 = schedule2(t,n,p);
   printschedule(S2,p,t);
   printf("+++ Bank finishes at time %d\n", makespan(t,S2,p));
   printf("+++ Total waiting time = %d\n", totalwaittime(t,S2,p));

   printf("\n+++ Schedule 3\n");
   schedule3(S2,p);
   printschedule(S2,p,t);
   printf("+++ Bank finishes at time %d\n", makespan(t,S2,p));
   printf("+++ Total waiting time = %d\n\n", totalwaittime(t,S2,p));

   freeall(S1,S2,p,t);
   exit(0);
}