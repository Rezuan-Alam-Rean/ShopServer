#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
};

int comparePriority(const void *a, const void *b) {
    struct Process *processA = (struct Process *)a;
    struct Process *processB = (struct Process *)b;
    return processA->priority - processB->priority; // Sort by priority
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time & priority for process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burstTime, &processes[i].priority);
        processes[i].waitingTime = 0;
        processes[i].turnAroundTime = 0;
    }

    // Sorting processes by priority
    qsort(processes, n, sizeof(struct Process), comparePriority);

    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    // Calculate waiting time
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burstTime, 
               processes[i].priority, 
               processes[i].waitingTime, 
               processes[i].turnAroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);

    return 0;
}
