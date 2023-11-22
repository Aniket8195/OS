#include<stdio.h>
struct proc{
    int id;
    int at;
    int bt;
    int tt;
    int wt;
    int ct;
    
};

void main(){
    int n;
    printf("Enter number of processes\n");
    scanf("%d",&n);
    struct proc P[n];
    for(int i=0;i<n;i++){
        printf("Enter the process %d details 1.Arrival Time ",i+1);
        scanf("%d",&P[i].at);
        printf("Burst time\n");
        scanf("%d",&P[i].bt);
        P[i].ct=0;
        P[i].wt=0;
        P[i].tt=0;
    }
    struct proc temp;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(P[i].at>P[j].at){
                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }
    
    
    P[0].ct=P[0].bt;
    
    for(int i=1;i<n;i++){
        P[i].ct=P[i-1].ct+P[i].bt;
 
    }
    double avgtt=0,avgwt=0;
	for(int i=0;i<n;i++){
	    P[i].tt=P[i].ct-P[i].at;
        P[i].wt=P[i].tt-P[i].bt;
		avgtt+=P[i].tt;
		avgwt+=P[i].wt;
	}
	printf("Average TT is %f and Average WT is %f\n",avgtt/n,avgwt/n);
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t%d\n",P[i].id,P[i].at,P[i].bt);
    }
    
    
    
}




