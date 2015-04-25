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

// defining structures
struct vertex // a location in the graph
{
    std::string name; // the name of the vertex
    bool visited; // whether the vertex has been visited, defined and used in some functions
    int distance; // the distance to the vertex, defined and used in some functions
    std::vector<edge> edges; // stores the vertex's adjacencies
};

struct edge // a connection between  to vertex's on the graph
{
    vertex* destination; // the vertex that the edge goes to
    int distance; // traversal distance
};

struct path // a path through the graph
{
    std::vector<std::string> path; // names of the vertices in the path
    int distance; // The distance of the path
};

struct edgeData // has returnable information about an edge of a graph
{
    std::string name; // the name of the node the edge goes to
    int distance; // the distance of the edge
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
        path getShortestNodePath(std::string,std::string);
        path getShortestDistancePathDijikstras(std::string,std::string);
        path getShortestVisitAllExhaustive(std::string);
        // add more shortest path functions
        std::vector<path> getLongestNodeVisitAllExhuastive(std::string);
        path getLongestDistanceVisitAllExhaustive(std::string);
    protected:
    private:
        std::vector<vertex> vertices;
};

#endif // GRAPH_H
