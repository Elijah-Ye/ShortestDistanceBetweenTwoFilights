#include <iostream>
#include <set>
#include <vector>

#include "include/graph.h"
#include "include/parser_header.h"


using std::string;
using std::vector;
using std::unordered_map;
using std::set;

using openFlight::Graph;
using openFlight::Parser;



int main()
{

    Parser p;

    vector<Graph::Node> airportData = p.parseAirportData("data/airports.dat"); // parse airport data
    //vector<Graph::Node> airportData = p.parseAirportData("data/test_node.dat"); // parse airport data
    cout << "Test airport data size: " << airportData.size() << endl;
    unordered_map<string, Graph::Node> airportMap = p.buildAirportMap(airportData); // string to node map

    Graph g; // create graph

    g.adj_list = p.parseRouteData(airportData, "data/routes.dat"); // parse route data
    //g.adj_list = p.parseRouteData(airportData, "data/test_route_SCC.dat"); // parse route data

    cout << "Test route data size: " << g.adj_list.size() << endl;
   
    g.nameToNode = airportMap; //initialize nameToNode
    
    string src;
    string dest;

    cout << "Enter the 3-letter IATA code of the airport you would like to start at: ";
    cin >> src;
    cout << "Enter the 3-letter IATA code of the airport you would like to end at: ";
    cin >> dest;

    Graph::Node source = airportMap[src];
    Graph::Node destination = airportMap[dest];

    // cout << airportData.size() << endl; 
    // cout << "The distance from " << src << " to " << dest << " is " << g.adj_list[src][dest].weight << " km." << endl;


    // quick test for get adjacent nodes
    // vector<string> adjacentNodes = g.getAdjacentNodes(dest);
    // cout << "The size of adjacent nodes is " << adjacentNodes.size() << endl;
    // for(int i = 0; i < 10; i++)
    // {
    //     cout << adjacentNodes[i] << endl;
    // }

    //get all the nodes in the graph
    // g.allNodes = g.getNodes(g.adj_list);
    // cout << "The size of all nodes is " << g.allNodes.size() << endl;



    // DFS dfs;
    cout << "Looking for all all reachable airports from " << src << " by DFS..." << endl;
    vector <string> reachable = g.DFS(src);
    cout << "The size of reachable airports are " << reachable.size() << "." << endl;


    // Run Dijkstra between SFO and CMI
    cout << "Looking for the shortest path between " << src << " and " << dest << " by Dijkstra..." << endl;
    vector <string> path = g.dijkstra(src, dest);
    if(path.size() == 1)
    {
        cout << "Sorry, there is no path between these two airports." << endl;
    }
    else if(path.size() != 1)
    {
        cout << "The shortest path between these two airports is: ";
        for(unsigned long i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    cout << endl;
    

    // Run SCC functions
    cout << "Looking for strongly connected component(SCC) that "<< src << " is in..." << endl;
    unordered_map<string, unordered_map<string, Graph::Edge>> gR = g.reverseGraph();
    vector<string> SCC = g.getSCC(src);
    cout << "The size of the SCC that " << src << " is in is " << SCC.size() << "."<< endl;

    cout << "The first 10 airports in this SCC are: ";
    for(unsigned long i = 0; i < 10; i++)
    {
        cout << SCC[i] << " ";
    }
    cout << endl;


    // vector<vector<string>> SCCs = g.getSCC();
    // cout << "The size of the SCCs is " << SCCs.size() << endl;
    // for(unsigned long i = 0; i < SCCs.size(); i++)
    // {
    //     cout << i << ": ";
    //     for(unsigned long j = 0; j < SCCs[i].size(); j++)
    //     {
    //         cout << SCCs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}