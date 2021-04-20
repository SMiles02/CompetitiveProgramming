#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    array<int,2> a[n+1];
    string s;
    for (int i=1;i<=n;++i)
        cin>>a[i][0],a[i][1]=i;
    sort(a+1,a+n+1);
    vector<array<int,3>> v;
    for (int i=1;i<=n;++i)
        for (int j=1;j<i;++j)
            v.push_back({abs(a[i][0]-a[j][0]),a[j][1],a[i][1]});
    sort(v.rbegin(), v.rend());
    for (auto i : v)
    {
        cout<<"? "<<i[2]<<" "<<i[1]<<endl;
        cin>>s;
        if (s[0]=='Y')
        {
            cout<<"! "<<i[1]<<" "<<i[2]<<endl;
            return 0;
        }
    }
    cout<<"! 0 0"<<endl;
    return 0;
}