#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=1,ans=0;
    cin>>n;
    vector<int> c;
    for (int i=1;i<13;++i)
    {
        x*=i;
        for (int j=0;j<100;++j)
            c.push_back(x);
    }
    while (!c.empty())
    {
        if (c.back()<=n)
        {
            n-=c.back();
            ++ans;
        }
        c.pop_back();
    }
    cout<<ans;
    return 0;
}