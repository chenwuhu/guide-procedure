//山东政法学院网络空间安全学院
//姜权罡
//日期 2020年月

#include<stdio.h>//无向带权图 
#include<stdlib.h>
#include<string.h>
#define Infinity 2000//表示无穷大 
#define MaxVertexNum 20 
#define MAX 40 
#define key 11//key为顶点个数 
typedef struct arcell//边的权值信息
{ 	int adj;//权值  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum];//图的邻接矩阵类型
typedef struct vexsinfo//顶点信息 
{ 	int position;//景点的编号 
	char name[32];//景点的名称 
	char introduction[256];//景点的介绍 
	char super_introduction[512];//景点的详细介绍 
}vexsinfo;
typedef struct mgraph//图结构信息
{  	vexsinfo vexs[MaxVertexNum];//顶点向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum,arcnum;//顶点数和边数 
}mgraph;
//全局变量
mgraph campus; //图变量（大学校园） 
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];//定义全局变量存储最小路径 
int pathh[MaxVertexNum][MaxVertexNum];//定义存储路径 
mgraph initgraph()
{	int i=0,j=0;
	mgraph c;
	c.vexnum=11;//顶点个数 
	c.arcnum=20;//边的个数 
	for(i=1;i<=key;i++)//依次设置顶点编号 
	  c.vexs[i].position=i;
	//依次输入顶点信息  
	strcpy(c.vexs[1].name,"西操场、鼎山楼、知行楼");strcpy(c.vexs[1].super_introduction,"\n西操场：西操场位于校园西侧，坐落在鼎山山脚下，内设排球场、篮球场、田径场。是同学上体育课的绝佳地点。\n鼎山：和茂岭山共同作为学校的标志，我校鼎山学堂由此得名。\n知行楼：得名于“知行合一”，表达了学校对同学们的殷切希望。内设模拟法庭，目前刑事司法学院和民商法学院在此学习。\n");
	strcpy(c.vexs[1].introduction,"有足球场、篮球场，比东操场较小；法学院所在地，学校办公室"); 
	strcpy(c.vexs[2].name,"茂陵山");strcpy(c.vexs[2].super_introduction,"\n茂岭山：因济南战役闻名，从校园内上山山路平坦，风景秀丽。因有不少解放军战士牺牲于此，\n所以校园内、山腰上有不少烈士墓。清明时节常常有人前来缅怀纪念。\n");
	strcpy(c.vexs[2].introduction,"校内一座山，曾是解放济南战役战场遗址"); 
	strcpy(c.vexs[3].name,"至善楼、致远楼");strcpy(c.vexs[3].super_introduction,"\n至善楼：目前至善楼是网络空间安全学院和外国语学院的同学学习生活的地方。内有多个机房、实验室、听力教室等等。\n致远楼：致远楼用于法学院和经济贸易法学院同学的学习和生活，另外致远楼有多个阶梯教室，可用于多种课程教学。");
	strcpy(c.vexs[3].introduction,"网络空间安全学院、外国语学院、经济贸易法学院所在地"); 
	strcpy(c.vexs[4].name,"文体馆");strcpy(c.vexs[4].super_introduction,"\n文体馆：位于学校中部偏东，内设游泳馆，瑜伽室，乒乓球馆和台球室等等，\n以供同学们上体育课、进行体育活动使用。二楼有印刷室，为大家打印资料提供了便利。\n");
	strcpy(c.vexs[4].introduction,"室内运动场、游泳馆"); 
	strcpy(c.vexs[5].name,"图书馆");strcpy(c.vexs[5].super_introduction,"\n图书馆：是省内藏书最多的高校图书馆之一，现有藏书256万册。始建于1979年，内设多个学科借阅室，\n学术氛围浓厚。还经常开展读者俱乐部、读书沙龙等活动，繁荣了文化氛围。\n");
	strcpy(c.vexs[5].introduction,"读书圣地，建筑面积6666平方米"); 
	strcpy(c.vexs[6].name,"一餐、二餐、礼堂、澡堂一");strcpy(c.vexs[6].super_introduction,"\n礼堂：位于学校南门口，第二餐厅楼上。是我校学术报告、文艺晚会、话剧公演、毕业典礼的举办地点。\n一餐二餐：位于南门，不仅便捷了学生用餐，也方便了来校的人们在这里用餐。\n澡堂：环境良好，每日晚上十点前为学生提供服务。\n");
	strcpy(c.vexs[6].introduction,"学生餐厅，礼堂可举办中、大型学术会议；洗浴"); 
	strcpy(c.vexs[7].name,"南大门");strcpy(c.vexs[7].super_introduction,"\n南大门：山东政法学院拆掉原来的大门，在门口两侧修建两个花坛，让更多的人来到校园内，\n了解我们学校的文化，也方便了济南居民一览茂陵山美景，了解茂陵战役。\n");
	strcpy(c.vexs[7].introduction,"学校大门、学校班车进出口"); 
	strcpy(c.vexs[8].name,"校医院、新南小门");strcpy(c.vexs[8].super_introduction,"\n校医院：为给学生提供更好的服务，我校的校医院进行了翻修，保障了学生的健康情况，\n校医都有多年的行医经验。新小南门：为了缓解南大门的交通压力，我校又建造了新小南门，也方便了学生的出行。\n");
	strcpy(c.vexs[8].introduction,"可买药，看小病的地方；距离校医院和教工餐厅、新澡堂比较近"); 
	strcpy(c.vexs[9].name,"东操场、三餐");strcpy(c.vexs[9].super_introduction,"\n东操场：在东操场，我们开展了田径，健美操，太极扇，女子防身术，大保健，羽毛球，乒乓球等体育课程，\n也是学生利用体育活动放松自己的主要场所。\n 三餐：三餐是靠近东门几个餐厅里最大的一个，共有三层，食物品种多样，\n又在第三层加了独具特色的火锅，饺子，甜品，深受学生党的喜爱。\n");
	strcpy(c.vexs[9].introduction,"举办大、中型体育活动处；学生食堂，人气较高"); 
	strcpy(c.vexs[10].name,"菜鸟驿站");strcpy(c.vexs[10].super_introduction,"\n菜鸟驿站：负责接收并整理分类学生的快递，也为学生提供在校兼职的机会。\n极大的辩解了学生的生活。\n");
	strcpy(c.vexs[10].introduction,"收发快递处"); 
	strcpy(c.vexs[11].name,"东门");strcpy(c.vexs[11].super_introduction,"\n东门：为临近东门的住校学生提供了出行的方便。\n");
	strcpy(c.vexs[11].introduction,"距离小吃街、公交车站、天联超市较近"); 
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
}//initgraph
//2.查找景点在图中的序号
int locatevex(mgraph c,int v)//locatevex
{	int i;
	for(i=1;i<=c.vexnum;i++)
	  if(v==c.vexs[i].position)  return i;//找到，返回顶点序号i 
 	return -1;//没有找到这个顶点 
} 
//3.查找并输出序号为m,n景点间的长度不超过8个景点的路径 
void path(mgraph c,int m,int n,int k)
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
				path(c,m,n,t);
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
	path(c,m,n,0);//调用程序。k=1，对应起点d[1]==m。k为d[]数组下标 
	return 1;
}
//5.用迪杰斯特拉算法，求出一个景点到其他景点间的最短路径，
void shortestpath_dij(mgraph c)
{	int v0,v,w,k=1,min,t,p;
	int final[MaxVertexNum];//final[w]=1表示已经求得顶点V0到Vw的最短路径
	int Patharc[MaxVertexNum];//用于存储最短路径下标的数组 
    int ShortPathtable[MaxVertexNum];//用于存储到各点最短路径的权值和 
	printf("\n请输入一个起始景点的编号："); 
	scanf("%d",&v0);printf("\n\n"); 
	while(v0<0||v0>key)
	{	printf("\n您输入的景点编号不存在\n");
		printf("请重新输入：");
		scanf("%d",&v0); 
	}
	//初始化数据
	for(v=1;v<=c.vexnum;v++)//数组0还是空出来 
	{	final[v]=0;//全部顶点初始化为未找到最短路径 
		ShortPathtable[v]=c.arcs[v0][v].adj;//将与v0点有连线的顶点加上权值 
		Patharc[v]=0;//初始化路径数组p为0 
	 }
	 ShortPathtable[v0]=0; // V0至v0的路径为0 
	 final[v0]=1;//V0至v0不需要路径 	 
	 //开始主循环，每次求得V0到某个v顶点的 最短路径 
	 for(v=1;v<=c.vexnum;v++)
	 {	min=Infinity;
	 	for(w=1;w<=c.vexnum;w++)//找出最近的顶点和权值 
	 	{	if(!final[w]&&ShortPathtable[w]<min)//有边 
	 		{	k=w;
	 			min=ShortPathtable[w];
			 }
		 }
		 final[k]=1;//将目前找到的最近的顶点置1 
	 	 //修正当前最短路径及距离
		 for(w=1;w<=c.vexnum;w++)
		 {	//如果经过v顶点的路径比现在这条路径的长度短的话，更新
			if(!final[w]&&(min+c.arcs[k][w].adj<ShortPathtable[w])) 
			{	ShortPathtable[w]=min+c.arcs[k][w].adj;//修改当前路径长度
				Patharc[w]=k; //存放前驱结点（像糖葫芦） 
			}
		  } 
     }
     
     
     printf("打印P数组:");
     for(t=1;t<=c.vexnum;t++)
     {
     	printf("%d ",Patharc[t]);
	 }
	 printf("\n\n");
	 //打印s数组
	 printf("打印S数组:");
     for(t=1;t<=c.vexnum;t++)
     {
     	printf("%d ",ShortPathtable[t]);
	 }
	 printf("\n\n");
	  
     //打印最短路径
	 for(t=1;t<=c.vexnum;t++)
	 {  p=t;
	 	if(t!=v0)//反向输出 
	 	{	printf("%d%s",t,c.vexs[t].name);
	 		for(w=1;w<=c.vexnum;w++)
	 		{	if(Patharc[p]!=0)
	 			{	printf("<--%d%s",Patharc[p],c.vexs[p].name);
	 				p=Patharc[p];
				 }
			 }
			 printf("<--%d%s",v0,c.vexs[v0].name);
			 printf("\n总路线长为%d米\n\n",ShortPathtable[t]); 
		 }
	  }     
}
//菜单 
void menu()
{	printf(" ┌──────────────────────────────────────────────────────┐\n");
	printf(" │ ╭ ═══════════════════════════════════════════════ ╮  │\n");
	printf(" │ ││        欢 迎 使 用 校 园 导 游 系 统          ││  │\n");
  	printf(" │ ╰ ═══════════════════════════════════════════════ ╯  │\n");
  	printf(" │                      欢迎来到                        │\n");
  	printf(" │                    山东政法学院                      │\n");
  	printf(" │                     菜 单 选 择                      │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  1.菜单                **   2.查看游览路线（迪）* │\n");// 学校景点介绍 
	printf(" │  *************************************************** │\n");
	printf(" │  *  3.查询景点间最短路径  **   4.查询景点间所有路径* │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  5.学校景点介绍        **   6.景点信息查询      * │\n");// 
	printf(" │  *************************************************** │\n");
	printf(" │  *  7.学校地图            **   8.更改图信息        * │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  0.退出                **   第一小组*^_^*       * │\n");
	printf(" │  *************************************************** │\n");
	printf(" └──────────────────────────────────────────────────────┘\n");
}
//以下是修改图的相关信息。包括建图、更新信息、删除、增加结点和边
//6.重新构造图 
int creatgraph(mgraph *c)
{	int i,j,m,n,v0,v1,distance;
	printf("请输入图的顶点数和边数: \n");
	scanf("%d %d",&c->vexnum,&c->arcnum);
	printf("下面请输入景点的信息： \n");
	for(i=1;i<=c->vexnum;i++)
	{	printf("请输入景点的编号：");
		scanf("%d",&c->vexs[i].position);
		printf("\n请输入景点的名称：");
		scanf("%s",&c->vexs[i].name);
		printf("\n请输入景点的简介：");
		scanf("%s",&c->vexs[i].introduction);
		printf("\n请输入修改后景点的详细介绍:");
		scanf("%s",&c->vexs[i].super_introduction);
	}
	for(i=1;i<=c->vexnum;i++)
	  for(j=1;j<=c->vexnum;j++)//权值全部初始化为无穷 
	    c->arcs[i][j].adj=Infinity;
	printf("下面请输入图的边的信息：\n");
	for(i=1;i<=c->vexnum;i++)
	{	printf("\n第%d条边的起点 终点 长度为：",i);
		scanf("%d %d %d",&v0,&v1,&distance);
		m=locatevex(campus,v0);//判断一下点是否存在，存在就返回位置 
		n=locatevex(campus,v1);
		if(m>0&&n>0)
		{	c->arcs[m][n].adj=distance;
			c->arcs[n][m].adj=c->arcs[m][n].adj;
		}
	}
	return 1;
}
//7.更新图的部分信息。返回值：1***比如某个信息输错了，需要改 
int newgraph(mgraph *c)
{	int changenum;
	int i,m,n,t,distance,v0,v1;
	printf("\n下面请输入您要修改的景点的个数：\n"); 
	scanf("%d",&changenum);
	while(changenum<0||changenum>key) 
	{	printf("\n输入错误！请重新输入");
		scanf("%d",&changenum);
	}
	for(i=0;i<changenum;i++)
	{	printf("\n请输入景点的编号：");
		scanf("%d",&m);
		t=locatevex(campus,m);
		printf("\n请输入修改后景点的名称:");
		scanf("%s",&c->vexs[t].name);
		printf("\n请输入修改后景点的简介:");
		scanf("%s",&c->vexs[t].introduction);
		printf("\n请输入修改后景点的详细介绍:");
		scanf("%s",&c->vexs[t].super_introduction);
	}
	printf("\n下面请输入您要更新的边数"); 
	scanf("%d",&changenum);
	while(changenum<0||changenum>key)
	{	printf("\n输入错误！请重新输入");
		scanf("%d",&changenum);
	}
	if(changenum!=0)
	printf("\n下面请输入更新边的信息：\n");
	for(i=1;i<=changenum;i++)
	{	printf("\n修改的第%d条边的起点 终点 长度为：",i);
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
//8.增加一条边。返回值：1*** 
int enarc(mgraph *c)
{	int m,n,distance;
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
//9.增加一个结点。返回值：1*** 
int envex(mgraph *c)
{	int i;
    c->vexnum++;//顶点个数+1
	printf("请输入您要增加结点的信息：");
	printf("\n编号：");
	scanf("%d",&c->vexs[c->vexnum].position);
	printf("名称：");
	scanf("%s",&c->vexs[c->vexnum].name);
	printf("简介：");
	scanf("%s",&c->vexs[c->vexnum].introduction);
	printf("详细介绍：");
	scanf("%s",&c->vexs[c->vexnum].super_introduction);
	
	for(i=1;i<=c->vexnum;i++)
	{	c->arcs[c->vexnum][i].adj=Infinity;
		c->arcs[i][c->vexnum].adj=Infinity;
	}
	return 1;
} 
//10.删除图的一个顶点。返回值：1*** 
int delvex(mgraph *c) 
{	int i=0,j;
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
//11.删除图的一条边。返回值：1*** 
int delarc(mgraph *c)
{	int m,n,v0,v1;
	if(c->vexnum<=0)
	{	printf("图中已无边，无法删除。");
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
//12.输出图的邻接矩阵的值*** 
void printmatrix(mgraph c)
{	int i,j,k=0;
	for(i=1;i<=key;i++)
	{  if(c.vexs[i].position!=-1)
		  printf("%6d",i);//横着的标号1到11
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
//13.图的操作主调函数。返回值：1*** 
int changegraph(mgraph *c)
{	int yourchoice;
	printf("(1)重新建图     (2)删除结点  (3)删除边\n");
	printf("(4)增加结点     (5)增加边    (6)更新信息\n");
	printf("(7)打印邻接矩阵 (8)返回上一级\n");
	do
	{	printf("请输入您的选择：");
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
			default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	}while(yourchoice);
}
int user_log()
{	int i;
	int a[6]={1,2,3,4,5,6},b[6];
	//for(i=0;i<6;i++)
		//printf("%d ",a[i]);
	printf("\n请输入6位密码(每输入一位密码间隔一个空格)：\n");
	for(i=0;i<6;i++)	
	  scanf("%d",&b[i]);
	for(i=0;i<6;i++)
	{	if(a[i]!=b[i])
	    {
	    	printf("密码错误!自动返回上一级\n");menu();return 0;
		} 
	}
	printf("密码正确，登陆成功！\n\n");
	changegraph(&campus);
}
//14.查询两景点间的最短路径（floyd算法）
void floyd(mgraph c)//一种暴力破解获取最短路径的算法 
{	int i,j,k;
	for(i=1;i<=key;i++)//将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1 
	{	for(j=1;j<=key;j++)
		{	shortest[i][j]=c.arcs[i][j].adj;
			pathh[i][j]=j; 
		}
	}
	int i1,j1,k1=0;
	for(i1=1;i1<=key;i1++)
		printf("%6d",i1);//横着的标号1到11
	printf("\n");
	for(i1=1;i1<=key;i1++)
	{  printf("%d",i1);//竖着的标号1到11
	  for(j1=1;j1<=key;j1++)
	  {	
	     printf("%6d",pathh[i1][j1]);
	  	k1++;
	  	if(k1%key==0) printf("\n");
	  }		
	}
	printf("\n\n\n");
	
	for(k=1;k<=key;k++)//核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改 
	{	for(i=1;i<=key;i++)
		{	for(j=1;j<=key;j++)
			 {
			 	if(shortest[i][j]>shortest[i][k]+shortest[k][j])
			 	{	shortest[i][j]=shortest[i][k]+shortest[k][j];			 	    
	     	 		pathh[i][j]=pathh[i][k];//记录一下所走的路 //P数组用来存放前驱顶点  
				}
			 }
		}
	}
}
void printf_Pshuzu()
{	int i,j,k=0;
	for(i=1;i<=key;i++)
		printf("%6d",i);//横着的标号0到11
	printf("\n");
	for(i=1;i<=key;i++)
	{  printf("%d",i);//竖着的标号0到11
	  for(j=1;j<=key;j++)
	  {	printf("%6d",pathh[i][j]);
	  	k++;
	  	if(k%key==0) printf("\n");
	  }		
	}
	printf("\n\n\n");
}
//打印出最短路径 
void display(mgraph c,int i,int j)
{	int a,b;
	a=i;b=j;
	printf("您要查询的两景点间最短路径：\n\n");	
	printf("%d%s",a,c.vexs[a].name);
	while(pathh[i][j]!=b)
	{ printf("-->%d%s",pathh[i][j],c.vexs[pathh[i][j]].name);	  	 
	  i=pathh[i][j]; 	  	 
	}
  	printf("-->%d%s\n\n",b,c.vexs[b].name);
	printf("%s-->%s的最短路径是：%d 米。\n\n",c.vexs[a].name,c.vexs[b].name,shortest[a][b]);
}
//任意两点间最短距离（弗洛伊德算法）
int shortdistance(mgraph c) 
{	int i,j;
	printf("请输入要查询的两个景点的数字编号（1->11）中间用空格间隔开。\n"); 
	scanf("%d %d",&i,&j);
	if(i>key||i<0||j>key||j<0)
	{	printf("输入信息错误！\n\n");
		printf("请输入要查询的两个景点的数字编号（1->11）中间用空格间隔开。\n"); 
		scanf("%d %d",&i,&j);
	}
	else
	{	floyd(c);printf_Pshuzu();
		display(c,i,j);
	}
	return 1;
}
//15.查询景点的信息
void seeabout(mgraph c)
{	int k;
	printf("\n请输入要查询的景点编号：");
	scanf("%d",&k);
	while(k<=0||k>key)
	{	printf("\n您所输入的景点编号不存在！");
		printf("\n请重新输入景点编号：");
		scanf("%d",&k); 
	}
	printf("\n\n编号：%-4d\n",c.vexs[k].position);
	printf("\n景点名称：%-10s\n",c.vexs[k].name);
	printf("\n详细介绍：%-80s\n\n",c.vexs[k].super_introduction);
}
//16.显示所有景点信息
void browsecompus(mgraph c) 
{	int i;
	printf(" \n\n编号        景点名称                   简介\n");
	printf("____________________________________________________________________________________________\n");
	for(i=1;i<=key;i++)
	{	if(c.vexs[i].position!=-1)
		printf("%-10d%-25s%-80s\n",c.vexs[i].position,c.vexs[i].name,c.vexs[i].introduction);
	}
	printf("____________________________________________________________________________________________\n");
}
//17.山政地图
void school_map()//│││││   ┌┌┌   ╰╰╰╭═  ╭═  ═╰═ ╭╭=  =╮  =╯  =■□■□  ══=
{   printf(" -------------------------------------------------山政地图------------------------------------------------\n");
    printf(" ---------------------------------------------------------------------------------------------------------\n");
	printf(" ___________                                                                                            ==\n");
	printf("││西操场 ││*                         致远楼                至善楼                            菜鸟驿站   == \n");
	printf("││_______││*                       * *  * * * * *  *  *  *   **   *  *  *  *  *  *  *  *  * *  * *  *   == \n");
	printf(" __________ *                     *        ##                *                       *     大学生    *  == \n");
	printf(" │鼎山楼 │ *-->***鼎山***茂陵山*                            *   ___________          *  自主学习中心  * ==\n");
	printf(" │_______│ *                              ##     文体馆     *   │        │          *     四餐         *东\n");
	printf(" __________ *                              ##               *   │ 东操场 │   三餐   * * * * * * ** * * *--> \n");
	printf(" │知行楼 │ *                              ##              *     │________│          *    _________     *门 \n");
	printf(" │_______│  *                    茂陵山        ##        *                          *    │慎行楼 │    * == \n");
	printf(" ##           *                 战役遗址         ##      *                          *    │_______│    * ==\n");
	printf(" ##            ****** 笃行楼    **********图书馆     ##  *                          *                 * ==\n");
	printf(" ##              *             *          * * * * * * * * * * * * * * * * * ** * * * * * * * * * *  *   ==\n");
	printf(" ##  停车场      *             *           ###           *                          _________           ==\n");
	printf(" ##              *             *           ###   澡堂    *                          │8、9号│            ==\n"); 
	printf(" ##  二餐        *    弘德楼   *           ###           *                          │_公寓_│            ==\n");
	printf(" ##  澡堂一      *             *  尚德楼   ### 教工餐厅  *                                              ==\n");
	printf(" ##  超市        *             *           ###           *            ==================================== \n");
	printf(" ##  一餐        *             *  司法鉴定 ###  校医院   *            ==  \n");
	printf(" ##  礼堂          *         *      中心   ###           *            ==    \n");
	printf(" ================ 山东政法学院 =======================小南门============  \n");
	printf(" ================     南门     =======================      ============\n");
	printf("\n                                                      西<---|--->东  \n");
} 
//18.主要工作函数。操作区用户界面
void mainwork()
{   menu();
	int yourchoice;
	campus=initgraph();
	do
	{	printf("请输入您的选择：");
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
			case 0:system("cls");printf("谢谢使用\n");break;
			default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	}while(yourchoice); 
}
int main()
{	system("color 1f");//背景颜色
	system("mode con: cols=140 lines=130");//程序页面长宽
	system("SchoolGraph.png");//调用校园地图 （就是一个图片）
	mainwork();
	return 0;
}

