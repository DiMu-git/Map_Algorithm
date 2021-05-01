//
//  main.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include <stdio.h>
#include "Data.h"
#include "Visualization.h"
#include "Algorithm.h"
int main(int argc, const char * argv[]) {
    FILE *filein;
    FILE *fileout;
    FILE *fileresult;
    MapList *map = (MapList*)malloc(sizeof(MapList));
    load_map(filein, map);
    for(int i=0; i<map->vexnum;i++){
        EdgeNode *p;
        p=map->adjList[i].firstedge;
        printf("Vex%i Id:%li Linked:",i,map->adjList[i].data._id);
        if(p==NULL){
            printf("NULL\n");
            continue;
        }
        while(p->next!=NULL){
            printf("With vex%i Length:%lfm ",p->adjvex,p->weight);
            p=p->next;
        }
        printf("With vex%i Length:%lfm ",p->adjvex,p->weight);
        printf("\n");
    }
    printf("%i\n",map->arcnum);
    out_data(fileout, *map);
    printf("Please input the start point and the end point:");
    int x,y;
    scanf("%i %i",&x,&y);
    Dijkstra(x, y,*map, fileresult);
    
    return 0;
}
