#include<stdio.h>

main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;


    printf("Enter the no of processes -- ");
    scanf("%d", &n);  // Read number of processes

    for(i = 0; i < n; i++) {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &bu[i]);  // Read burst time for each process
        ct[i] = bu[i];  // Store original burst times in ct[]
    }

    printf("\nEnter the size of time slice -- ");
    scanf("%d", &t);  // Read time slice

    max = bu[0];
    for(i = 1; i < n; i++) {
        if(max < bu[i]) max = bu[i];  // Find the maximum burst time
    }

    for(j = 0; j < (max / t) + 1; j++) {  // Loop for the number of time slices
        for(i = 0; i < n; i++) {
            if(bu[i] != 0) {  // Process has remaining burst time
                if(bu[i] <= t) {  // If burst time is less than or equal to time slice
                    tat[i] = temp + bu[i];  // Turnaround time = previous time + burst time
                    temp += bu[i];  // Add burst time to the total time
                    bu[i] = 0;  // Process is completed
                } else {  // If burst time is greater than time slice
                    bu[i] -= t;  // Decrease burst time by the time slice
                    temp += t;  // Add time slice to the total time
                }
            }
        }
    }

    // Calculate waiting time and turnaround time
    for(i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];  // Waiting time = turnaround time - burst time
        att += tat[i];  // Accumulate turnaround time
        awt += wa[i];  // Accumulate waiting time
    }

    // Print average turnaround time and average waiting time
    printf("\nThe Average Turnaround time is -- %f", att / n);
    printf("\nThe Average Waiting time is -- %f", awt / n);

    // Print the process details
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, ct[i], wa[i], tat[i]);
    }
    getch();
}
//PRIORITY

#include<stdio.h>
 main()
{
int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp; float wtavg, tatavg;

printf("Enter the number of processes --- "); scanf("%d",&n);
for(i=0;i<n;i++){ p[i] = i;
printf("Enter the Burst Time & Priority of Process %d --- ",i);
scanf("%d%d",&bt[i], &pri[i]);
}
for(i=0;i<n;i++) 
    for(k=i+1;k<n;k++) 
    if(pri[i] > pri[k]){ 
        temp=p[i]; p[i]=p[k]; p[k]=temp; temp=bt[i]; bt[i]=bt[k]; bt[k]=temp; temp=pri[i]; pri[i]=pri[k]; pri[k]=temp;
}
wtavg = wt[0] = 0; tatavg = tat[0] = bt[0]; for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];

wtavg = wtavg + wt[i]; tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]); printf("\nAverage Waiting Time is --- %f",wtavg/n); printf("\nAverage Turnaround Time is --- %f",tatavg/n);
getch();}
