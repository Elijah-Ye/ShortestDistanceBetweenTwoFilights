// #pragma once

// #include <fstream>
// #include <sstream>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include "graph.h"
// // #include <unordered_set>
// #include <stack>
// #include <set>

// using namespace std;

// namespace openFlight {
// class DFS {
//   public:
//     class Iterator {
//       public:
//         Iterator();
//         Iterator(Graph::Node*, DFS*);
//         Graph::Node* operator*();
//         bool operator!=(Iterator& other);
//         Iterator& operator++();
//       private:
//         //missing something
//         Graph::Node* curNode_;
//         DFS* dfs;
//     };
//     DFS(Graph* g, string start);
//     DFS(const DFS& other);
//     Iterator  begin();
//     Iterator   end();
//     void add(Graph::Node*  node); // 
//     Graph::Node* pop();
//     Graph::Node* peek() const;
//     bool empty() const;
//     std::unordered_map<Graph::Node*, bool> visited_;
//     //std::set<string> visited_;
//     Graph::Node* start_;
//     Graph* graph_;
//     std::stack<Graph::Node*> path_;
// };
// }