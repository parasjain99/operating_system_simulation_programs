#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fsize, n, hit, miss, fptr;
    cout << "Enter no. of frames(frame size)\n";
    cin >> fsize;
    cout << "Enter no. of requests\n";
    cin >> n;
    vector<int> req(n), frame(fsize, -1), freq(fsize, 0);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter request " << i + 1 << ": ";
        cin >> req[i];
    }
    miss = 0;
    hit = 0;
    fptr = 0;
    for (int i = 0; i < n; i++)
    {
        bool isHit = false;
        cout << endl
             << i << ". Request " << req[i] << "\nframes ";
        for (int j = 0; j < fsize; j++)
            cout << frame[j] << " ";
        for (int j = 0; j <= fptr && j < fsize; j++)
        {
            if (req[i] == frame[j])
            {
                freq[j]++;
                hit++;
                isHit = true;
                cout << "\nHit at frame " << j << endl;
                break;
            }
        }
        if (isHit)
            continue;
        else if (fptr < fsize)
        {
            frame[fptr] = req[i];
            freq[fptr]++;
            cout << "\nMiss frame " << fptr << " = " << frame[fptr] << endl;
            fptr++;
            miss++;
        }
        else
        {
            int x = INT_MAX;
            fptr = 0;
            for (int j = 0; j < fsize; j++)
            {
                if (freq[j] < x)
                {
                    fptr = j;
                    x = freq[j];
                }
                else if (freq[j] == x)
                {
                    for (int k = 0; k < i; k++)
                    {
                        if (req[k] == frame[j])
                        {
                            fptr = j;
                            x = freq[j];
                            break;
                        }
                        else if (req[k] == frame[fptr])
                        {
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (req[j] == frame[fptr])
                    req[j] = -1;
            }
            frame[fptr] = req[i];
            freq[fptr] = 1;
            cout << "\nMiss frame" << fptr << " = " << frame[fptr] << endl;
            fptr = fsize;
            miss++;
        }
    }
    float h = (float)hit, m = (float)miss;
    h /= n;
    m /= n;
    cout << "\nHit Count = " << hit << "\nMiss Count = " << miss << "\nHit ratio = " << h << "\nMiss ratio = " << m;
}
//Input
// 3
// 13
// 7 0 1 2 0 3 0 4 2 3 0 3 2
//Output
// Hit Count = 5
// Miss Count = 8
// Hit ratio = 0.384615
// Miss ratio = 0.615385