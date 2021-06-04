#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t>>n;
    while (t--)
    {
        for (int i=1;i<n;++i)
        {
            cout<<"M "<<i<<" "<<n<<endl;
            cin>>k;
            if (k==i)
                continue;
            cout<<"S "<<i<<" "<<k<<endl;
            cin>>k;
        }
        cout<<"D"<<endl;
        cin>>k;
    }
    return 0;
}