// includes
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


int main() // this serves as a driver to demonstrate the graph class
{
    // declare the graph object
    cout << "Creating graph object...";
    Graph graph;
    cout << " Finished" << endl;
    // create vertices in graph
    cout << "Creating vertices...";
    graph.createVertex("Location 1");
    graph.createVertex("Location 2");
    graph.createVertex("Location 3");
    graph.createVertex("Location 4");
    graph.createVertex("Location 5");
    graph.createVertex("Location 6");
    graph.createVertex("Location 7");
    graph.createVertex("Location 8");
    graph.createVertex("Location 9");
    cout << " Finished" << endl;
    // create edges between the vertices
    cout << "Creating edges... ";
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
    graph.createEdge("Location 2", "Location 1", 55);
    graph.createEdge("Location 4", "Location 1", 2);
    graph.createEdge("Location 3", "Location 2", 33);
    graph.createEdge("Location 4", "Location 3", 5);
    graph.createEdge("Location 5", "Location 3", 10);
    graph.createEdge("Location 7", "Location 3", 40);
    graph.createEdge("Location 5", "Location 4", 60);
    graph.createEdge("Location 6", "Location 5", 17);
    graph.createEdge("Location 9", "Location 5", 9);
    graph.createEdge("Location 7", "Location 6", 11);
    graph.createEdge("Location 8", "Location 6", 3);
    graph.createEdge("Location 8", "Location 7", 6);
    cout << " Finished" << endl;
    // run and store results of getGraph
    cout << "Getting graph data... " << endl;
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
    cout << "Deleting an edge...";
    graph.deleteEdge("Location 6", "Location 7");
    cout << " Finished" << endl;
    // delete a vertex
    cout << "Deleting a vertex...";
    graph.deleteVertex("Location 9");
    cout << " Finished" << endl;
    // show the changes after delete using getGraph()
    cout << "Getting graph data... " << endl;
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
    cout << "Getting shortest node path..." << endl;
    path shortestPath = graph.getShortestNodePath("Location 1", "Location 5");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    cout << "distance: " << shortestPath.distance << endl;
    // run and store results of getShortestDistancePathDijikstras()
    cout << "Getting shortest path using Dijikstras..." << endl;
    shortestPath = graph.getShortestDistancePathDijikstras("Location 1","Location 8");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    cout << "distance: " << shortestPath.distance << endl;
    /*
    // run and store results of getShortestVisitAllExhaustive()
    cout << "Getting shortest path that visits all nodes" << endl;
    shortestPath = graph.getShortestVisitAllExhaustive("Location 1");
    // output stored path information
    for (int i = 0; i < shortestPath.path.size(); i++)
    {
        cout << shortestPath.path.at(i) << endl;
    }
    cout << "distance: " << shortestPath.distance << endl;
    */
    return 0;
}
