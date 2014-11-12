/*
13388. Easy Jug

Problem code: MAY99_3

One day Manku was very thirsty , so he decided to drink exactly z litres of water .
However , in front of him, there is a well of infinite amount of water and 2 empty jugs of quantity x litres and y litres respectively.


Now Manku can do the following operations to any jug

1> Fill it completely from the well
2> Empty it entirely
3> Transfer as much water from Jug 1 to Jug 2 , till Jug 1 gets empty or Jug 2 is completely filled.

Now since he has no measuring device so he will do these operations only to make any of the 2 jug having exactly z litres of water.

Now Your task is given value of x,y,z , tell whether it is possible for Manku to drink water or not.



Input

First Line of Input contains t , no. of test cases. (t<=25)

Then for each test case there are 3 no's x,y,z given in separate line

1<=x<=10^12

1<=y<=10^12

1<=z<=10^12



Output

For each test case output  "YES" if manku can drink exactly z litres of water else "NO".

Example

Input:
5
2 4 3
2 5 1
9 3 6
3 8 7
6 1 10


 Output:
NO
YES
YES
YES
NO

Explanation

In Test case 1 Either Manku can have 2 or 4 litres of water so he cant drink 3 litres

In Test case 2 Manku can have 1 litre water by doing the following operations

                  -> Fill 2 litre Jug

                  -> Transfer its water to 5 litre Jug

                  -> Again Fill 2 litre Jug

                  -> Again Transfer its entire water to 5 litre Jug
                      Now 5 litre Jug will have total 4 litre water

                  ->Again Fill 2 litre Jug

                   -> Now transfer 1 litre water to 5 litre Jug

                        because at present 5 litre Jug don't have space for more than 1 litre water
     Now the 2 litre Jug will have only 1 litre water left

For Test case 3 we will transfer 3 litre water twice from 3 litre jug to 9 litre jug

For test Case 4 , transfer 3 times water of 3 litre jug to 8 litre jug
     Ultimately 3 litre Jug has 1 litre water left and 8 litre Jug is full
     Now empty 8 litre jug and pour remaining 1 litre of 3 litre jug in it
     Now fill 3 litre jug fully twice and transfer its water to 8 litre jug

Now 8 litre Jug will have 7 litre water

For Test case 5, we cant have 10 litre of water in any jug
*/

#include <stdio.h>
#define ll long long

ll GCD(ll a, ll b)
{
	ll r;

	while(b != 0)
	{
		r = b;
		b = a % b;
		a = r;
	}

	return r;
}

int main()
{
	int testCases;
	ll x, y, z, gcd;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld %lld", &x, &y, &z);

		if(z > x && z > y)
			printf("NO\n");
		else
		{
			gcd = GCD(x, y);
			if(z % gcd)
				printf("NO\n");
			else
				printf("YES\n");
		}

	}

	return 0;
}
