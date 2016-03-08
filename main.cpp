#include <iostream>
#include <ctime>
#include "graph.h"
#include "directed_graph.h"
#include "undirected_graph.h"
using namespace std;


int main()
{
srand(time(NULL));
    Undirected_graph Graf_nieskierowany(3,10);
    Graf_nieskierowany.show();
    Graf_nieskierowany.mst_Prim();
    Graf_nieskierowany.find_edge();

    //printf("\n\n\n\n\n\n\n");
    Directed_graph Graf_skierowany(5, 10);
    Graf_skierowany.show();
    Graf_skierowany.bellmanFord(3,4);
    Graf_skierowany.find_edge();
    return 0;
}


