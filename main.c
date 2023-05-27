#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "graph.h"

int main() {
    FILE *file = fopen("graph.txt", "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }


//    GRAPH_AM graphAdjMatrix = createGraphAdjMatrix(file);
//
//    int visited[graphAdjMatrix.numberOfNodes];
//    for(int i=1;i<graphAdjMatrix.numberOfNodes;i++)
//        visited[i]=NOTVISITED;

//    bfsAdjMatrix(graphAdjMatrix, 1);
//    dfsAdjMatrix(graphAdjMatrix,1);
//    dfsAdjMatrixRecursive(graphAdjMatrix,1,visited);

//    GRAPH_DL graphDynamicList = createGraphDynamicList(file);

//    int visited[graphDynamicList.numberOfNodes];
//    for(int i=1;i<graphDynamicList.numberOfNodes;i++)
//        visited[i]=NOTVISITED;

//    bfsDynamicList(graphDynamicList,1);
//    dfsDynamicList(graphDynamicList,1);
//    dfsDynamicListRecursive(graphDynamicList,1,visited);

    fclose(file);

    return 0;
}
