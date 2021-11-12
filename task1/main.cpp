/*CPS2004 - OOP
  Task 1 - DAG (in C++)
  Luke D'Amato
*/

#include <iostream>
#include <vector>

using namespace std;

// creating a struct to hold the start and end of our DAG
struct edge
{
    int start, end;
    // since we are working with DAGs, start != end (no cycles)
};

// representing the graph object in class DAG
class DAG
{
public:
    vector<vector<int>> graphList;

    // creating the Graph constroctor to take a list of edges
    DAG (vector<edge> const &edges, int num)
    {
        graphList.resize(num);

        // adding edges to the DAG
        for(auto &edge: edges)
        {
            // adding in a directed graph 
            graphList[edge.start].push_back(edge.end);
        }
    }
};

// removing individual nodes
// void removeNode()
// {
 
// }

// returning the list of edges 
// DO NOT DESTROY in-memorry struct
void outputDAG(DAG const &graph, int n)
{
    for(int cnt=0; cnt < n; cnt++)
    {
        std::cout << cnt << "->" << endl;
        
        // outputting the vertices 
        for (int x: graph.graphList[cnt])
        {
            std::cout << x << ", ";
        }
        std::cout << endl;
    }
}

int main() 
{
    // creating the vecotr for the DAG
    vector<edge> edges = 
    {
        {1, 2}, {1, 3}, {2, 4}, {2, 5}, {4, 6}
    };

    // number of nodes, used in the constructor
    int num = 6;

    // calling the constructor
    DAG dag(edges, num); 

    // outputting the dag formed thanks to the constructor dag
    outputDAG(dag, num);

    return 0;
}