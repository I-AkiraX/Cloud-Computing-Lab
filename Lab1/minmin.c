#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n,m;
    printf("Enter the number of virtual machines and number of tasks: ");
    scanf("%d %d",&n,&m);

    int a[m][n];
    bool visited[m];
    for(int i=0;i<m;i++){
        printf("Enter times for task %d\n",i+1);
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            
        }
        visited[i]=false;
    }
    int cnt=0;
    int max_time[n];
    for(int i=0;i<n;i++){
        max_time[i]=0;
    }
    while(cnt < m){
        int min=1e9;
        int machine_no=-1;
        int task_no=-1;
        for(int i=0;i<m;i++){
            if(visited[i]==true)continue;
            for(int j=0;j<n;j++){
                if(min> a[i][j]){
                    min=a[i][j];
                    machine_no=j;
                    task_no=i;
                }
            }
        }

        visited[task_no]=true;
        max_time[machine_no]=min;
        cnt++;
        printf("Task %d is assigned to machine %d\n",task_no+1,machine_no+1);
        for(int i=0;i<m;i++){
            if(visited[i]==true)continue;
            a[i][machine_no]+=min;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
            if(ans<max_time[i]){
                ans=max_time[i];
            }
    }
    printf("The maximum time required is %d\n",ans);

}
