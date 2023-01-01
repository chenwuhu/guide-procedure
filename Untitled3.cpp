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

//path[i]=v;  //����v������i�б�ʱ���ö���i��ǰһ������Ϊv
void Dijkstra(MGraph g,int v)        //���v��������������·��
{    /********** Begin **********/
    int dist[MAX_VERTEX_NUM];                //����dist����
    int path[MAX_VERTEX_NUM];                //����path����
    int S[MAX_VERTEX_NUM];                    //����S����
    int min=0,i,j;
  for (i=0;i<g.vexnum ;i++)// ��ʼ�� dist[]  �� path[]     ������path��ֵ�������и�ֵ�ĵط�Ҳͬ������path[i]=v;  //����v������i�б�ʱ���ö���i��ǰһ������Ϊv
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

    Dispdistpath(dist,path,g.vexnum);    //���dist��ʼֵ��path��ʼֵ
    S[v]=1;                            //Դ����v����s��
    for (i=0;i<g.vexnum-1;i++)            //ѭ����S�����n-1������
    {   
        dist[min]=INFINITY;                //mindis����С���ȳ�ֵ
        for (j=0;j<g.vexnum;j++)           
            if(!S[j]&&dist[j]<dist[min])
                min=j;      //ѡȡ����s���Ҿ�����С����Ķ���u
			
		S[min]=1;        //����u����s��
                                          
        for (j=0;j<g.vexnum;j++)           
        { 
            if((!S[j])&&(g.arcs[min][j].adj!=INFINITY)&&(dist[min]+g.arcs[min][j].adj<dist[j]) )
                {
                    dist[j]=dist[min]+g.arcs[min][j].adj;
                    path[j]=min;
                
                }
            
            //�޸Ĳ���s�еĶ���ľ���   ,  ���¡�
        }
        Dispdistpath(dist,path,g.vexnum);  //���distֵ��pathֵ
    }
    DispAllPath(g,dist,path,S,v);        //����������·��������
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
