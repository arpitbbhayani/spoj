#include<stdio.h>

int main()
{	
	int n,i,sum=0,j,x,y;
	int a[100010];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	
	i=sum;

	while(i>1)
	{
		if(sum%i==0)
		{
			x=sum/i;
			y=x;
			j=0;
			while(j<n)
			{
				if(x>a[j])
					x-=a[j];
				else if(x==a[j])
					x=y;
				else
					break;
				j++;
			}
			if(j==n)
				printf("%d ",y);
		}
		i--;
	}
	printf("%d \n",sum);
	return 0;
}
