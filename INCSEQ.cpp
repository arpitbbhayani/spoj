#include<bits/stdc++.h>
using namespace std;
#define mod 5000000
int bit[100002][51],a[10001];
void update(int ind,int val,int l,int n)
{
    while(ind<=n)
    {
        bit[ind][l]=((bit[ind][l]%mod)+(val%mod))%mod;
        ind+=ind&(-ind);
    }
}
int que(int ind,int l)
{
    int ans=0;
    while(ind>0)
    {
        ans=(ans%mod+bit[ind][l]%mod)%mod;
        ind-=ind&(-ind);
    }
return ans;
}
int main()
{
    int n,k,z,maxi=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),maxi=max(maxi,a[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int l=1;l<=k;l++)
        {
                if(l==1)
                    update(a[i]+1,1,1,maxi);
                else
                {
                    z=que(a[i]+1-1,l-1);
                    update(a[i]+1,z,l,maxi);
                }
        }
    }
    printf("%d",que(maxi,k));
}
