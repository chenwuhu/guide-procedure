//ɽ������ѧԺ����ռ䰲ȫѧԺ
//��Ȩ�
//���� 2020����

#include<stdio.h>//�����Ȩͼ 
#include<stdlib.h>
#include<string.h>
#define Infinity 2000//��ʾ����� 
#define MaxVertexNum 20 
#define MAX 40 
#define key 11//keyΪ������� 
typedef struct arcell//�ߵ�Ȩֵ��Ϣ
{ 	int adj;//Ȩֵ  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum];//ͼ���ڽӾ�������
typedef struct vexsinfo//������Ϣ 
{ 	int position;//����ı�� 
	char name[32];//��������� 
	char introduction[256];//����Ľ��� 
	char super_introduction[512];//�������ϸ���� 
}vexsinfo;
typedef struct mgraph//ͼ�ṹ��Ϣ
{  	vexsinfo vexs[MaxVertexNum];//�������������飩 
	adjmatrix arcs;//�ڽӾ��� 
	int vexnum,arcnum;//�������ͱ��� 
}mgraph;
//ȫ�ֱ���
mgraph campus; //ͼ��������ѧУ԰�� 
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];//����ȫ�ֱ����洢��С·�� 
int pathh[MaxVertexNum][MaxVertexNum];//����洢·�� 
mgraph initgraph()
{	int i=0,j=0;
	mgraph c;
	c.vexnum=11;//������� 
	c.arcnum=20;//�ߵĸ��� 
	for(i=1;i<=key;i++)//�������ö����� 
	  c.vexs[i].position=i;
	//�������붥����Ϣ  
	strcpy(c.vexs[1].name,"���ٳ�����ɽ¥��֪��¥");strcpy(c.vexs[1].super_introduction,"\n���ٳ������ٳ�λ��У԰���࣬�����ڶ�ɽɽ���£��������򳡡����򳡡��ﾶ������ͬѧ�������εľ��ѵص㡣\n��ɽ����ï��ɽ��ͬ��ΪѧУ�ı�־����У��ɽѧ���ɴ˵�����\n֪��¥�������ڡ�֪�к�һ���������ѧУ��ͬѧ�ǵ�����ϣ��������ģ�ⷨͥ��Ŀǰ����˾��ѧԺ�����̷�ѧԺ�ڴ�ѧϰ��\n");
	strcpy(c.vexs[1].introduction,"�����򳡡����򳡣��ȶ��ٳ���С����ѧԺ���ڵأ�ѧУ�칫��"); 
	strcpy(c.vexs[2].name,"ï��ɽ");strcpy(c.vexs[2].super_introduction,"\nï��ɽ�������ս����������У԰����ɽɽ·ƽ̹���羰���������в��ٽ�ž�սʿ�����ڴˣ�\n����У԰�ڡ�ɽ�����в�����ʿĹ������ʱ�ڳ�������ǰ���廳���\n");
	strcpy(c.vexs[2].introduction,"У��һ��ɽ�����ǽ�ż���ս��ս����ַ"); 
	strcpy(c.vexs[3].name,"����¥����Զ¥");strcpy(c.vexs[3].super_introduction,"\n����¥��Ŀǰ����¥������ռ䰲ȫѧԺ�������ѧԺ��ͬѧѧϰ����ĵط������ж��������ʵ���ҡ��������ҵȵȡ�\n��Զ¥����Զ¥���ڷ�ѧԺ�;���ó�׷�ѧԺͬѧ��ѧϰ�����������Զ¥�ж�����ݽ��ң������ڶ��ֿγ̽�ѧ��");
	strcpy(c.vexs[3].introduction,"����ռ䰲ȫѧԺ�������ѧԺ������ó�׷�ѧԺ���ڵ�"); 
	strcpy(c.vexs[4].name,"�����");strcpy(c.vexs[4].super_introduction,"\n����ݣ�λ��ѧУ�в�ƫ����������Ӿ�ݣ��٤�ң�ƹ����ݺ�̨���ҵȵȣ�\n�Թ�ͬѧ���������Ρ����������ʹ�á���¥��ӡˢ�ң�Ϊ��Ҵ�ӡ�����ṩ�˱�����\n");
	strcpy(c.vexs[4].introduction,"�����˶�������Ӿ��"); 
	strcpy(c.vexs[5].name,"ͼ���");strcpy(c.vexs[5].super_introduction,"\nͼ��ݣ���ʡ�ڲ������ĸ�Уͼ���֮һ�����в���256��ᡣʼ����1979�꣬������ѧ�ƽ����ң�\nѧ����ΧŨ�񡣻�������չ���߾��ֲ�������ɳ���Ȼ���������Ļ���Χ��\n");
	strcpy(c.vexs[5].introduction,"����ʥ�أ��������6666ƽ����"); 
	strcpy(c.vexs[6].name,"һ�͡����͡����á�����һ");strcpy(c.vexs[6].super_introduction,"\n���ã�λ��ѧУ���ſڣ��ڶ�����¥�ϡ�����Уѧ�����桢������ᡢ���繫�ݡ���ҵ����ľٰ�ص㡣\nһ�Ͷ��ͣ�λ�����ţ����������ѧ���òͣ�Ҳ��������У�������������ò͡�\n���ã��������ã�ÿ������ʮ��ǰΪѧ���ṩ����\n");
	strcpy(c.vexs[6].introduction,"ѧ�����������ÿɾٰ��С�����ѧ�����飻ϴԡ"); 
	strcpy(c.vexs[7].name,"�ϴ���");strcpy(c.vexs[7].super_introduction,"\n�ϴ��ţ�ɽ������ѧԺ���ԭ���Ĵ��ţ����ſ������޽�������̳���ø����������У԰�ڣ�\n�˽�����ѧУ���Ļ���Ҳ�����˼��Ͼ���һ��ï��ɽ�������˽�ï��ս�ۡ�\n");
	strcpy(c.vexs[7].introduction,"ѧУ���š�ѧУ�೵������"); 
	strcpy(c.vexs[8].name,"УҽԺ������С��");strcpy(c.vexs[8].super_introduction,"\nУҽԺ��Ϊ��ѧ���ṩ���õķ�����У��УҽԺ�����˷��ޣ�������ѧ���Ľ��������\nУҽ���ж������ҽ���顣��С���ţ�Ϊ�˻����ϴ��ŵĽ�ͨѹ������У�ֽ�������С���ţ�Ҳ������ѧ���ĳ��С�\n");
	strcpy(c.vexs[8].introduction,"����ҩ����С���ĵط�������УҽԺ�ͽ̹������������ñȽϽ�"); 
	strcpy(c.vexs[9].name,"���ٳ�������");strcpy(c.vexs[9].super_introduction,"\n���ٳ����ڶ��ٳ������ǿ�չ���ﾶ�������٣�̫���ȣ�Ů�ӷ��������󱣽�����ë��ƹ����������γ̣�\nҲ��ѧ����������������Լ�����Ҫ������\n ���ͣ������ǿ������ż�������������һ�����������㣬ʳ��Ʒ�ֶ�����\n���ڵ�������˶�����ɫ�Ļ�������ӣ���Ʒ������ѧ������ϲ����\n");
	strcpy(c.vexs[9].introduction,"�ٰ���������������ѧ��ʳ�ã������ϸ�"); 
	strcpy(c.vexs[10].name,"������վ");strcpy(c.vexs[10].super_introduction,"\n������վ��������ղ��������ѧ���Ŀ�ݣ�ҲΪѧ���ṩ��У��ְ�Ļ��ᡣ\n����ı����ѧ�������\n");
	strcpy(c.vexs[10].introduction,"�շ���ݴ�"); 
	strcpy(c.vexs[11].name,"����");strcpy(c.vexs[11].super_introduction,"\n���ţ�Ϊ�ٽ����ŵ�סУѧ���ṩ�˳��еķ��㡣\n");
	strcpy(c.vexs[11].introduction,"����С�Խ֡�������վ���������нϽ�"); 
	for(i=1;i<=key;i++)
	  for(j=1;j<=key;j++)
	    c.arcs[i][j].adj=Infinity;//�ȳ�ʼ��ͼ���ڽӾ��� 	
	c.arcs[1][2].adj=60;c.arcs[1][5].adj=70;c.arcs[2][3].adj=40;c.arcs[2][4].adj=40;c.arcs[3][4].adj=15;
	c.arcs[3][9].adj=10;c.arcs[3][10].adj=30;c.arcs[4][5].adj=30;c.arcs[4][9].adj=20;c.arcs[5][6].adj=60;
	c.arcs[5][7].adj=60;c.arcs[5][8].adj=30;c.arcs[5][9].adj=40;c.arcs[6][7].adj=10;c.arcs[7][8].adj=30;
	c.arcs[8][9].adj=50;c.arcs[8][11].adj=200;c.arcs[9][10].adj=35;c.arcs[9][11].adj=10;c.arcs[10][11].adj=20; 
	for(i=1;i<=key;i++)//�ڽӾ����ǶԳƾ��󣬶ԳƸ�ֵ������ͼ��Ҫ�ԳƸ�ֵ�� 
	  for(j=1;j<=key;j++)
	    c.arcs[j][i].adj=c.arcs[i][j].adj;
    return c;
}//initgraph
//2.���Ҿ�����ͼ�е����
int locatevex(mgraph c,int v)//locatevex
{	int i;
	for(i=1;i<=c.vexnum;i++)
	  if(v==c.vexs[i].position)  return i;//�ҵ������ض������i 
 	return -1;//û���ҵ�������� 
} 
//3.���Ҳ�������Ϊm,n�����ĳ��Ȳ�����8�������·�� 
void path(mgraph c,int m,int n,int k)
{	int s,t=k+1,length=0;//t���ڴ��·������һ�������Ӧ��d[]����Ԫ�ص��±� 
	if(d[k]==n&&k<8)//��d[k]���յ�n�Ҿ������<=8,�������·�� 
	{	for(s=0;s<k;s++)//����·������ 
	    {    	 
	    	length=length+c.arcs[d[s]][d[s+1]].adj;
		} 
		if(length<=100)//��ӡ·������С�ڶ�����·�� 
		{	for(s=0;s<k;s++)//�����·����s=0ʱΪ���m
	        {
	    	   printf("%d%s--->",d[s],c.vexs[d[s]].name);
		    } 
	        printf("%d%s  ",d[s],c.vexs[d[s]].name);//������һ����������������n�����֣���ʱs==k��	
	        printf("��·�߳�Ϊ%d��\n\n",length);
		}
	} 
	else
	{	s=1;
		while(s<=c.vexnum)//�ӵ�m�����㣬��̽���ж����Ƿ���·�� 
		{	if((c.arcs[d[k]][s].adj<Infinity)&&(visited[s]==0))//����m������s�б�(Ȩֵ��Ϊ�����)����δ������ 
			{	visited[s]=1;
				d[k+1]=s;//�洢������ 
				path(c,m,n,t);
				visited[s]=0;//���ҵ���·���϶���ķ��ʱ�־��������Ϊ0����������̽�µ�·�� 
			}
			s++;//��̽����һ������s��ʼ�Ƿ��е��յ��·�� 
		}
	}	
} 
//4.�����������ľ��������·��
int allpath(mgraph c)
{	int k,i,j,m,n;
	printf("\n\n����������Ҫ��ѯ����������ı�ţ�\n\n");
	scanf("%d%d",&i,&j);printf("\n\n");
	m=locatevex(c,i);//locatevex ȷ���ö����Ƿ���ڡ������ڣ����ظö����š� 
	n=locatevex(c,j);
	d[0]=m;//�洢·�����m��int d[]������ȫ�ֱ����� 
	for(k=0;k<key;k++)//ȫ��������ʱ�־��ֵ��Ϊ0 
	  visited[k]=0;
	visited[m]=1;//��m��������ʱ�־����Ϊ1 
	path(c,m,n,0);//���ó���k=1����Ӧ���d[1]==m��kΪd[]�����±� 
	return 1;
}
//5.�õϽ�˹�����㷨�����һ�����㵽�������������·����
void shortestpath_dij(mgraph c)
{	int v0,v,w,k=1,min,t,p;
	int final[MaxVertexNum];//final[w]=1��ʾ�Ѿ���ö���V0��Vw�����·��
	int Patharc[MaxVertexNum];//���ڴ洢���·���±������ 
    int ShortPathtable[MaxVertexNum];//���ڴ洢���������·����Ȩֵ�� 
	printf("\n������һ����ʼ����ı�ţ�"); 
	scanf("%d",&v0);printf("\n\n"); 
	while(v0<0||v0>key)
	{	printf("\n������ľ����Ų�����\n");
		printf("���������룺");
		scanf("%d",&v0); 
	}
	//��ʼ������
	for(v=1;v<=c.vexnum;v++)//����0���ǿճ��� 
	{	final[v]=0;//ȫ�������ʼ��Ϊδ�ҵ����·�� 
		ShortPathtable[v]=c.arcs[v0][v].adj;//����v0�������ߵĶ������Ȩֵ 
		Patharc[v]=0;//��ʼ��·������pΪ0 
	 }
	 ShortPathtable[v0]=0; // V0��v0��·��Ϊ0 
	 final[v0]=1;//V0��v0����Ҫ·�� 	 
	 //��ʼ��ѭ����ÿ�����V0��ĳ��v����� ���·�� 
	 for(v=1;v<=c.vexnum;v++)
	 {	min=Infinity;
	 	for(w=1;w<=c.vexnum;w++)//�ҳ�����Ķ����Ȩֵ 
	 	{	if(!final[w]&&ShortPathtable[w]<min)//�б� 
	 		{	k=w;
	 			min=ShortPathtable[w];
			 }
		 }
		 final[k]=1;//��Ŀǰ�ҵ�������Ķ�����1 
	 	 //������ǰ���·��������
		 for(w=1;w<=c.vexnum;w++)
		 {	//�������v�����·������������·���ĳ��ȶ̵Ļ�������
			if(!final[w]&&(min+c.arcs[k][w].adj<ShortPathtable[w])) 
			{	ShortPathtable[w]=min+c.arcs[k][w].adj;//�޸ĵ�ǰ·������
				Patharc[w]=k; //���ǰ����㣨���Ǻ�«�� 
			}
		  } 
     }
     
     
     printf("��ӡP����:");
     for(t=1;t<=c.vexnum;t++)
     {
     	printf("%d ",Patharc[t]);
	 }
	 printf("\n\n");
	 //��ӡs����
	 printf("��ӡS����:");
     for(t=1;t<=c.vexnum;t++)
     {
     	printf("%d ",ShortPathtable[t]);
	 }
	 printf("\n\n");
	  
     //��ӡ���·��
	 for(t=1;t<=c.vexnum;t++)
	 {  p=t;
	 	if(t!=v0)//������� 
	 	{	printf("%d%s",t,c.vexs[t].name);
	 		for(w=1;w<=c.vexnum;w++)
	 		{	if(Patharc[p]!=0)
	 			{	printf("<--%d%s",Patharc[p],c.vexs[p].name);
	 				p=Patharc[p];
				 }
			 }
			 printf("<--%d%s",v0,c.vexs[v0].name);
			 printf("\n��·�߳�Ϊ%d��\n\n",ShortPathtable[t]); 
		 }
	  }     
}
//�˵� 
void menu()
{	printf(" ����������������������������������������������������������������������������������������������������������������\n");
	printf(" �� �q �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �r  ��\n");
	printf(" �� ����        �� ӭ ʹ �� У ԰ �� �� ϵ ͳ          ����  ��\n");
  	printf(" �� �t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �s  ��\n");
  	printf(" ��                      ��ӭ����                        ��\n");
  	printf(" ��                    ɽ������ѧԺ                      ��\n");
  	printf(" ��                     �� �� ѡ ��                      ��\n");
	printf(" ��  *************************************************** ��\n");
	printf(" ��  *  1.�˵�                **   2.�鿴����·�ߣ��ϣ�* ��\n");// ѧУ������� 
	printf(" ��  *************************************************** ��\n");
	printf(" ��  *  3.��ѯ��������·��  **   4.��ѯ���������·��* ��\n");
	printf(" ��  *************************************************** ��\n");
	printf(" ��  *  5.ѧУ�������        **   6.������Ϣ��ѯ      * ��\n");// 
	printf(" ��  *************************************************** ��\n");
	printf(" ��  *  7.ѧУ��ͼ            **   8.����ͼ��Ϣ        * ��\n");
	printf(" ��  *************************************************** ��\n");
	printf(" ��  *  0.�˳�                **   ��һС��*^_^*       * ��\n");
	printf(" ��  *************************************************** ��\n");
	printf(" ����������������������������������������������������������������������������������������������������������������\n");
}
//�������޸�ͼ�������Ϣ��������ͼ��������Ϣ��ɾ�������ӽ��ͱ�
//6.���¹���ͼ 
int creatgraph(mgraph *c)
{	int i,j,m,n,v0,v1,distance;
	printf("������ͼ�Ķ������ͱ���: \n");
	scanf("%d %d",&c->vexnum,&c->arcnum);
	printf("���������뾰�����Ϣ�� \n");
	for(i=1;i<=c->vexnum;i++)
	{	printf("�����뾰��ı�ţ�");
		scanf("%d",&c->vexs[i].position);
		printf("\n�����뾰������ƣ�");
		scanf("%s",&c->vexs[i].name);
		printf("\n�����뾰��ļ�飺");
		scanf("%s",&c->vexs[i].introduction);
		printf("\n�������޸ĺ󾰵����ϸ����:");
		scanf("%s",&c->vexs[i].super_introduction);
	}
	for(i=1;i<=c->vexnum;i++)
	  for(j=1;j<=c->vexnum;j++)//Ȩֵȫ����ʼ��Ϊ���� 
	    c->arcs[i][j].adj=Infinity;
	printf("����������ͼ�ıߵ���Ϣ��\n");
	for(i=1;i<=c->vexnum;i++)
	{	printf("\n��%d���ߵ���� �յ� ����Ϊ��",i);
		scanf("%d %d %d",&v0,&v1,&distance);
		m=locatevex(campus,v0);//�ж�һ�µ��Ƿ���ڣ����ھͷ���λ�� 
		n=locatevex(campus,v1);
		if(m>0&&n>0)
		{	c->arcs[m][n].adj=distance;
			c->arcs[n][m].adj=c->arcs[m][n].adj;
		}
	}
	return 1;
}
//7.����ͼ�Ĳ�����Ϣ������ֵ��1***����ĳ����Ϣ����ˣ���Ҫ�� 
int newgraph(mgraph *c)
{	int changenum;
	int i,m,n,t,distance,v0,v1;
	printf("\n������������Ҫ�޸ĵľ���ĸ�����\n"); 
	scanf("%d",&changenum);
	while(changenum<0||changenum>key) 
	{	printf("\n�����������������");
		scanf("%d",&changenum);
	}
	for(i=0;i<changenum;i++)
	{	printf("\n�����뾰��ı�ţ�");
		scanf("%d",&m);
		t=locatevex(campus,m);
		printf("\n�������޸ĺ󾰵������:");
		scanf("%s",&c->vexs[t].name);
		printf("\n�������޸ĺ󾰵�ļ��:");
		scanf("%s",&c->vexs[t].introduction);
		printf("\n�������޸ĺ󾰵����ϸ����:");
		scanf("%s",&c->vexs[t].super_introduction);
	}
	printf("\n������������Ҫ���µı���"); 
	scanf("%d",&changenum);
	while(changenum<0||changenum>key)
	{	printf("\n�����������������");
		scanf("%d",&changenum);
	}
	if(changenum!=0)
	printf("\n������������±ߵ���Ϣ��\n");
	for(i=1;i<=changenum;i++)
	{	printf("\n�޸ĵĵ�%d���ߵ���� �յ� ����Ϊ��",i);
		scanf("%d %d %d",&v0,&v1,&distance);
		m=locatevex(campus,v0);
		n=locatevex(campus,v1);
		if(m>=0&&n>=0)
		{	c->arcs[m][n].adj=distance;
			c->arcs[n][m].adj=c->arcs[m][n].adj;
		}
	 } 
	return 1;
} 
//8.����һ���ߡ�����ֵ��1*** 
int enarc(mgraph *c)
{	int m,n,distance;
	printf("\n������ߵ������յ��ţ�Ȩֵ��");
	scanf("%d %d %d",&m,&n,&distance);
	while(m<0||m>c->vexnum||n<0||n>c->vexnum)
	{	printf("����������������룺");
		scanf("%d %d",&m,&n);
	} 	
	if(locatevex(campus,m)<0)
	{	printf("�˽ڵ�%d��ɾ��",m);
		return 1;
	}
	if(locatevex(campus,n)<0)
	{	printf("�˽ڵ�%d�ѱ�ɾ��",n);
		return 1;
	}
	
	c->arcs[m][n].adj=distance;//���ڽӾ����ж��һ��ֵ 
	c->arcs[n][m].adj=c->arcs[m][n].adj;
	c->arcnum --;//ͼ�б���+1
	return 1;
}
//9.����һ����㡣����ֵ��1*** 
int envex(mgraph *c)
{	int i;
    c->vexnum++;//�������+1
	printf("��������Ҫ���ӽ�����Ϣ��");
	printf("\n��ţ�");
	scanf("%d",&c->vexs[c->vexnum].position);
	printf("���ƣ�");
	scanf("%s",&c->vexs[c->vexnum].name);
	printf("��飺");
	scanf("%s",&c->vexs[c->vexnum].introduction);
	printf("��ϸ���ܣ�");
	scanf("%s",&c->vexs[c->vexnum].super_introduction);
	
	for(i=1;i<=c->vexnum;i++)
	{	c->arcs[c->vexnum][i].adj=Infinity;
		c->arcs[i][c->vexnum].adj=Infinity;
	}
	return 1;
} 
//10.ɾ��ͼ��һ�����㡣����ֵ��1*** 
int delvex(mgraph *c) 
{	int i=0,j;
	int m,v;
	if(c->vexnum<=0)
	{	printf("ͼ�����޶���");
		return 1;
	}
	printf("\n������������Ҫɾ���ľ����ţ�");
	scanf("%d",&v);
	while(v<0||v>key)
	{	printf("\n�����������������:");
		scanf("%d",&v);
	}
	m=locatevex(campus,v);
	if(m<0)
	{	printf("�˶���%d��ɾ��\n",v);
		return 1;
	}
	for(i=m;i<=c->vexnum-1;i++)
	  for(j=1;j<=c->vexnum;j++)//����ά�����еĵ�m+1��������ǰ�ƶ�һ�У�ɾ����m�У� 
	    c->arcs[i][j]=c->arcs[i+1][j]; 
	for(i=m;i<=c->vexnum-1;i++)
	  for(j=1;j<=c->vexnum;j++)//����ά�����еĵ�m+1��������ǰ�ƶ�һ�У�ɾ����m�У�
	    c->arcs[j][i]=c->arcs[j][i+1];
	c->vexs[v].position=-1;//��ʾ�˵���ɾ�������ڴ�ӡҲ������ʾ�õ� 
	c->vexnum--;//�������-1 
	return 1;
}
//11.ɾ��ͼ��һ���ߡ�����ֵ��1*** 
int delarc(mgraph *c)
{	int m,n,v0,v1;
	if(c->vexnum<=0)
	{	printf("ͼ�����ޱߣ��޷�ɾ����");
		return 1; 
	}
	printf("\n������������Ҫɾ���ıߵ������յ��ţ�");
	scanf("%d %d",&v0,&v1);
	m=locatevex(campus,v0);
	if(m<0)
	{	printf("��%d������ɾ��",v0);
		return 1;
	}
	n=locatevex(campus,v1);
	if(n<0)
	{	printf("��%d������ɾ��",v1);
		return 1;
	}
	c->arcs[m][n].adj=Infinity;//��ɾ���ıߵ�Ȩֵ��Ϊ���� 
	c->arcs[n][m].adj=Infinity;
	c->arcnum --;//ͼ�б�����1 
	return 1;
}
//12.���ͼ���ڽӾ����ֵ*** 
void printmatrix(mgraph c)
{	int i,j,k=0;
	for(i=1;i<=key;i++)
	{  if(c.vexs[i].position!=-1)
		  printf("%6d",i);//���ŵı��1��11
	}
	printf("\n");
	for(i=1;i<=c.vexnum;i++)
	{   	for(j=1;j<=c.vexnum;j++)
	        {	if(c.arcs[i][j].adj==Infinity)
	  	            printf(" *#@* ");
	  	        else
	  	            printf("%6d",c.arcs[i][j].adj);
	         	k++;
	  	        if(k%c.vexnum==0) printf("\n");
	         }		
	  }		
} 
//13.ͼ�Ĳ�����������������ֵ��1*** 
int changegraph(mgraph *c)
{	int yourchoice;
	printf("(1)���½�ͼ     (2)ɾ�����  (3)ɾ����\n");
	printf("(4)���ӽ��     (5)���ӱ�    (6)������Ϣ\n");
	printf("(7)��ӡ�ڽӾ��� (8)������һ��\n");
	do
	{	printf("����������ѡ��");
	    scanf("%d",&yourchoice);
	    switch(yourchoice)
	    {	case 1:creatgraph(c);break;
			case 2:delvex(c);break;
			case 3:delarc(c);break;
			case 4:envex(c);break;
			case 5:enarc(c);break;
			case 6:newgraph(c);break;
			case 7:printmatrix(campus);break;
			case 8:system("cls");menu();return 1;//break;
			default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");break;
		}
	}while(yourchoice);
}
int user_log()
{	int i;
	int a[6]={1,2,3,4,5,6},b[6];
	//for(i=0;i<6;i++)
		//printf("%d ",a[i]);
	printf("\n������6λ����(ÿ����һλ������һ���ո�)��\n");
	for(i=0;i<6;i++)	
	  scanf("%d",&b[i]);
	for(i=0;i<6;i++)
	{	if(a[i]!=b[i])
	    {
	    	printf("�������!�Զ�������һ��\n");menu();return 0;
		} 
	}
	printf("������ȷ����½�ɹ���\n\n");
	changegraph(&campus);
}
//14.��ѯ�����������·����floyd�㷨��
void floyd(mgraph c)//һ�ֱ����ƽ��ȡ���·�����㷨 
{	int i,j,k;
	for(i=1;i<=key;i++)//��ͼ���ڽӾ���ֵ�� shortest��ά���飬������pathhȫ����ʼ��Ϊ-1 
	{	for(j=1;j<=key;j++)
		{	shortest[i][j]=c.arcs[i][j].adj;
			pathh[i][j]=j; 
		}
	}
	int i1,j1,k1=0;
	for(i1=1;i1<=key;i1++)
		printf("%6d",i1);//���ŵı��1��11
	printf("\n");
	for(i1=1;i1<=key;i1++)
	{  printf("%d",i1);//���ŵı��1��11
	  for(j1=1;j1<=key;j1++)
	  {	
	     printf("%6d",pathh[i1][j1]);
	  	k1++;
	  	if(k1%key==0) printf("\n");
	  }		
	}
	printf("\n\n\n");
	
	for(k=1;k<=key;k++)//���Ĳ������������kΪ�м������еĶ���ԣ�i,j�����м����޸� 
	{	for(i=1;i<=key;i++)
		{	for(j=1;j<=key;j++)
			 {
			 	if(shortest[i][j]>shortest[i][k]+shortest[k][j])
			 	{	shortest[i][j]=shortest[i][k]+shortest[k][j];			 	    
	     	 		pathh[i][j]=pathh[i][k];//��¼һ�����ߵ�· //P�����������ǰ������  
				}
			 }
		}
	}
}
void printf_Pshuzu()
{	int i,j,k=0;
	for(i=1;i<=key;i++)
		printf("%6d",i);//���ŵı��0��11
	printf("\n");
	for(i=1;i<=key;i++)
	{  printf("%d",i);//���ŵı��0��11
	  for(j=1;j<=key;j++)
	  {	printf("%6d",pathh[i][j]);
	  	k++;
	  	if(k%key==0) printf("\n");
	  }		
	}
	printf("\n\n\n");
}
//��ӡ�����·�� 
void display(mgraph c,int i,int j)
{	int a,b;
	a=i;b=j;
	printf("��Ҫ��ѯ������������·����\n\n");	
	printf("%d%s",a,c.vexs[a].name);
	while(pathh[i][j]!=b)
	{ printf("-->%d%s",pathh[i][j],c.vexs[pathh[i][j]].name);	  	 
	  i=pathh[i][j]; 	  	 
	}
  	printf("-->%d%s\n\n",b,c.vexs[b].name);
	printf("%s-->%s�����·���ǣ�%d �ס�\n\n",c.vexs[a].name,c.vexs[b].name,shortest[a][b]);
}
//�����������̾��루���������㷨��
int shortdistance(mgraph c) 
{	int i,j;
	printf("������Ҫ��ѯ��������������ֱ�ţ�1->11���м��ÿո�������\n"); 
	scanf("%d %d",&i,&j);
	if(i>key||i<0||j>key||j<0)
	{	printf("������Ϣ����\n\n");
		printf("������Ҫ��ѯ��������������ֱ�ţ�1->11���м��ÿո�������\n"); 
		scanf("%d %d",&i,&j);
	}
	else
	{	floyd(c);printf_Pshuzu();
		display(c,i,j);
	}
	return 1;
}
//15.��ѯ�������Ϣ
void seeabout(mgraph c)
{	int k;
	printf("\n������Ҫ��ѯ�ľ����ţ�");
	scanf("%d",&k);
	while(k<=0||k>key)
	{	printf("\n��������ľ����Ų����ڣ�");
		printf("\n���������뾰���ţ�");
		scanf("%d",&k); 
	}
	printf("\n\n��ţ�%-4d\n",c.vexs[k].position);
	printf("\n�������ƣ�%-10s\n",c.vexs[k].name);
	printf("\n��ϸ���ܣ�%-80s\n\n",c.vexs[k].super_introduction);
}
//16.��ʾ���о�����Ϣ
void browsecompus(mgraph c) 
{	int i;
	printf(" \n\n���        ��������                   ���\n");
	printf("____________________________________________________________________________________________\n");
	for(i=1;i<=key;i++)
	{	if(c.vexs[i].position!=-1)
		printf("%-10d%-25s%-80s\n",c.vexs[i].position,c.vexs[i].name,c.vexs[i].introduction);
	}
	printf("____________________________________________________________________________________________\n");
}
//17.ɽ����ͼ
void school_map()//����������   ������   �t�t�t�q�T  �q�T  �T�t�T �q�q=  =�r  =�s  =��������  �T�T=
{   printf(" -------------------------------------------------ɽ����ͼ------------------------------------------------\n");
    printf(" ---------------------------------------------------------------------------------------------------------\n");
	printf(" ___________                                                                                            ==\n");
	printf("�������ٳ� ����*                         ��Զ¥                ����¥                            ������վ   == \n");
	printf("����_______����*                       * *  * * * * *  *  *  *   **   *  *  *  *  *  *  *  *  * *  * *  *   == \n");
	printf(" __________ *                     *        ##                *                       *     ��ѧ��    *  == \n");
	printf(" ����ɽ¥ �� *-->***��ɽ***ï��ɽ*                            *   ___________          *  ����ѧϰ����  * ==\n");
	printf(" ��_______�� *                              ##     �����     *   ��        ��          *     �Ĳ�         *��\n");
	printf(" __________ *                              ##               *   �� ���ٳ� ��   ����   * * * * * * ** * * *--> \n");
	printf(" ��֪��¥ �� *                              ##              *     ��________��          *    _________     *�� \n");
	printf(" ��_______��  *                    ï��ɽ        ##        *                          *    ������¥ ��    * == \n");
	printf(" ##           *                 ս����ַ         ##      *                          *    ��_______��    * ==\n");
	printf(" ##            ****** ����¥    **********ͼ���     ##  *                          *                 * ==\n");
	printf(" ##              *             *          * * * * * * * * * * * * * * * * * ** * * * * * * * * * *  *   ==\n");
	printf(" ##  ͣ����      *             *           ###           *                          _________           ==\n");
	printf(" ##              *             *           ###   ����    *                          ��8��9�ũ�            ==\n"); 
	printf(" ##  ����        *    ���¥   *           ###           *                          ��_��Ԣ_��            ==\n");
	printf(" ##  ����һ      *             *  �е�¥   ### �̹�����  *                                              ==\n");
	printf(" ##  ����        *             *           ###           *            ==================================== \n");
	printf(" ##  һ��        *             *  ˾������ ###  УҽԺ   *            ==  \n");
	printf(" ##  ����          *         *      ����   ###           *            ==    \n");
	printf(" ================ ɽ������ѧԺ =======================С����============  \n");
	printf(" ================     ����     =======================      ============\n");
	printf("\n                                                      ��<---|--->��  \n");
} 
//18.��Ҫ�����������������û�����
void mainwork()
{   menu();
	int yourchoice;
	campus=initgraph();
	do
	{	printf("����������ѡ��");
	    scanf("%d",&yourchoice);
	    switch(yourchoice)
	    {	case 1:system("cls");menu();break; 
			case 2:system("cls");shortestpath_dij(campus);break;
			case 3:system("cls");shortdistance(campus);break; 
			case 4:system("cls");allpath(campus);break; 
			case 5:system("cls");browsecompus(campus);break; 
			case 6:system("cls");seeabout(campus);break; 
			case 7:system("cls");school_map();break; 
			case 8:system("cls");user_log();break;  
			case 0:system("cls");printf("ллʹ��\n");break;
			default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");break;
		}
	}while(yourchoice); 
}
int main()
{	system("color 1f");//������ɫ
	system("mode con: cols=140 lines=130");//����ҳ�泤��
	system("SchoolGraph.png");//����У԰��ͼ ������һ��ͼƬ��
	mainwork();
	return 0;
}

