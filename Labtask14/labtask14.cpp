// Najam Ali Abbas 
// 20I-2612 
// Labtask 14
#include <iostream>
#include <cstdlib>
#include <queue>
#include <list>
using namespace std;

class Node
{
public:

    int data;
    Node* next;
};


class AdjList
{
public:
    Node* head;
};


class Graph
{
private:
    int V;
    AdjList* Arr;
    list<int>* adj;

public:

    Graph(int V)
    {
        this->V = V;
        
        Arr = new AdjList[V];
        
        for (int i = 0; i < V; ++i)
        {
            Arr[i].head = NULL;
        }

        adj = NULL;
    }


    void insertEdge(int src, int dest)
    {

        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = NULL;
        newNode->next = Arr[src].head;
        Arr[src].head = newNode;

        newNode = new Node;
        newNode->data = src;
        newNode->next = NULL;

        newNode->next = Arr[dest].head;
        Arr[dest].head = newNode;
    }

    void printGraph()
    {
        int v;
        for (v = 0; v < V; ++v)
        {
            Node* tmp = Arr[v].head;
            cout << "Adjacency list of the vertex " << v << ": ";
            while (tmp)
            {
                cout << "-> " << tmp->data;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void BFS(int s)
    {

        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;


        visited[s] = true;
        queue.push_back(s);


        list<int>::iterator i;

        while (!queue.empty())
        {

            s = queue.front();
            cout << s << ", ";

            queue.pop_front();

            Node* tmp = Arr[s].head;
            while (tmp)
            {

                if (!visited[tmp->data])
                {
                    visited[tmp->data] = true;
                    queue.push_back(tmp->data);

                }
                tmp = tmp->next;
            }
        }
    }
};


int main()
{
    Graph graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 4);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(1, 4);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);

    
    graph.printGraph();


    cout << "\nBreadth first search from vertex 3: ";
    graph.BFS(3);

    cout << endl;

    return 0;
}