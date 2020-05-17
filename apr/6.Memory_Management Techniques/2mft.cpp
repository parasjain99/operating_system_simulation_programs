#include <bits/stdc++.h>
using namespace std;

int main()
{

    int s, n, min, pos,IF=0,EF=0;
    cout << "Enter the number of partitions\n";
    cin >> s;
    int bs[s];
    for (int i = 0; i < s; i++){
        cout << "Enter the size of partition "<<i+1<<": ";
        cin >> bs[i];
    }

    cout << "Enter the number of processes\n";
    cin>>n;
    int ps[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the size of process " << i+1 << ": ";
        cin >> ps[i];
    }
    cout << "Process no.| Process size| Partition no.| Part size| Internal Fragmentation\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t"<<ps[i]<<"\t\t";
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
            IF += (bs[pos] - ps[i]);
            cout << pos + 1 <<"\t\t"<< bs[pos] << "\t\t" << bs[pos] - ps[i] << "\n";
            bs[pos]=0;
            
        }
        else
            cout << "None\n";
    }
    for(int i=0;i<s;i++){
        EF+=bs[i];
    }
    cout<<"Total internal fragmentation = "<<IF<<endl;
    cout<<"Total external fragmentation(Memory Left) = "<<EF<<endl;
    return 0;
}
//Input
// 6
// 200
// 400
// 600
// 500
// 300
// 250
// 4
// 357
// 210
// 468
// 491
