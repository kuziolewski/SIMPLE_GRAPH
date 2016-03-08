#pragma once
#include <cstdlib>
#include "graph.h"
#define inf 99999                       //wartosc potrzeba do algorytmu MST Prima
class Undirected_graph : public Graph   //klasa bazowa jest klasa Graph
{
private:
protected:

public:
    Undirected_graph(int nb_of_vertex, int percent);    //konstruktor z parametrami
    void mst_Prim();                                    //minimalne drzewo rozpinajace
    ~Undirected_graph();                                //destruktor


};

