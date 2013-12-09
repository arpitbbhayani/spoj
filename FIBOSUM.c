#include<stdio.h>
unsigned long long int MOD=1000000007;
int i, j, k;
unsigned long long fib_fn(int n)
{
	unsigned long long int fib[2][2]={{1,1},{1,0}}, ans[2][2]={{1,0},{0,1}}, temp[2][2]={{0,0},{0,0}};
	while(n)
	{
		if(n&1)
		{
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					temp[i][j]=0;
			for(i=0;i<2;i++) 
				for(j=0;j<2;j++)
					for(k=0;k<2;k++)
						temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%MOD;
			for(i=0;i<2;i++) 
				for(j=0;j<2;j++) 
					ans[i][j]=temp[i][j];
		}
		for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					temp[i][j]=0;
		for(i=0;i<2;i++) 
			for(j=0;j<2;j++) 
				for(k=0;k<2;k++)
					temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%MOD;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++) 
				fib[i][j]=temp[i][j];
		n>>1;

	}
	return (ans[0][1])%MOD;
}

int main()
{
	int t,m,n;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n", (fib_fn(m+2)-fib_fn(n+1)+MOD)%MOD);
	}
	return 0;
}
