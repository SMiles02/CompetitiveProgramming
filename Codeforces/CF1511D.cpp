#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    string s = "a";
    cin>>n>>k;
    while (sz(s)<n)
    {
        for (int i=0;i<k&&sz(s)<n;++i)
            for (int j=k-1;j>i&&sz(s)<n;--j)
            {
                s+='a'+i;
                if (sz(s)<n)
                    s+='a'+j;
            }
        for (int i=k-1;i>=0&&sz(s)<n;--i)
            s+='a'+i;
    }
    cout<<s;
    return 0;
}