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
//define the struct of vertex
//include the id, latitude and longtitude of the vertex
typedef struct{
    long int _id;
    double lat;
    double lon;
}VertexType;

//define the type of edge.
typedef double EdgeType;

//define the type of edgenode
//include the number of vertex, weight of edge and
//the pointer to the next edge
typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

//define the vertextnode
//declare the array of it at the same time as defining it
//include the vertex and the pointer to the edgenode
typedef struct VextexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[10000];

//struct of the whole adjecent list
//include the list and the number of vertices and edges
typedef struct{
    AdjList adjList;
    int vexnum, arcnum;
}MapList;

//input the data into the maplist struct from file
//return 0 if input successfully
//return -1 if anything is wrong
int load_map (FILE *file, MapList *m, char* filename);

//create new edgenode
//simplify the progress of adding data
//return the node of new edge
//return NULL if the creation fails
EdgeNode *create_edge(int adjvex, EdgeType weight);

//check whether the string is illegal or not
//int number is the linenumber of the file,
//if is zero meanings it is not checking the file
//return -1 if the string is illegal
//return 0 if the string is llegal
int _check(char *s, int number);

//return the order of the vertex in the vertex array
//return -1 if the index not found
//return the order of the vertex if found
int index_check(long int i, MapList m);

void print_data(MapList *map);
#endif /* Data_h */
