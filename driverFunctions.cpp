#include <iostream>
#include "Graph.h"

using namespace std;



string getInput() // function to get multi-word input
{
    char key;
    string input = "";
    cin.get(key);
    while (key != '\n')
    {
        input = input + key;
        cin.get(key);
    }
    return input;
}

void outputPath(pathData displayPath) // outputs the vertices and distance of a path
{
    for (int i = 0; i < displayPath.path.size(); i++)
    {
        cout << displayPath.path.at(i) << endl;
    }
    cout << "distance: " << displayPath.distance << endl;
}

void outputGraph(vector<vector<edgeData> > graphData) // displays each vertex and its edges, as recived
{
    for (int i = 0; i < graphData.size(); i++)
    {
        cout << graphData.at(i).at(0).name << "-->";
        for (int j = 1; j < graphData.at(i).size(); j++)
        {
            cout << graphData.at(i).at(j).name << ":" << graphData.at(i).at(j).distance << "***";
        }
        cout << endl;
    }
}


