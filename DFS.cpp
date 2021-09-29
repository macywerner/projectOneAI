/*
Group members:
Josh Michaels
Colton Wedell
Macy Werner
*/

#include <vector>
#include <iostream>
using namespace std;

// An edge between two nodes: parent, child, and path cost
class Edge {
public:
  Edge(char p, char c, int w);
  char parent;
  char child;
  int weight;
};

Edge::Edge(char p, char c, int w) {
  parent = p;
  child = c;
  weight = w;
}

class DFS {
public:
  DFS();
  void Search(vector<Edge> vec, int idx);
  vector<Edge> path;
};

DFS::DFS() {

}

// Depth-First Search, takes a vector of edges
void DFS::Search(vector<Edge> vec, int idx) {
  if(!vec.empty()) {
    Edge e = vec[idx]; // grab first edge from list of all edges
    path.push_back(e);
    if(e.child == 'g') { // if goal state is reached, return
      return;
    } else if(e.child == ' ') { // if the node has no children, back up to parent of leaf node
      path.pop_back();
      path.pop_back();
      Search(vec, idx + 1);
    } else { // continue for non-leaf nodes
      Search(vec, idx + 1);
    }
  }
}

int main(int argc, char** argv) {
  vector<Edge> myEdges;
  // add all edges to the graph
  myEdges.push_back(Edge('s', 'a', 3));
  myEdges.push_back(Edge('a', 'd', 3));
  myEdges.push_back(Edge('d', ' ', 0));
  myEdges.push_back(Edge('a', 'e', 7));
  myEdges.push_back(Edge('e', ' ', 0));
  myEdges.push_back(Edge('a', 'g', 15));
  myEdges.push_back(Edge('g', ' ', 0));
  myEdges.push_back(Edge('s', 'b', 1));
  myEdges.push_back(Edge('b', 'g', 20));
  myEdges.push_back(Edge('s', 'c', 8));
  myEdges.push_back(Edge('c', 'g', 5));

  DFS mySearch;
  mySearch.Search(myEdges, 0);

  int cost = 0;

  // Prints formatted path with edge cost
  cout << "Path found:" << endl;
  for(int i = 0; i < mySearch.path.size(); ++i) {
    cost += mySearch.path[i].weight;
    if(i == 0) {
      cout << mySearch.path[i].parent << "->";
      cout << mySearch.path[i].child;
    } else {
      cout << "->" << mySearch.path[i].child;
    }
  }
  cout << "\nCost: " << cost << endl;
}
