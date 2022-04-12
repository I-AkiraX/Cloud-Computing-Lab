#include<stdio.h>
#include <limits.h>

int main(){
    int nT,nM;
    printf("Sufferage Heuristic\n");
    printf("\nEnter number of machines and tasks: \n");
    scanf("%d%d",&nM,&nT);

    int minMin[nM][nT];
    int tmp[nM][nT];
    int makespan=0;
    for(int i=0;i<nM;i++){
        printf("\nEnter data for machine %d:\n",i+1);
        for(int j=0;j<nT;j++){
            scanf("%d",&minMin[i][j]);
            tmp[i][j]=minMin[i][j];
        }
    }
    printf("\nData Provided\n");
    for(int i=0;i<nM;i++){
        for(int j=0;j<nT;j++)
            printf("%d ",minMin[i][j]);

        printf("\n");
    }

    int resultTask[nT];
    int resultMachine[nT];
    int resultTime[nT];
    int ptr=-1;
    while(ptr<nT-1){
        int time[nT],machine[nT],sufferage[nT];
        for(int j=0;j<nT;j++){
            //time[j]=min time of machine of max(minofmachine-secondminofmachine)
            //machine[j]=min machine of max('')
            int min=INT_MAX,secmin=INT_MAX;
            int pos=-1;
            for(int i=0;i<nM;i++){
                if(minMin[i][j]<min){
                    secmin=min;
                    min=minMin[i][j];
                    pos=i;
                }
                else if(minMin[i][j]<secmin && minMin[i][j]!=min){
                    secmin=minMin[i][j];
                }
            }
            sufferage[j]=secmin-min;
            time[j]=min;
            machine[j]=pos;
        }
        int minimum=INT_MAX;
        int maxSuff=INT_MIN;
        int pos=-1;
        for(int j=0;j<nT;j++){
            if(maxSuff<sufferage[j])
            {
                maxSuff=sufferage[j];
                minimum=time[j];
                pos=j;
            }
        }
        resultTask[++ptr]=pos;
        resultMachine[ptr]=machine[pos];
        resultTime[ptr]=tmp[machine[pos]][pos];
        if(minimum>makespan)
        makespan=minimum;
        for(int i=0;i<nM;i++){
            for(int j=0;j<nT;j++){
                if(j==resultTask[ptr])
                minMin[i][j]=INT_MAX;
                else if(i==resultMachine[ptr] && minMin[i][j]!=INT_MAX)
                minMin[i][j]+=minimum;
                else
                continue;
            }
        }
    }

    printf("\nScheduled Task are :");
    for(int i=0;i<nT;i++)
        printf("\nTask %d Runs on Machine %d with Time %d units",
               resultTask[i]+1,resultMachine[i]+1,resultTime[i]);
    printf("\n\nMakespan : %d units\n",makespan);
}