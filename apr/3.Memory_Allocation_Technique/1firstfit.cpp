#include <bits/stdc++.h>
using namespace std;

int main()

{

    int b, p, pos;
    cout << "Enter the number of blocks :";
    cin >> b;
    cout<<"Enter the number of processes: ";
    cin >> p;
    int bs[b],ps[p];

    for (int i = 0; i < b; i++){
        cout << "Enter the size of block "<<i+1<<": ";
        cin >> bs[i];
    }
        
    
    for (int i = 0; i < p; i++){
        cout << "Enter the size of processe "<<i+1<<": ";
        cin >> ps[i];
    }
        

    for (int i = 0; i < p; i++){
        pos = -1;
        for (int j = 0; j < b; j++){
            if (bs[j]>=ps[i]){
                pos = j;
                break;
            }
        }
        if (pos!=-1){
            cout << "\nProcess " << i+1  << " allocated block " << pos+1 ;
            bs[pos] = bs[pos] - ps[i];
        }
        else
            cout << "\nProcess " << i+1 << " not allocated";
    }

    return 0;
}

//Input
// 2
// 4
// 150
// 350
// 300
// 25
// 125
// 50
//Output
// Process 1 allocated block 2
// Process 2 allocated block 1
// Process 3 allocated block 1
// Process 4 allocated block 2