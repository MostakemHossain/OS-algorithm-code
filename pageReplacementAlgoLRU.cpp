#include <bits/stdc++.h>

using namespace std;

void LRUPageReplacement(int pages[], int n, int frameSize)
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
            // Page hit - move the page to the most recently used position
            frames.erase(it);
            frames.insert(frames.begin(), page);
            pageHits++;
        }
        else
        {
            // Page miss - increment page faults
            pageFaults++;

            // If frames are full, remove the least recently used page
            if (frames.size() == frameSize)
            {
                frames.pop_back();
            }

            // Insert the new page at the front (most recently used position)
            frames.insert(frames.begin(), page);
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

    LRUPageReplacement(pages, n, frameSize);

    return 0;
}
