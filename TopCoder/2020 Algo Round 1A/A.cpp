#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

class AveragePrice
{
public:
    double nonDuplicatedAverage(vector<int> prices)
    {
        int n=sz(prices),tot=0;
        double ans=0;
        map<int,int> m;
        for (int i=0;i<n;++i)
        {
            if (!m[prices[i]])
            {
                ans+=prices[i];
                ++tot;
            }
            m[prices[i]]=1;
        }
        return ans/tot;
    }
};