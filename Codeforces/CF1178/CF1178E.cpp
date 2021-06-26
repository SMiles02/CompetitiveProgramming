#include <bits/stdc++.h>
using namespace std;

string s;

void f(int l, int r)
{
    if (r<l)
        return;
    if (r-l<3)
    {
        cout<<s[l];
        return;
    }
    for (int i=l;i<l+2;++i)
        for (int j=r-1;j<=r;++j)
            if (s[i]==s[j])
            {
                cout<<s[i];
                f(l+2,r-2);
                cout<<s[j];
                return;
            }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    f(0,s.size()-1);
    return 0;
}