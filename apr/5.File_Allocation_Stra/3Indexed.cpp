#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s, start, l;
    cout << "Enter memory size in terms of number of blocks\n";
    cin >> m; //50
    s=m;
    vector<int> f(s, -1);
    int n, x=1, ind,c;
    for(int i=1;x!=0;i++)
    {
        cout << "Enter the index block of the file: ";
        cin >> ind;
        if(ind>=m){
            cout<<"Error:Index Out of range!\n";
        }
        else if (f[ind] ==-1)
        {
            cout << "Enter no of blocks of file for the index " << ind << " on the disk : \n";
            cin >> n;
            if(n+1>s){
                cout<<"File size is more than available memory \n";
            }
            else{
                c=n;
                cout<<"File "<<i<<" Indexed at "<<ind<<". Allocation is as follows:\n";
                f[ind]=i;
                s--;
                for(int j=0;j<m&&c>0;j++){
                    if(f[j]==-1){
                        f[j]=i;
                        cout<<"file "<<ind<<" ------->"<<j<<endl;
                        c--;
                        s--;
                    }
                }
                cout<<"File Allocation Successful!\n";
            }
        }
        else
        {
            cout << "File not allocated due to error: This location is already allocated to another file \n";
        }

        cout << "\nPress 1 to enter another files, 0 to exit ";
        cin >> x;
        if(s<1){
            cout<<"Memory Full!\n";
            x=0;
        }
    }
}