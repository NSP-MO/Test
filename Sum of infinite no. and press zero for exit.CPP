//Sum of infinite no. and press zero for exit
#include<stdio.h>
#include<conio.h>
int main()
{
	float n,s=0;
	for( ; ; )
	{ printf("Enter an elment=");
	  scanf("%f",&n);
	  if(n==0)
	  break;
	  s=s+n;
	}
	printf("Sum=%f\n",s);
	getch();
}