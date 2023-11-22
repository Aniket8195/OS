#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<ctype.h>
#include<unistd.h>

void asc(int arr[],int n){
   int i,j,temp;

   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }

   printf("Array in ascending order :");

   for(i=0;i<n;i++){
     printf("%d ",arr[i]);
   }
}

void dsc(int arr[], int n){
   int i,j,temp;

   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(arr[i]<arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }
   printf("Array in descending order :");

   for(i=0;i<n;i++){
     printf("%d ",arr[i]);
   }
}

void main(){
  int n=5;
  int a[5]={1,8,3,8,5};
  pid_t pid;
  pid=fork();

  if(pid<0){
  printf("Fork error\n");
  }else if(pid==0){
  printf("Child process id : %ld\n",(long)getpid());

  }else{
  printf("Parent process id: %ld\n",(long)getpid());
  }

  switch(pid){
          case -1 :printf("Fork error\n");
                   exit(-1);
          case 0:printf("Child executes\n");
                 asc(a,n);
                 exit(pid);
          default:
                 wait(NULL);
                 printf("Parent executes\n");
                  dsc(a,n);
                  system("ps -elf");
                  exit(pid);


  }
}
   
   
   
