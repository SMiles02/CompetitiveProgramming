#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bitset<4000> bad[4000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=sz(s);
    bool b;
    for (int i=0;i<n;++i)
        for (int j=i;j<n;++j)
            for (int k=2;k<j-i+1;++k)
                if ((j-i+1)%k==0)
                {
                    b=1;
                    for (int l=i+k;l<j;++l)
                        if (s[l]!=s[l-k])
                        {
                            b=0;
                            break;
                        }
                    bad[i][j]=b;
                }
    return 0;
}