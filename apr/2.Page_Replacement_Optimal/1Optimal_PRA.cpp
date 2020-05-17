#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fsize,n,hit,miss,fptr;
    cout<<"Enter no. of frames(frame size)\n";
    cin>>fsize;
    cout << "Enter no. of requests\n"; 
    cin>>n;
    vector<int> req(n), frame(fsize, -1);
    for(int i=0;i<n;i++){
        cout<<"Enter request "<<i+1<<": ";
        cin>>req[i];
    }
    miss = 0; 
    hit = 0;
    fptr = 0;
    for(int i=0;i<n;i++){
        bool isHit=false;
        cout << endl
             << i << ". Request " << req[i] << "\nframes ";
        for (int j = 0; j < fsize; j++)
            cout<<frame[j]<<" ";

        for (int j = 0; j < fsize; j++)
        {
            if (req[i] == frame[j])
            {
                hit++;
                isHit=true;
                cout<<"\nHit at frame "<<j<<endl;
                break;
            }
        }
        if(isHit)
            continue;
        else if (fptr < fsize)
        {
            frame[fptr] = req[i];
            cout <<"\nMiss frame "<< fptr << "= " << frame[fptr]<<endl;
            fptr++;
            miss++;
        }
        else{

            int temp = 0, pos = INT_MIN;
            for (int j = 0; j < fsize; j++)
            {
                temp=0;
                for(int k=i+1;k<n;k++){
                    temp++;
                    if (req[k] == frame[j])
                        break;
                    else if(k+1==n)
                        temp++;
                }
                if(pos<temp){
                    pos=temp;
                    fptr=j;
                }
            }
            frame[fptr] = req[i];
            cout<<"\nMiss frame "<<fptr<<"= "<<frame[fptr]<<endl;
            fptr = fsize;
            miss++;
        }
    }
    float h=(float)hit, m = (float)miss;
    h/=n;
    m/=n;
cout<<"\nHit Count = "<<hit<<"\nMiss Count = "<<miss<<"\nHit ratio = "<<h<<"\nMiss ratio = "<<m;
}
//Input
// 4
// 20
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
//output
// Total hit = 12
// Total miss = 8
// Hit ratio = 0.6
// Miss ratio = 0.4