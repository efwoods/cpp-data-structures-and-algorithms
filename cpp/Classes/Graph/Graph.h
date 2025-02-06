#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <gtest/gtest.h>

using namespace std;

class Graph {
    private:
        unordered_map<string, unordered_set<string>> adjList;
        FRIEND_TEST(GraphTest, Graph);

    public:
        ~Graph();
        void printGraph();
        bool addVertex(string vertex);
        bool addEdge(string vertex1, string vertex2);
        bool removeEdge(string vertex1, string vertex2);
        bool removeVertex(string vertex);
};