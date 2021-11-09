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
    vector<vector<int>> graphList;

    // creating the Graph constroctor to take a list of edges
    DAG (vector<edge> const &edges, int n)
    {
        graphList.resize(n);

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
// void outputDAG()
// {

// }



int main() 
{

}