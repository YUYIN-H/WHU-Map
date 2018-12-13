#pragma once

typedef struct ANode
{
	int adjvex;				//该边的邻接点编号
	struct ANode* nextarc;	//指向下一条边的指针
	int dist;				//该边的相关信息：路程
} ArcNode;					        //边结点类型

typedef struct VNode
{
	InfoType info;			//顶点的其他信息:地名
	ArcNode *firstarc;		//指向第一个边结点
} VNode;							//头结点类型

typedef struct
{
	Vnode adjlist[MAXV];	//邻接表的头结点数组
	int n, e;				//图中的顶点数n和边数e
} AdjGraph;							//完整的图邻接表类型