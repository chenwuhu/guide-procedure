/*void manage_map_information()//�����ͼ��Ϣ
{
	void add_attraction ()//���Ӿ���
void delete_attraction()//ɾ������
void modify_attraction_information()//�޸ľ�����Ϣ
void add_road ()//����·��
void delete_road//ɾ��·��
}*/
/*typedef struct arcell//�ߵ�Ȩֵ��Ϣ
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
}mgraph;*/ 

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
			case 6:system("cls");menu();return 1;//break;
			default:printf("����ѡ�����\n");break;
		}
	}while(a);
} 
 
 
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












