#include <stdio.h>

int main(){
    int n, m;
    printf("Enter No of Processes : ");
    scanf("%d", &n);
    printf("Enter No of Machines : ");
    scanf("%d", &m);

    int arr[m][n];
    for (int i = 0; i < m; i++){
        printf("\nEnter Times for Machine-%d : ", i);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // MIN MAX ALGO
    int final_time[m];
    printf("\n\nSequence  : \n\n");
    for (int tc = 0; tc < n; tc++){
        int machine = -1, time = -1000, task_no = -1;
        for (int i = 0; i < n; i++){
            if (arr[0][i] == -1)
                continue;
            int t = 1e5, task = i, ma = -1;
            for (int j = 0; j < m; j++){
                if (arr[j][i] < t){
                    t = arr[j][i];
                    ma = j;
                }
            }
            if (t > time){
                time = t;
                task_no = task;
                machine = ma;
            }
        }

        final_time[machine] = time;
        printf("Task : %d Machine : %d Time : %d \n", task_no, machine, time);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (j == task_no){
                    arr[i][j] = -1;
                }
                else if (i == machine && arr[i][j] != -1){
                    arr[i][j] = arr[i][j] + time;
                }
            }
        }
    }

    int res = -1000;
    for (int i = 0; i < m; i++){
        if (final_time[i] > res){
            res = final_time[i];
        }
    }

    printf("\nMAKESPAN : %d", res);
    return 0;
}