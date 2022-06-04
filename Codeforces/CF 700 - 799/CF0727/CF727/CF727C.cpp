#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    cin>>n;
    int a[n+1];
    cout<<"? 1 2"<<endl;
    cin>>x;
    cout<<"? 3 2"<<endl;
    cin>>y;
    cout<<"? 1 3"<<endl;
    cin>>z;
    a[1]=(x+z-y)/2;
    a[2]=x-a[1];
    a[3]=z-a[1];
    for (int i=4;i<=n;++i)
    {
        cout<<"? 1 "<<i<<endl;
        cin>>x;
        a[i]=x-a[1];
    }
    cout<<"!";
    for (int i=1;i<=n;++i)
    {
        cout<<" "<<a[i];
    }
    return 0;
}