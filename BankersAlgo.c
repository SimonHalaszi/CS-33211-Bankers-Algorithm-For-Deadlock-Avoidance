#include <stdio.h>
#include <stdbool.h>

#define P 5   // Amount of proccesses which is 5
#define R 3   // Amount of resources which is 3


static int avail[R];          // Array for Available Count for A B C
static int alloc[P][R];       // 2D Array for Allocation Count for P0-P4 for A B C
static int maxR[P][R];        // 2D Array for Max Count for P0-P4 for A B C
static int need[P][R];        // 2D Array for what P0-P4 need for A B C

static int safeSeq[P];        // Array for The Safe Sequence Array, if one exist

// Function that handles reading the input file, returns false if the file is not correctly set up, returns true if no issues.
static bool readInput(void) {
    // Reading in the avaible resources
    for (int j = 0; j < R; ++j) {
        if (scanf("%d", &avail[j]) != 1) {
            fprintf(stderr, "Input Syntax Error: Expecting 3 ints for Available\n");
            return false;
        }
    }

    // Reading in the allocation for A B C for all processes
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            if (scanf("%d", &alloc[i][j]) != 1) {
                fprintf(stderr, "Input Syntax Error: Missing integer for allocation for proccess %d at index %d\n", i, j);
                return false;
            }
        }
    }

    // Reading in the max for A B C for all processes
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            if (scanf("%d", &maxR[i][j]) != 1) {
                fprintf(stderr, "Input Syntax Error: Missing integer for max for proccess %d at index %d\n", i, j);
                return false;
            }
        }
    }

    // Need is equal to Max - Allocation
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            need[i][j] = maxR[i][j] - alloc[i][j];
        }
    }

    return true;
}

// Function for checking if system is in a safe state. If so it returns true, if not it returns false.
static bool isSafe(void) {
    // Array that stores true for if proccess at finish[i] can finish. We dont know yet so all to false.
    bool finish[P] = { false };
    
    // Work will be the array of available  resources throughout the simulation. Intialized to initial available.
    int currentAvail[R];
    for (int j = 0; j < R; ++j) {
        currentAvail[j] = avail[j];
    }

    // Count for how many processes have be sequenced.
    int count = 0;
    
    // Repeat until all processes finish or until no found proccesses
    while (count < P) {
        bool foundProcess = false;
        
        // Go through all unfished proccesses.
        for (int i = 0; i < P; ++i) {
            // If Pi is not finished
            if (!finish[i]) {
                bool canRun = true;
                // Checking if Pi's remaining needs can be met by current avaible resources
                for (int j = 0; j < R; ++j) {
                    if (need[i][j] > currentAvail[j]) {
                        // If its needs are greater at any point than what can be supported then it cant run and we break the for loop iteration
                        canRun = false;
                        break;
                    }
                }
                // If Pi can run then we assume it ran and is now finished.
                if (canRun) {
                    // Resources from Pi are added back into the current pool of available resources.
                    for (int j = 0; j < R; ++j) {
                        currentAvail[j] += alloc[i][j];
                    }
                    // Recording Pi in the safe sequence as it could run.
                    safeSeq[count] = i;
                    // Incrementing count.
                    count++;
                    // Proccess Pi is now finished.
                    finish[i] = true;
                    // A proccess was found to have ran.
                    foundProcess = true;
                }
            }
        }
        // If no process out of the 5 could run then there was deadlocked potential. So we return false.
        if (!foundProcess) {
            return false;
        }
    }

    // Sequence was found as 5 processes were counted into safe sequence
    return true;
}

/*----------------------------------------------------------------------------*/
int main(void) {
    // If readInput returns false exit program early
    if (readInput() == false) {
        return 1;
    }

    // If isSafe returns true print the system is in a safe state and print the sequence in the array
    if (isSafe()) {
        printf("The system is in a SAFE state.\nSafe sequence: ");
        for (int k = 0; k < P; ++k) {
            printf("P%d%s", safeSeq[k], (k == P - 1 ? "\n" : " -> "));
        }
    // If isSafe returns false print that it isnt in a safe state
    } else {
        printf("The system is NOT in a safe state.\n");
    }
    
    return 0;
}
