#include <stdio.h>			
int main()					
{
	//********Begin*********
	int n,s=1,x;
	scanf("%d",&x);
	for(n=1;n++;)
	{
		s*=n;
		if(s>x)
		break;
	}
	printf("%d",n-1);
	//********End*********** 
	return 0;
}

