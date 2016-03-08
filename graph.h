#pragma once
#include <vector>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#define inf 99999
//struktura potrzebna do wyswietlania
struct edge             //strc krawedz
    {
        int destination;    //wierzcholek docelowy
        int weight;         //waga krawedzi
    };
/////////////////////////////////////////////////////////////
//klasa Graph, jest klasa podstawowa
class Graph
{
private:
    int nb_of_vertex;         //liczba wierzcholkow
    int ** adjacency_matrix;  //macierz sasiedztwa
protected:
    //metody potrzebne do wypelnienia macierzy
    void fill_graph(int nb_of_vertrex, int percent);
    bool add_edges(int start_vertex, int end_vertex, int weight);
public:
    Graph(int nb_of_vertex, int percent);             //konstruktor
    virtual ~Graph();                                 //destruktor wirtualny (polimorfizm)
    void show();                                      //funkcja wyswietlajaca macierz w formie listy s¹siadów
    void find_edge();                                 //funkcja znajdujaca krawedz
    friend  std::ostream& operator<<(std::ostream& out, Graph& graph);  //przeciazenie operatora strumienia wyjscia

    int get_nb_of_vertex();                           //akcesory, potrzebne do obslugi pol prywatnyych
    int** get_adjacency_matrix();
    void set_nb_of_vertex(int nb_of_vertex);
    void set_adjacency_matrix(int **adjacency_matrix);
};



