#include <iostream>
#include <queue>

using namespace std;

class Graph
{
private:
    int n;
    int vis2[8];
    bool *visited;
    int **AdjMatrix;
public:
    /* */
    Graph (int n)
    {
        this->n = n;
        visited = new bool [n];
        AdjMatrix = new int* [n];
        for (int i = 0; i < n; i++ ) {
            AdjMatrix[i] = new int [n];
            for (int j=0; j < n; j++) {
                AdjMatrix[i][j] = 0;
            }
        }
    }
    void edgeAddition();
    void displayMatrix();
    void breadthFirstSearch(int n);
    void deapthFirstSearch(int v);
};
void Graph::deapthFirstSearch(int n)
{
    vis2[n] = 1;
    cout <<"\nVisited vertex: " <<n;
    for (int i=0;i<this->n;i++)
    {
        if (vis2[i]!=1 && AdjMatrix[n][i] == 1)
        {
         deapthFirstSearch(i);
        }
    }
}
void Graph::breadthFirstSearch(int n)
{
    int vis[10];
    queue<int> Q;
    for (int i=0;i<this->n;i++)
        vis[i] = 0;
    Q.push(n);
    cout << "\nBreadth first of the given Graph with vertex 0 to "<< this->n-1 ;
    cout << "\nVisited vertex: " << n;
    vis[n]=1;
    while(!Q.empty())
    {
        n = Q.front();
        Q.pop();
        for (int i=0;i<this->n;i++)
        {
            if (vis[i]==0 && AdjMatrix[n][i] !=0)
            {
                Q.push(i);
                vis[i] = 1;
                cout <<"\nVisited vertex: " <<i;
            }
        }
    }
}
void Graph::edgeAddition ()
{
    /* Adding 16 edges */
    AdjMatrix[0][1] = 1;
    AdjMatrix[1][0] = 1;

    AdjMatrix[0][4] = 1;
    AdjMatrix[4][0] = 1;

    AdjMatrix[0][5] = 1;
    AdjMatrix[5][0] = 1;

    AdjMatrix[1][2] = 1;
    AdjMatrix[2][1] = 1;

    AdjMatrix[1][5] = 1;
    AdjMatrix[5][1] = 1;

    AdjMatrix[1][6] = 1;
    AdjMatrix[6][1] = 1;

    AdjMatrix[2][3] = 1;
    AdjMatrix[3][2] = 1;

    AdjMatrix[2][5] = 1;
    AdjMatrix[5][2] = 1;

    AdjMatrix[2][6] = 1;
    AdjMatrix[6][2] = 1;

    AdjMatrix[2][7] = 1;
    AdjMatrix[7][2] = 1;

    AdjMatrix[3][4] = 1;
    AdjMatrix[4][3] = 1;

    AdjMatrix[3][6] = 1;
    AdjMatrix[6][3] = 1;

    AdjMatrix[3][7] = 1;
    AdjMatrix[7][3] = 1;

    AdjMatrix[4][7] = 1;
    AdjMatrix[7][4] = 1;

    AdjMatrix[5][6] = 1;
    AdjMatrix[6][5] = 1;

    AdjMatrix[6][7] = 1;
    AdjMatrix[7][6] = 1;

}
void Graph::displayMatrix()
{
    cout<< "\n\nGraph implemented as an adjacency matrix.\n\n";
	cout<< "   (2)-----(3)----(4)"<<endl;
	cout<< "  / | \\   / |\\   / | \\ "<<endl;
	cout<< " /  |  \\ /  | \\ /  |  \\ "<<endl;
	cout<< "(1)-----\\----- \\------(5)"<<endl;
	cout<< " \\  |  / \\  | / \\  |  /"<<endl;
	cout<< "  \\ | /   \\ |/   \\ | /"<<endl;
	cout<< "   (6)-----(7)----(8)"<<endl;
	cout<< "\nUndirected Graph with 16 edges and 8 nodes\n\n";
	cout<< "Adjacency Matrix for the above given graph\n";
    for (int i = 0; i <n ;i++) {
        for (int j=0; j<n ; j++) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    int num_nodes;
    num_nodes = 8;
    Graph g1(num_nodes);
    g1.edgeAddition();
    g1.displayMatrix();
    g1.breadthFirstSearch(0);
    cout << "\n\nDeapth first of the given Graph with vertex 0 to "<< num_nodes - 1 ;
    g1.deapthFirstSearch(0);
    return 0;
}
