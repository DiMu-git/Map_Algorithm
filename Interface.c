//
//  Interface.c
//  cw2
//
//  Created by 穆迪 on 2021/4/18.
//

#include "Interface.h"
char *answer;
char *filename;
FILE *filein;
FILE *fileout;
FILE *fileresult;

char* askquestion(char *question)
{
    printf("%s",question);

    const int size_step = 2;
    char *answer = malloc(size_step);
    answer[0] = 0; //now it's a string of length 0.

    //read until a new line in blocks of size_step  bytes at at time
    char *next_chunk = answer;
    int iteration = 0;
    do {
        answer = realloc(answer, size_step + iteration*size_step);
        next_chunk = answer + strlen(answer); //answer may have moved.
        fgets(next_chunk, size_step, stdin);

        next_chunk = answer + strlen(answer); //take the new read into account
        ++iteration;
    } while (* (next_chunk-1) != '\n');

    *(next_chunk-1) = 0; //truncate the string eliminating the new line.
    return answer;
}


void main_interface(){
    MapList *map = (MapList*)malloc(sizeof(MapList));
    answer = (char*)malloc(sizeof(char));
    printf("Welcome to the system!\n");
    while(1){
    answer = askquestion("Please choose the option:\n 1)Load map\n 2)Show data\n 3)Output the map\n 4)Obtain the shortest path\n 5)Quit\nOption:");
        if(!strcmp(answer, "1")){
            filename = askquestion("Please input the filename/path of the map file:");
            if(load_map(filein, map,filename)==-1) continue;
            else
                printf("Load successfully!\n");
        }
        else if (!strcmp(answer, "2")){
            print_data(map);
        }
        else if (!strcmp(answer, "3")){
            filename = askquestion("Please input the filename/path of the out file:");
            if(out_data(fileout, *map,filename)==-1) continue;
            else printf("File formed, please use gnuplot or other tools to draw the map.\n");
        }
        else if (!strcmp(answer, "4")){
            char *x = askquestion("Please choose the start point x:");
            if(_check(x, 0)==-1) continue;
            char *y = askquestion("Please choose the end point y:");
            if(_check(y, 0)==-1) continue;
            if(!strcmp(x, y)){
                printf("The points should not be the same\n");
                continue;
            }
            int x_ = atoi(x);
            int y_ = atoi(y);
            Dijkstra(x_, y_,*map, fileresult);
            getchar();
        }
        else if(!strcmp(answer, "5")){
            printf("Thanks for using");
            return;
        }
        else{
            printf("Wrong input, please try again\n");
            continue;
        }
    }
    
    
}

