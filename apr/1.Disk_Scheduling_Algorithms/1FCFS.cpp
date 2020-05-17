#include<bits/stdc++.h>
using namespace std;

int main(){
    int pos, n, size, seekmovs,d;//track size
    cout << "Enter disk size(total number of tracks)\n";
    cin>>size;
    cout<<"Enter initial head position\n";
    cin>>pos;
    cout << "Enter number of track requests\n";
    cin >> n;
    vector<int> req(n);
    
    for(int i=0;i<n;i++){
        cout << "Enter request "<<i+1<<": ";
        cin >> req[i];
    }
        
    seekmovs=0;
    cout<<"Order:\n";
    cout<<pos<<"->";
    for (int i = 0; i < n; i++){
        cout << req[i] << "->";
        d = abs(req[i] - pos);
        pos = req[i];
        seekmovs+=d;
    }
    cout<<"\nTotal track/seek movements = "<<seekmovs;
}
// input
// 199
// 53
// 8
// 98 183 41 122 14 124 65 67
// output
// 53->98->183->41->122->14->124->65->67
// Total no of seek movements are 632