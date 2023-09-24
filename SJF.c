#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct pro {
    int id;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int remaining_bt;
};

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct pro p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival time of process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst time of process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].ct = 0;
        p[i].tt = 0;
        p[i].wt = 0;
        p[i].remaining_bt = p[i].bt;
    }

    int time = 0;
    int completed = 0;

    while (completed < n) {
        int min_bt = INT_MAX;
        int selected_process = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining_bt < min_bt && p[i].remaining_bt > 0) {
                min_bt = p[i].remaining_bt;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            time++;
        } else {
            p[selected_process].remaining_bt--;
            time++;

            if (p[selected_process].remaining_bt == 0) {
                completed++;
                p[selected_process].ct = time;
                p[selected_process].tt = p[selected_process].ct - p[selected_process].at;
                p[selected_process].wt = p[selected_process].tt - p[selected_process].bt;
            }
        }
    }

    int avgtt = 0;
    int avgwt = 0;

    for (int i = 0; i < n; i++) {
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }

    printf("Process\tArrival Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].tt, p[i].wt);
    }
    
    printf("\nAverage Turnaround Time: %lf\n", (double)avgtt / n);
    printf("Average Waiting Time: %lf\n", (double)avgwt / n);
}

