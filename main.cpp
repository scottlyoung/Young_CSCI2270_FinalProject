// includes
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main() // this serves as a driver to demonstrate the graph class
{
    // declare the graph object
    Graph graph;
    // create vertices in graph
    graph.createVertex("Location 1");
    graph.createVertex("Location 2");
    graph.createVertex("Location 3");
    graph.createVertex("Location 4");
    graph.createVertex("Location 5");
    graph.createVertex("Location 6");
    graph.createVertex("Location 7");
    graph.createVertex("Location 8");
    graph.createVertex("Location 9");
    // create edges between the vertices
    graph.createEdge("Location 1", "Location 2", 50);
    graph.createEdge("Location 1", "Location 4", 5);
    graph.createEdge("Location 2", "Location 3", 37);
    graph.createEdge("Location 3", "Location 4", 3);
    graph.createEdge("Location 3", "Location 5", 7);
    graph.createEdge("Location 3", "Location 7", 44);
    graph.createEdge("Location 4", "Location 5", 64);
    graph.createEdge("Location 5", "Location 6", 19);
    graph.createEdge("Location 5", "Location 9", 11);
    graph.createEdge("Location 6", "Location 7", 9);
    graph.createEdge("Location 6", "Location 8", 1);
    graph.createEdge("Location 7", "Location 8", 8);
    // run and store results of getGraph
    vector<vector<edgeData> > graphData = graph.getGraph();
    // output stored graph information
    for (int i = 0; i < graphData.size(); i++)
    {
        cout << graphData.at(i).at(0).name << "-->";
        for (int j = 1; j < graphData.at(i).size(); j++)
        {
            cout << graphData.at(i).at(j).name << ":" << graphData.at(i).at(j).distance << "***";
        }
        cout << endl;
    }
    // delete an edge
    graph.deleteEdge("Location 6", "Location 7");
    // delete a vertex
    graph.deleteVertex("Location 9");
    // show the changes after delete using getGraph()
    graphData = graph.getGraph();
    for (int i = 0; i < graphData.size(); i++)
    {
        cout << graphData.at(i).at(0).name << "-->";
        for (int j = 1; j < graphData.at(i).size(); j++)
        {
            cout << graphData.at(i).at(j).name << ":" << graphData.at(i).at(j).distance << "***";
        }
        cout << endl;
    }
    // run and store results of getShortestNodePath
    path shortestPath = graph.getShortestNodePath("Location 1", "Location 5");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    // run and store results of getShortestDistancePathDijikstras()
    shortestPath = graph.getShortestDistancePathDijikstras("Location 1","Location 8");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    cout << "distance: " << shortestPath.distance << endl;
    // run and store results of getShortestVisitAllExhaustive()
    shortestPath = graph.getShortestVisitAllExhaustive("Location 1");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    cout << "distance: " << shortestPath.distance << endl;
    return 0;
}
