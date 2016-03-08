#include "graph.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  konstruktor tworzacy macierz wag (tablica dynamiczna dwuwymiarowa
//wejscie: liczba wierzchokow i gestosc grafu wyrazona w procentach
//wyjscie: macierz wag
Graph::Graph(int nb_of_vertex, int percent)
{
    this->nb_of_vertex = nb_of_vertex;
    adjacency_matrix = new int*[nb_of_vertex];
    for(int i=0; i<nb_of_vertex; i++)
        adjacency_matrix[i] = new int[nb_of_vertex];
    for(int j=0; j<nb_of_vertex; j++)
            for(int k=0; k<nb_of_vertex; k++)
                adjacency_matrix[j][k] = 0;
    nb_of_vertex = get_nb_of_vertex();

    fill_graph(nb_of_vertex, percent);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Metoda pozwalajaca zbudowac uzytkownikowi graf w postaci macierzy wag (zawsze wszsytkie krawedzie sa polaczone
//wejscie: liczba wierzcholkow w grafie, oraz gestosc grafu wyrazona w procentach (zakres od 1 do 100 procent)
//wyjscie: macierz wag

void Graph::fill_graph(int nb_of_vertex, int percent)
{
    int size_of_graph = nb_of_vertex;
    int to_add = size_of_graph * (size_of_graph-1) * percent / 200;

    if((percent<=100) && (percent>0))
    {
        int range = 10;
        int nb_of_added = 0;

        for(int i=0; i<size_of_graph; i++)
        {
            nb_of_added += add_edges(i, i+1, 1+rand()%range);
        }
            nb_of_added += add_edges(0, nb_of_vertex-1, 1+rand()%range);
        while(nb_of_added<to_add)
            nb_of_added += add_edges(rand()%size_of_graph, rand()%size_of_graph, 1+rand()%range);
    }else
    {
        printf("\nError! bad percent range!\n");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Metoda dodajaca krawedz do macierzy
//wejscie: 2 wierzcholki miedzy ktorymi znajduje sie krawedz oraz waga krawedzi
//wyjscie: metoda zwraca true albo false, w zale¿noœci, czy uda jej siê dodaæ krawedz
bool Graph::add_edges(int start_vertex, int end_vertex, int weight)
{
    if(start_vertex>=Graph::get_nb_of_vertex()||end_vertex>=Graph::get_nb_of_vertex()||start_vertex==end_vertex)
        return false;
    if(Graph::get_adjacency_matrix()[start_vertex][end_vertex]!=0)
        return false;
    get_adjacency_matrix()[start_vertex][end_vertex]=weight;
    get_adjacency_matrix()[end_vertex][start_vertex]=weight;
    return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Destruktor virtualny (polimorfizm)
//wejscie: -
//wyjscie: -
Graph::~Graph()
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Wyswietlanie grafu w bardziej przyjaznej, czytelnej formie dla uzyktownika
//wejscie: macierz sasiedztwa (tablica dynamiczna wuwymiarowa)
//wyjscie: wyswietlanie w formie listy krawedzi (vector<vector<edge>>)
void Graph::show()
{
    typedef std::vector<edge> vector_of_edge;
    std::vector<vector_of_edge> *adjList;
    std::printf("\n");
    adjList = new std::vector<vector_of_edge>(get_nb_of_vertex());
    int start_vert=0;
    for(int i=0; i<nb_of_vertex; i++)                             //petle tworzacy graf pelny
    {
        for(int j=0; j<nb_of_vertex; j++)
        {
           if(adjacency_matrix[i][j]!=0)
           {
                edge newEdge;
                newEdge.destination = j;
                newEdge.weight = adjacency_matrix[i][j];
                start_vert = i;
                (*adjList)[start_vert].push_back(newEdge);
            }
        }
    }
    printf("\nAdjacency matrix show as adjacency list: \n");
    for(int i=0; i<nb_of_vertex; i++)
    {
        std::printf("vertrex: %d", i);
        for(int j=0; j<(int)(*adjList)[i].size(); j++)
        {
           std::printf(" -> |%d %d|", (*adjList)[i][j].destination, (*adjList)[i][j].weight);
        }
        std::printf("\n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Meoda znajdujaca krawedz podana przez uzytkownika
//wejscie: dane wprowadzanie we wnetrzu metody, (wprowadzane s¹ dwa wierzcholki
//wyjscie: waga znalezionej krawedzi, a jesli nie odnaleziona komunikat o braku
void Graph::find_edge()
{
    int temp1, temp2;
    std::printf("\nPlease, enter starting vertex: ");
    std::scanf("%d", &temp1);
    std::printf("\nPlease, enter ending vertex: ");
    std::scanf("%d", &temp2);
    if ((temp1 >= 0 && temp1 < nb_of_vertex) && (temp2 >= 0 && temp2 <nb_of_vertex) && (adjacency_matrix[temp1][temp2]!= 0))
    {
        std::printf("Edge found! Weight this edge is: %d\n", adjacency_matrix[temp1][temp2]);
        }else
            {
                std::printf("There is no such edge!\n");
            }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Akcesory
//(settery i gettery
int Graph::get_nb_of_vertex()
{
    return nb_of_vertex;
}
int** Graph::get_adjacency_matrix()
{
    return adjacency_matrix;
}

void Graph::set_nb_of_vertex(int nb_of_vertex)
{
    this->nb_of_vertex=nb_of_vertex;
}
void Graph::set_adjacency_matrix(int **adjacency_matrix)
{
    this->adjacency_matrix=adjacency_matrix;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Przeciazenie operatora wyjscia
//wejscie:Wyswietla macierz sasiedztwa
//wyjscie: macierz siasiedztwa w formie tablicy dwuwymiarowej
std::ostream& operator<<(std::ostream& out,Graph& graph)
    {
        out << "\noverload operator <<";
        out <<"\nAdjacency matrix:";
        for(int i=0; i<graph.get_nb_of_vertex(); i++)
        {
            out << "\n";
            for(int j=0; j<graph.get_nb_of_vertex(); j++)
            {
                out.width(3);
                out <<graph.get_adjacency_matrix()[i][j] << " ";
            }
        }

        return out;
    }


