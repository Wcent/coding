// dijkstra.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int dijkstra(int (*graphy)[8], int vertexs, int s_v, int e_v, int *path);

int _tmain(int argc, _TCHAR* argv[])
{
	int g[8][8];
	memset(g, -1, sizeof(int)*8*8);
	g[0][0] = 0, g[1][1] = 0, g[2][2] = 0, g[3][3] = 0;
	g[4][4] = 0, g[5][5] = 0, g[6][6] = 0, g[7][7] = 0;
	g[1][2] = 3, g[2][1] = 3;
	g[1][6] = 1, g[6][1] = 1;
	g[2][3] = 2, g[3][2] = 2;
	g[2][4] = 1, g[4][2] = 1;
	g[3][4] = 3, g[4][3] = 3;
	g[3][5] = 1, g[5][3] = 1;
	g[3][6] = 1, g[6][3] = 1;
	g[3][7] = 3, g[7][3] = 3;
	g[4][5] = 1, g[5][4] = 1;
	g[5][7] = 2, g[7][5] = 2;

	int p[8];
	int s = 2;
	int e;
	int path;
	for(e=1; e<8; e++)
	{
		path = dijkstra(g, 8, s, e, p);
		if(path != -1)
		{
			cout<<"shortest path, from "<<s<<" to "<<e<<" is: "<<path<<endl;
			cout<<"path: ";
			for(int i=e; p[i] != -1; i=p[i])
				cout<<i<<"<--";
			cout<<s<<endl<<endl;
		}
		else
			cout<<"shortest path, from "<<s<<" to "<<e<<" is not exist."<<endl<<endl;
	}

	return 0;
}


// 最短路径：~ Dijkstra, dist[j] = min{dist[j], dist[i]+graphy[i][j]}
// ~ graphy: G = (V, E), V：顶点集, E: 边集
// ~ e ∈ E & e > 0表示顶点邻接，权值为e, e = -1表示两顶点不邻接
// ~
int dijkstra(int (*graphy)[8], int vertexs, int s_v, int e_v, int *path)
{
	int *dist; //起点到各终点的最短路径
	int *vis;  //已访问过的顶点
	int num;
	int min, k;
	
	dist = new int[vertexs];
	vis = new int [vertexs];

	//初始化，-1代表max_value
	memset(dist, -1, sizeof(int)*vertexs);
	//起点到终点最短距离为0
	dist[s_v] = 0;
	memset(vis, 0, sizeof(int)*vertexs);
	memset(path, -1, sizeof(int)*vertexs);
	num = vertexs-1;
	while(num)
	{
		//贪心策略：从访问过的顶点中，找出最短路径，从已知的最短路径开始延伸
		min = -1;
		k = -1;
		for(int i=0; i<vertexs; i++)
		{
			if(vis[i] != 1 && dist[i] != -1 &&
				(min != -1 && dist[i] < min || min == -1))
			{
				min = dist[i];
				k = i;
			}
		}

		//终点最短路径已找到或所有顶点最短路径都已找到
		if(e_v == k || min == -1)
			break;
		//标记访问过的顶点
		vis[k] = 1;
		num--;
		
		//dist[j] = min{d[j], dist[i]+graphy[i][j]}
		//更新未访问过邻接顶点的最短路径
		for(int i=0; i<vertexs; i++)
		{
			if(vis[i] != 1 && graphy[k][i] != -1 &&
			   (dist[i] != -1 && dist[i] > min + graphy[k][i] || dist[i] == -1))
			{
				dist[i] = min + graphy[k][i];
				path[i] = k; //更新记录前驱顶点，供最后回溯最短路径
			}
		}
	}
	min = dist[e_v];
	delete [] dist;
	delete [] vis;
	return min;
}

