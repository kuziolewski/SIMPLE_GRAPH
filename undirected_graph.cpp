#include "undirected_graph.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  konstruktor wywolujacy konstruktor w klasie bazowej
//wejscie: liczba wierzcholkow oraz procentowa gestosc grafu
//wyjscie: macierz wag o podanych na wejscie parametrach
Undirected_graph::Undirected_graph(int nb_of_vertex, int percent) : Graph(nb_of_vertex, percent)
{
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  destruktor usuwajacy macierz wag, na ktorej operujemyw programie
//wejscie: -
//wyjscie: -
Undirected_graph::~Undirected_graph()
{
    for(int i=0; i<get_nb_of_vertex(); i++)
    {
        delete [] get_adjacency_matrix()[i];
    }
    delete [] get_adjacency_matrix();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Opis:  Metoda znajdujaca minimalne drzewo rozpinajace graf (graf musi byæ nieskierowany). Wykorzystany zosta³ algorytm
//       Prima-Jarnika.
//wejscie: metoda operuje na macierzy wykorzysywanej jako g³ówna struktura w programie
//wyjscie: zwraca numery wierzchokow oraz wagi minimalnych krawedzi, oraz calkowita sume wag krawedzi
void Undirected_graph::mst_Prim()
{
int a,b,u,v,i,j,ne=1;
int **temp_matrix = new int *[get_nb_of_vertex()];
int * visited = new int[get_nb_of_vertex()+1];
for (int i = 0; i<get_nb_of_vertex()+1;i++)
{
	 temp_matrix[i] = new int[get_nb_of_vertex()];
     visited[i] = 0;
}
int min,mincost=0;

   //przypisanie do macierzy wykorzyst w funkcji
	for(i=0;i<get_nb_of_vertex();i++)
     {
        for(j=0;j<get_nb_of_vertex();j++)
        {
            temp_matrix[i][j] = get_adjacency_matrix()[i][j];
        }
     }
	for(i=0;i<get_nb_of_vertex();i++)
        for(j=0;j<get_nb_of_vertex();j++)
        {
            if(temp_matrix[i][j]==0)
                temp_matrix[i][j]=inf;
        }
	printf("\nPrim:");
	visited[1]=1;
	while(ne < get_nb_of_vertex())
	{
		for(i=0,min=inf;i<get_nb_of_vertex();i++)
            for(j=0;j<get_nb_of_vertex();j++)
                if(temp_matrix[i][j]< min)
                    if(visited[i]!=0)
                    {
                        min=temp_matrix[i][j];
                        a=u=i;
                        b=v=j;
                    }
                    if(visited[u]==0 || visited[v]==0)
                    {
                        printf("\n Edge %d:(%d,%d) weight:%d",(ne++),a,b,min);
                        mincost+=min;
                        visited[b]=1;
                    }
                temp_matrix[a][b]=temp_matrix[b][a]=inf;
	}
	printf("\n \tMinimun weight = %d\n",mincost);

    for (int i=0; i<get_nb_of_vertex(); i++)
        delete [] temp_matrix[i];

	delete [] visited;
	delete [] temp_matrix[i];
}

