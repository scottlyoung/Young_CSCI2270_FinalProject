#ifndef GRAPH_H
#define GRAPH_H
// header file include class header and headers for any structures used

//includes
#include <string>
#include <vector>

// declaring structures
struct vertex;
struct edge;
struct path;
struct edgeData;
struct pathData;

// defining structures
struct vertex // a location in the graph
{
    std::string name; // the name of the vertex
    bool visited; // whether the vertex has been visited, defined and used in some functions
    int distance; // the distance to the vertex, defined and used in some functions
    vertex* source;
    std::vector<edge> edges; // stores the vertex's adjacencies
    vertex(std::string _name) // constructor function for the structure
    {
        name = _name;
    }
};

struct edge // a connection between  to vertex's on the graph
{
    vertex* destination; // the vertex that the edge goes to
    int distance; // traversal distance
    edge(vertex* _destination, int _distance) // constructor function the for structure
    {
        destination = _destination;
        distance = _distance;
    }
};

struct pathData // info about path through the graph
{
    std::vector<std::string> path; // names of the vertices in the path
    int distance; // The distance of the path
};

struct path // a path through the graph
{
    std::vector<vertex*> path; // pointers to the vertices in the path
    int distance; // The distance of the path
};

struct edgeData // has returnable information about an edge of a graph
{
    std::string name; // the name of the node the edge goes to
    int distance; // the distance of the edge
    edgeData(std::string _name, int _distance) // constructor function for the structure
    {
        name = _name;
        distance = _distance;
    }
};

class Graph // the graph class, functions are described where they are defined
{
    public:
        Graph();
        virtual ~Graph();
        void createVertex(std::string);
        void createEdge(std::string,std::string,int);
        void deleteVertex(std::string);
        void deleteEdge(std::string,std::string);
        std::vector<std::vector<edgeData> > getGraph();
        pathData getShortestNodePath(std::string,std::string);
        pathData getShortestDistancePathDijikstras(std::string,std::string);
        pathData getShortestVisitAllExhaustive(std::string);
        // add more shortest path functions
        pathData getLongestDistanceVisitAllExhaustive(std::string);
    protected:
    private:
        std::vector<vertex> vertices;
};

#endif // GRAPH_H
