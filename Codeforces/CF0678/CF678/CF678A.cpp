#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n>>k;
	cout<<(1+(n/k))*k;
	return 0;
}