//
//  Algorithm.h
//  Debug
//
//  Created by 穆迪 on 2021/4/26.
//

#ifndef Algorithm_h
#define Algorithm_h

#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

//
void Dijkstra(int x, int y, MapList m, FILE *file);

void printRoad(int path[], int y, FILE *file,MapList m);

#endif /* Algorithm_h */
