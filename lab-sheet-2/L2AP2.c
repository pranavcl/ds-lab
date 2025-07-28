#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10
 
int main() {
    int n, c, i;
 
    printf("Enter number of voters: ");
    scanf("%d", &n);
    printf("Enter number of candidates: ");
    scanf("%d", &c);
 
    char** candidates = (char**)calloc(c, sizeof(char*));
    printf("Enter the names of the candidates:\n");
    for(i = 0; i < c; i++) {
        *(candidates + i) = (char*)calloc(MAX_LENGTH, sizeof(char));
        scanf("%s", *(candidates + i));
    }
 
    int* votes = (int*)calloc(n, sizeof(int));
    printf("Which candidate would you like to vote for?\n");
    for(i = 0; i < c; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
 
    int max_id = 0;
 
    for(i = 0; i < n; i++) {
        int vote;
        scanf("%d", &vote);
 
        if(vote > c || vote < 1) votes[0]++;
        else {
            votes[vote]++;
            if(votes[vote] > votes[max_id]) max_id = vote;
        }
 
        printf("Vote confirmed!\n");
    }
 
    printf("Results:\n");
    for(i = 0; i < c; i++) {
        printf("%d. %s - %d\n", i+1, candidates[i], votes[i+1]);
    }
    printf("Foul votes: %d\n", votes[0]);
    printf("Winner: %s\n", candidates[max_id-1]);
 
    free(candidates);
    free(votes);
 
    return 0;
}
