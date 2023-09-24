#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>

void asc(int*,int);
void dsc(int*,int);

int main(){
   int *arr,n,i;
   
   
   pid_t pid;

   printf("Enter number of elements :");
   scanf("%d",&n);

   arr = (int*)malloc(n*sizeof(int));

   printf("Enter elements of array :\n");
   for(i=0;i<n;i++){
      printf("arr[%d] : ",i);
      scanf("%d",&arr[i]);
   }

   for(i=0;i<n;i++){
      printf("%d",arr[i]);
   }

   printf("\n");

   pid = fork();

   if(pid < 0){
     perror("Fork error");
   }else if (pid == 0){
     printf("Child process id : %ld",(long)getpid());
   }else{
     printf("Parent process id : %ld",(long)getpid());
   }

   switch(pid){
      case -1:
	      printf("\n Fork error \n");
	      exit(-1);
      case 0:
	      printf("\n Child executes...\n");
	      asc(arr,n);
	      exit(pid);
      default:
	      //wait(NULL);
	      printf("\n Parent executes...\n");
	      dsc(arr,n);
	      system("ps -elf");
	      exit(pid);
   }

}

void asc(int *arr, int n){
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

void dsc(int *arr, int n){
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

