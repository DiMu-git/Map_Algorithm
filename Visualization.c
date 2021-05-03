//
//  Visualization.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include "Visualization.h"
int out_data(FILE *file, MapList m,char* filename){
    file = fopen(filename, "w");
    if(file==NULL) {
        printf("Can't find file!\n");
        return -1;
    }
    for(int i=0;i<m.vexnum;i++){
        if(m.adjList[i].firstedge!=NULL){
            EdgeNode *p = m.adjList[i].firstedge;
            while(p!=NULL){
                fprintf(file, "%lf %lf\n",m.adjList[i].data.lon,m.adjList[i].data.lat);
        fprintf(file, "%lf %lf\n",m.adjList[p->adjvex].data.lon,m.adjList[p->adjvex].data.lat);
                fprintf(file, "\n");
                p=p->next;
        }
    }
    }
    return 0;
}




