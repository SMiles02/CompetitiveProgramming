#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,a,b,done=0,maa;
    double c;
    map<int,int> occurences;
    vector<double> doubles;
    cin>>n;
    while (n--)
    {
        cin>>k;
        ++occurences[k];
        if (occurences[k]==2)
        {
            doubles.push_back(k);
        }
        else if (occurences[k]==4)
        {
            done=1;
            maa=k;
        }
    }
    if (done)
    {
        cout<<maa<<" "<<maa<<" "<<maa<<" "<<maa<<"\n";
        return;
    }
    k=sz(doubles);
    sort(doubles.begin(), doubles.end());
    a=doubles[0];b=doubles[1];c=(doubles[0]/doubles[1])+(doubles[1]/doubles[0]);
    for (int i=1;i<k-1;++i)
    {
        if ((doubles[i]/doubles[i+1])+(doubles[i+1]/doubles[i])<c)
        {
            c=(doubles[i]/doubles[i+1])+(doubles[i+1]/doubles[i]);
            a=doubles[i];
            b=doubles[i+1];
        }
    }
    cout<<a<<" "<<b<<" "<<a<<" "<<b<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}