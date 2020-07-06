#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int,int> m;
    int a=1,b;
    for (int i=0;i<10;++i)
    {
        while (m[a])
        {
            ++a;
        }
        b=a+1;
        while (m[b]||m[a^b])
        {
            ++b;
        }
        cout<<a<<"\n"<<b<<"\n"<<(a^b)<<"\n";
        m[a]=1;
        m[b]=1;
        m[a^b]=1;
    }
    return 0;
}