# cs225-sp22 Final project
## Group member
- Elijah Gaohan Ye (gaohany2@illinois.edu)
- Bowei Song (boweis2@illinois.edu) 
- Michael Duan (hduan5@illinois.edu)

# Project Description
This project creates a graph of the airports and the connecting flight routes. The dataset used in this project is from OpenFlights. 
This project utilizes three algorithms: Depth-first search (DFS) algorithm, Dijkstra algorithm, and Strongly Connected Component(SCC) algorithm to reach following goals:
  -   Traverse the graph (DFS)
  -   Find the shortest distance travelled between two airports/node (Dijkstra)
  -   Find the strongly connected components that contains a certain airport/input, and the total number of strongly connected components in the graph (SCC)
  
# Running instructions to the project
  - To build and run the main.cpp: 
    - input and output data description:
      - input data format: 
        - automatically load airport and route data from OpenFlights to construct the graph
        - user-defined 3-letter IATA code of the scource and destination airport, for example: "PVG" , "ORD"
      - expected output format: 
        - The number and content of all airports by DFS from starting airport
        - The shortest path between the scource and destination airport (Dijkstra)
        - The specific SCC containing scource airport and the total number of SCCs in the graph
    - Command: ``` make main ``` ``` ./main ```
                      
                      
  - To build and run the test suite
    - 5 general test cases with each one respectively testing "parsing the airport data", "build the graph(airport map)", "DFS algorithm", "Dijkstra algorithm" "Strongly connected component algorithm"
    - Command: ``` make test_file ``` ``` ./test```
  
# Github files organization
  - "data": including proginal data from OpenFlights and local created data for tests
  - "include": including all header files to parse data, build graph and implement algorithms
  - "src": including cpp files to parse data, build graph and implement algorithms
  - "tests": including all the test cases
  - "deliverables": including the final report and presentation video
  - "main": user-based cpp file for the project 
  -  other files: including project development documentation, feedback, and grading
