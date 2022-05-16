// // #include "../include/DFS.h"

// // namespace openFlight {
// // DFS::DFS(Graph* g) {
// //     // What is the start node ?
// //     Node* start = ???;
    
// //     unordered_map<Node*, bool> visited;
// //     for (auto i = g_->adj_list.begin(); i != g_->adj_list.end(); ++i) {
// //       visited[i->first] = false;
// //     }
// //     graph_ = g;
// //     stack<Node*> stack;
// //     stack.push(start);

// //     while (!stack.empty()) {
// //       Node curr* = stack.top();
// //       stack.pop();
// //       path_.push_back(curr);  
// //       if (!visited[curr]) {
// // 	  visited[curr] = true;
// //       }
// //     // how to update the current iterator ???
// // }
// // }

// #include "../include/DFS.h"
// #include <string>

// // using std::string
// // using DFS::Iterator;
// namespace openFlight {

// DFS::DFS(Graph* g, string start) {
//     // std::cout<<"start: "<<graph_<<std::endl;
//     graph_ = g;
//     start_ = g->nameToNode[start];
//     vector<Graph::Node*> nodes = g->getNodes(g->adj_list);
//     for (auto i = nodes.begin(); i != nodes.end(); ++i) {
//         visited_[*i] = false;
//     }
//     // print visited size
//     std::cout<<"visited size: "<<visited_.size()<<std::endl;
// }

// DFS::DFS(const DFS& other) {
//     // std::cout<<"copy constructor: "<<graph_<<std::endl;
//     if (this != &other) {
//         graph_ = other.graph_;
//         start_ = other.start_;
//     }
//     // std::cout<<"copy constructor: "<<graph_<<std::endl;
//     // return *this;
// }

// DFS::Iterator DFS::begin() {
//     // std::cout<<"begin: "<<graph_<<std::endl;
//     return Iterator(start_, new DFS(*this));
// }

// DFS::Iterator DFS::end() {
//     return Iterator(NULL, NULL);
// }

// void DFS::add(Graph::Node*  node) {
//     visited_[node] = true;
//     //visited_.insert(node->name); // this is for string implementation. I tried and it didn't work.
//     for (auto i = graph_->adj_list[node].begin(); i != graph_->adj_list[node].end(); ++i) {
//         // std::cout<<"in add line 60"<<std::endl;
//         if (visited_[i->first] == false){
//             // std::cout<<"in add line 62"<<std::endl;
//             path_.push(i->first);
//         }
//     }
// }

// Graph::Node* DFS::pop() {
//     Graph::Node* node = path_.top();
//     path_.pop();
//     return node;
// }

// Graph::Node* DFS::peek() const {
//     return path_.top();
// }

// bool DFS::empty() const {
//     return path_.empty();
// }

// DFS::Iterator::Iterator() {
//     curNode_ = NULL;
//     dfs = NULL;
// }

// DFS::Iterator::Iterator(Graph::Node* node, DFS* dfs) {
//     curNode_ = node;
//     dfs = dfs;
// }

// Graph::Node* DFS::Iterator::operator*() {
//     return curNode_;
// }

// bool DFS::Iterator::operator!=(DFS::Iterator& other) {
//     if (dfs == NULL) return false;
//     return curNode_ != NULL;
// }

// DFS::Iterator& DFS::Iterator::operator++() {
//     if (dfs == NULL) return *this;
//     if (curNode_ == NULL) return *this;
//     dfs->add(curNode_);
//     //std::cout<<"in ++ line " << __LINE__ << std::endl;
//     curNode_ = dfs->pop();
//     return *this;
// }

// }