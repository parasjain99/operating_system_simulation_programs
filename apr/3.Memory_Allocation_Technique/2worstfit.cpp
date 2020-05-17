#include <bits/stdc++.h>
using namespace std;

int main()

{

    int b, p,max,pos;
    cout << "Enter the number of blocks :";
    cin >> b;
    cout << "Enter the number of processes: ";
    cin >> p;
    int bs[b], ps[p];
    
    for (int i = 0; i < b; i++)
    {
        cout << "Enter the size of block " << i + 1 << ": ";
        cin >> bs[i];
    }

    for (int i = 0; i < p; i++)
    {
        cout << "Enter the size of processe " << i + 1 << ": ";
        cin >> ps[i];
    }

    for (int i = 0; i < p; i++){
        max = bs[0];
        pos = 0;
        for (int j = 0; j < b; j++){
            if (max < bs[j]){
                max = bs[j];
                pos = j;
            }
        }
        if (max >= ps[i]){
            cout << "\nProcess " << i+1  << " allocated block " << pos+1 ;
            bs[pos] = bs[pos] - ps[i];
        }
        else
            cout << "\nProcess " << i+1 << " not allocated";
    }

    return 0;
}
//Input
// 4
// 4
// 100
// 200
// 300
// 400
// 125
// 225
// 330
// 50
//Output
// Process 1 allocated block 4
// Process 2 allocated block 3
// Process 3 not allocated
// Process 4 allocated block 4
