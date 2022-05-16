#include "../include/parser_header.h"

//std::cout <<  << std::endl;

// using openFlight::Node;
// using openFlight::Edge;

namespace openFlight {

Parser::Parser() {
}

vector<Graph::Node> Parser::parseAirportData(string file1){
    string line;
    ifstream input(file1);
    vector<Graph::Node> airports;
    int line_count = -1;
     
    //getline(input, line);
    while(getline(input, line) && line.length() != 0)
    {
        line_count++; //increment line_count;
        //cout << line_count << endl;

        Graph::Node curr_point = Graph::Node();
        string name;
        double lat;
        double lng;

        int commaCount = 0;
        for (int i = 0; i < line.length(); ++i) 
        {
            if(line[i] == ',')
            {
                commaCount++;
            }
            if(commaCount == 4)
            {
                i += 2;
                commaCount++; //commaCount = 5
                // std::cout << i << std::endl;
                name = line.substr(i, 3);
            }
            if(commaCount == 7) //actual comma is 6
            {
                i++;
                commaCount++;
                std::string point1 = "";
                while(line[i] != ',')
                {
                    point1 += line[i];
                    i++;
                }
                i--;
                lat = std::stod(point1);
            }
            if(commaCount == 9) //actual comma is 7
            {
                i++;
                commaCount++;
                std::string point2 = "";
                while(line[i] != ',')
                {
                    point2 += line[i];
                    i++;
                }
                i--;
                lng = std::stod(point2);
            }
        }
        curr_point.name = name;
        curr_point.lat = lat;
        curr_point.lng = lng;

        airports.push_back(curr_point);
    }

    input.close();
    return airports;
}

unordered_map<string, Graph::Node> Parser::buildAirportMap(vector<Graph::Node> airportData) {
    unordered_map<string, Graph::Node> airportMap;
    for (auto i = 0; i < airportData.size(); i++) {
        airportMap[airportData[i].name] = airportData[i];
    }
    return airportMap;
}


 unordered_map<string, unordered_map<string, Graph::Edge>> Parser::parseRouteData(vector<Graph::Node> airportData, string edge_filename) {
    string line;
    ifstream input(edge_filename);
    unordered_map<string, Graph::Node> airportMap = buildAirportMap(airportData);
    unordered_map<string, unordered_map<string, Graph::Edge>> adj_list;

    // cout << "airportData size in the function: " << airportData.size() << endl;
    // cout << "airport map size in the function: " << airportMap.size() << endl;

    
    for(unsigned i = 0; i < airportData.size(); i++) {
        adj_list[airportData[i].name] = unordered_map<string, Graph::Edge>();
    }

    // cout << "Test route data size in the function: " << adj_list.size() << endl;

    int line_count = -1;
     
    //getline(input, line);
    while(getline(input, line) && line.length() != 0)
    {
        line_count++; //increment line_count;

        Graph::Edge edge = Graph::Edge();
        string src;
        string dest;
        int commaCount = 0;
        for (int i = 0; i < line.length(); ++i) 
        {
            if(line[i] == ',')
            {
                commaCount++;
            }
            if(commaCount == 2)
            {
                i++;
                commaCount++; //commaCount = 3
                // std::cout << i << std::endl;
                src = line.substr(i, 3);
            }
            if(commaCount == 5) //actual comma is 4
            {
                i++;
                commaCount++;
                dest = line.substr(i, 3);
            }
        }
        edge.src = airportMap[src];
        edge.dest = airportMap[dest];
        edge.weight = calculateGreatCircleDist(edge.src, edge.dest);
        adj_list[src][dest] = edge;
    }

    input.close();
    return adj_list;
}

double Parser::calculateGreatCircleDist(Graph::Node source, Graph::Node destination) {

        double lat1 = source.lat;
        double lon1 = source.lng;
        double lat2 = destination.lat;
        double lon2 = destination.lng;

        // Convert to radians
        lat1 = lat1 * M_PI / 180;
        lon1 = lon1 * M_PI / 180;
        lat2 = lat2 * M_PI / 180;
        lon2 = lon2 * M_PI / 180;

        // Calculate distance
        double dlon = lon2 - lon1;
        double dlat = lat2 - lat1;
        double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        double d = 6371 * c;

        return d;
}
}