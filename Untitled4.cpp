#include <stdio.h>			
int main()					
{
	//********Begin*********
	int n,x,sum=0;
	scanf("%d",n);
	for(x=1;x<=n;x++)
	{
		if(x%10==3||x%10==5)
		sum+=x;
		
	}
	printf("%d",sum);
	//********End*********** 
	return 0;
}

