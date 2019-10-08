#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node * next;
    
    node(char x)
    {
        data = x;
        next = NULL;
    }
};

struct linkedlist
{
    int size;
    node * head;
    node * tail;

    linkedlist()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void insert(char x)
    {
        node * newnode = new node(x);
        if(size == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }
};

struct Queue
{
    int size;
    node * head;
    node * tail;

    Queue()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void push(char x)
    {
        node * newnode = new node(x);
        if(size == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    void pop()
    {
        if(size != 0)
        {
            node * temp = head;
            if(size == 1)
            {
                delete temp;
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete temp;
            }
            size--;
        }
    }

    bool isempty()
    {
        return size == 0;
    }
};

struct graph
{
    linkedlist * adjlist;
    bool * visited;
    
    graph()
    {
    	adjlist = new linkedlist[150];
    	visited = new bool[150];
    	resetvisited();
	}
	
	void resetvisited()
	{
		for(int i=0;i<150;i++) visited[i] = 0;
	}

    void insert(char c1,char c2)
    {
        adjlist[c1].insert(c2);
        adjlist[c2].insert(c1);
    }

    void BFS(char start)
    {
        Queue q;
        visited[start] = 1;
        q.push(start);
        while(!q.isempty())
        {
            start = q.head->data;
            cout<<start<<" ";
            q.pop();
            node * adjhead = adjlist[start].head;
            while(adjhead != NULL)
            {
                if(!visited[adjhead->data])
                {
                    visited[adjhead->data] = 1;
                    q.push(adjhead->data);
                }
                adjhead = adjhead->next;
            }
        }
        cout<<endl;
        resetvisited();
    }

    void DFS(char start)
    {
        visited[start] = true;
	    cout<<start<<" ";
	    node * adjhead = adjlist[start].head;
        while(adjhead != NULL)
        {
            if(!visited[adjhead->data])
            {
                DFS(adjhead->data);
            }
            adjhead = adjhead->next;
        }
    }

    void findcycle()
    {

    }
    
    int calculatediameter()
    {
        return 0;
	}
};

int main()
{
    graph g;
    ifstream fin("L6_Q1_sample_input.txt");
    while(fin)
    {
        char c1,c2,buf;
        fin>>std::noskipws>>c1>>buf>>c2>>buf;
        g.insert(c1,c2);
    }
    fin.close();
    int choice = 1;
    while(choice)
    {
        cout<<"Enter your choice:-"<<endl<<endl;
        cout<<"1. Insert edge"<<endl;
        cout<<"2. BFS traversal"<<endl;
        cout<<"3. DFS traversal"<<endl;
        cout<<"4. Cycle finding in the graph"<<endl;
        cout<<"5. Calculate diameter of the graph"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    char c1,c2;
                    cout<<"Enter the two nodes"<<endl;
                    cin>>c1>>c2;
                    g.insert(c1,c2);
                }
                break;
            case 2:
                {
                    char c1;
                    cout<<"Enter starting node"<<endl;
                    cin>>c1;
                    cout<<endl<<"Breadth First Search(BFS) traversal:- "<<endl;
                    g.BFS(c1);
                    cout<<endl;
                }
                break;
            case 3:
                {
                    char c1;
                    cout<<"Enter starting node"<<endl;
                    cin>>c1;
                    cout<<endl<<"Depth First Search(DFS) traversal:- "<<endl;
					g.DFS(c1);
					cout<<endl;
					g.resetvisited();
					cout<<endl;
                }
                break;
            // case 4:
            //     {
            //         g.findcycle();
            //     }
            //     break;
            // case 5:
            //     {
            //         cout<<g.calculatediameter();
            //     }
            //     break;
            case 6:
                {
                    choice = 0;
                }
                break;
            default:
                cout<<"Wrong choice! Enter again.";
        }
    }
}
