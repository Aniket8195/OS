#include <stdio.h>

// Function to find the index of the least recently used page
int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    // Find the index of the minimum time value
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }

    return pos; // Return the index of the least recently used page
}

// Main function
int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;

    // Input the number of frames, number of pages, and the reference string
    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the reference string:\n");

    printf("\n---------------------------------------\n");

    // Input the reference string
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames array to -1
    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    // Loop through the pages and implement LRU page replacement algorithm
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if the page is already in a frame
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If the page is not in a frame, find an empty frame
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If all frames are occupied, find the least recently used page and replace it
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        // Print the current state of frames after each page reference
        printf("\n");

        for (j = 0; j < no_of_frames; ++j) {
            printf("%d\t", frames[j]);
        }
    }

    // Print the total number of page faults
    printf("\n---------------------------------------\nTotal Page Faults = %d\n---------------------------------------\n", faults);

    return 0;
}

