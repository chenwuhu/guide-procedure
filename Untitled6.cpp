#include <stdio.h>
#include<math.h>		
int main()					
{
	//********Begin*********
	float high;
	float sum;
	int n,d=1;
	scanf("%f%d",&high,&n);
	sum=0;
	while(d<=n)
	{
		high=high/2;
		sum+=4*high;
		d++;
	}
printf("%.2f\n%.2f\n",sum,high);
	//********End*********** 
	return 0;
}

