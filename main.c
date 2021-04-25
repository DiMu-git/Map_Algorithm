//
//  main.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include <stdio.h>
#include "Data.h"
#include "Visualization.h"
int main(int argc, const char * argv[]) {
    FILE * file1;
    FILE *file2;
    MapList *map = (MapList*)malloc(sizeof(MapList));
    load_map(file1, map);
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
    out_data(file2, *map);
    return 0;
}
