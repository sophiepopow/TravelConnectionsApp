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

/// MARK: - optimalTimeMatrix

int minTime(int a, int b){
    if(a < b)
        return a;
    return b;
}

int** optimalTimeMatrix(int numberOfStations, int numberOfLines, Line** lines){
    int** connectionsMatrix = malloc(numberOfStations*sizeof(int*));
    for (int i = 0; i < numberOfStations; i++) {
      connectionsMatrix[i] = malloc(numberOfStations*sizeof(int));
    }

    for (int i = 0; i < numberOfStations; i++) {
        for (int j = 0; j < numberOfStations; j++) {
            if (i == j)
                connectionsMatrix[i][j] = 0;
            else
                connectionsMatrix[i][j] = __INT_MAX__/2;
        }
    }
    
    for (int i = 0; i < numberOfLines; i++) {
        Line* line = lines[i];
        int station = line->startingStation;
        
        for (int j = 0; j < line->lineLength; j++) {
            connectionsMatrix[station][line->connections[j].destination] = minTime(line->connections[j].travelTime, connectionsMatrix[station][line->connections[j].destination]);
            
            connectionsMatrix[line->connections[j].destination][station] = minTime(line->connections[j].travelTime, connectionsMatrix[line->connections[j].destination][station]);
            
            station = line->connections[j].destination;
            
        }
    }

    for(int m = 0; m < numberOfStations; m++)
        for(int i = 0; i < numberOfStations; i++)
            for(int j = 0; j < numberOfStations; j++)
                if(connectionsMatrix[i][j] > connectionsMatrix[i][m] + connectionsMatrix[m][j])
                    connectionsMatrix[i][j] = connectionsMatrix[i][m] + connectionsMatrix[m][j];
    
    
    return connectionsMatrix;
}

int main(int argc, const char * argv[]) {
    
/// MARK: - Lines initialization
    
    int stations, lines, queries;
    scanf("%d %d %d",&stations, &lines, &queries);
    
    Line** subwayLines = (Line *) malloc(lines*sizeof(Line));
    
    for (int i = 0; i < lines; i++) {
        int lineLength, lineStart;
        scanf("%d %d", &lineLength, &lineStart);
        
        // lineLength - 1 beacuse we don't count starting station
        subwayLines[i] = newLine(i, lineLength-1, lineStart);
        
        for (int j = 0; j < lineLength-1; j++) {
            int travelTime, nextStation;
            scanf("%d %d", &travelTime, &nextStation);
            subwayLines[i]->connections[j].travelTime = travelTime;
            subwayLines[i]->connections[j].destination = nextStation;

        }
    }
    
    int** shortestTravelTime = optimalTimeMatrix(stations, lines, subwayLines);
    
/// MARK: - Queries
    
    int startingPoint, finalPoint;
    for (int i = 0; i < queries; i++) {
        scanf("%d %d", &startingPoint, &finalPoint);
        printf("%d\n", shortestTravelTime[startingPoint][finalPoint]);
    }

 /// MARK: - Free memory
    
    for(int i = 0; i<lines; i++) {
        free(subwayLines[i]->connections);
        free(subwayLines[i]);
        
    }
    free(subwayLines);
    
    for(int i = 0; i<stations; i++) {
        free(shortestTravelTime[i]);
    }
    free(shortestTravelTime);
    
    return 0;
}
