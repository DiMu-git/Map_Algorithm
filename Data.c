//
//  Data.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include "Data.h"
int _check(char * s){
    for(int i=0; s[i]!='\0'; i++){
        if(!('0'<s[i]||s[i]<'9')){
            return -1;
        }
    }
    return 0;
}
EdgeNode *create_edge(int adjecx, EdgeType weight){
    EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = adjecx;
    e->weight = weight;
    e->next = NULL;
    return e;
}
//int add_edge(MapList m, int index,EdgeNode *e){
//    EdgeNode *p = m.adjList[index].firstedge;
//    if(p==NULL){
//        m.adjList[index].firstedge = e;
//        return 0;
//    }
//    else{
//        m.adjList[index].firstedge = e;
//        e->next = p;
//        }
//    return -1;
//}
int index_check(long int i, MapList m){
    for(int j = 0; j<m.vexnum;j++){
        if(i == m.adjList[j].data._id) return j;
    }
    return -1;
}
int load_map(FILE * file, MapList m){
    char * line;
    char * head;
    char * id;
    char * data;
    int count = 0;
    int index1 = 0;
    int index2 = 0;
    EdgeType length =0;
    head = malloc(5*sizeof(char));
    line = malloc(1000*sizeof(char));
    id = malloc(10*sizeof(char));
    data = malloc(10*sizeof(char));
    //open file
    file = fopen("/Users/mudi/Desktop/Final_Map\(1\).map", "r");
    if(file==NULL){
        printf("File opening error");
        return -1;
    }
    
    //haven't check the data yet
    m.arcnum=0;
    m.vexnum=0;
    while(fgets(line, 1000, file)!=NULL){
        sscanf(line, "%[^ ]",head);
        if(!strcmp(head,"<node")){
            sscanf(line, "%*[^=]=%[^ ]",id);
            m.adjList[count].data._id = atoi(id);
            sscanf(line, "%*[^=]=%*[^=]=%[^ ]",data);
            m.adjList[count].data.lat = atof(data);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%[^ ]",data);
            m.adjList[count].data.lon = atof(data);
            m.adjList[count].firstedge = NULL;
            m.vexnum++;
            count++;
        }
    }
    rewind(file);
    while(fgets(line, 1000, file)!=NULL){
        sscanf(line, "%[^ ]",head);
        if(!strcmp(head,"<link")){
            sscanf(line, "%*[^=]=%*[^=]=%[^ ]",id);
            index1 = index_check(atoi(id), m);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%[^ ]",id);
            index2 = index_check(atoi(id), m);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%*[^=]=%*[^=]=%[^ ]",data);
            length = atof(data);
            EdgeNode *newedge1 =create_edge(index1, length);
            EdgeNode *newedge2 =create_edge(index2, length);
//            add_edge(m, index1, newedge1);
//            add_edge(m, index2, newedge2);
            if(m.adjList[index1].firstedge==NULL) m.adjList[index1].firstedge = newedge1;
            else{
                EdgeNode *p = m.adjList[index1].firstedge;
                m.adjList[index1].firstedge=newedge1;
                m.adjList[index1].firstedge->next=p;
            }
            if(m.adjList[index2].firstedge==NULL) m.adjList[index2].firstedge = newedge2;
            else{
                EdgeNode *p = m.adjList[index2].firstedge;
                m.adjList[index2].firstedge=newedge2;
                m.adjList[index2].firstedge->next=p;
            }
            
            m.arcnum++;
        }
    }
//    for(int i=0; i<m.vexnum;i++){
//        EdgeNode *p;
//        p=m.adjList[i].firstedge;
//        printf("Vex%i Id:%li Linked:",i,m.adjList[i].data._id);
//        if(p==NULL){
//            printf("NULL\n");
//            continue;
//        }
//        while(p->next!=NULL){
//            printf("With vex%i Length:%lfm ",p->adjvex,p->weight);
//            p=p->next;
//        }
//        printf("With vex%i Length:%lfm ",p->adjvex,p->weight);
//        printf("\n");
//    }
//    printf("%i\n",m.arcnum);
    fclose(file);
    return 0;
}
