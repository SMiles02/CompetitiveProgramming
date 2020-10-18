#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    int n,m=1,x,y;
    cin>>n;
    int a[n+1];
    for (int i=2;i<=n;++i)
    {
        cout<<"? "<<m<<" "<<i<<endl;
        cin>>x;
        cout<<"? "<<i<<" "<<m<<endl;
        cin>>y;
        if (x>y)
        {
            a[m]=x;
            m=i;
        }
        else
            a[i]=y;
    }
    a[m]=n;
    cout<<"! ";
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}