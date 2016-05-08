#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define endl '\n'
#define max(a,b) (a > b ? a : b)

using namespace std;

const int MAXN = 1e6 + 5;

int p[MAXN],dp[MAXN];
int n;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		
		memset(p,-1,sizeof(p));
		memset(dp,0,sizeof(dp));
		
		int num,x;
		int i,j,ans = 1;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&x);
			dp[i] = 1;
			for(j = 2;j * j <= x;j++)
			{
				if(x % j)continue;
				if(~p[j])
				{
					dp[i] = max(dp[i],dp[p[j]] + 1);
				}
				p[j] = i;
				while(x % j == 0)x /= j;
			}
			if(x > 1)
			{
				if(~p[x])
				{
					dp[i] = max(dp[i],dp[p[x]] + 1);
				}
				p[x] = i;
			}
			ans = max(dp[i],ans);
		}
		cout << ans << endl;
	}
	return 0;
}
