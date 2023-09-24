#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct pro {
 int id;
 int at;
 int bt;
 int ct;
 int tt;
 int wt;
};
void main(){
   int n;
   printf("Enter the number of processes");
   scanf("%d",&n);
   struct pro p[n];
   for(int i=0;i<n;i++){
     p[i].id=i+1;
     printf("Enter Arrival time of process: %d ",i+1);
     scanf("%d",&p[i].at);
     printf("Enter Burst time of process: %d ",i+1);
     scanf("%d",&p[i].bt);
     p[i].ct=0;
     p[i].tt=0;
     p[i].wt=0;
   }

   struct pro temp;
   for (int i = 0; i <n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp=p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
               
            }
        }

    }
   p[0].ct=p[0].bt;
   int avgtt=0;
   int avgwt=0;
   for(int i=1;i<n;i++){
     p[i].ct=p[i-1].ct + p[i].bt;
   }
   for(int i=0;i<n;i++){
      p[i].tt=p[i].ct-p[i].at;
      p[i].wt=p[i].tt-p[i].bt;
      avgtt=avgtt+p[i].tt;
      avgwt=avgwt+p[i].wt;
   }

   for(int i=0;i<n;i++){
    printf("Process:%d  Arrival time:%d TT:%d WT:%d",p[i].id,p[i].at,p[i].tt,p[i].wt);
    printf("\n");
   }
   printf("\n");
   printf("Average TT is: %d ",(avgtt/n));
   printf("Average WT is: %d ",(avgwt/n));
   
}

