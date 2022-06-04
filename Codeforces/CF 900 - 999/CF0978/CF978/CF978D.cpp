#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int answer=100001,c,n;
vector<int> v;

void check(int altered)
{
    c=v[1]-v[0];
    for (int i=2;i<n;++i)
    {
        if (abs(-v[i]+v[0]+(i*c))<2)
        {
            altered+=abs(-v[i]+v[0]+(i*c));
        }
        else
        {
            //cout<<": "<<-1<<"\n";
            return;
        }
    }
    answer=min(answer,altered);
    //cout<<": "<<altered<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    if (n<3)
    {
        cout<<0;
        return 0;
    }
    for (int i=-1;i<2;++i)
    {
        v[0]+=i;
        for (int j=-1;j<2;++j)
        {
            //cout<<i<<" "<<j;
            v[1]+=j;
            check(abs(i)+abs(j));
            v[1]-=j;
        }
        v[0]-=i;
    }
    if (answer==100001)
    {
        cout<<-1;
    }
    else
    {
        cout<<answer;
    }
    return 0;
}