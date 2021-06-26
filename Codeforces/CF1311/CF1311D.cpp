#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int a,b,c,ans=30000,C_MAX,C_MIN,ansA,ansB,ansC;
    cin>>a>>b>>c;
    for (int A=1;A<=2*a;++A)
        for (int B=A;B<=2*b;B+=A)
        {
            if (B>c)
            {
                if (abs(a-A)+abs(b-B)+abs(c-B)<ans)
                {
                    ans=abs(a-A)+abs(b-B)+abs(c-B);
                    ansA=A;ansB=B;ansC=B;
                }
            }
            else
            {
                C_MIN=B*(c/B);
                C_MAX=B*(c/B+1);
                if (abs(a-A)+abs(b-B)+abs(C_MAX-c)<ans)
                {
                    ans=abs(a-A)+abs(b-B)+abs(C_MAX-c);
                    ansA=A;
                    ansB=B;
                    ansC=C_MAX;
                }
                if (abs(a-A)+abs(b-B)+abs(C_MIN-c)<ans)
                {
                    ans=abs(a-A)+abs(b-B)+abs(C_MIN-c);
                    ansA=A;
                    ansB=B;
                    ansC=C_MIN;
                }
            }
        }
    cout<<ans<<"\n"<<ansA<<" "<<ansB<<" "<<ansC<<"\n";
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