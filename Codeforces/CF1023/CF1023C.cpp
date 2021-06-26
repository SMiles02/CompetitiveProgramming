#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a=0,b=0,score=0;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
        {
            if (a<k/2)
            {
                ++a;
                cout<<s[i];
                ++score;
            }
        }
        else
        {
            if (b<k/2&&score>0)
            {
                ++b;
                cout<<s[i];
                --score;
            }
        }
    }
    return 0;
}