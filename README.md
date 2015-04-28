Project Summary:
This library contains a graph class. Using it data can be stored and accessed
in graph form. The program includes code to add or delete vertices and edges,
as well as various algorithms to find different kinds of paths, including
multiple shortest path algorithms.

How to Run:
Enter the numbers corresponding to each menu item to run that item.
The graph object is pre-declared.
Numbers 1-3 de-allocate the graph object, create another one, and add a pre-determined set of vertices and edges.
Numbers 4-14 all run a public function of the Graph class, and display the results when appropriate
Number 15 Quits the program and de-allocates the graph.
Example:
======Main Menu======
1. Pre-made setup: Normal
2. Pre-made setup: No cycles
3. Pre-made setup: Negative weight
4. Create a Vertex
5. Create an Edge
6. Delete Vertex
7. Delete Edge
8. Display Graph
9. Shortest Node path
10. Dijkstra's Algorithm
11. Bellman-Ford Algorithm
12. DAG Algorithm
13. Shortest Visit All
14. Longest Visit All
15. Quit
1
======Main Menu======
1. Pre-made setup: Normal
2. Pre-made setup: No cycles
3. Pre-made setup: Negative weight
4. Create a Vertex
5. Create an Edge
6. Delete Vertex
7. Delete Edge
8. Display Graph
9. Shortest Node path
10. Dijkstra's Algorithm
11. Bellman-Ford Algorithm
12. DAG Algorithm
13. Shortest Visit All
14. Longest Visit All
15. Quit
8
Location 1-->Location2:50***Location 4:5***
Location 2-->Location3:37***Location 1:55***
Location 3-->Location4:3***Location 5:7***Location 7:44***Location 2:33***
Location 4-->Location5:64***Location 1:2***Location 3:5***
Location 5-->Location6:19***Location 3:10***Location 4:60***
Location 6-->Location7:9***Location 8:1***Location 5:17***
Location 7-->Location8:8***Location 3:40***Location 6:11***
Location 8-->Location6:3***Location 7:6***
======Main Menu======
1. Pre-made setup: Normal
2. Pre-made setup: No cycles
3. Pre-made setup: Negative weight
4. Create a Vertex
5. Create an Edge
6. Delete Vertex
7. Delete Edge
8. Display Graph
9. Shortest Node path
10. Dijkstra's Algorithm
11. Bellman-Ford Algorithm
12. DAG Algorithm
13. Shortest Visit All
14. Longest Visit All
15. Quit
10
Source Vertex:Location 1
End Vertex:Location 8
Location 1
Location 4
Location 3
Location 5
Location 6
Location 8
distance: 37
Dependencies:
Only uses default C++ 2011 libraries
======Main Menu======
1. Pre-made setup: Normal
2. Pre-made setup: No cycles
3. Pre-made setup: Negative weight
4. Create a Vertex
5. Create an Edge
6. Delete Vertex
7. Delete Edge
8. Display Graph
9. Shortest Node path
10. Dijkstra's Algorithm
11. Bellman-Ford Algorithm
12. DAG Algorithm
13. Shortest Visit All
14. Longest Visit All
15. Quit
15

Documentation: https://github.com/tontolon22/Young_CSCI2270_FinalProject/blob/master/driver.cpp

System Requirements:
Any OS that uses C++ 2011

Group Members:
Scott Young

Contributers:

Open issues/bugs:
-Currently there is no input checking on all functions. Any incorrect or invalid input will likely result in an error.
