#include <bits/stdc++.h>
using namespace std;

int n,k,mx,a,b;
map<int,int> m;

void query(int x)
{
    cout<<"?";
    for (int i=1;i<k+2;++i)
        if (i^x)
            cout<<" "<<i;
    cout<<endl;
    cin>>a>>b;
    ++m[b];
    mx=max(mx,b);
}

int main()
{
    cin>>n>>k;
    for (int i=1;i<k+2;++i)
        query(i);
    cout<<"! "<<m[mx]<<endl;
    return 0;
}