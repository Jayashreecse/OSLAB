//Write a C program to simulate the following contiguous memory
//allocation techniques:
//(a) Worst-fit
//(b) Best-fit
//(c) First-fit
//1.1.1 Code:
#include <stdio.h>
#define MAX 25

void firstFit(int b[], int nb, int f[], int nf);
void worstFit(int b[], int nb, int f[], int nf);
void bestFit(int b[], int nb, int f[], int nf);

int main() {
    int b[MAX], f[MAX], nb, nf;

    // Input: Number of blocks and files
    printf("Memory Management Schemes\n");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input: Block sizes
    printf("\nEnter the size of the blocks:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input: File sizes
    printf("\nEnter the size of the files:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // First Fit Allocation
    printf("\nMemory Management Scheme - First Fit\n");
    firstFit(b, nb, f, nf);

    // Worst Fit Allocation
    printf("\nMemory Management Scheme - Worst Fit\n");
    worstFit(b, nb, f, nf);

    // Best Fit Allocation
    printf("\nMemory Management Scheme - Best Fit\n");
    bestFit(b, nb, f, nf);

    return 0;
}

// First Fit Allocation
void firstFit(int b[], int nb, int f[], int nf) {
    int bf[MAX] = {0};  // Block allocation tracker
    int ff[MAX] = {0};  // File allocation tracker
    int frag[MAX];      // Fragmentation array
    int i, j;

    // Process each file
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1 && b[j] >= f[i]) {
                ff[i] = j;
                bf[j] = 1;
                frag[i] = b[j] - f[i];
                break;
            }
        }
        if (j == nb) {
            ff[i] = -1; // No suitable block found
            frag[i] = -1; // No space
        }
    }

    // Print results
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t\t\t", i + 1, f[i]);
        }
    }
}

// Worst Fit Allocation
void worstFit(int b[], int nb, int f[], int nf) {
    int bf[MAX] = {0};  // Block allocation tracker
    int ff[MAX] = {0};  // File allocation tracker
    int frag[MAX];      // Fragmentation array
    int i, j, temp, highest = -1;

    // Process each file
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0 && highest < temp) {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }
        if (highest != -1) {
            frag[i] = highest;
            bf[ff[i]] = 1;
            highest = -1;
        } else {
            ff[i] = -1;  // No suitable block found
            frag[i] = -1;  // No space
        }
    }

    // Print results
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t\t\t", i + 1, f[i]);
        }
    }
}

// Best Fit Allocation
void bestFit(int b[], int nb, int f[], int nf) {
    int bf[MAX] = {0};  // Block allocation tracker
    int ff[MAX] = {0};  // File allocation tracker
    int frag[MAX];      // Fragmentation array
    int i, j, temp, lowest = 10000;

    // Process each file
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0 && lowest > temp) {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        if (lowest != 10000) {
            frag[i] = lowest;
            bf[ff[i]] = 1;
            lowest = 10000;
        } else {
            ff[i] = -1;  // No suitable block found
            frag[i] = -1;  // No space
        }
    }

    // Print results
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t\t\t", i + 1, f[i]);
        }
    }
}
