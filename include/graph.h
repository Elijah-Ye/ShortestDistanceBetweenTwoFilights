#pragma once


//#include "parser_header.h"



#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
#include <limits>
#include <climits>

using namespace std;

namespace openFlight{
  class Graph {
    public:
      typedef struct Node 
        {
          string name;
          double lat;
          double lng;

          Node()
          {
            name = "";
            lat = 0;
            lng = 0;
          }

          //overload == operator
          bool operator==(const Node& other) const
          {
            return (name == other.name);
          }

          //overload = operator
          Node& operator=(const Node& other)
          {
            name = other.name;
            lat = other.lat;
            lng = other.lng;
            return *this;
          }

        } Node;

      typedef struct Edge 
      {
        Graph::Node src;
        Graph::Node dest;
        double weight;

        Edge()
        {
          src = Node();
          dest = Node();
          weight = 0;
        }

      } Edge; 



      Graph();
      Graph(unordered_map<string, Node> nodes, unordered_map<string, Edge> edges);

      //functions
      vector<string> DFS(string start); //this will traverse component that start is in
      vector<string> DFS(string start, string end); //this will traverse the graph and return a path from start to end
      vector<string> DFS(string start, unordered_map<string, unordered_map<string, Graph::Edge>> &gR);
      vector<string> getAdjacentNodes(string IATA);
      vector<string> getAdjacentNodes(string IATA, unordered_map<string, unordered_map<string, Graph::Edge>> &gR);
      vector<string> getNodes(unordered_map<string, unordered_map<string, Graph::Edge>> &adj_list);
      bool edgeExists(string src, string dest);

      //Dijkstra functions -----------------------------------
      string minDist(unordered_map<string, int> flightDist, unordered_map<string, bool> visited, int numAirports, vector<string> allAirports);
      vector<string> recursivePath(unordered_map<string, string> parent, string cur, vector<string> populate_path);
      vector<string> print(unordered_map<string, int> flightDist, int n, unordered_map<string, string> parent, vector<string> allAirports, string source, string dest, vector<string> populate_path);
      vector<string> dijkstra(string source, string dest); //use adj_list
      //---------------------------------------------------------

      //SCC functions -----------------------------------------
      unordered_map<string, unordered_map<string, Graph::Edge>> reverseGraph();
      vector<string> getSCC(string start);
      vector<vector<string>> getSCC();
      //---------------------------------------------------------

      //variables
      unordered_map<string, unordered_map<string, Graph::Edge>> adj_list;
      unordered_map<string, Graph::Node> nameToNode;
      // unordered_map<string, int> connectedComp;
      // unordered_map<string, bool> visited;
      // vector<string> allNodes;
      // vector<string> path;
      // int numConnectedComp;
  };
}
