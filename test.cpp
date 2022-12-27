#include<stdio.h>
#include <stdlib.h>

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
{  	vexsinfo vexs[MaxVertexNum];//顶点 向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum,arcnum;//顶点数和边数 
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

		printf("请输入您的需求：");
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
		case 0:system("cls");printf("感谢您的使用,期待着我们下次见面。\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");
		}

	} while (choice);

}
void menu() {
	printf("┌────────────────────────────┐\n");
	printf("│  ╭ ═══════════════════════ ╮  │\n");
	printf("│  ││       欢 迎 使 用 校 园 导 游 系 统        ││  │\n");
	printf("│  ╰ ═══════════════════════ ╯  │\n");
	printf("│                      欢迎来到                          │\n");
	printf("│                   三峡大学  CTGU                       │\n");
	printf("│         ⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕⁕          │\n");
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
void allattractions()//所有景点信息查询
{



}
void specificattractions()//具体景点信息查询 
{
	

}
void shortestpath() //查询景点间最短路径
{


}
void allpath()//查询景点间所有路径
{



}
void manage_map_information()//管理地图信息
{
	int outcome=verification();//权限核验结果。  如果返回结果为1，则可登入系统修改；否则返回上一级
	if (outcome == 1)
	{
		printf("密码正确，登入系统成功!\n");
		manage_map();
	}
	else
	{
		printf("密码输入错误！自动返回上一级\n");menu();return ;
	}

}

void manage_user_information()//管理用户信息
{
	int outcome = verification();//权限核验结果。  如果返回结果为1，则可登入系统修改；否则返回上一级
	if (outcome == 1)
	{
		printf("密码正确，登入系统成功!\n");
		manage_user();
	}
	else
	{
		printf("密码输入错误！自动返回上一级\n");menu();return;
	}

}
int verification()//身份确认权限核验函数
{

}

//管理地图信息
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
			case 6:a=0;menu();return 1;//break;
			default:printf("输入选项不存在\n");break;
		}
	}while(a);
} 
 
//以下是修改图的相关信息。包括建图、更新信息、删除、增加结点和边
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

// 以下是用户信息管理
void manage_user()
{

}


//1所有景点信息查询
void allattractions(){
	int i;
	printf("景点编号 景点名称 景点介绍\n");
	for(i=1;i<=sum;i++){
		if(g.attr[i].position!=-1)
		printf("%d%s%s\n",g.attr[i].position,g.attr[i].name,g.attr[i].introduction);
	}
}


//2具体景点信息查询
void specifications(){
	int j;
	printf("请输入要查询的景点编号\n");
	scanf("%d",&j);
	while(j<=0 ||j>sum){
		printf("你输入的景点编号不存在\n");
		printf("请重新输入景点编号\n");
		scanf("%d",&j);
	}
	printf("景点编号：%d\n景点名称：%s\n景点介绍：%s\n",g.attr[i].position,g.attr[i].name,g.attr[i].introduction);
}

//3查询景点间最短路径
void  shortestpath(){
	int i,j;
	printf("请输入要查询的两个景点的编号\n");
	scanf("%d %d",&i,&j);
	if(i>sum ||i<=0||j>sum||j<=0){
		printf("输入信息有误\n");
		printf("请输入要查询的两个景点的编号\n");
		scanf("%d %d",&i,&j);
	}
	else{
		floyd(g);//计算最短路径的长度
		display(g,i,j);//展示最短路径
	}
	return 1;
}
//计算最短路径的长度
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

//展示最短路径
void display(map g,int i,int j){
	int a,b;
	a=i,b=j;
	printf("你要查询的两景点最短路径：\n");
	printf("%d%s",a,g.attr[a].name);
	while(path[i][j]!=b){
		i=path[i][j];
	}
	printf("-->%d%s\n\n",b,g.attr[b].name);
	printf("%s-->%s的最短路径：%d。\n",g.attr[a].name,g.attr[b].name,dist[a][b]);
}


//查询景点间所有路径
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
		printf("总路径长为%d\n",length);
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
