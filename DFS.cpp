#include <vector>
#include <iostream>
using namespace std;

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

void DFS::Search(vector<Edge> vec, int idx) {
  if(!vec.empty()) {
    Edge e = vec[idx];
    path.push_back(e);
    if(e.child == 'g') {
      return;
    } else if(e.child == ' ') {
      path.pop_back();
      path.pop_back();
      Search(vec, idx + 1);
    } else {
      Search(vec, idx + 1);
    }
  }
}

int main(int argc, char** argv) {
  vector<Edge> myEdges;
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

/*
class Node {
public:
  Node(state, parent[]=NULL, path_cost=0, children[]=NULL);

private:
  Node[] myparents;
  Node[] mychildren;
  int[] mypath_costs;
}

Node::Node(state, parents[]=NULL, path_costs[]=0, children[]=NULL) {
  myparents[] = parent;
  mychildren[] = children;
  mypath_costs[] = path_costs;
}

class Graph {
public:
  Graph(nodes[]=NULL);

private:
  Node[] mynodes;
}

Graph::Graph(nodes[]) {
  mynodes[] = nodes;
}
*/
