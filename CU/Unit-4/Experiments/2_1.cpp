#include <stdio.h>
#include <stdlib.h>

// Job structure
typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

// Function to compare two jobs based on their profit. Returns true if job b's profit < job a's profit
int compareJob(const void *a, const void *b){
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function finds the best job sequence
void bestJob(Job jobs[], int sizeOfJobs){
    // Null char array
    char jobsToDo[5] = {'\0'};

    for(int i=0, k=0; i<sizeOfJobs; i++){
        k = jobs[i].deadline-1;

        // Searching backwards the empty date nearest to deadline
        while(jobsToDo[k] != '\0' && k >= 0){
            k--;
        }       

        // If empty date found, set the job
        if(k != -1)
            jobsToDo[k] = jobs[i].id;
    }   

    // Output the final job sequence
    printf("\nBest order and jobs to do is: ");
    int idx=0;
    while(jobsToDo[idx] != '\0'){
        printf("%c ",jobsToDo[idx]);
        idx++;
    }
}

// Function to display the jobs table
void display(Job jobs[], int n){
    printf("Job Id:     \t");
    for(int i=0; i<n; i++){
        printf("%c \t",jobs[i].id);
    }
    printf("\n");

    printf("Job Deadline: \t");
    for(int i=0; i<n; i++){
        printf("%d \t",jobs[i].deadline);
    }
    printf("\n");

    printf("Job Profit: \t");
    for(int i=0; i<n; i++){
        printf("%d \t",jobs[i].profit);
    }
    printf("\n");
}

int main(){  
    // Initialize the jobs
    Job jobs[]=  {{'w', 1, 19}, {'v', 2, 100}, {'x', 2, 27}, {'y', 1, 25}, {'z', 3, 15}};                  

    // Display the jobs data
    display(jobs,5);

    // Sorting jobs[] w.r.t their profit
    qsort(jobs,5,sizeof(jobs[0]),compareJob);

    bestJob(jobs,5);

    return 0;
}
