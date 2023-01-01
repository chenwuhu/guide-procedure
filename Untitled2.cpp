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

int getMin(int *record,int *dist,MGraph g){
    int min = INFINITY;
    int index;
    for(int i = 0;i < g.vexnum;i++){
        if(min > dist[i] && !record[i]){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(MGraph g,int v)
{
    //求从v到其他顶点的最短路径
    /********** Begin **********/
    //定义辅助数组
    int *record = (int *)malloc(sizeof (int) * g.vexnum);  //记录是否被纳入集合V
    int *path = (int *)malloc(sizeof (int) * g.vexnum);  //记录前驱节点
    int *dist = (int *)malloc(sizeof (int) * g.vexnum);  //记录 v->i 的最短距离

    //初始化辅助数组
    for(int i = 0; i < g.vexnum; i++){
        if(g.arcs[v][i].adj > 0 && g.arcs[v][i].adj != INFINITY){
            path[i] = v;
            dist[i] = g.arcs[v][i].adj;
        }
        else{
            path[i] = -1;
            dist[i] = INFINITY;
        }
        if(v == i) {
            record[i] = 1;
            //dist[i] = 0;
        } else{
            record[i] = 0;
        }
    }
    Dispdistpath(dist,path,g.vexnum);
    for(int i = 0;i < g.vexnum - 1;i++){
        int min = getMin(record,dist,g);
        record[min] = 1;
        for(int j = 0;j < g.vexnum;j++){
            if(!record[j] && dist[min] + g.arcs[min][j].adj < dist[j]){
                dist[j] = dist[min] + g.arcs[min][j].adj;
                path[j] = min;
            }
        }
        Dispdistpath(dist,path,g.vexnum);
    }

    DispAllPath(g,dist,path,record,v);
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
