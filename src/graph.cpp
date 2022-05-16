#include "../include/graph.h"

namespace openFlight{
    Graph::Graph()
    {

        // visited = unordered_map<string, bool>();
        // allNodes = vector<string>();
        // connectedComp = unordered_map<string, int>();
        // path = vector<string>();
        // numConnectedComp = 0;
        adj_list = unordered_map<string, unordered_map<string, Graph::Edge>>();
        nameToNode = unordered_map<string, Graph::Node>();
    }
    
    Graph::Graph(unordered_map<string, Node> nodes, unordered_map<string, Edge> edges) {
        
    }

    vector<string> Graph::getAdjacentNodes(string IATA){
        vector<string> adjacentNodes;
        auto lookup = adj_list.find(IATA);
        if(lookup != adj_list.end()) {
            for(auto i = adj_list[IATA].begin(); i != adj_list[IATA].end(); ++i) {
                adjacentNodes.push_back(i->first);
            }
        }
        return adjacentNodes;
    }

    vector<string> Graph::getAdjacentNodes(string IATA, unordered_map<string, unordered_map<string, Graph::Edge>> &gR){
        vector<string> adjacentNodes;
        auto lookup = gR.find(IATA);
        if(lookup != gR.end()) {
            for(auto i = gR[IATA].begin(); i != gR[IATA].end(); ++i) {
                adjacentNodes.push_back(i->first);
            }
        }
        return adjacentNodes;
    }


    vector<string> Graph::getNodes(unordered_map<string, unordered_map<string, Graph::Edge>> &adj_list){
        vector<string> nodes;
        for(auto i = adj_list.begin(); i != adj_list.end(); ++i) {
            nodes.push_back(i->first);
        }
        return nodes;
    }

    // void Graph::DFS(string start) {
    //     numConnectedComp++;

    //     vector<string> tempPath;
    //     stack<string> stack;
    //     stack.push(start);

    //     while(!stack.empty()) {
    //         string curr = stack.top();
    //         stack.pop();

    //         if(!visited[curr]) {
    //             visited[curr] = true;
    //             tempPath.push_back(curr);
    //             connectedComp[curr] = numConnectedComp;
    //         }

    //         vector<string> adjacentNodes = getAdjacentNodes(curr);
            
    //         for(auto i = adjacentNodes.begin(); i != adjacentNodes.end(); ++i) {
    //             if(!visited[*i]) {
    //                 stack.push(*i);
    //             }
    //         }
    //     }
        
    //     auto it = path.end();
    //     path.insert(it, tempPath.begin(), tempPath.end());

    //     for(auto i = connectedComp.begin(); i != connectedComp.end(); ++i) {
    //         if(i->second < 0){
    //             DFS(i->first); //hopefully it can traverse the whole graph
    //         }
    //     }

    // }

    vector<string> Graph::DFS(string start) {
        unordered_map<string, bool> visited;
        vector<string> allNodes = getNodes(adj_list);

        for(auto i = allNodes.begin(); i != allNodes.end(); ++i) {
            visited[*i] = false;
        }

        vector<string> path;
        stack<string> stack;
        stack.push(start);

        int DFS1 = 0;
        while(!stack.empty()) {
            //cout << "DFS1: " << DFS1 << endl;
            DFS1++;
            string curr = stack.top();
            stack.pop();

            if(!visited[curr]) {
                visited[curr] = true;
                path.push_back(curr);
            }

            vector<string> adjacentNodes = getAdjacentNodes(curr);
            
            for(auto i = adjacentNodes.begin(); i != adjacentNodes.end(); ++i) {
                if(!visited[*i]) {
                    stack.push(*i);
                }
            }
        }
        
        return path;
    }

    vector<string> Graph::DFS(string start, unordered_map<string, unordered_map<string, Graph::Edge>> &gR)
    {
        unordered_map<string, bool> visited;
        vector<string> allNodes = getNodes(gR);

        for(auto i = allNodes.begin(); i != allNodes.end(); ++i) {
            visited[*i] = false;
        }

        vector<string> path;
        stack<string> stack;
        stack.push(start);
        
        int DFS2 = 0;
        while(!stack.empty()) {
            //cout << "DFS2: " << DFS2 << endl;
            DFS2++;
            string curr = stack.top();
            stack.pop();

            if(!visited[curr]) {
                visited[curr] = true;
                path.push_back(curr);
            }

            vector<string> adjacentNodes = getAdjacentNodes(curr, gR);
            
            for(auto i = adjacentNodes.begin(); i != adjacentNodes.end(); ++i) {
                if(!visited[*i]) {
                    stack.push(*i);
                }
            }
        }
        
        return path;
    }

    bool Graph::edgeExists(string src, string dest) {
        auto lookup = adj_list.find(src);
        if(lookup != adj_list.end()) {
            auto lookup2 = adj_list[src].find(dest);
            if(lookup2 != adj_list[src].end()) {
                return true;
            }
        }
        //cout << "There is no edge between " << src << " and " << dest << endl;
        return false;
    }

    //Dijsktra's algorithm------------------------------------------------
    string Graph::minDist(unordered_map<string, int> flightDist, unordered_map<string, bool> visited, int numAirports, vector<string> allAirports){
        string min = "";
        int min_dist = INT_MAX;
        for(int i = 0; i < numAirports; i++){
            if(!visited[allAirports[i]] && flightDist[allAirports[i]] < min_dist){
                min = allAirports[i];
                min_dist = flightDist[allAirports[i]];
            }
        }
        return min;
    }

