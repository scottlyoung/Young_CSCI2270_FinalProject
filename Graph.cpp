#include "Graph.h"
#include <queue>
#include <stack>

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

vector<vector<edgeData> > Graph::getGraph()
{
    vector<vector<edgeData> > information;
    for (int i = 0; i < vertices.size(); i++)
    {
        vector<edgeData> vertexInfo;
        vertexInfo.push_back(edgeData(vertices.at(i).name,0));
        for (int j = 0; j < vertices.at(i).edges.size(); j++)
        {
            vertexInfo.push_back(edgeData(vertices.at(i).edges.at(j).destination->name,vertices.at(i).edges.at(j).distance));
        }
        information.push_back(vertexInfo);
    }
    return information;
}

path Graph::getShortestNodePath(string sourceVertex, string destinationVertex)
{
    queue<vertex*> que;
    vertex* endVertex;
    for (int i = 0; i < vertices.size(); i++)
    {
        vertices.at(i).source == NULL;
        if (sourceVertex == vertices.at(i).name)
        {
            que.push(&vertices.at(i));
            vertices.at(i).source = &vertices.at(i);
        }
        if (destinationVertex == vertices.at(i).name)
        {
            endVertex = &vertices.at(i);
        }
    }
    while (! que.empty())
    {
        vertex* working = que.front();
        que.pop();
        for (int i = 0; i < working->edges.size(); i++)
        {
            if ( working->edges.at(i).destination->source == NULL)
            {
                working->edges.at(i).destination->source == working;
                que.push(working->edges.at(i).destination);
            }
        }
    }
    stack<vertex*> route;
    vertex* working = endVertex;
    while (working != working->source)
    {
        route.push(working);
        working = working->source;
    }
    route.push(working);
    path shortestPath;
    shortestPath.distance = 0;
    while (! route.empty())
    {
        working = route.top();
        route.pop();
        shortestPath.path.push_back(working->name);
        for (int i = 0; i < working->edges.size(); i++)
        {
            if ( working->edges.at(i).destination == route.top())
            {
                shortestPath.distance += working->edges.at(i).distance;
            }
        }
    }
    return shortestPath;
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
