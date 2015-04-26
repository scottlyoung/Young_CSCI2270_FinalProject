#include "Graph.h"

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::createVertex(string name) //creates a vertex
{
    vertices.push_back(vertex(name));
}

void Graph::createEdge(string nameSource, string nameDestination, int distance) //creates a one way edge
{
    vertex* destination; // stores pointer for destination vertex
    for (int i = 0; i < vertices.size(); i++) // finds destination vertex
    {
        if (nameDestination == vertices.at(i).name)
        {
            destination = &vertices.at(i); // stores pointer to destination vertex
        }
    }
    for (int i = 0; i < vertices.size(); i++) // finds source vertex
    {
        if (nameSource == vertices.at(i).name)
        {
            vertices.at(i).edges.push_back(edge(destination, distance)); // creates the edge
        }
    }
}

void Graph::deleteVertex(std::string)
{

}

void Graph::deleteEdge(std::string,std::string)
{

}

std::vector<std::vector<edgeData> > Graph::getGraph()
{

}

path Graph::getShortestNodePath(std::string,std::string)
{

}

path Graph::getShortestDistancePathDijikstras(std::string,std::string)
{

}

path Graph::getShortestVisitAllExhaustive(std::string)
{

}

std::vector<path> Graph::getLongestNodeVisitAllExhuastive(std::string)
{

}

path Graph::getLongestDistanceVisitAllExhaustive(std::string)
{

}
