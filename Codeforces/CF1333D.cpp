#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,total=0,minLevels=0,m,flag=0,x;
    string s;
    vector<vector<int>> big;
    vector<int> v;
    cin>>n>>k;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        v.clear();
        for (int j=0;j<n-1;++j)
        {
            if (s[j]=='R')
            {
                if (s[j+1]=='L')
                {
                    v.push_back(j+1);
                    swap(s[j],s[j+1]);
                    j+=1;
                    ++total;
                }
            }
        }
        if (sz(v)==0)
        {
            break;
        }
        ++minLevels;
        big.push_back(v);
    }
    if (k<minLevels||total<k)
    {
        cout<<-1;
        return 0;
    }
    m=minLevels;
    for (int i=0;i<minLevels;++i)
    {
        x=sz(big[i]);
        flag=0;
        for (int j=0;j<x;++j)
        {
            if (j==x-1)
            {
                if (!flag)
                {
                    cout<<"1 "<<big[i][j];
                    cout<<"\n";
                }
                else
                {
                    cout<<big[i][j]<<"\n";
                }
            }
            else if (m<k)
            {
                cout<<"1 "<<big[i][j];
                cout<<"\n";
                ++m;
            }
            else if (flag)
            {
                cout<<big[i][j]<<" ";
            }
            else
            {
                flag=1;
                cout<<x-j<<" "<<big[i][j]<<" ";
            }
        }
    }
    return 0;
}