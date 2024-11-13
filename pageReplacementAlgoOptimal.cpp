#include <bits/stdc++.h>

using namespace std;

void optimalPageReplacement(int pages[], int n, int frameSize)
{
    vector<int> frames;
    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];

        // Check if the page is already in the frames (hit)
        auto it = find(frames.begin(), frames.end(), page);
        if (it != frames.end())
        {
            // Page hit - increment page hits count
            pageHits++;
            continue;
        }

        // Page miss - increment page faults
        pageFaults++;

        // If frames are not full, insert the page
        if (frames.size() < frameSize)
        {
            frames.push_back(page);
        }
        else
        {
            // Frames are full, find the page to replace
            int farthest = i + 1;
            int indexToReplace = -1;

            // Find the page with the farthest next use
            for (int j = 0; j < frameSize; j++)
            {
                int nextUse = n; // Set next use to a large value initially
                for (int k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        nextUse = k;
                        break;
                    }
                }

                // Update the page with the farthest next use
                if (nextUse > farthest)
                {
                    farthest = nextUse;
                    indexToReplace = j;
                }
            }

            // If no page has a future use, replace the first page
            if (indexToReplace == -1)
            {
                frames[0] = page;
            }
            else
            {
                frames[indexToReplace] = page;
            }
        }
    }

    cout << "Total Page Hits: " << pageHits << endl;
    cout << "Total Page Faults: " << pageFaults << endl;
}

int main()
{
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;

    optimalPageReplacement(pages, n, frameSize);

    return 0;
}
