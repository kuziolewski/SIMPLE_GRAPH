#include "directed_graph.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Konstruktor, ktory korzysta z konstrukora w klasie bazowej (jest tam tworzony graf nieskierowany,
//       tutaj jest on zamieniany na skierowany
//wejscie: liczba wierzcholkow oraz procentowa gestosc grafu
//wyjscie: macierz wag gafu skierowanego
Directed_graph::Directed_graph(int nb_of_vertex, int percent) : Graph(nb_of_vertex, percent)
{
    int range = 10;
    for(int i=0; i<get_nb_of_vertex(); i++)
    {
        for(int j=0; j<get_nb_of_vertex(); j++)
        {
            if((get_adjacency_matrix()[i][j]!=0) && (j!=i))
            {
                get_adjacency_matrix()[i][j]=rand()%range+1;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  destruktor
//wejscie: -
//wyjscie: -
Directed_graph::~Directed_graph()
{
    for(int i=0; i<get_nb_of_vertex(); i++)
    {
        delete [] get_adjacency_matrix()[i];
    }
    delete [] get_adjacency_matrix();
    set_adjacency_matrix(NULL);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Metoda prezentujaca wyniki funkcji Bellmana Forda
//wejscie: tablica kosztow krawedzi, tablica poprzednikow, oraz werzcholek poczatkowy i koncowy
//wyjscie: wyswietla wyniki metody BellmanaForda
void Directed_graph::show_BellmanFord(int * cost, int * number_of_prev, int start_vertex, int end_vertex)
{
    printf("\n Ford Bellman (shortest path)\n");
	bool test;
	test = check_negative_cycle(cost, number_of_prev);
	if(test==false)
	{
		printf("Graph doesnt have negative cycles\n");
	}else printf("Graph have negative cycles\n");
if(get_nb_of_vertex()<30)
{
	int * S = new int [get_nb_of_vertex()];              // tymczasowy stos
    int my_stack = 0;
	printf( "Results for start: %d \n" , start_vertex);
	printf("End: Dist:  Path \n");

	for(int i=0; i<get_nb_of_vertex(); i++)
	{
	    printf("| %d, %*d |", i, 3,cost[i]);


      for(int x = i; x!=-1; x = number_of_prev[x]) // umieszcz. wierzcholki na stosie
	  {
        S[my_stack++] = x;            // w kolejnoœci od ostatniego do pierwszego

      while(my_stack)                 // drukujemy w kolejnosci od konca odl
        printf("%d ", S[--my_stack]);
	  }
	  printf("\n");
	}
}else
{
	printf("\nBellmanFord: \n");
	printf("\n\n Start vertex: %d , distance to %d = %d\n", start_vertex, end_vertex, cost[end_vertex]);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Meoda znajdujaca najkroszta scieszke w grafie pomiedzy dwoma wierzcholkami podanymi przez uzytkownika
//       Korzysta ona z algorytmu Forda-Bellmana. Dziaa³a ona równie¿ na ujemnych wagach, ale aby dzia³a³ poprawnie
//       w grafie nie powinno byæ ujemnych cykli
//wejscie: wierzcholek startowy i koncowy
//wyjscie: wyswietla minimalne sciezki pomiedzy wierzcholkami
void Directed_graph::bellmanFord(int start_vertex, int end_vertex)
{
    int * cost = new int[get_nb_of_vertex()];                   //cost dojscia
    int * number_of_prev    = new int[get_nb_of_vertex()];      //i-ty number_of_prev wierzcholka grafu
    for(int i=0; i<get_nb_of_vertex(); i++)                     //ktory jest poprzednikiem wierz. i-tego na
    {                                                           //na najkrotszej sciezce
        number_of_prev[i] = -1;			                        //domyslny numer poprzednika
        cost[i] = inf;		                                    //dimyslny cost dotarcia (nieskonczonosc)
    }
	cost[start_vertex]=0;                                       //cost dotarcia z wierzcholka startowego do startowego

for(int i=1; i<=get_nb_of_vertex(); i++)                        //relaksacja
{
	for(int w=0; w<get_nb_of_vertex(); w++)
    {
        for(int k=0; k<get_nb_of_vertex(); k++)
		{

			if((get_adjacency_matrix()[w][k] !=0) && (cost[k]) >= (cost[w]+ get_adjacency_matrix()[w][k]))
				{
					cost[k] = cost[w] + get_adjacency_matrix()[w][k];
					number_of_prev[k] = w;

				}
		}
	}
}
 show_BellmanFord(cost, number_of_prev, start_vertex, end_vertex);
 delete [] cost;
 delete [] number_of_prev;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Metoda sprawdzajaca czy w grafie znajduja sie ujemne cykle
//wejscie: informacja przekazywane z metody  Bellmanford, ktora szuka najkroszte sciezki w grafie
//wyjscie: zwraca false jesli nie ma ujemnych cykli, w przeciwnym wypadku true
bool Directed_graph::check_negative_cycle(int *cost, int* number_of_prev)
{
	for(int w=0; w<get_nb_of_vertex(); w++)
        for(int k=0; k<get_nb_of_vertex(); k++)
			if((get_adjacency_matrix()[w][k] !=0) && (cost[k]) >= (cost[w]+ get_adjacency_matrix()[w][k])) return false;
		return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
