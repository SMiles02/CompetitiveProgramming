#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,k,su,n;
    cin>>q;
    while (q--)
    {
        cin>>n;
        su=0;
        for (int i=0;i<n;++i)
        {
            cin>>k;
            su+=k;
        }
        if (su%n)
        {
            cout<<(su/n)+1<<"\n";
        }
        else
        {
            cout<<su/n<<"\n";
        }
    }
    return 0;
}