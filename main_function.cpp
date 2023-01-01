?#include<stdio.h>
#include <stdlib.h>

typedef struct arcell//�ߵ�Ȩֵ��Ϣ
{ 	
int adj;//Ȩֵ  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum]; 

typedef struct vexsinfomation//������Ϣ 
{ 	int number;//����ı�� 
	char name[20];//��������� 
	char introduction[200];//����Ľ���  
}vexsinfomation;

typedef struct mgraph//ͼ
{  	vexsinfo vexs[MaxVertexNum];//���� ���������飩 
	adjmatrix arcs;//�ڽӾ��� 
	int vexnum,arcnum;//�������ͱ��� 
}mgraph;


int main()
{
	mainwork();
	return 0;
}
void mainwork() {
	menu();
	int choice;
	do
	{

		printf("��������������");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu();break;
		case 2:system("cls");allattractions();break;
		case 3:system("cls");specificattractions();break;
		case 4:system("cls");shortestpath();break;
		case 5:system("cls");allpath();break;
		case 6:system("cls");manage_map_information();break;
		case 7:system("cls");manage_user_information();break;
		case 0:system("cls");printf("��л����ʹ��,�ڴ��������´μ��档\n");break;
		default:printf("δ�ҵ��ù��ܣ���������Чѡ�\n");
		}

	} while (choice);

}
void menu() {
	printf("������������������������������������������������������������\n");
	printf("��  �q �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �r  ��\n");
	printf("��  ����       �� ӭ ʹ �� У ԰ �� �� ϵ ͳ        ����  ��\n");
	printf("��  �t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T �s  ��\n");
	printf("��                      ��ӭ����                          ��\n");
	printf("��                   ��Ͽ��ѧ  CTGU                       ��\n");
	printf("��         ?????????????????????????????????????          ��\n");
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
	printf("������������������������������������������������������������\n");

}

void manage_map_information()//�����ͼ��Ϣ
{
	int outcome=verification();//Ȩ�޺�������  ������ؽ��Ϊ1����ɵ���ϵͳ�޸ģ����򷵻���һ��
	if (outcome == 1)
	{
		printf("������ȷ������ϵͳ�ɹ�!\n");
		manage_map();
	}
	else
	{
		printf("������������Զ�������һ��\n");menu();return ;
	}

}

void manage_user_information()//�����û���Ϣ
{
	int outcome = verification();//Ȩ�޺�������  ������ؽ��Ϊ1����ɵ���ϵͳ�޸ģ����򷵻���һ��
	if (outcome == 1)
	{
		printf("������ȷ������ϵͳ�ɹ�!\n");
		manage_user();
	}
	else
	{
		printf("������������Զ�������һ��\n");menu();return;
	}

}
int verification()//���ȷ��Ȩ�޺��麯��
{

}

//�����ͼ��Ϣ
void manage_map_information(mgraph *c)
{
	int a;
	printf("1 ���Ӿ���/n2 ɾ������/n4 �޸ľ�����Ϣ/n5 ����·��/n5 ɾ��·��/n6 �˳�");
do
	{	printf("����������ѡ��");
	    scanf("%d",&a);
	    switch(a)
	    {	case 1:add_attraction(c);break;
			case 2:delete_attraction(c);break;
			case 3:modify_attraction_information;break;
			case 4:add_road(c);break;
			case 5:delete_road(c);break;
			case 6:a=0;menu();return 1;//break;
			default:printf("����ѡ�����\n");break;
		}
	}while(a);
} 
 
//�������޸�ͼ�������Ϣ��������ͼ��������Ϣ��ɾ�������ӽ��ͱ�
//���Ӿ��� 
void add_attraction (mgraph *c)
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
void delete_attraction()
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
	c->vexs[v].position=-1;//��ʾ�˵���ɾ�������ڴ�ӡҲ������ʾ�õ� 
	c->vexnum--;//�������-1 
	return 1;
}


//�޸ľ�����Ϣ
void modify_attraction_information()
{




} 


//����·��
void add_road ()
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
void delete_road()
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

// �������û���Ϣ����
void manage_user()
{

}


//1���о�����Ϣ��ѯ
void allattractions(){
	int i;
	printf("������ �������� �������\n");
	for(i=1;i<=sum;i++){
		if(g.attr[i].position!=-1)
		printf("%d%s%s\n",g.attr[i].position,g.attr[i].name,g.attr[i].introduction);
	}
}


//2���徰����Ϣ��ѯ
void specifications(){
	int j;
	printf("������Ҫ��ѯ�ľ�����\n");
	scanf("%d",&j);
	while(j<=0 ||j>sum){
		printf("������ľ����Ų�����\n");
		printf("���������뾰����\n");
		scanf("%d",&j);
	}
	printf("�����ţ�%d\n�������ƣ�%s\n������ܣ�%s\n",g.attr[i].position,g.attr[i].name,g.attr[i].introduction);
}

//3��ѯ��������·��
void  shortestpath(){
	int i,j;
	printf("������Ҫ��ѯ����������ı��\n");
	scanf("%d %d",&i,&j);
	if(i>sum ||i<=0||j>sum||j<=0){
		printf("������Ϣ����\n");
		printf("������Ҫ��ѯ����������ı��\n");
		scanf("%d %d",&i,&j);
	}
	else{
		floyd(g);//�������·���ĳ���
		display(g,i,j);//չʾ���·��
	}
	return 1;
}
//�������·���ĳ���
void floyd(map g){
	int i,j,k;
	for(i=1;i<=sum;i++){
		for(j=1;j<=sum;j++){
			dist[i][j]=g.attr[i][j].adj;
			path[i][j]=j;
		}
	}
	for(k=1;k<=sum;k++){
		for(i=1;i<=sum;i++){
			for(j=1;j<=sum;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[i][k];
				}
			}
		}
	}
}

//չʾ���·��
void display(map g,int i,int j){
	int a,b;
	a=i,b=j;
	printf("��Ҫ��ѯ�����������·����\n");
	printf("%d%s",a,g.attr[a].name);
	while(path[i][j]!=b){
		i=path[i][j];
	}
	printf("-->%d%s\n\n",b,g.attr[b].name);
	printf("%s-->%s�����·����%d��\n",g.attr[a].name,g.attr[b].name,dist[a][b]);
}


//��ѯ���������·��
void allpath(map g,int m,int n,int t){
	int s,k=t+1,length=0;
	if(a[t]==n){
		for(s=0;s<t;s++){
			length=length+g.attr[a[s]][a[s+1]].adj;
		}
		if(length<=1000){
		  for(s=0;s<t;s++){
			printf("%d%s-->",a[s],g.attr[a[s]].name);
		}
		printf("%d%s  ",a[s],g.attr[a[s]].name);
		printf("��·����Ϊ%d\n",length);
	  }
	}	
	else{
		s=1;
		while(s<=g.num){
			if((g.attr[a[t][s].adj<Infinity)&&(visited[s]==0)){
				visited[s]=1;
				a[t+1]=s;
				visited[s]=0;
			}
			s++;
		}
	}
}
//