    vector<string> Graph::recursivePath(unordered_map<string, string> parent, string cur, vector<string> populate_path){
        if(parent[cur] == "-1"){
            reverse(populate_path.begin(), populate_path.end());
            return populate_path;
        }
        
        populate_path.push_back(parent[cur]);
        return recursivePath(parent, parent[cur], populate_path);
        
        cout << cur << endl;
    }

    vector<string> Graph::print(unordered_map<string, int> flightDist, int numAirports, unordered_map<string, string> parent, vector<string> allAirports, string source, string dest, vector<string> populate_path){
        for (int i = 1; i < numAirports; i++) 
        { 
            if (allAirports[i] == dest) {
                if(flightDist[dest] == INT_MAX){
                    cout << "No path exists" << endl;
                }
                else {
                    std::cout << "Your Flight Information: \n" << std::endl;

                    cout << source << " -> " << allAirports[i] << "   Total Distance: " <<  flightDist[allAirports[i]]
                    << "km \n" << endl;
                }
            }
        }
        populate_path.push_back(dest);
        return recursivePath(parent, dest, populate_path); 
    }

    vector<string> Graph::dijkstra(string source, string dest){
        unordered_map<string, int> flightDist;
        unordered_map<string, bool> visited;
        unordered_map<string, string> parentMap;
        vector<string> populate_path;
        parentMap[source] = "-1";

        vector<string> allAirports = getNodes(adj_list);
        int numAirports = allAirports.size();

        for(int i = 0; i < numAirports; i++){
            flightDist[allAirports[i]] = INT_MAX;
            visited[allAirports[i]] = false;
            parentMap[allAirports[i]] = "-1";
        }

        flightDist[source] = 0;

        for(int i = 0; i < numAirports; i++){
            //cout << "Iteration: " << i << endl;
            string u = minDist(flightDist, visited, numAirports, allAirports);
            visited[u] = true;

            for(int j = 0; j < numAirports; j++){
                if(edgeExists(u, allAirports[j]) && !visited[allAirports[j]]){
                    int alt = flightDist[u] + adj_list[u][allAirports[j]].weight;
                    if(alt < flightDist[allAirports[j]]){
                        //cout << allAirports[j] << " " << alt << endl;
                        flightDist[allAirports[j]] = alt;
                        parentMap[allAirports[j]] = u;
                    }
                }
            }
        }
        return print(flightDist, numAirports, parentMap, allAirports, source, dest, populate_path);
    }
    //--------------------------------------------------------------------

    //SCC Functions------------------------------------------------------------
    unordered_map<string, unordered_map<string, Graph::Edge>> Graph::reverseGraph()
    {
        unordered_map<string, unordered_map<string, Edge>> reverse_graph;
        for(auto i = adj_list.begin(); i != adj_list.end(); ++i) {
            for(auto j = adj_list[i->first].begin(); j != adj_list[i->first].end(); ++j) {
                Edge e;
                e.dest = nameToNode[i->first];
                e.weight = j->second.weight;
                e.src = nameToNode[j->first];
                reverse_graph[j->first][i->first] = e;
                //cout << "Edge: " << reverse_graph[j->first][i->first].src.name << " " << reverse_graph[j->first][i->first].dest.name << endl;
            }
        }
        return reverse_graph;
    }

    vector<string> Graph::getSCC(string start){
       // cout << "Getting SCC" << endl;
        vector<string> path1 = DFS(start);
        unordered_map<string, unordered_map<string, Graph::Edge>> gR = reverseGraph();
        vector<string> path2 = DFS(start, gR);
        vector<string> scc;
        int first = 0;
        for(auto i = path1.begin(); i != path1.end(); ++i) {
            //cout << "first: " << first << endl;
            first++;
            if(find(path2.begin(), path2.end(), *i) != path2.end()) {
                scc.push_back(*i);
            }
        }

        return scc;
    }

    vector<vector<string>> Graph::getSCC() //this will find all SCC in the graph
    { 
        //cout << "Getting SCCs" << endl;
        vector<string> allNodes = getNodes(adj_list);
        vector<vector<string>> scc;
        int second = 0;
        for(auto i = allNodes.begin(); i != allNodes.end(); ++i) {
            //cout << "second: " << second << endl;
            second++;
        
            bool visited = false;
            //cout << "SCCs size: " << scc.size() << endl;
            for(unsigned long x = 0; x < scc.size(); x++) {
                if(find(scc[x].begin(), scc[x].end(), *i) != scc[x].end()) {
                    visited = true;
                    break;
                }
            }
            // print visited
            //cout<<"Visited: "<<visited<<endl;
            if(!visited) {
                vector<string> temp = getSCC(*i);
                scc.push_back(temp);
            }
            // for(unsigned i = 0; i < scc.size(); i++)
            // {
            //     if(scc_i == scc[i])
            //     {
            //         isSame = true;
            //         break;
            //     }
            // }

            // if(!isSame)
            // {
            //     scc.push_back(scc_i);
            // }
        }

        return scc;

    }

    //--------------------------------------------------------------------
}


