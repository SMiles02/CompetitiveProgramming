#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct FirstColumnOnlyCmp
{
    bool operator()(const std::vector<double>& lhs,
                    const std::vector<double>& rhs) const
    {
        return lhs[0] < rhs[0];
    }
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,v,a,b,ans,k;
	ans=0;
	cin>>n>>v;
	int ripeOnDay[3001]={0};
	int doneOnDay[3002]={0};
	for (int i=0;i<n;++i)
	{
		cin>>a>>b;
		ripeOnDay[a]+=b;
	}
	for (int i=1;i<3001;++i)
	{
		k=min(v-doneOnDay[i],ripeOnDay[i]);
		ripeOnDay[i]-=k;
		doneOnDay[i]+=k;
		ans+=doneOnDay[i];
		doneOnDay[i+1]+=min(v-doneOnDay[i+1],ripeOnDay[i]);
	}
	ans+=doneOnDay[3001];
	cout<<ans;
	return 0;
}