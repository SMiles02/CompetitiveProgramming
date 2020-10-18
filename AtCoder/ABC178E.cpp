#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF=2e9;
int minPlus=INF,maxPlus=-INF,minMinus=INF,maxMinus=-INF;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    while (n--)
    {
        cin>>x>>y;
        minPlus=min(minPlus,x+y);
        maxPlus=max(maxPlus,x+y);
        minMinus=min(minMinus,x-y);
        maxMinus=max(maxMinus,x-y);
    }
    cout<<max(maxPlus-minPlus,maxMinus-minMinus);
    return 0;
}