#include<stdio.h>
struct node {int v[4];int s;};void po(struct node * a) {a[0].v[0]=0;a[6].s=a[3].v[3]=a[1].s=a[0].s=a[1].v[0]=1;a[2].v[0]=2;a[2].v[1]=4;a[2].v[2]=8;a[2].v[3]=6;a[2].s=4;a[3].v[0]=3;a[3].v[1]=9;a[3].v[2]=7;a[3].s=4;a[4].v[0]=4;a[4].v[1]=6;a[4].s=2;a[5].v[0]=5;a[5].s=1;a[6].v[0]=6;a[7].v[0]=7;a[7].v[1]=9;a[7].v[2]=3;a[7].v[3]=1;a[7].s=4;a[8].v[0]=8;a[8].v[1]=4;a[8].v[2]=2;a[8].v[3]=6;a[8].s=4;a[9].v[0]=9;a[9].v[1]=1;a[9].s=2;}
int main(){struct node a[10];int p,t,b,n;long long int q=0;po(a);scanf("%d",&n);while(n--) {scanf("%d%lld",&p,&q);t=p%10;b=q%a[t].s;if(q==0) {printf("1\n");continue;}if(b==0)printf("%d\n",a[t].v[a[t].s-1]);else
printf("%d\n",a[t].v[b-1]);}return 0;}
