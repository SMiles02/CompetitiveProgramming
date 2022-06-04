#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,maxi=1,cur=1;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=1;i<2*n;++i)
    {
        if (s[i%n]==s[(i-1)%n])
        {
            cur=1;
        }
        else
        {
            ++cur;
            maxi=max(maxi,cur);
        }
    }
    cout<<min(n,maxi);
    return 0;
}