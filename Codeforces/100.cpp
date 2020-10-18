#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define sz(x) (int)(x).size()
using namespace std;

int n,a[1000];

bool fix(int x, int y)
{
    vector<int> v,w;
    v.push_back({x,a[x]});
    v.push_back({y,a[y]});
    double d = 
    for (int i=0;i<n;++i)
        if (i!=x&&i!=y)
        {
            if ()
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (fix(0,1)||fix(0,2)||fix(1,2))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}