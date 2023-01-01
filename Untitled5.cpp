#include <stdio.h>			
int main()					
{
	//********Begin*********
	int n,i,sum=0;
	scanf("%d",n);
	for(i=1;i<=n;i++)
	{
		if(i%10==3||i%10==5)
		sum=sum+i;
	}
	printf("%d",sum);
	//********End*********** 
	return 0;
}
