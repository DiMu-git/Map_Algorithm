//
//  Algorithm.c
//  Debug
//
//  Created by 穆迪 on 2021/4/26.
//

#include "Algorithm.h"

void Dijkstra(int x, int y, MapList m, FILE *file){
    file = fopen("/Users/mudi/Desktop/out.txt", "w");
    int i,j,k;
    int min;
    int u = -1;
    EdgeType dis[m.vexnum];
    int mark[m.vexnum];
    int path[m.vexnum];
    //initialize the shortest path
    
    for(i=0; i<m.vexnum; i++){
        EdgeNode *p = m.adjList[x].firstedge;
        mark[i] = 0;
        dis[i] = 999;
        path[i] = -1;
        while(p!=NULL){
        if(i==p->adjvex)
            dis[i] =p->weight;
            p=p->next;
        }
    }
    mark[x]=1;
    for(k=0; k<m.vexnum; k++){
        min = 999;
        for(i=0; i<m.vexnum; i++){
            if(mark[i]==0&&min>dis[i]){
                min = dis[i];
                u=i;
            }
        }
        if(u==-1) break;
        
        mark[u] = 1;
        
        for(i =0; i<m.vexnum;i++){
            EdgeNode *p = m.adjList[u].firstedge;
            while(p!=NULL){
                if(p->adjvex==i&&!mark[i]&&dis[i]>dis[u]+p->weight){
                    dis[i] = dis[u] + p->weight;
                    path[i]=u;
                }
                p=p->next;
                }
        }
    }
    
    printf("最短路径值为:%lf\n",dis[y]);
    printf("依次经过的路径为:");
    printf("%i ",x);
    printRoad(path, y,file,m);
    fclose(file);
}


void printRoad(int path[], int target, FILE *file,MapList m){
    
    if (path[target] == -1){
        printf("%i ",target);
        return;
    }
    
    printRoad(path, path[target],file,m);
    
    printf("%i ",path[target]);
    fprintf(file, "%lf %lf\n",m.adjList[path[target]].data.lon,m.adjList[path[target]].data.lat);
    printf("%i        ",target);
    fprintf(file, "%lf %lf\n",m.adjList[target].data.lon,m.adjList[target].data.lat);
    fprintf(file, "\n");
}
