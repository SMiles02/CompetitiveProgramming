#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll NCR(int n, int r)
{
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r); 
    ll res = 1; 
    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	cout<<NCR(n,5)+NCR(n,6)+NCR(n,7);
	return 0;
}