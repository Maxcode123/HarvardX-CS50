#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int merge_two(int *a,int s1,int e1,int s2,int e2,int* m1,int* m2);
int my_mergesort(int* a,int len); 


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // loop as times as there are candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if input name is equal with candidate name return true
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // if name not found in candidate names, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // 
    int sorted_votes[candidate_count];
    
    for (int i = 0; i < candidate_count; i++)
    {
        sorted_votes[i] = candidates[i].votes;
    }
    
    my_mergesort(sorted_votes, candidate_count);
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == sorted_votes[candidate_count - 1])
        {
            printf("%s\n", candidates[i].name);
        }
    }
    
    return;
}

// merge sublists function from GitHub: cave7/sort repository
int merge_two(int *a,int s1,int e1,int s2,int e2,int* m1,int* m2)
{
    int len1=e1-s1+1;
    int len2=e2-s2+1;
    int p1=0;
    int p2=0;
    int p=s1;
    memcpy(m1,a+s1,sizeof(int)*len1);
    memcpy(m2,a+s2,sizeof(int)*len2);
    while (p1<len1&&p2<len2) {
        if(m1[p1]<m2[p2]){
            a[p++]=m1[p1++];
        }
        else{
            a[p++]=m2[p2++];
        }
    }
    while (p1<len1) {
        a[p++]=m1[p1++];
    }
    while(p2<len2){
        a[p++]=m2[p2++];
    }
    return 0;
}

// merge sort function from GiHub: cave7/sort repository
int my_mergesort(int* a,int len)
{
    int step=1;
    int *m1=(int *)malloc(len*sizeof(int));
    if(!m1) return -1;
    int *m2=(int *)malloc(len*sizeof(int));
    if(!m2) return -1;
    while (step<len) {
        int i,s1,e1,s2,e2;
        for(i=0;(i+step-1)<(len-1);i+=2*step){
            s1=i;
            e1=i+step-1;
            s2=e1+1;
            (i+2*step-1)<(len-1)?(e2=i+2*step-1):(e2=len-1);
            merge_two(a,s1,e1,s2,e2,m1,m2);
        }
        step=step<<1;
    }
    return 0;
}

