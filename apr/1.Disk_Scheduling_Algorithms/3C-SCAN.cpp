#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pos, n, size, seekmovs, temp, start; //track size
    cout << "Enter disk size (total number of tracks)\n";
    cin >> size;
    cout << "Enter initial head position\n";
    cin >> pos;
    cout << "Enter number of track requests\n";
    cin >> n;
    vector<int> req(n);
    
    for (int i = 0; i < n; i++){
        cout << "Enter request "<<i+1<<" : ";
        cin >> req[i];
    }
        
    req.push_back(pos);

    sort(req.begin(), req.end());
    for (int i = 0; i < req.size(); i++){
        if (req[i] == pos){
            start = i;
            break;
        }
    }

    seekmovs = 0;
    cout << "Order:\n";
    cout << pos << "->";

    if (req[start] - req[start - 1] >= req[start + 1] - req[start])
    {
        req.push_back(size);
        for (int i = start + 1; i < n + 2; i++)
        {
            cout << req[i] << "->";
            temp = req[i] - pos;
            pos = req[i];
            seekmovs += temp;
            // cout<<seekmovs<<endl;//
        }
        pos=0;
        cout << 0 << "->";
        seekmovs+=size;
        // cout << seekmovs << endl;//
        for (int i = 0; i < start; i++)
        {

            cout << req[i] << "->";
            temp = req[i]-pos;
            // cout<<seekmovs<<"+"<<temp<<"=";
            pos = req[i];
            seekmovs += temp;
            // cout << seekmovs << endl;//
        }
    }
    else
    {
        req.push_back(0);
        start++;
        sort(req.begin(), req.end());
        for (int i = start - 1; i > -1; i--)
        {
            cout << req[i] << "->";
            temp = pos - req[i];
            pos = req[i];
            seekmovs += temp;
            // cout << seekmovs << endl; //
        }
        pos=req[size];
        cout << size << "->";
        seekmovs += size;
        for (int i = req.size()-1; i > start; i--)
        {
            cout << req[i] << "->";
            temp = pos-req[i];
            pos = req[i];
            seekmovs += temp;
            // cout << seekmovs << endl; //
        }
    }

    cout << "\nTotal track/seek movements = " << seekmovs;
}
//input
// 199
// 53
// 8
// 98 183 41 122 14 124 65 67
//output
// 53->65->67->98->122->124->183->199->0->14->41
//Total no of seek movements are 386
