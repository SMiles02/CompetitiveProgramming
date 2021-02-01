#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> types; //1=light, 2=bulb, 3=gate
map<int,int> lights;
map<int,int> sourceOfBulb;
map<int,pair<int,pair<int,int>>> gates;
map<int,int> gateAnswer; //1=>0, 2=>1

int recursion(int x)
{
    if (types[x]==1)
    {
        return lights[x];
    }
    if (types[x]==2)
    {
        return recursion(sourceOfBulb[x]);
    }
    if (!gateAnswer[x])
    {
        //cout<<"bigetst\n";
        if (gates[x].first==1)
        {
            gateAnswer[x]=recursion(gates[x].second.first)&&recursion(gates[x].second.second);
        }
        if (gates[x].first==2)
        {
            gateAnswer[x]=recursion(gates[x].second.first)||recursion(gates[x].second.second);
        }
        if (gates[x].first==3)
        {
            gateAnswer[x]=recursion(gates[x].second.first)^recursion(gates[x].second.second);
        }
        if (gates[x].first==4)
        {
            gateAnswer[x]=!(recursion(gates[x].second.first)||recursion(gates[x].second.second));
        }
        if (gates[x].first==5)
        {
            gateAnswer[x]=!(recursion(gates[x].second.first)&&recursion(gates[x].second.second));
        }
        gateAnswer[x]+=1;
    }
    return gateAnswer[x]-1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,b,g,x,y,z,t,cur=0;
    cin>>l>>b>>g;
    int bulbs[b];
    for (int i=0;i<l;++i)
    {
        cin>>x>>y;
        types[x]=1;
        lights[x]=y;
    }
    for (int i=0;i<b;++i)
    {
        cin>>x>>y;
        types[x]=2;
        sourceOfBulb[x]=y;
        bulbs[cur]=x;
        ++cur;
    }
    for (int i=0;i<g;++i)
    {
        cin>>x>>y>>z>>t;
        types[x]=3;
        gates[x]=make_pair(t,make_pair(y,z));
    }
    for (int i=0;i<b;++i)
    {
        cout<<recursion(bulbs[i])<<" ";
    }
    cout<<"\n";
    return 0;
}