#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
 
string strBuilder(string s0, string s1, string s2, int k)
{
	string s = "";
	for (int i=0;i<k;++i)
	{
		if (i%3==0)
		{
			s.append(s0);
		}
		else if (i%3==1)
		{
			s.append(s1);
		}
		else
		{
			s.append(s2);
		}
	}
	return s;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n,k,cur1,cur2,cur3,ans,c1,c2,c3;
	string s,s1,s2,s3;
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>n>>k;
		cin>>s;
		s1=strBuilder("R","G","B",k);
		s2=s1;
		s3=s1;
		s2.erase(0,1);
		if (k%3==0)
		{
			s2.append("R");
			s3.append("G");
		}
		else if (k%3==1)
		{
			s2.append("G");
			s3.append("B");
		}
		else
		{
			s2.append("B");
			s3.append("R");
		}
		ans=k;
		cur1=0;
		cur2=0;
		cur3=0;
		//cout<<"s1: "<<s1<<"\n";
		//cout<<"s2: "<<s2<<"\n";
		for (int add=0;add<k;++add)
		{
			if (s1[add]==s[add])
			{
				++cur2;
				++cur3;
			}
			else if (s2[add]==s[add])
			{
				++cur1;
				++cur3;
			}
			else
			{
				++cur2;
				++cur1;
			}
		}
		ans=min({ans,cur1,cur2,cur3});
		for (int j=1;j<=n-k;j++)
		{
			if (s1[0]==s[j-1])
			{
				--cur2;
				--cur3;
			}
			else if (s2[0]==s[j-1])
			{
				--cur1;
				--cur3;
			}
			else
			{
				--cur2;
				--cur1;
			}
			c1=cur1;
			c2=cur2;
			c3=cur3;
			cur1=c3;
			cur2=c1;
			cur3=c2;
			if (s1[k-1]==s[j+k-1])
			{
				++cur2;
				++cur3;
			}
			else if (s2[k-1]==s[j+k-1])
			{
				++cur1;
				++cur3;
			}
			else
			{
				++cur2;
				++cur1;
			}
			ans=min({ans,cur1,cur2,cur3});
		}
		cout<<ans<<"\n";
	}
	return 0;
}