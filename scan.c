
#include <stdio.h>
#include <conio.h> // Include for getch()

int main() {
    int i, j, sum = 0, n;
    int d[20];
    int disk; // location of head
    int temp, max;
    int dloc; // location of disk in array

    printf("Enter number of locations: ");
    scanf("%d", &n);

    printf("Enter position of head: ");
    scanf("%d", &disk);

    printf("Enter elements of disk queue:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    d[n] = disk; // add the disk position to the queue
    n = n + 1;

    // Sorting disk locations in ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (d[i] > d[j]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    max = d[n - 1]; // max is the last element after sorting

    // Find location of disk in array
    for (i = 0; i < n; i++) {
        if (disk == d[i]) {
            dloc = i;
            break;
        }
    }

    // Moving left from the head to the start
    printf("Head movement: ");
    for (i = dloc; i >= 0; i--) {
        printf("%d --> ", d[i]);
    }
    printf("0 --> ");

    // Moving right from the head to the end
    for (i = dloc + 1; i < n; i++) {
        printf("%d --> ", d[i]);
    }

    // Total movement calculation
    sum = disk + max;
    printf("\nTotal cylinder movement: %d", sum);

    getch(); // Wait for key press (only works on some systems with <conio.h>)
    return 0;
}
