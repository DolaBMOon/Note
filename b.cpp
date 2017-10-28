#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int MOD=1e9+7;
const int MAXN=4000;
void A(int& a,int b){a+=b;if(a>=MOD)a-=MOD;}
int AA(int a,int b){a+=b;return (a>=MOD)?(a-MOD):a;}
void M(int& a,int b){return (ll)a*b%MOD;}
int MM(int a,int b){return (ll)a*b%MOD;}
int n,s;
int a[MAXN+10],b[MAXN+10];
bool vis[MAXN+10];
vector<int> qwq,qaq;int f[MAXN+10];
void solve()
{
	sort(qwq+1,qwq+1+n);sort(qaq+1,qaq+1+n);
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;++i)if(!a[i])qwq.push_back(b[i]);else vis[a[i]]=true;
	for(int i=1;i<=n;++i)if(!vis[i])qaq.push_back(i);
	solve();qwq.clear();qaq.clear();memset(vis,0,sizeof vis);
	return 0;
}
