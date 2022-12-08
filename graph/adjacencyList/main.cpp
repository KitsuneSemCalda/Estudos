#include <iostream>
#include "common.h"
#include <bits/stdc++.h>
#include <algorithm>

using LL = long long;

using namespace std;

const i64 v = 6;

// Adiciona uma indireção entre a fonte e o destino
void add_edge(vector<i64> graph[], i64 source, i64 destination){
    graph[source].push_back(destination);
    graph[destination].push_back(source);
}

void printGraph(vector<i64> graph[]){
     for (i64 source = 0; source < v; source++ ){
        for (i64 neighbour : graph[source]){
            cout << "There is an Edge between: " << source << " and " << neighbour << endl;
        }
     }
}

int main (int argc, char *argv[])
{
    // Declarando a lista de adjancencia
    vector<i64> graph[v];
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 5);
    add_edge(graph, 0, 5);
    add_edge(graph, 3, 5);
    add_edge(graph, 3, 4);
    add_edge(graph, 2, 4);

    printGraph(graph);
    return 0;
}


