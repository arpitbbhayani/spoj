#include<stdio.h>
 
#include<iostream>
 
#include<math.h>
 
using namespace std;
 
int main()
 
{
 
int n;
 
M:
 
cin>>n;
 
if(n!=0)
 
{
 
n=log(n)/log(2);
 
cout<<n<<endl;
 
goto M;
 
}
 
//system("pause");
 
return 0;
 
}
