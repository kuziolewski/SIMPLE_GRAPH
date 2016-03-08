#pragma once
#include "undirected_graph.h"
#include <ctime>
#include <cstdlib>
class Directed_graph : public Graph     //klasa podstawowa Graph
{
private:
protected:
    bool check_negative_cycle(int *cost, int* number_of_prev);  //funkcja sprawdzajaca ujemny cykl (wykorzystywana przez BellmanaForda
    void show_BellmanFord(int * cost, int * number_of_prev,int start_vertex, int end_vertex);   //funkcja pokazujaca wyniki BellmanaForda
public:
    Directed_graph(int nb_of_vertex, int percent);              //konstruktor z parametrami
    ~Directed_graph();                                          //destruktor
    void bellmanFord(int start_vertex, int end_vertex);         //metoda ktora zwraca najkrotsza sciezke pomiedzy dwoma wierzcholkami

};
