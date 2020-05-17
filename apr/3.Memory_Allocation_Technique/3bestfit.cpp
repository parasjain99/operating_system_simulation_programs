#include <bits/stdc++.h>
using namespace std;

int main()

{

    int s, n,min,pos;
    cout << "Enter the number of blocks :";
    cin >> s;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bs[s], ps[n];

    for (int i = 0; i < s; i++)
    {
        cout << "Enter the size of block " << i + 1 << ": ";
        cin >> bs[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the size of processe " << i + 1 << ": ";
        cin >> ps[i];
    }
    for (int i = 0; i < n; i++)
    {
        min = INT_MAX;
        pos = -1;
        for (int j = 0; j < s; j++)
        {
            if (min > bs[j] && bs[j] >= ps[i])
            {
                min = bs[j];
                pos = j;
            }
        }
        if (pos != -1)
        {
            cout << "\nProcess " << i + 1 << " allocated block " << pos + 1;
            bs[pos] = bs[pos] - ps[i];
        }
        else
            cout << "\nProcess " << i + 1 << " not allocated";
    }

    return 0;
}
// 2
// 4
// 150
// 350
// 300
// 25
// 125
// 50
// Process 1 allocated block 2
// Process 2 allocated block 2
// Process 3 allocated block 1
// Process 4 not allocated