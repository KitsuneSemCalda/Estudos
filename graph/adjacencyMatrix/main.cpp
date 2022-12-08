#include "common.h"
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

const i64 v = 5;

void printGraph(i64 graph[v][v]){
    cout << "Graph is: " << endl;
    for (i64 j = 0; j < v; j++ ){
        for (i64 i = 0; i < v; i++){
            cout << graph[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    i64 graph[v][v];
    
    for (i64 i = 0; i < v; i++){
        for (i64 j = 0; j < v; j++){
            graph[i][j] = 0;
            if (i == j){
                graph[i][j] = 1;
            }
        }
    }
    
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][4] = 1;
    graph[4][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;

    printGraph(graph);

    return 0;
}
