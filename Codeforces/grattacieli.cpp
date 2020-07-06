#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    int ans[N];
    int total=0;
    if (M==N-1)
    {
    	map<int,ll> m;
    	for (int i=0;i<M;++i)
    	{
    		m[A[i]]=C[i];
    	}
    	ans[0]=H[0];
    	total=H[0];
    	//cout<<total<<" ";
    	for (int i=1;i<N;++i)
    	{
    		ans[i]=min(H[i],ans[i-1]+m[i-1]);
    		//cout<<ans[i]<<" ";
    		total+=ans[i];
    	}
    }
    //cout<<"\n";
    return total;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	ll d;
	cin>>n>>m;
	vector<ll> h;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	for (int i=0;i<n;++i)
	{
		cin>>d;
		h.push_back(d);
	}
	for (int i=0;i<m;++i)
	{
		cin>>k;
		a.push_back(k);
		cin>>k;
		b.push_back(k);
		cin>>k;
		c.push_back(k);
	}
	cout<<costruisci(n,m,h,a,b,c);
	return 0;
}