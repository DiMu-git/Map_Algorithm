//
//  Data.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include "Data.h"
int _check(char * s, int number){
    for(int i=0; s[i]!='\0'; i++){
//        if(!('0'<s[i]||s[i]<'9'||s[i]=='.'||s[i]=='-')){
        if(!(s[i]>='0'&&s[i]<='9')){
            if(s[i]=='-'||s[i]=='.') continue;
            if(number!=0)
                printf("Data invalid! The invalid number is at line %d\n",number);
            else
                printf("Input invalid! The input should contain number only\n");
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

int index_check(long int i, MapList m){
    for(int j = 0; j<m.vexnum;j++){
        if(i == m.adjList[j].data._id) return j;
    }
    return -1;
}
int load_map(FILE * file, MapList *m, char* filename){
    char * line;
    char * head;
    char * id;
    char * data;
    int count = 0;
    int index1 = 0;
    int index2 = 0;
    int linenumber = 0;
    EdgeType length =0;
    head = malloc(5*sizeof(char));
    line = malloc(1000*sizeof(char));
    id = malloc(10*sizeof(char));
    data = malloc(10*sizeof(char));
    //open file
    file = fopen(filename, "r");
    if(file==NULL){
        printf("File opening error");
        return -1;
    }
    
    //haven't check the data yet
    m->arcnum=0;
    m->vexnum=0;
    while(fgets(line, 1000, file)!=NULL){
        sscanf(line, "%[^ ]",head);
        if(!strcmp(head,"<node")){
            sscanf(line, "%*[^=]=%[^ ]",id);
            if(_check(id,linenumber)==-1) return -1;
            m->adjList[count].data._id = atoi(id);
            sscanf(line, "%*[^=]=%*[^=]=%[^ ]",data);
            if(_check(data,linenumber)==-1) return -1;
            m->adjList[count].data.lat = atof(data);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%[^ ]",data);
            if(_check(data,linenumber)==-1) return -1;
            m->adjList[count].data.lon = atof(data);
            m->adjList[count].firstedge = NULL;
            m->vexnum++;
            count++;
        }
        linenumber++;
    }
    rewind(file);
    linenumber = 1;
    while(fgets(line, 1000, file)!=NULL){
        sscanf(line, "%[^ ]",head);
        if(!strcmp(head,"<link")){
            sscanf(line, "%*[^=]=%*[^=]=%[^ ]",id);
            if(_check(id,linenumber)==-1) return -1;
            index1 = index_check(atoi(id), *m);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%[^ ]",id);
            if(_check(id,linenumber)==-1) return -1;
            index2 = index_check(atoi(id), *m);
            sscanf(line, "%*[^=]=%*[^=]=%*[^=]=%*[^=]=%*[^=]=%[^ ]",data);
            if(_check(data,linenumber)==-1) return -1;
            length = atof(data);
            EdgeNode *newedge1 =create_edge(index1, length);
            EdgeNode *newedge2 =create_edge(index2, length);
            if(m->adjList[index1].firstedge==NULL) m->adjList[index1].firstedge = newedge2;
            else{
                EdgeNode *p = m->adjList[index1].firstedge;
                m->adjList[index1].firstedge=newedge2;
                m->adjList[index1].firstedge->next=p;
            }
            if(m->adjList[index2].firstedge==NULL) m->adjList[index2].firstedge = newedge1;
            else{
                EdgeNode *p = m->adjList[index2].firstedge;
                m->adjList[index2].firstedge=newedge1;
                m->adjList[index2].firstedge->next=p;
            }
            
            m->arcnum++;
        }
        linenumber++;
    }
    return 0;
}

void print_data(MapList *map){
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
    printf("number of edges: %i\n",map->arcnum);
    printf("number of points: %i\n",map->vexnum);
}
