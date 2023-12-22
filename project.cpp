//Muhammad Murtaza
//2022402
#include <iostream>
#include <queue>
#include <climits>
#include<stack>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include<fstream>
#include<sstream>
using namespace std;

class graph {
public:
    unordered_map<string, list<pair<string,int>>> adj;

    // bool edgeExists(int u, int v) {
    //     return adj[u].end() != find(adj[u].begin(), adj[u].end(), v) ||
    //            adj[v].end() != find(adj[v].begin(), adj[v].end(), u);
    // }

    void addedge(string u, string v,int weight, bool direction) {
        adj[u].emplace_back(v,weight);
        if (direction == 0) {
            adj[v].emplace_back(u,weight);
        }
    }
    void printGraph() const {
        for (const auto& pair : adj) {
            string u = pair.first;
            cout << "Vertex " << u << " is connected to:\n";
            cout<<u<<"-> ";
            for (const auto& edge : pair.second) {
                string v = edge.first;
                int weight = edge.second;
                 cout << "  Vertex " << v << " with weight " << weight << '\n';
                

            }
           
        }
    }
   void BFS(const string& start, const string& end) {
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;
    unordered_map<string, int> distance;

    queue<string> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const auto& neighbor : adj[current]) {
            string next = neighbor.first;
            int weight = neighbor.second;

            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                parent[next] = current;
                distance[next] = distance[current] + weight;
            } else if (distance[next] > distance[current] + weight) {
                // Update distance if a shorter path is found
                distance[next] = distance[current] + weight;
                parent[next] = current;
            }
        }
    }

    // Reconstruct and print the shortest path
    if (!visited[end]) {
        cout << "No path from " << start << " to " << end << " exists." << endl;
    } else {
        cout << "Shortest path from " << start << " to " << end << ": ";
        stack<string> path;
        for (string at = end; at != ""; at = parent[at]) {
            path.push(at);
        }

        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << " (Distance: " << distance[end] << ")" << endl;
    }
}
 void readGraphFromFile(const string& filename) {
        ifstream file("cities.txt");
        if (!file.is_open()) {
            cout << "Error opening file: "<< endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string u, v;
            int weight;

            if (!(iss >> u >> v >> weight)) {
                cerr << "Error reading line: " << line << endl;
                continue;
            }

            addedge(u, v, weight,0);
        }

        file.close();
     }

};
int main(){
    graph g;
    ifstream inputfile("cities.txt");
    if(!inputfile.is_open()){
        cerr<<"File not opened successfully!"<<endl;
    }
    string start,destination;
    g.readGraphFromFile("cities.txt");
    cout<<"Enter starting city";
    cin>>start;
    cout<<"Enter destination";
    cin>>destination;
    g.BFS(start,destination);

}