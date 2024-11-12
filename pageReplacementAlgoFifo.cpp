#include <bits/stdc++.h>
using namespace std;
void pageReplacementFiFo(int pages[], int n, int capacity)
{
    int frame[capacity];
    int pageFaults = 0;
    int hits = 0;
    int index = -1;
    for (int i = 0; i < capacity; i++)
    {
        frame[i] = -1;
    }

    // Check if the page is already in the frame
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; i < capacity; j++)
        {
            if (frame[j] == pages[i])
            {
                hits++;
                found = true;
                break;
            }
        }
        // If the page is not found in the frame, we have a page fault
        if (!found)
        {
            frame[index] = pages[i];
            index = (index + 1) % capacity; // Move to the next index in a circular manner
            pageFaults++;
        }
    }

    cout << "Page Faults: " << pageFaults << endl;
    cout << "Hits: " << hits << endl;
}
int main()
{
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    pageReplacementFiFo(pages, n, capacity);

    return 0;
}