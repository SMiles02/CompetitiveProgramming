#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e7+1;
int ans[N];
bitset<N> b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur=0,k;
    cin>>n;
    ans[2]=1;
    for (int i=2;i<N;i+=2)
        b[i]=1;
    for (int i=3;i<N;++i)
    {
        if (!b[i])
        {
            ++cur;
            for (int j=i*2;j<N;j+=i)
                b[j]=1;
        }
        else if (i%2==0&&!b[i/2])
            --cur;
        ans[i]=cur+1;
    }
    while (n--)
    {
        cin>>k;
        cout<<ans[k]<<"\n";
    }
    return 0;
}