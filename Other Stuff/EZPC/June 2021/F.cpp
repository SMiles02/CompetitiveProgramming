#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    char c = 'a';
    for (char c='a';n>0;++c)
    {
        if ('z'<c)
            c='a';
        for (int i=200;i>0;--i)
            if ((i*(i+1))/2<=n)
            {
                for (int j=0;j<i;++j)
                    cout<<c;
                n-=(i*(i+1))/2;
                break;
            }
    }
    cout<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}