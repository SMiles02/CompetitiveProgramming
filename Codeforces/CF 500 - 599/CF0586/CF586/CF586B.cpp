#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,currentB;
	cin>>n;
	int a[n-1];
	int b[n-1];
	int c[n];
	int dpA[n];
	int dpB[n];
	int ansL[n];
	dpA[0]=0;
	for (int i=0;i<n-1;++i)
	{
		cin>>a[i];
		dpA[i+1]=dpA[i]+a[i];
	}
	currentB=0;
	for (int i=0;i<n-1;++i)
	{
		cin>>b[i];
		currentB+=b[i];
	}
	for (int i=0;i<n-1;++i)
	{
		dpB[i]=currentB;
		currentB-=b[i];
	}
	dpB[n-1]=0;
	for (int i=0;i<n;++i)
	{
		cin>>c[i];
		ansL[i]=c[i]+dpA[i]+dpB[i];
	}
	sort(ansL,ansL+n);
	//for (int i=0;i<n;++i)
	//{
	//	cout<<dpA[i]<<" "<<c[i]<<" "<<dpB[i]<<"\n";
	//}
	cout<<ansL[0]+ansL[1];
	return 0;
}