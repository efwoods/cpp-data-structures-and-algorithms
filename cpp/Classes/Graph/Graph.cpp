#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;

void Graph::printGraph(){
    unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
    while(kvPair != adjList.end()){
        cout << kvPair->first << ": [ ";
        unordered_set<string>::iterator edge = kvPair->second.begin();
        while (edge != kvPair->second.end()){
            cout << edge->data() << " ";
            edge++;
        }
        cout << "]" << endl;
        kvPair++;
    }
}

bool Graph::addVertex(string vertex){
    if(adjList.count(vertex) == 0){
        adjList[vertex];
        return true;
    }
    return false;
}

bool Graph::addEdge(string vertex1, string vertex2){
    if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
        adjList.at(vertex1).insert(vertex2);
        adjList.at(vertex2).insert(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(string vertex1, string vertex2){
    if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0){
        adjList.at(vertex1).erase(vertex2);
        adjList.at(vertex2).erase(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeVertex(string vertex){
    if(adjList.count(vertex) != 0){
        auto edgeList = adjList.at(vertex);
        if (!edgeList.empty()){
            for (auto edge : edgeList){
                removeEdge(vertex, edge);
            }
        }
        adjList.erase(vertex);
        return true;
    }
    return false;
}
