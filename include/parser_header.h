#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include "graph.h"

using namespace std;
using openFlight::Graph;

typedef vector<Graph::Node> VectorOfNodes;

namespace openFlight{
class Parser {
public: 

    Parser();
    VectorOfNodes parseAirportData(string filename);
    unordered_map<string, Graph::Node> buildAirportMap(VectorOfNodes airportData);
    unordered_map<string, unordered_map<string, Graph::Edge>> parseRouteData(VectorOfNodes airportData, string filename2);
    double calculateGreatCircleDist(Graph::Node source, Graph::Node destination);
};
}
