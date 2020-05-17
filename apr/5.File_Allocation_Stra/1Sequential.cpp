#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,start, l;
    cout<<"Enter memory size in terms of number of blocks\n";
    cin>>s; //50
    vector<int> f(s,0);
    int x=1;
    while(x==1){
        int count = 0;
        cout << "Enter starting block : ";
        cin >> start;
        cout<<"Enter the length of file: ";
        cin>>l;
        for (int k = start; k < (start + l) && k < s; k++){
            if (f[k] == 0)
                count++;
        }
        if (l == count){
            for (int j = start; j < (start + l); j++)
                if (f[j] == 0){
                    f[j] = 1;
                    cout<<j<<"\t"<<f[j]<<endl;
                }
        }
        else
            cout<<"The file is not allocated \n";
        
        cout<<"Press 1 to enter more files, 0 to exit ";
        cin >> x;
    }
return 0;
}