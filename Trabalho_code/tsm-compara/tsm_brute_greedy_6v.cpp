// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 6

// implementation of traveling Salesman Problem GREEDY

int findMinRoute(vector<vector<int> > tsp)
{
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
 
    // Starting from the 0th indexed
    // city i.e., the first city
    visitedRouteList[0] = 1;
    int route[tsp.size()];
 
    // Traverse the adjacency
    // matrix tsp[][]
    while (i < tsp.size() && j < tsp[i].size())
    {
 
        // Corner of the Matrix
        if (counter >= tsp[i].size() - 1)
        {
            break;
        }
 
        // If this path is unvisited then
        // and if the cost is less then
        // update the cost
        if (j != i && (visitedRouteList[j] == 0))
        {
            if (tsp[i][j] < min)
            {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;
 
        // Check all paths from the
        // ith indexed city
        if (j == tsp[i].size())
        {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }
 
    // Update the ending city in array
    // from city which was last visited
    i = route[counter - 1] - 1;
 
    for (j = 0; j < tsp.size(); j++)
    {
 
        if ((i != j) && tsp[i][j] < min)
        {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;
 
    // Started from the node where
    // we finished as well.
    //cout << ("Minimum Cost is : ");
    //cout << (sum) <<endl;
    return sum;
}


 
// implementation of traveling Salesman Problem BRUTE FORCEE

int travllingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
 
// Driver Code
int main()
{
   // int result;
    srand((unsigned) time(0));
    int s = 0;
    //clrscr();
    //char Str[100];
    FILE *arq;
    arq = fopen("Brute_time_6v.txt", "wt");  // Cria um arquivo texto para gravação
    if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO BT do arquivo\n");
        return 0;
    }
    FILE *arq2;
    arq2 = fopen("Greedy_time_6v.txt", "wt");  // Cria um arquivo texto para gravação
    if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO GD do arquivo\n");
        return 0;
    }
    int entradas[15];
    // matrix representation of graph
    for(int g =0; g<20 ; g++){
        
        for(int i =0;i<15;i++){
            entradas[i] = (rand() % 20) + 11;//entre 10 e 30
        }
        int graph[][V] = { { 0, entradas[0], entradas[1], entradas[2], entradas[3], entradas[4] },
                           { entradas[0], 0, entradas[5], entradas[6], entradas[7], entradas[8] },
                           { entradas[1], entradas[5], 0, entradas[9], entradas[10], entradas[11] },
                           { entradas[2], entradas[6], entradas[9], 0, entradas[12], entradas[13] },
                           { entradas[3], entradas[7], entradas[10], entradas[12], 0, entradas[14] },
                           { entradas[4], entradas[8], entradas[11], entradas[13], entradas[14], 0 }, };
        
        fprintf(arq,"%d\n",travllingSalesmanProblem(graph, s));
        
        vector<vector<int> > tsp = { { -1, entradas[0], entradas[1], entradas[2], entradas[3], entradas[4] },
                           { entradas[0], -1, entradas[5], entradas[6], entradas[7], entradas[8] },
                           { entradas[1], entradas[5], -1, entradas[9], entradas[10], entradas[11] },
                           { entradas[2], entradas[6], entradas[9], -1, entradas[12], entradas[13] },
                           { entradas[3], entradas[7], entradas[10], entradas[12], -1, entradas[14] },
                           { entradas[4], entradas[8], entradas[11], entradas[13], entradas[14], -1 }, };
        fprintf(arq2,"%d\n",findMinRoute(tsp));
    }    
    fclose(arq);
    fclose(arq2);
    cout << "Concluido!" << endl;
    return 0;
}
