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
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // MIN MIN ALGO
    printf("\n\nSequence  : \n");
    int final_time[m];
    for (int tc = 0; tc < n; tc++){
        int machine = -1, time = 1e5, task_no = -1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] < time && arr[i][j] != -1){
                    time = arr[i][j];
                    machine = i;
                    task_no = j;
                }
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