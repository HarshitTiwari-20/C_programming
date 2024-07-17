#include <stdio.h>

int step_count = 0;

void tower(int n, char source, char helper, char destination) {
    if (n == 1) {
        step_count++;
        printf("\nStep %d: Move disk 1 from rod %c ---> rod %c", step_count, source, destination);
        return;
    }
    tower(n - 1, source, destination, helper);
    step_count++;
    printf("\nStep %d: Move disk %d from rod %c ---> rod %c", step_count, n, source, destination);
    tower(n - 1, helper, source, destination);
}

int main() {
    int n = 4; // Number of disks
    printf("Solving Tower of Hanoi with %d disks:\n", n);
    tower(n, 'A', 'B', 'C'); // A, B, and C are names of rods
    printf("\nAll moves are completed in %d steps.\n", step_count);
    return 0;
}
