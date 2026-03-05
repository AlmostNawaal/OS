#include<stdio.h>

typedef struct process{
    int pid;
    int at;
    int bt;
    int wt;
    int tat;
    }process;

void sort_by_at(process p[],int n){

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(p[j].at > p[j+1].at){
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    return;
}

void FCFS(process p[], int n){
    int t=0;
    for(int i = 0; i < n; i++){
        if(p[i].at>t){
            t = p[i].at;
        }
        p[i].wt = t -p[i].at;
        p[i].tat = p[i].bt + t-p[i].at;
        t += p[i].bt;
    }

    printf("%-5s%-5s%-5s%-5s%-5s\n","PID","AT","BT","WT","TAT");

    for(int i = 0; i < n; i++){
        printf("%-5d%-5d%-5d%-5d%-5d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);
    }

    double swt = 0;
    double stat = 0;

    for(int i = 0; i < n; i++){
        swt += p[i].wt;
        stat += p[i].tat;
    }

    double awt = swt/n;
    double atat = stat/n;

    printf("%-12s%-12s\n","AWT","ATAT");
    printf("%-12f%-12f\n",awt,atat);

    return;
}


void main(){
    int n;

    printf("Enter no. of processes:");
    scanf("%d",&n);

    process processes[n];
    for(int i = 0; i < n; i++){
        printf("Enter the AT and BT of process %d:",i+1);
        scanf("%d %d",&processes[i].at,&processes[i].bt);
        processes[i].pid = i+1;
    }
    sort_by_at(processes,n);
    FCFS(processes,n);
}
