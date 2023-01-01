/*void manage_map_information()//管理地图信息
{
	void add_attraction ()//增加景点
void delete_attraction()//删除景点
void modify_attraction_information()//修改景点信息
void add_road ()//增加路径
void delete_road//删除路径
}*/
/*typedef struct arcell//边的权值信息
{ 	
int adj;//权值  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum]; 

typedef struct vexsinfomation//顶点信息 
{ 	int number;//景点的编号 
	char name[20];//景点的名称 
	char introduction[200];//景点的介绍  
}vexsinfomation;

typedef struct mgraph//图
{  	vexsinfo vexs[MaxVertexNum];//顶点 向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum,arcnum;//顶点数和边数 
}mgraph;*/ 

 void manage_map_information(mgraph *c)
{
	int a;
	printf("1 增加景点/n2 删除景点/n4 修改景点信息/n5 增加路径/n5 删除路径/n6 退出");
do
	{	printf("请输入您的选择：");
	    scanf("%d",&a);
	    switch(a)
	    {	case 1:add_attraction(c);break;
			case 2:delete_attraction(c);break;
			case 3:modify_attraction_information;break;
			case 4:add_road(c);break;
			case 5:delete_road(c);break;
			case 6:system("cls");menu();return 1;//break;
			default:printf("输入选项不存在\n");break;
		}
	}while(a);
} 
 
 
 //增加景点 
void add_attraction (mgraph *c)
{	int i;
    c->vexnum++;//顶点个数加一 
	printf("请输入您要增加景点的信息：");
	printf("\n编号：");
	scanf("%d",&c->vexs[c->vexnum].number );
	printf("名称：");
	scanf("%s",&c->vexs[c->vexnum].name);
	printf("介绍：");
	scanf("%s",&c->vexs[c->vexnum].introduction);
	for(i=1;i<=c->vexnum;i++)
	{	c->arcs[c->vexnum][i].adj=Infinity;
		c->arcs[i][c->vexnum].adj=Infinity;
	}
	return 1;
}

//删除景点
void delete_attraction()
{
	int i=0,j;
	int m,v;
	if(c->vexnum<=0)
	{	printf("图中已无顶点");
		return 1;
	}
	printf("\n下面请输入您要删除的景点编号：");
	scanf("%d",&v);
	while(v<0||v>key)
	{	printf("\n输入错误！请重新输入:");
		scanf("%d",&v);
	}
	m=locatevex(campus,v);
	if(m<0)
	{	printf("此顶点%d已删除\n",v);
		return 1;
	}
	for(i=m;i<=c->vexnum-1;i++)
	  for(j=1;j<=c->vexnum;j++)//将二维数组中的第m+1行依次向前移动一行（删除第m行） 
	    c->arcs[i][j]=c->arcs[i+1][j]; 
	for(i=m;i<=c->vexnum-1;i++)
	  for(j=1;j<=c->vexnum;j++)//将二维数组中的第m+1列依次向前移动一列（删除第m列）
	    c->arcs[j][i]=c->arcs[j][i+1];
	c->vexs[v].position=-1;//表示此点已删除，后期打印也不会显示该点 
	c->vexnum--;//顶点个数-1 
	return 1;
}


//修改景点信息
void modify_attraction_information()
{




} 


//增加路径
void add_road ()
{
	int m,n,distance;
	printf("\n请输入边的起点和终点编号，权值：");
	scanf("%d %d %d",&m,&n,&distance);
	while(m<0||m>c->vexnum||n<0||n>c->vexnum)
	{	printf("输入错误，请重新输入：");
		scanf("%d %d",&m,&n);
	} 	
	if(locatevex(campus,m)<0)
	{	printf("此节点%d已删除",m);
		return 1;
	}
	if(locatevex(campus,n)<0)
	{	printf("此节点%d已被删除",n);
		return 1;
	}
	
	c->arcs[m][n].adj=distance;//在邻接矩阵中多加一个值 
	c->arcs[n][m].adj=c->arcs[m][n].adj;
	c->arcnum --;//图中边数+1
	return 1;


} 


//删除路径
void delete_road()
{
	int m,n,v0,v1;
	if(c->vexnum<=0)
	{	printf("此道路不存在");
		return 1; 
	}
	printf("\n下面请输入您要删除的边的起点和终点编号：");
	scanf("%d %d",&v0,&v1);
	m=locatevex(campus,v0);
	if(m<0)
	{	printf("此%d顶点已删除",v0);
		return 1;
	}
	n=locatevex(campus,v1);
	if(n<0)
	{	printf("此%d顶点已删除",v1);
		return 1;
	}
	c->arcs[m][n].adj=Infinity;//将删掉的边的权值改为无穷 
	c->arcs[n][m].adj=Infinity;
	c->arcnum --;//图中边数减1 
	return 1;



} 












