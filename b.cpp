#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const int MAXN=4000;
void A(int& a,int b){a+=b;if(a>=MOD)a-=MOD;}
int AA(int a,int b){a+=b;return (a>=MOD)?(a-MOD):a;}
void D(int& a,int b){a-=b;if(a<0)a+=MOD;}
int DD(int a,int b){a-=b;return (a<0)?(a+MOD):a;}
void M(int& a,int b){a=(ll)a*b%MOD;}
int MM(int a,int b){return (ll)a*b%MOD;}
int n,s,a[MAXN+10],b[MAXN+10],jc[MAXN+10],njc[MAXN+10];
bool vis[MAXN+10];
int qa[MAXN+10],qb[MAXN+10],tot,now;
int f[MAXN+10][MAXN+10],fa[MAXN+10],fb[MAXN+10],f1[MAXN+10],f2[MAXN+10];
int C(int a,int b){return MM(jc[a],MM(njc[b],njc[a-b]));}
bool FFF;
void solve()
{
	sort(qa+1,qa+1+tot);now=1;
	for(int i=1;i<=tot;++i)
	{
		if(now>tot)break;
		if(qa[i]>=qb[i])qb[now++]=i-1;
	}
	while(now<=tot)qb[now++]=tot;
	memset(f,0,sizeof f);f[0][0]=1;
	for(int i=1;i<=tot;++i)
		for(int j=0;j<=i;++j)
		{
			f[i][j]=f[i-1][j];
			if(j&&qb[i]>=j)A(f[i][j],MM(f[i-1][j-1],(qb[i]-(j-1))));
		}
	for(int i=0;i<=tot;++i)fa[i]=MM(f[tot][i],jc[tot-i]);
	for(int i=tot;i>=0;--i)
	{
		fb[i]=fa[i];
		for(int j=i+1;j<=tot;++j)D(fb[i],MM(fb[j],C(j,i)));
	}
}
int PP(int x,int y){int res=1;while(y){if(y&1)M(res,x);y>>=1;M(x,x);}return x;}
int ny(int x){return PP(x,MOD-2);}
int main()
{
	scanf("%d%d",&n,&s);
	jc[0]=1;for(int i=1;i<=n;++i)jc[i]=MM(jc[i-1],i);
	for(int i=0;i<=n;++i)njc[i]=ny(jc[i]);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	for(int i=1;i<=n;++i)if(a[i]&&b[i])s-=(a[i]>b[i]);
	for(int i=1;i<=n;++i)if(!a[i])qa[++tot]=b[i];else vis[a[i]]=true;
	for(int i=1;i<=n;++i)if(!vis[i])qb[++now]=i;
	solve();for(int i=0;i<=n;++i)f1[i]=fb[i];
	tot=now=0;memset(vis,0,sizeof vis);
	for(int i=1;i<=n;++i)if(!b[i])qa[++tot]=a[i];else vis[b[i]]=true;
	for(int i=1;i<=n;++i)if(!vis[i])qb[++now]=i;
	FFF=true;solve();for(int i=0;i<=n;++i)f2[i]=fb[i];
	int ans=0;
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)if(i+j==s) A(ans,MM(f1[i],f2[j]));
	printf("%d",ans);
	return 0;
}
