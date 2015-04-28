// includes
#include <iostream>
#include <vector>
#include "Graph.h"
#include "driverFunctions.h"

using namespace std;


int main() // this serves as a driver to demonstrate the graph class
{
    Graph* graph = new Graph; // declare graph object
    bool running = true;
    while (running)
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Pre-made setup: Normal" << endl;
        cout << "2. Pre-made setup: No cycles" << endl;
        cout << "3. Pre-made setup: Negative weight" << endl;
        cout << "4. Create a Vertex" << endl;
        cout << "5. Create an Edge" << endl;
        cout << "6. Delete Vertex" << endl;
        cout << "7. Delete Edge" << endl;
        cout << "8. Display Graph" << endl;
        cout << "9. Shortest Node path" << endl;
        cout << "10. Dijkstra's Algorithm" << endl;
        cout << "11. Bellman-Ford Algorithm" << endl;
        cout << "12. DAG Algorithm" << endl;
        cout << "13. Shortest Visit All" << endl;
        cout << "14. Longest Visit All" << endl;
        cout << "15. Quit" << endl;
        string input = getInput();
        if (stoi(input) == 1)
        {
            graph->~Graph();
            graph = new Graph;
            graph->createVertex("Location 1");
            graph->createVertex("Location 2");
            graph->createVertex("Location 3");
            graph->createVertex("Location 4");
            graph->createVertex("Location 5");
            graph->createVertex("Location 6");
            graph->createVertex("Location 7");
            graph->createVertex("Location 8");
            graph->createEdge("Location 1", "Location 2", 50);
            graph->createEdge("Location 1", "Location 4", 5);
            graph->createEdge("Location 2", "Location 3", 37);
            graph->createEdge("Location 3", "Location 4", 3);
            graph->createEdge("Location 3", "Location 5", 7);
            graph->createEdge("Location 3", "Location 7", 44);
            graph->createEdge("Location 4", "Location 5", 64);
            graph->createEdge("Location 5", "Location 6", 19);
            graph->createEdge("Location 6", "Location 7", 9);
            graph->createEdge("Location 6", "Location 8", 1);
            graph->createEdge("Location 7", "Location 8", 8);
            graph->createEdge("Location 2", "Location 1", 55);
            graph->createEdge("Location 4", "Location 1", 2);
            graph->createEdge("Location 3", "Location 2", 33);
            graph->createEdge("Location 4", "Location 3", 5);
            graph->createEdge("Location 5", "Location 3", 10);
            graph->createEdge("Location 7", "Location 3", 40);
            graph->createEdge("Location 5", "Location 4", 60);
            graph->createEdge("Location 6", "Location 5", 17);
            graph->createEdge("Location 7", "Location 6", 11);
            graph->createEdge("Location 8", "Location 6", 3);
            graph->createEdge("Location 8", "Location 7", 6);
        }
        else if (stoi(input) == 2)
        {
            graph->~Graph();
            graph = new Graph;
            graph->createVertex("Location 1");
            graph->createVertex("Location 2");
            graph->createVertex("Location 3");
            graph->createVertex("Location 4");
            graph->createVertex("Location 5");
            graph->createVertex("Location 6");
            graph->createVertex("Location 7");
            graph->createEdge("Location 1","Location 2", 10);
            graph->createEdge("Location 2","Location 3", 10);
            graph->createEdge("Location 3","Location 4", 15);
            graph->createEdge("Location 1","Location 4", 17);
            graph->createEdge("Location 4","Location 6", 12);
            graph->createEdge("Location 3","Location 5", 7);
            graph->createEdge("Location 5","Location 7", 21);
            graph->createEdge("Location 6","Location 7", 13);
        }
        else if (stoi(input) == 3)
        {

        }
        else if (stoi(input) == 4)
        {
            cout << "Vertex Name:";
            input = getInput();
            graph->createVertex(input);
        }
        else if (stoi(input) == 5)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            cout << "Edge Weight:";
            int input3 = stoi(getInput());
            graph->createEdge(input, input2, input3);
        }
        else if (stoi(input) == 6)
        {
            cout << "Vertex Name:";
            input = getInput();
            graph->deleteVertex(input);
        }
        else if (stoi(input) == 7)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            graph->deleteEdge(input, input2);
        }
        else if (stoi(input) == 8)
        {
            outputGraph(graph->getGraph());
        }
        else if (stoi(input) == 9)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            outputPath(graph->getShortestNodePath(input, input2));
        }
        else if (stoi(input) == 10)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            outputPath(graph->getShortestDistancePathDijikstras(input, input2));
        }
        else if (stoi(input) == 11)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            outputPath(graph->getShortestDistancePathBellmanFord(input, input2));
        }
        else if (stoi(input) == 12)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            cout << "End Vertex Name:";
            string input2 = getInput();
            outputPath(graph->getShortestDistancePathDAG(input, input2));
        }
        else if (stoi(input) == 13)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            outputPath(graph->getShortestVisitAllExhaustive(input));
        }
        else if (stoi(input) == 14)
        {
            cout << "Source Vertex Name:";
            input = getInput();
            outputPath(graph->getLongestDistanceVisitAllExhaustive(input));
        }
        else if (stoi(input) == 15)
        {
            running = false;
        }
    }
    return 0;
}
