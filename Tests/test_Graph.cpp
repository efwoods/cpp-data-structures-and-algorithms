#include <gtest/gtest.h>
#include <iostream>
#include "../Graph/Graph.h"

using namespace std;

TEST(GraphTest, Constructor){
    EXPECT_NO_THROW(Graph* myGraph = new Graph());
}

TEST(GraphTest, AddVertex){
    Graph* graph = new Graph();
    EXPECT_TRUE(graph->addVertex("A"));
}

TEST(GraphTest, PrintGraph){
    Graph* graph = new Graph();
    EXPECT_TRUE(graph->addVertex("A"));
    EXPECT_NO_THROW(graph->printGraph());
}

TEST(GraphTest, addEdge){
    Graph* graph = new Graph();
    graph->addVertex("A");
    graph->addVertex("B");
    EXPECT_TRUE(graph->addEdge("A", "B"));
}

TEST(GraphTest, removeEdge){
    Graph* graph = new Graph();
    graph->addVertex("A");
    graph->addVertex("B");
    graph->addEdge("A", "B");
    EXPECT_TRUE(graph->removeEdge("A", "B"));
}

TEST(GraphTest, removeVertex){
    Graph* graph = new Graph();
    graph->addVertex("A");
    graph->addVertex("B");
    graph->addEdge("A", "B");
    EXPECT_TRUE(graph->removeVertex("A"));
}