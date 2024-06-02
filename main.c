#include <stdio.h>
#include "process.h"
#include "scheduler.h"

void selectScheduler(ProcessPtr process_ptr, int size); //scheduler type 입력

int main(void) {
    printf("CPU Scheduler is Start!\n");
    printf("input process number : ");

    int size = 0;
    scanf("%d", &size);
    ProcessPtr process_ptr;
    process_ptr = createProcess(size);

    selectScheduler(process_ptr, size);
    return 0;
}

void selectScheduler(ProcessPtr process_ptr, int size){
    printf("Scheduler List\n\n");
    printf("### 1 : FCFS\n");
    printf("### 2 : Non-Preemptive SJF\n");
    printf("### 3 : Preemptive SJF\n");
    printf("### 4 : Non-Preemptive Priority\n");
    printf("### 5 : Preemptive Priority\n");
    printf("### 6 : RR\n");

    int scheduler_type = 0;
    while(1){
        printf("\nselect scheduler : ");
        scanf("%d", &scheduler_type);
        switch (scheduler_type) {
            case 1:
                scheduleFCFS(process_ptr, size);
                break;
            case 2:
                scheduleSJF(process_ptr, size);
                break;
            case 3:
                schedulePRSJF(process_ptr, size);
                break;
            case 4:
                schedulePRIORITY(process_ptr, size);
                break;
            case 5:
                schedulePRPRIORITY(process_ptr, size);
                break;
            case 6:
                int time_quantum = 0;
                printf("Enter the time quantum : ");
                scanf("%d", &time_quantum);
                scheduleRR(process_ptr, size, time_quantum);
                break;
            default:
                printf("Invalid input. Please select a scheduler between 1 and 6: ");
        }
        resetProcess(process_ptr, size);
    }

}