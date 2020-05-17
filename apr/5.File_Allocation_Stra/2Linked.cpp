#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s, start, l, p,m;
    cout << "Enter memory size in terms of number of blocks\n";
    cin >> s; //50
    m=s;
    vector<int> f(s, -1);
    cout<<"Enter how many blocks already allocated: ";
    cin>>p;
    
    for (int i = 0; i < p; i++)
    {   int a;
        cout << "Enter allocated block "<<i+1<<": ";
        cin>>a;
        if(f[a]!=-1){
            f[a] = 0;
            s--;
        }

    }
    int x=1;
    for(int i=1;x!=0;i++){
        cout<<"Enter index starting block of the file : ";
        cin>>start;
        cout << "Enter length of the file: ";
        cin>>l;
        int k = l;
        if (f[start] == -1 && l<=s)
        {
            cout<<"File stored in blocks: ";
            f[start] = i;
            l--;
            s--;
            cout << start << ", ";
            for (int j = 0; j < m && l>0; j++)
            {
                if (f[j] == -1)
                {
                    s--;
                    l--;
                    f[j] = i;
                    cout<<j<<", ";
                }
            }
        }
        else if(l>s){
            cout << "\nFile not allocated due to Error:- File size is larger than the available memory\n";
        }
        else{
            cout <<"\nFile not allocated due to Error:- Starting block is already allocated\n";
        }
        cout << "\nPress 1 to enter more files, 0 to exit ";
        cin >> x;
        if (s < 1)
        {
            cout << "Memory Full!\n";
            x = 0;
        }
    }
    return 0;
}