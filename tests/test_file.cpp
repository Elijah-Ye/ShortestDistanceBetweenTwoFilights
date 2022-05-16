// #include <catch2/catch_test_macros.hpp>
#include "catch2/catch.hpp"
#include "../include/parser_header.h"
#include "../include/graph.h"
#include <set>

using namespace std;
using namespace openFlight;

TEST_CASE("TEST_parseAirportData") {

    SECTION("Test small file") {
        Parser p;
        vector<Graph::Node> airportData = p.parseAirportData("data/small.dat"); //why we don't need ../data/small.dat?
        REQUIRE(airportData.size() == 5);
    }

    SECTION("Test midum size file") {
        Parser p;
        vector<Graph::Node> airportData = p.parseAirportData("data/midAir.dat"); 
        REQUIRE(airportData.size() == 3040);
    }

    SECTION("Test my own file") {
        Parser p;
        vector<Graph::Node> airportData = p.parseAirportData("data/test_node.dat"); 

        REQUIRE(airportData.size() == 10);
    }

}

TEST_CASE("Test_buildAirportMap") {
    Parser p;
    vector<Graph::Node> airportData = p.parseAirportData("data/midAir.dat"); 
    unordered_map<string, Graph::Node> airportMap = p.buildAirportMap(airportData);
    string name = airportData[500].name;
    REQUIRE(airportMap[name] == airportData[500]);
}



TEST_CASE("DFS") {
    Parser p;
    vector<Graph::Node> airportData = p.parseAirportData("data/test_node.dat"); 
    unordered_map<string, Graph::Node> airportMap = p.buildAirportMap(airportData);
    Graph g;
    g.adj_list = p.parseRouteData(airportData, "data/test_route.dat");
    g.nameToNode = airportMap;

    vector<string> dfsNodes = g.DFS("SFO");

    set<string> visited;
    for(unsigned long i = 0; i < dfsNodes.size(); i++)
    {
        visited.insert(dfsNodes[i]);
    }

    SECTION("Size of the vector") {
        REQUIRE(g.DFS("SFO").size() == 4);
    }

    SECTION("Test if the nodes are in the vector") {
        REQUIRE(visited.find("SFO") != visited.end());
        REQUIRE(visited.find("LAX") != visited.end());
        REQUIRE(visited.find("CMI") != visited.end());
        REQUIRE(visited.find("ORD") != visited.end());
    }
}

TEST_CASE("Dijkstra's Algorithm")
{
    Parser p;
    vector<Graph::Node> airportData = p.parseAirportData("data/test_node.dat"); 
    unordered_map<string, Graph::Node> airportMap = p.buildAirportMap(airportData);
    Graph g;
    g.adj_list = p.parseRouteData(airportData, "data/test_route.dat");
    g.nameToNode = airportMap;

    SECTION("Path exists")
    {
        vector <string> path = g.dijkstra("SFO", "LAX");
        REQUIRE(path.size() > 1);
        REQUIRE(path[0] == "SFO");
        REQUIRE(path[1] == "LAX");
    }

    //next we want to test if the path is the shortest
    //we will use SFO->CMI
    SECTION("Path is shortest")
    {
        vector <string> path2 = g.dijkstra("SFO", "CMI");
        REQUIRE(path2[0] == "SFO");
        REQUIRE(path2[1] == "CMI");
        g.adj_list = p.parseRouteData(airportData, "data/test_routeSimple.dat");
        vector <string> path1 = g.dijkstra("SFO", "CMI");
        REQUIRE(path1[0] == "SFO");
        REQUIRE(path1[1] == "ORD");
        REQUIRE(path1[2] == "CMI");
    }

    //next we want to test if the path does not exist
    //we will use SFO->PKX
    SECTION("Path does not exist")
    {
        vector <string> path = g.dijkstra("SFO", "PKX");
        REQUIRE(path.size() == 1); //it is 1 because only the dest is in it. There is no path
    }
}

TEST_CASE("Strongly Connected Component")
{
    Parser p;
    vector<Graph::Node> airportData = p.parseAirportData("data/test_node.dat"); 
    unordered_map<string, Graph::Node> airportMap = p.buildAirportMap(airportData);
    Graph g;
    g.adj_list = p.parseRouteData(airportData, "data/test_route_SCC.dat");
    g.nameToNode = airportMap;
    vector<vector<string>> SCCs = g.getSCC();

    vector<string> comp1 = g.getSCC("SFO");
    vector<string> comp2 = g.getSCC("PKX");
    vector<string> comp3 = g.getSCC("DOH");

    set<string> SCC1;
    for(unsigned long i = 0; i < comp1.size(); i++)
    {
        SCC1.insert(comp1[i]);
    }

    set<string> SCC2;
    for(unsigned long i = 0; i < comp2.size(); i++)
    {
        SCC2.insert(comp2[i]);
    }

    set<string> SCC3;
    for(unsigned long i = 0; i < comp3.size(); i++)
    {
        SCC3.insert(comp3[i]);
    }
    

    SECTION("Correct number of SCC for the whole graph")
    {
        REQUIRE(SCCs.size() == 3);
    }

    SECTION("Correct number of airports in each SCC")
    {
        REQUIRE(comp1.size() == 4);
        REQUIRE(comp2.size() == 4);
        REQUIRE(comp3.size() == 2);
    }

    SECTION("Correct element in SCC")
    {
        REQUIRE(SCC1.find("LAX") != SCC1.end());
        REQUIRE(SCC2.find("WNZ") != SCC2.end());
        REQUIRE(SCC3.find("DXB") != SCC3.end());
    }
}
