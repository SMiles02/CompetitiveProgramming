#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x=0,y;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=1;i<n;++i)
        if (s[i]>=s[0])
        {
            x=i;
            break;
        }
    if (x>0)
    {
        y=x-1;
        for (int j=x;j<n;++j)
        {
            if (s[j]>s[j-y-1])
                break;
            if (s[j-y-1]>s[j])
                y=j;
        }
        while (sz(s)>y+1)
            s.pop_back();
    }
    n=sz(s);
    for (int i=n;i<=k;i+=n)
        cout<<s;
    for (int i=0;i<k%n;++i)
        cout<<s[i];
    return 0;
}