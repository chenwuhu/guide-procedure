#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<limits.h>  
#include<iostream>
using namespace std;
#include"MGraph.h"


void Dijkstra(MGraph g,int v);		//求从v到其他顶点的最短路径
void DispAllPath(MGraph &g,int dist[],int path[],int S[],int v) ;//输出从顶点v出发的所有最短路径
void Dispdistpath(int dist[],int path[],int n);	//输出dist数组和path数组

int main()
{
	MGraph g;
	int i,j,n;
	CreateGraphF(g);           /* 利用数据文件创建有向图*/
	Display(g);	/* 输出有向图*/  
	Dijkstra(g,0);	
	return 0;
}

//path[i]=v;  //顶点v到顶点i有边时，置顶点i的前一个顶点为v
void Dijkstra(MGraph g,int v)        //求从v到其他顶点的最短路径
{    /********** Begin **********/
    int dist[MAX_VERTEX_NUM];                //建立dist数组
    int path[MAX_VERTEX_NUM];                //建立path数组
    int S[MAX_VERTEX_NUM];                    //建立S数组
    int min=0,i,j;
  for (i=0;i<g.vexnum ;i++)// 初始化 dist[]  和 path[]     这样对path赋值，后面有赋值的地方也同样处理：path[i]=v;  //顶点v到顶点i有边时，置顶点i的前一个顶点为v
    {  
        /*dist[i]=g.arcs[v][i].adj;
        if(dist[i]<INFINITY)
        path[i]=v;*/
        if( g.arcs[v][i].adj > 0 && g.arcs[v][i].adj != INFINITY)
        {
            path[i] = v;
            dist[i] = g.arcs[v][i].adj;
        }
        else{
            path[i] = -1;
            dist[i] = INFINITY;
        }
        if(v == i) {
           S[i] = 1;
        } else{
          S[i] = 0;
        }
    }

    Dispdistpath(dist,path,g.vexnum);    //输出dist初始值和path初始值
    S[v]=1;                            //源点编号v放入s中
    for (i=0;i<g.vexnum-1;i++)            //循环向S中添加n-1个顶点
    {   
        dist[min]=INFINITY;                //mindis置最小长度初值
        for (j=0;j<g.vexnum;j++)           
            if(!S[j]&&dist[j]<dist[min])
                min=j;      //选取不在s中且具有最小距离的顶点u
			
		S[min]=1;        //顶点u加入s中
                                          
        for (j=0;j<g.vexnum;j++)           
        { 
            if((!S[j])&&(g.arcs[min][j].adj!=INFINITY)&&(dist[min]+g.arcs[min][j].adj<dist[j]) )
                {
                    dist[j]=dist[min]+g.arcs[min][j].adj;
                    path[j]=min;
                
                }
            
            //修改不在s中的顶点的距离   ,  更新。
        }
        Dispdistpath(dist,path,g.vexnum);  //输出dist值和path值
    }
    DispAllPath(g,dist,path,S,v);        //输出所有最短路径及长度
  /********** End **********/
}

void DispAllPath(MGraph &g,int dist[],int path[],int S[],int v) //输出从顶点v出发的所有最短路径
{
	int i,j,k,count=0;
	int apath[MAX_VERTEX_NUM],d;				//存放一条最短路径(逆向)及其顶点个数
	for (i=0;i<g.vexnum;i++)
		if (path[i]!=-1)
			count++;
	if (count==1)						//path中只有一个不为-1时表示没有路径
	{	printf("从指定的顶点到其他顶点都没有路径!!!\n");
		return;
	}
	for (i=0;i<g.vexnum;i++)					//循环输出从顶点v到i的路径
		if (S[i]==1 && i!=v)
		{
			//printf("从%s到%s最短路径长度为:%s\t路径:",g.vexs [v],g.vexs[i],dist[i]);
			cout<<"从"<<g.vexs [v]<<"到"<<g.vexs[i]<<"最短路径长度为:"<<dist[i]<<"\t";
			d=0; 			apath[d]=i;			//添加路径上的终点
			k=path[i];
			if (k==-1)					//没有路径的情况
				printf("无路径\n");
			else						//存在路径时输出该路径
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//添加路径上的起点
				//printf("%d",apath[d]);	//先输出起点
				cout<<g.vexs [ apath[d] ];
				for (j=d-1;j>=0;j--)	//再输出其他顶点
					//printf("→%d",apath[j]);
					cout<<"→"<<g.vexs [ apath[j] ];
				printf("\n");
			}
		}
}


void Dispdistpath(int dist[],int path[],int n)	//输出dist数组和path数组
{
	int i;
	printf("dist:\t");
	for (i=0;i<n;i++)
		if (dist[i]==INFINITY)
			printf("%s\t","∞");
		else
			printf("%d\t",dist[i]);
	printf("\n");
	printf("path:\t");
	for (i=0;i<n;i++)
		printf("%d\t",path[i]);
	printf("\n");
}
