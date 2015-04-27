#include "Graph.h"
#include <queue>
#include <stack>
#include <iostream>
#include <climits>

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

void Graph::deleteVertex(string vertexName)
{
    int vertexLoc;
    for (int i = 0; i< vertices.size(); i++) // goes though all vertices
    {
        if (vertices.at(i).name != vertexName) // skips the vertex to be deleted
        {
            for (int j = 0; j < vertices.at(i).edges.size(); j++) // searches the current vertex for edges to the vertex to be deleted
            {
                if (vertices.at(i).edges.at(j).destination->name == vertexName)
                {
                    vertices.at(i).edges.erase(vertices.at(i).edges.begin() + j); // deletes the edge
                }
            }
        }
        else
        {
            vertexLoc = i; // stores location of vertex to be deleted
        }
    }
    vertices.erase(vertices.begin() + vertexLoc); // deletes vertex
}

void Graph::deleteEdge(string startVertex, string endVertex) // deletes an edge
{
    for (int i = 0; i < vertices.size(); i++) // searches for the start vertex
    {
        if (vertices.at(i).name == startVertex)
        {
            for (int j = 0; j < vertices.at(i).edges.size(); j++) // searches the start vertex for edges to the end vertex
            {
                if (vertices.at(i).edges.at(j).destination->name == endVertex)
                {
                    vertices.at(i).edges.erase(vertices.at(i).edges.begin() + j); // deletes the edge
                }
            }
        }
    }
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

path Graph::getShortestNodePath(string sourceVertex, string destinationVertex) // gets the shortest path from the start vertex to the end vertex, by vertex traversals
{
    queue<vertex*> que; // declares a queue to store vertex
    vertex* endVertex; // variable to store end vertex
    for (int i = 0; i < vertices.size(); i++) // goes through each vertex to set up initial conditions
    {
        vertices.at(i).visited = false;
        vertices.at(i).source = NULL;
        if (sourceVertex == vertices.at(i).name) // checks if the vertex is the starting vertex
        {
            que.push(&vertices.at(i));
            vertices.at(i).visited = true;
        }
        if (destinationVertex == vertices.at(i).name) // checks if the vertex is the ending vertex
        {
            endVertex = &vertices.at(i);
        }
    }
    while (! que.empty()) // proceeds through the queue
    {
        vertex* working = que.front(); // gets the value in the front of the queue
        que.pop();
        for (int i = 0; i < working->edges.size(); i++) // sets unnassigned vertices to have the current vertex as their source
        {
            if ( working->edges.at(i).destination->visited == false)
            {
                working->edges.at(i).destination->visited = true;
                working->edges.at(i).destination->source = working;
                que.push(working->edges.at(i).destination);
                //cout << working->name << " to " << working->edges.at(i).destination->name << endl; // debug line
            }
        }
    }
    stack<vertex*> route; // creates a stack to flip the order in
    vertex* working = endVertex;
    while (working != NULL) // goes from end to start, putting all vertices on the stack
    {
        route.push(working);
        //cout << working << endl; // debug line
        //cout << working->name << endl; // debug line
        working = working->source;
    }
    path shortestPath;
    shortestPath.distance = 0;
    while (! route.empty()) // goes through stack, removing vertices and putting them into path vertex, also calculates distance
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

path Graph::getShortestDistancePathDijikstras(string startVertex,string endVertex)
{
    vertex* startPoint;
    vertex* endPoint;
    vector<vertex*> solved;
    for (int i = 0; i <vertices.size(); i++) // goes through all vertices to establish inital conditions and find start and end vertices
    {
        vertices.at(i).visited = false;
        vertices.at(i).source = NULL;
        vertices.at(i).distance = INT_MAX;
        if (vertices.at(i).name == startVertex) // checks for start vertex
        {
            vertices.at(i).distance = 0;
            vertices.at(i).visited = true;
            solved.push_back(&vertices.at(i));
            startPoint = &vertices.at(i);
        }
        if (vertices.at(i).name == endVertex) // checks for end vertex
        {
            endPoint = &vertices.at(i);
        }
    }
    while(! endPoint->visited) // runs till solution for end vertex has been found
    {
        for (int i = 0; i < solved.size(); i++) // goes through each solved vertex
        {
            for (int j = 0; j < solved.at(i)->edges.size(); j++) // goes through all edges for current vertex
            {
                if ( (! solved.at(i)->edges.at(j).destination->visited) && ((solved.at(i)->edges.at(j).destination->distance > solved.at(i)->distance + solved.at(i)->edges.at(j).distance) ) ) // checks and updates distance for the vertex that the edge goes to
                    {
                        solved.at(i)->edges.at(j).destination->distance = solved.at(i)->distance + solved.at(i)->edges.at(j).distance;
                        solved.at(i)->edges.at(j).destination->source = solved.at(i);
                    }
            }
        }
        vertex* minVertex = NULL;
        for (int i = 0; i < vertices.size(); i++) // finds the lowest distance unsolved vertex
        {
            if (! vertices.at(i).visited)
            {
                if (minVertex == NULL)
                {
                    minVertex = &vertices.at(i);
                }
                else
                {
                    if (minVertex->distance > vertices.at(i).distance)
                    {
                        minVertex = &vertices.at(i);
                    }
                }
            }
        }
        minVertex->visited = true; // set the vertex as solved
        solved.push_back(minVertex);
    }
    stack<string> route; // puts the vertex names into a stack to flip the order
    vertex* working = endPoint;
    while (working != NULL)
    {
        route.push(working->name);
        working = working->source;
    }
    path shortestPath; // creates the return path
    shortestPath.distance = endPoint->distance; // puts the distance into the return path
    while (! route.empty()) // puts the vertex names into the return path
    {
        shortestPath.path.push_back(route.top());
        route.pop();
    }
    return shortestPath;
}

path Graph::getShortestVisitAllExhaustive(string startVertex)
{

}

path Graph::getLongestDistanceVisitAllExhaustive(std::string)
{

}
