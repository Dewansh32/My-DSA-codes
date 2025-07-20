#include<iostream>
#include<vector>
using namespace std;

int main() {
     // your code here
    int vertex,edges;
    cout<<"Enter number of vertices: ";
    cin>>vertex;
    cout<<endl;
    cout<<"Enter number of edges: ";
    cin>>edges;
    cout<<endl;

    vector<int> Adjlist[vertex];

    int u,v;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        Adjlist[u].push_back(v);
        Adjlist[v].push_back(u);
    }

    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" -> ";
        for(int j = 0;j<Adjlist[i].size();j++)
        {
            cout<<Adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
for weighted  we use 
    vector<pair<int,int>> Adjlist[vertex];

    int u,v,weight;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        Adjlist[u].push_back({v,weight});
        Adjlist[v].push_back({u,weight});
    }

    for(int i=0;i<vertex;i++)
    {
        cout<<i<<" -> ";
        for(int j = 0;j<Adjlist[i].size();j++)
        {
            cout<<Adjlist[i][j].first<<" "<<Adjlist[i][j].second<<" ";
        }
        cout<<endl;
    }

*/