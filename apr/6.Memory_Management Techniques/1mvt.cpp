#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s,m;
    cout << "Enter total memory available in KB: ";
    cin >> s;
    m=s;
    cout << "Enter no. of processes: ";
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the size of process " << i << " in KB: ";
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (m >= p[i])
        {
            cout << "Process " << i << " allocated.\n";
            m -= p[i];
        }
        else
            cout << "Process " << i << " not allocated due to insufficient memory.\n";
    }
    cout << endl;
    cout<<"Total memory allocated = "<<s-m;
    cout << "\nExternal Fragmentation = " << m;
}
