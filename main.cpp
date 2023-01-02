#include<stdio.h>//无向带权图 
#include<stdlib.h>
#include<string.h>
#define Infinity 2000//表示无穷大 
#define MaxVertexNum 20 
#define MAX 40 
#define key 11//key为顶点个数 

typedef struct arcell//边的权值信息
{ 	
int adj;//权值  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum]; 

typedef struct vexsinfomation//顶点信息 
{ 	int number;//景点的编号 
	char name[20];//景点的名称 
	char introduction[200];//景点的介绍  
}vexsinfomation;

typedef struct mgraph//图
{  	vexsinfomation vexs[MaxVertexNum];//顶点 向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum,arcnum;//顶点数和边数 
}mgraph;

//全局变量
mgraph campus; //图变量（大学校园） 
int d[30];
int visited[30];
int dist[MaxVertexNum][MaxVertexNum];//定义全局变量存储最小路径 
int path[MaxVertexNum][MaxVertexNum];//定义存储路径 
mgraph initgraph()
{	int i=0,j=0;
	mgraph c;
	c.vexnum=11;//顶点个数 
	c.arcnum=20;//边的个数 
	for(i=1;i<=key;i++)//依次设置顶点编号 
	  c.vexs[i].number=i;
	//依次输入顶点信息  
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[2].name,"");
	strcpy(c.vexs[2].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	strcpy(c.vexs[1].name,"");
	strcpy(c.vexs[1].introduction,""); 
	
	for(i=1;i<=key;i++)
	  for(j=1;j<=key;j++)
	    c.arcs[i][j].adj=Infinity;//先初始化图的邻接矩阵 	
	c.arcs[1][2].adj=60;c.arcs[1][5].adj=70;c.arcs[2][3].adj=40;c.arcs[2][4].adj=40;c.arcs[3][4].adj=15;
	c.arcs[3][9].adj=10;c.arcs[3][10].adj=30;c.arcs[4][5].adj=30;c.arcs[4][9].adj=20;c.arcs[5][6].adj=60;
	c.arcs[5][7].adj=60;c.arcs[5][8].adj=30;c.arcs[5][9].adj=40;c.arcs[6][7].adj=10;c.arcs[7][8].adj=30;
	c.arcs[8][9].adj=50;c.arcs[8][11].adj=200;c.arcs[9][10].adj=35;c.arcs[9][11].adj=10;c.arcs[10][11].adj=20; 
	for(i=1;i<=key;i++)//邻接矩阵是对称矩阵，对称赋值（无向图需要对称赋值） 
	  for(j=1;j<=key;j++)
	    c.arcs[j][i].adj=c.arcs[i][j].adj;
    return c;
}//初始化图
 
//管理员菜单展示 
void menu1() {
	printf("┌────────────────────────────┐\n");
	printf("│  ╭ ═══════════════════════ ╮  │\n");
	printf("│  ││       欢 迎 使 用 校 园 导 游 系 统        ││  │\n");
	printf("│  ╰ ═══════════════════════ ╯  │\n");
	printf("│                      欢迎来到                          │\n");
	printf("│                   三峡大学  CTGU                       │\n");
	printf("│         ?????????????????????????????????????          │\n");
	printf("│                      管 理 员                          │\n");
	printf("│                     菜 单 选 择                        │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  1.菜单                 **   2.所有景点信息查询   * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  3.具体景点信息查询     **   4.查询景点间最短路径 * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  5.查询景点间所有路径   **   6.管理地图信息       * │\n");// 
	printf("│  ***************************************************** │\n");
	printf("│  *  7.管理用户信息         **   0.退出               * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *                         **                        * │\n");
	printf("│  ***************************************************** │\n");
	printf("└────────────────────────────┘\n");

}

//游客菜单展示 
void menu2() {
	printf("┌────────────────────────────┐\n");
	printf("│  ╭ ═══════════════════════ ╮  │\n");
	printf("│  ││       欢 迎 使 用 校 园 导 游 系 统        ││  │\n");
	printf("│  ╰ ═══════════════════════ ╯  │\n");
	printf("│                      欢迎来到                          │\n");
	printf("│                   三峡大学  CTGU                       │\n");
	printf("│         ?????????????????????????????????????          │\n");
	printf("│                        游 客                           │\n");
	printf("│                     菜 单 选 择                        │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  1.菜单                 **   2.所有景点信息查询   * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  3.具体景点信息查询     **   4.查询景点间最短路径 * │\n");
	printf("│  ***************************************************** │\n");
	printf("│  *  5.查询景点间所有路径   **   0.退出               * │\n");// 
	printf("│  ***************************************************** │\n");
	printf("│  *                         **                        * │\n");
	printf("│  ***************************************************** │\n");
	printf("└────────────────────────────┘\n");

}

//身份确认权限核验函数
int verification()
{
	int n=6,count=0;
	int i;
	int a[6];
	int password[6]={5,3,7,4,3,6};
	printf("请输入六位数密码：\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	if(a[i]==password[i])
	count++;
	
	if(count==n)
	return 1;
	else
	return 0;
	
}

//查找景点在图中的序号
int locatevex(mgraph c,int v)//locatevex
{	int i;
	for(i=1;i<=c.vexnum;i++)
	  if(v==c.vexs[i].number)  return i;//找到，返回顶点序号i 
 	return -1;//没有找到这个顶点 
} 

//以下是修改图的相关信息。包括建图、更新信息、删除、增加结点和边
//增加景点 
int add_attraction (mgraph *c)
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
int delete_attraction(mgraph *c)
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
	c->vexs[v].number=-1;//表示此点已删除，后期打印也不会显示该点 
	c->vexnum--;//顶点个数-1 
	return 1;
}


//修改景点信息
void modify_attraction_information(mgraph *c)
{




} 


//增加路径
int add_road (mgraph *c)
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
int delete_road(mgraph *c)
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

//管理地图信息
void manage_map_information(mgraph *c)
{
	int a;
	campus=initgraph();
	printf("1 增加景点\n2 删除景点\n4 修改景点信息\n5 增加路径\n5 删除路径\n0 退出\n");
do
	{	printf("请输入您的选择：");
	    scanf("%d",&a);
	    switch(a)
	    {	case 1:add_attraction(c);break;
			case 2:delete_attraction(c);break;
			case 3:modify_attraction_information;break;
			case 4:add_road(c);break;
			case 5:delete_road(c);break;
			case 0:system("cls");menu1();break;
			default:printf("输入选项不存在\n");break;
		}
	}while(a);
} 
 
// 以下是用户信息管理
void manage_user(mgraph *c)
{

}

//计算最短路径的长度
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

//展示最短路径
void display(mgraph c,int i,int j){
	int a,b;
	a=i,b=j;
	printf("你要查询的两景点最短路径：\n");
	printf("%d%s",a,c.vexs[a].name);
	while(path[i][j]!=b){
		i=path[i][j];
	}
	printf("-->%d%s\n\n",b,c.vexs[b].name);
	printf("%s-->%s的最短路径：%d。\n",c.vexs[a].name,c.vexs[b].name,dist[a][b]);
}


//1所有景点信息查询
void allattractions(mgraph c){
	int i;
	printf("景点编号 景点名称 景点介绍\n");
	for(i=1;i<=key;i++){
		if(c.vexs[i].number!=-1)
		printf("%d%s%s\n",c.vexs[i].number,c.vexs[i].name,c.vexs[i].introduction);
	}
}


//2具体景点信息查询
void specificattractions(mgraph c){
	int j;
	printf("请输入要查询的景点编号\n");
	scanf("%d",&j);
	while(j<=0 ||j>key){
		printf("你输入的景点编号不存在\n");
		printf("请重新输入景点编号\n");
		scanf("%d",&j);
	}
	printf("景点编号：%d\n景点名称：%s\n景点介绍：%s\n",c.vexs[j].number ,c.vexs[j].name,c.vexs[j].introduction);
}

//3查询景点间最短路径
int  shortestpath(mgraph c){
	int i,j;
	printf("请输入要查询的两个景点的编号\n");
	scanf("%d %d",&i,&j);
	if(i>key ||i<=0||j>key||j<=0){
		printf("输入信息有误\n");
		printf("请输入要查询的两个景点的编号\n");
		scanf("%d %d",&i,&j);
	}
	else{
		floyd(c);//计算最短路径的长度
		display(c,i,j);//展示最短路径
	}
	return 1;
}

//4.查找并输出序号为m,n景点间的长度不超过8个景点的路径 
void pathh(mgraph c,int m,int n,int k)
{	int s,t=k+1,length=0;//t用于存放路径上下一个顶点对应的d[]数组元素的下标 
	if(d[k]==n&&k<8)//若d[k]是终点n且景点个数<=8,则输出该路径 
	{	for(s=0;s<k;s++)//计算路径长度 
	    {    	 
	    	length=length+c.arcs[d[s]][d[s+1]].adj;
		} 
		if(length<=100)//打印路径长度小于定长的路径 
		{	for(s=0;s<k;s++)//输出该路径。s=0时为起点m
	        {
	    	   printf("%d%s--->",d[s],c.vexs[d[s]].name);
		    } 
	        printf("%d%s  ",d[s],c.vexs[d[s]].name);//输出最后一个景点名（即顶点n的名字，此时s==k）	
	        printf("总路线长为%d米\n\n",length);
		}
	} 
	else
	{	s=1;
		while(s<=c.vexnum)//从第m个顶点，试探所有顶点是否有路径 
		{	if((c.arcs[d[k]][s].adj<Infinity)&&(visited[s]==0))//顶点m到顶点s有边(权值不为无穷大)，且未被访问 
			{	visited[s]=1;
				d[k+1]=s;//存储顶点编号 
				pathh(c,m,n,t);
				visited[s]=0;//将找到的路径上顶点的访问标志重新设置为0，以用于试探新的路径 
			}
			s++;//试探从下一个顶点s开始是否有到终点的路径 
		}
	}	
} 
//4.查找两景点间的景点的所有路径
int allpath(mgraph c)
{	int k,i,j,m,n;
	printf("\n\n请输入您想要查询的两个景点的编号：\n\n");
	scanf("%d%d",&i,&j);printf("\n\n");
	m=locatevex(c,i);//locatevex 确定该顶点是否存在。若存在，返回该顶点编号。 
	n=locatevex(c,j);
	d[0]=m;//存储路径起点m（int d[]数组是全局变量） 
	for(k=0;k<key;k++)//全部顶点访问标志初值设为0 
	  visited[k]=0;
	visited[m]=1;//第m个顶点访问标志设置为1 
	pathh(c,m,n,0);//调用程序。k=1，对应起点d[1]==m。k为d[]数组下标 
	return 1;
}

//管理员功能函数 
void menuwork1(mgraph c) {
	menu1();
	int choice;
	do
	{

		printf("请输入您的需求：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu1();break;
		case 2:system("cls");allattractions(c);break;
		case 3:system("cls");specificattractions(c);break;
		case 4:system("cls");shortestpath(c);break;
		case 5:system("cls");allpath(c);break;
		case 6:system("cls");manage_map_information(&campus);break;
		//case 7:system("cls");manage_user_information(&campus);break;
		case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");
		}

	} while (choice);

}

//游客功能函数 
void menuwork2(mgraph c) {
	menu2();
	int choice;
	do
	{

		printf("请输入您的需求：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menu2();break;
		case 2:system("cls");allattractions(c);break;
		case 3:system("cls");specificattractions(c);break;
		case 4:system("cls");shortestpath(c);break;
		case 5:system("cls");allpath(c);break;
		case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");
		}

	} while (choice);

}

//主函数 
int main()
{
	int choice;
	printf("管理员请输入1\n游客请输入2\n");
	do
	{

		printf("请选择您的身份：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:system("cls");menuwork1(campus);break;
		case 2:system("cls");menuwork2(campus);break;
		case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");
		}

	} while (choice);
}

