#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<limits.h>  
#include<iostream>
using namespace std;
#include"MGraph.h"


void Dijkstra(MGraph g,int v);		//���v��������������·��
void DispAllPath(MGraph &g,int dist[],int path[],int S[],int v) ;//����Ӷ���v�������������·��
void Dispdistpath(int dist[],int path[],int n);	//���dist�����path����

int main()
{
	MGraph g;
	int i,j,n;
	CreateGraphF(g);           /* ���������ļ���������ͼ*/
	Display(g);	/* �������ͼ*/  
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
    //���v��������������·��
    /********** Begin **********/
    //���帨������
    int *record = (int *)malloc(sizeof (int) * g.vexnum);  //��¼�Ƿ����뼯��V
    int *path = (int *)malloc(sizeof (int) * g.vexnum);  //��¼ǰ���ڵ�
    int *dist = (int *)malloc(sizeof (int) * g.vexnum);  //��¼ v->i ����̾���

    //��ʼ����������
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

void DispAllPath(MGraph &g,int dist[],int path[],int S[],int v) //����Ӷ���v�������������·��
{
	int i,j,k,count=0;
	int apath[MAX_VERTEX_NUM],d;				//���һ�����·��(����)���䶥�����
	for (i=0;i<g.vexnum;i++)
		if (path[i]!=-1)
			count++;
	if (count==1)						//path��ֻ��һ����Ϊ-1ʱ��ʾû��·��
	{	printf("��ָ���Ķ��㵽�������㶼û��·��!!!\n");
		return;
	}
	for (i=0;i<g.vexnum;i++)					//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{
			//printf("��%s��%s���·������Ϊ:%s\t·��:",g.vexs [v],g.vexs[i],dist[i]);
			cout<<"��"<<g.vexs [v]<<"��"<<g.vexs[i]<<"���·������Ϊ:"<<dist[i]<<"\t";
			d=0; 			apath[d]=i;			//���·���ϵ��յ�
			k=path[i];
			if (k==-1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//���·���ϵ����
				//printf("%d",apath[d]);	//��������
				cout<<g.vexs [ apath[d] ];
				for (j=d-1;j>=0;j--)	//�������������
					//printf("��%d",apath[j]);
					cout<<"��"<<g.vexs [ apath[j] ];
				printf("\n");
			}
		}
}


void Dispdistpath(int dist[],int path[],int n)	//���dist�����path����
{
	int i;
	printf("dist:\t");
	for (i=0;i<n;i++)
		if (dist[i]==INFINITY)
			printf("%s\t","��");
		else
			printf("%d\t",dist[i]);
	printf("\n");
	printf("path:\t");
	for (i=0;i<n;i++)
		printf("%d\t",path[i]);
	printf("\n");
}
