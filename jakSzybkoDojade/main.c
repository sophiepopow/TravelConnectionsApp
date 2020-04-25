//
//  main.c
//  jakSzybkoDojade
//
//  Created by Sophie Popow on 26/04/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"


/// MARK: - Lines implementation

typedef struct Connection {
    int travelTime;
    int destination;
} Connection;

typedef struct Line {
    int lineNumber;
    int lineLength;
    int startingStation;
    Connection* connections;
} Line;

Line* newLine(int lineNumber, int lineLength, int startingStation) {
    Line* l = (Line *) malloc(sizeof(Line));
    l->lineNumber = lineNumber;
    l->lineLength = lineLength;
    l->startingStation = startingStation;
    l->connections = (Connection *) malloc(lineLength*sizeof(Connection));
    return l;
}

/// MARK: - optimalTimeMatrix - TO DO

int** optimalTimeMatrix(int n){
    int** connectionsMatrix = malloc(n*sizeof(int*));
    
    
    // TO DO
    
    return connectionsMatrix;
}

int main(int argc, const char * argv[]) {
    
    int stations, lines, queries;
    scanf("%d %d %d",&stations, &lines, &queries);
    

    
    return 0;
}
