#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arraySum(int a[], int n)  
{ 
    int initial_sum  = 0;  
    return accumulate(a, a+n, initial_sum); 
} 

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,l,r,ans,maxNum,cur;
	cin>>n>>l>>r;
	maxNum=pow(2.0,l-1);
	cur=maxNum;
	ans=maxNum;
	while (cur>1)
	{
		cur/=2;
		ans+=cur;
	}
	cout<<ans+(n-l)<<" ";
	maxNum=pow(2.0,r-1);
	cur=maxNum;
	ans=maxNum;
	while (cur>1)
	{
		cur/=2;
		ans+=cur;
	}
	ans+=(maxNum*(n-r));
	cout<<ans;
	return 0;
}