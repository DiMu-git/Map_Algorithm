//
//  Data.h
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//
#ifndef DATA__H
#define DATA__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    long int _id;
    double lat;
    double lon;
}VertexType;
typedef double EdgeType;

typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VextexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[10000];
typedef struct{
    AdjList adjList;
    int vexnum, arcnum;
}MapList;

int load_map (FILE *file, MapList m);

int get_details (MapList m,int n);

int search_arc(MapList m, int n);

//int add_edge(MapList m, int index,EdgeNode *e);

EdgeNode *create_edge(int adjvex, EdgeType weight);
//check whether the string is illegal or not
//return -1 if the string is illegal
int _check(char *s);
//return the real id of the vertex
int index_check(long int i, MapList m);
#endif /* Data_h */
