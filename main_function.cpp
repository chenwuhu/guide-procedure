#include<stdio.h>//�����Ȩͼ 
#include<stdlib.h>
#include<string.h>
#define Infinity 2000//��ʾ����� 
#define MaxVertexNum 20 
#define MAX 40 
#define key 10//keyΪ������� 

typedef struct arcell//�ߵ�Ȩֵ��Ϣ
{ 	
int adj;//Ȩֵ  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum]; 

typedef struct vexsinfomation//������Ϣ 
{ 	int number;//����ı�� 
	char name[50];//��������� 
	char introduction[50];//����Ľ���  
}vexsinfomation;

typedef struct mgraph//ͼ
{  	vexsinfomation vexs[MaxVertexNum];//���� ���������飩 
	adjmatrix arcs;//�ڽӾ��� 
	int vexnum,arcnum;//�������ͱ��� 
}mgraph;

//ȫ�ֱ���
mgraph campus; //ͼ����  
int d[30];
int visited[30];
int dist[MaxVertexNum][MaxVertexNum];//����ȫ�ֱ����洢��С·�� 
int path[MaxVertexNum][MaxVertexNum];//����洢·�� 
mgraph initgraph()
{	int i=0,j=0;
	mgraph c;
	c.vexnum=10;//������� 
	c.arcnum=12;//�ߵĸ��� 
	for(i=1;i<=key;i++)//�������ö����� 
	  c.vexs[i].number=i;
	//�������붥����Ϣ  
	strcpy(c.vexs[1].name,"��Է");
	strcpy(c.vexs[1].introduction,"ѧ������ĵط�����Էʳ�÷�����"); 
	strcpy(c.vexs[2].name,"��Է");
	strcpy(c.vexs[2].introduction,"ѧ������ĵط����и���С�꣬�����ٰ���ֻ"); 
	strcpy(c.vexs[3].name,"��Է");
	strcpy(c.vexs[3].introduction,"ѧ������ĵط���ʳ�÷���Ƿ��"); 
	strcpy(c.vexs[4].name,"��Է");
	strcpy(c.vexs[4].introduction,"ѧ������ĵط����������Ŀ�����Ͱ����ܺó�"); 
	strcpy(c.vexs[5].name,"��Է");
	strcpy(c.vexs[5].introduction,"ѧ������ĵط�,��Ͽ��ѧ�Ƽ�ѧԺѧ��ס�ĵط�"); 
	strcpy(c.vexs[6].name,"ͼ���");
	strcpy(c.vexs[6].introduction,"ѧ���ǽ����鼮�ĵط�����������ϰ����ѧϰʥ��"); 
	strcpy(c.vexs[7].name,"УҽԺ");
	strcpy(c.vexs[7].introduction,"������������"); 
	strcpy(c.vexs[8].name,"J¥");
	strcpy(c.vexs[8].introduction,"��ѧ¥����¥���л���"); 
	strcpy(c.vexs[9].name,"����������");
	strcpy(c.vexs[9].introduction,"ѧ�����ճ��������������εĵط���ÿ��һ�ε�У�˻��ڴ˾ٰ�"); 
	strcpy(c.vexs[10].name,"��Է���� ");
	strcpy(c.vexs[10].introduction,"������ĵط��������������ڴ˽���"); 
	
	for(i=1;i<=key;i++)
	  for(j=1;j<=key;j++)
	    c.arcs[i][j].adj=Infinity;//�ȳ�ʼ��ͼ���ڽӾ��� 	
	c.arcs[1][2].adj=200;c.arcs[2][5].adj=200;c.arcs[2][8].adj=300;c.arcs[6][8].adj=80;c.arcs[6][7].adj=400;
	c.arcs[5][8].adj=300;c.arcs[8][10].adj=100;c.arcs[4][9].adj=50;c.arcs[9][10].adj=50;c.arcs[8][9].adj=80;
	c.arcs[3][10].adj=50;c.arcs[2][3].adj=280; 
	for(i=1;i<=key;i++)//�ڽӾ����ǶԳƾ��󣬶ԳƸ�ֵ������ͼ��Ҫ�ԳƸ�ֵ�� 
	  for(j=1;j<=key;j++)
	    c.arcs[j][i].adj=c.arcs[i][j].adj;
    return c;
}//��ʼ��ͼ
 
//����Ա�˵�չʾ 
void menu1() {
	printf("��������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                        ��\n");
	printf("��              �� ӭ ʹ �� У ԰ �� �� ϵ ͳ             ��\n");
	printf("��                                                        ��\n");
	printf("��                      ��ӭ����                          ��\n");
	printf("��                   ��Ͽ��ѧ  CTGU                       ��\n");
	printf("��         ?????????????????????????????????????          ��\n");
	printf("��                      �� �� Ա                          ��\n");
	printf("��                     �� �� ѡ ��                        ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  1.�˵�                 **   2.���о�����Ϣ��ѯ   * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  3.���徰����Ϣ��ѯ     **   4.��ѯ��������·�� * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  5.��ѯ���������·��   **   6.�����ͼ��Ϣ       * ��\n");// 
	printf("��  ***************************************************** ��\n");
	printf("��  *  7.�����û���Ϣ         **   0.�˳�               * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *                         **                        * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������\n");

}

//�οͲ˵�չʾ 
void menu2() {
	printf("��������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                        ��\n");
	printf("��              �� ӭ ʹ �� У ԰ �� �� ϵ ͳ             ��\n");
	printf("��                                                        ��\n");
	printf("��                      ��ӭ����                          ��\n");
	printf("��                   ��Ͽ��ѧ  CTGU                       ��\n");
	printf("��         ?????????????????????????????????????          ��\n");
	printf("��                        �� ��                           ��\n");
	printf("��                     �� �� ѡ ��                        ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  1.�˵�                 **   2.���о�����Ϣ��ѯ   * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  3.���徰����Ϣ��ѯ     **   4.��ѯ��������·�� * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��  *  5.��ѯ���������·��   **   0.�˳�               * ��\n");// 
	printf("��  ***************************************************** ��\n");
	printf("��  *                         **                        * ��\n");
	printf("��  ***************************************************** ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������\n");

}

//���ȷ�Ϻ���
int verification()
{
	int n=6;
	int i;
	int a[6];
	int password[6]={1,2,3,4,5,6};
	printf("��������λ�����룺\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<6;i++)
	{	
		if(a[i]!=password[i])
	    {
	    	printf("�������!\n");return 0;
		} 
	}
	printf("������ȷ����½�ɹ���\n\n");
	return 1;
}

//���Ҿ�����ͼ�е����
int locatevex(mgraph c,int v)//locatevex
{	int i;
	for(i=1;i<=c.vexnum;i++)
	  if(v==c.vexs[i].number)  return i;//�ҵ������ض������i 
 	return -1;//û���ҵ�������� 
} 

//�������޸�ͼ�������Ϣ��������ͼ��������Ϣ��ɾ�������ӽ��ͱ�
//���Ӿ��� 
int add_attraction (mgraph *c)
{	int i;
    c->vexnum++;//���������һ 
	printf("��������Ҫ���Ӿ������Ϣ��");
	printf("\n��ţ�");
	scanf("%d",&c->vexs[c->vexnum].number );
	printf("���ƣ�");
	scanf("%s",&c->vexs[c->vexnum].name);
	printf("���ܣ�");
	scanf("%s",&c->vexs[c->vexnum].introduction);
	for(i=1;i<=c->vexnum;i++)
	{	c->arcs[c->vexnum][i].adj=Infinity;
		c->arcs[i][c->vexnum].adj=Infinity;
	}
	return 1;
}

//ɾ������
int delete_attraction(mgraph *c)
{
	int i=0,j;
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
	c->vexs[v].number=-1;//��ʾ�˵���ɾ�������ڴ�ӡҲ������ʾ�õ� 
	c->vexnum--;//�������-1 
	return 1;
}


//�޸ľ�����Ϣ
void modify_attraction_information(mgraph *c)
{
	int a;
	char str[50];
	//campus=initgraph();
	printf("1 ��������\n2 �������\n0 �˳�\n"); 
	do
	{	printf("����������ѡ��");
	    scanf("%d",&a);
	    switch(a)
	    {	case 1:
			printf("���뽫%s�޸�Ϊ��",c->vexs[a].name);
			scanf("%s",str);
			strcpy(c->vexs[a].name,str);
			break;
			case 2:
			printf("%-10s%-50s",c->vexs[a].name,c->vexs[a].introduction);
			printf("���뽫�þ�������޸�Ϊ��");
			scanf("%s",str);
			strcpy(c->vexs[a].introduction,str);
			break;
			case 0:system("cls");menu1();break;
			default:printf("����ѡ�����\n");break;
		}
	}while(a);
} 


//����·��
int add_road (mgraph *c)
{
	int m,n,distance;
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


//ɾ��·��
int delete_road(mgraph *c)
{
	int m,n,v0,v1;
	if(c->vexnum<=0)
	{	printf("�˵�·������");
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

//�����ͼ��Ϣ
void manage_map_information(mgraph *c)
{
	int a;
	//campus=initgraph();
	printf("1 ���Ӿ���\n2 ɾ������\n3 �޸ľ�����Ϣ\n4 ����·��\n5 ɾ��·��\n0 �˳�\n");
do
	{	printf("����������ѡ��");
	    scanf("%d",&a);
	    switch(a)
	    {	case 1:add_attraction(c);break;
			case 2:delete_attraction(c);break;
			case 3:modify_attraction_information(c);break;
			case 4:add_road(c);break;
			case 5:delete_road(c);break;
			case 0:system("cls");menu1();break;
			default:printf("����ѡ�����\n");break;
		}
	}while(a);
} 

//�������·���ĳ���
void floyd(mgraph c){
	int i,j,k;
	for(i=1;i<=key;i++){
		for(j=1;j<=key;j++){
			dist[i][j]=c.arcs[i][j].adj;
			path[i][j]=j;
		}
	}
	for(k=1;k<=key;k++){
		for(i=1;i<=key;i++){
			for(j=1;j<=key;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}
}

//չʾ���·��
void display(mgraph c,int i,int j){
	int a,b;
	a=i,b=j;
	printf("��Ҫ��ѯ�����������·����\n");
	printf("%d%s",a,c.vexs[a].name);
	while(path[i][j]!=b)
	{ 
		printf("-->%d%s",path[i][j],c.vexs[path[i][j]].name);	  	 
	  	i=path[i][j]; 	  	 
	}
	printf("-->%d%s\n\n",b,c.vexs[b].name);
	printf("%s-->%s�����·����%d��\n",c.vexs[a].name,c.vexs[b].name,dist[a][b]);
}


//1���о�����Ϣ��ѯ
void allattractions(mgraph c){
	int i;
	printf(" \n\n���        ��������                   ���\n");
	printf("____________________________________________________________________________________________\n");
	for(i=1;i<=key;i++)
	{	if(c.vexs[i].number!=-1)
		printf("%-10d%-25s%-50s\n",c.vexs[i].number,c.vexs[i].name,c.vexs[i].introduction);
	}
	printf("____________________________________________________________________________________________\n");
}

//2���徰����Ϣ��ѯ
void specificattractions(mgraph c){
	int j;
	printf("������Ҫ��ѯ�ľ�����\n");
	scanf("%d",&j);
	while(j<=0 ||j>key){
		printf("������ľ����Ų�����\n");
		printf("���������뾰����\n");
		scanf("%d",&j);
	}
	printf("�����ţ�%d\n�������ƣ�%s\n������ܣ�%s\n",c.vexs[j].number ,c.vexs[j].name,c.vexs[j].introduction);
}

//3��ѯ��������·��
int  shortestpath(mgraph c){
	int i,j;
	printf("������Ҫ��ѯ����������ı��\n");
	scanf("%d %d",&i,&j);
	if(i>key ||i<=0||j>key||j<=0){
		printf("������Ϣ����\n");
		printf("������Ҫ��ѯ����������ı��\n");
		scanf("%d %d",&i,&j);
	}
	else{
		floyd(c);//�������·���ĳ���
		display(c,i,j);//չʾ���·��
	}
	return 1;
}

//3.���Ҳ�������Ϊm,n�����ĳ��Ȳ�����8�������·�� 
void pathh(mgraph c,int m,int n,int k)
{	int s,t=k+1,length=0;//t���ڴ��·������һ�������Ӧ��d[]����Ԫ�ص��±� 
	if(d[k]==n&&k<8)//��d[k]���յ�n�Ҿ������<=8,�������·�� 
	{	for(s=0;s<k;s++)//����·������ 
	    {    	 
	    	length=length+c.arcs[d[s]][d[s+1]].adj;
		} 
		if(length<=1000)//��ӡ·������С�ڶ�����·�� 
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
				pathh(c,m,n,t);
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
	pathh(c,m,n,0);//���ó���k=1����Ӧ���d[1]==m��kΪd[]�����±� 
	return 1;
}

//����Ա���ܺ��� 
void menuwork1() {
	menu1();
	int choice;
	campus=initgraph();
	do
	{

		printf("��������������");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu1();break;
		case 2:system("cls");allattractions(campus);break;
		case 3:system("cls");specificattractions(campus);break;
		case 4:system("cls");shortestpath(campus);break;
		case 5:system("cls");allpath(campus);break;
		case 6:system("cls");manage_map_information(&campus);break;
		case 7:system("cls");system("D:\\����\\���ݽṹ��Ŀ\\Project5\\manage_user_information");break;
		//case 7:system("cls");manage_user_information(&campus);break;
		case 0:system("cls");printf("��л����ʹ��,�ڴ��������´μ��档\n");break;
		default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");
		}

	} while (choice);

}

//�ο͹��ܺ��� 
void menuwork2() {
	menu2();
	int choice;
	campus=initgraph();
	do
	{

		printf("��������������(����1���ز˵�)��");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu2();break;
		case 2:system("cls");allattractions(campus);break;
		case 3:system("cls");specificattractions(campus);break;
		case 4:system("cls");shortestpath(campus);break;
		case 5:system("cls");allpath(campus);break;
		case 0:system("cls");printf("��л����ʹ��,�ڴ��������´μ��档\n");break;
		default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");
		}

	} while (choice);

}

//������ 
int main()
{
	int choice;
	printf("����Ա������1\n�ο�������2\n");
	int t;
	do
	{

		printf("��ѡ��������ݣ�");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");
		t=verification();
		if(t) {
				menuwork1();
		}break;
		case 2:system("cls");menuwork2();break;
		case 0:system("cls");printf("��л����ʹ��,�ڴ��������´μ��档\n");break;
		default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");
		}

	} while (choice);
}


