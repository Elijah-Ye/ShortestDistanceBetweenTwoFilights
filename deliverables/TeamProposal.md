# Final Project Proposal
## Leading Question
Millions of people are taking flight everyday. We want to build a search tool that helps people to find the best way for them to travel by using airline route data from Open Flights. ([https://openflights.org/data.html](https://openflights.org/data.html)) By using the route and airport dataset on the website, we can have 67663 routes between 3321 airports on 548 airlines as well as name, ID, location of each airport and airline. Using the algorithms listed below, we can generate a shortest path from one airport to another. If time permits, we can use our tool to plan a trip that includes various stop points and find a preferred route.

## Dataset Acquisition and Processing
- Data Format
	- The Dataset we are using is from Open flights which is the open source data set of flights routes and airports (https://openflights.org/data.html). The input data is .dat format. The size of the dataset varies from 400 KB to 2 MB. We plan to use all of the dataset. 
- Data Correction
	- When we are reading the data from the document, we will check if there are errors due to invalid or uninterpretable data. Then we will treat them as false data and ignore them. Also, some information of the original dataset might not be useful for our project goal, so they will be neglected as well.
- Data Storage
	- We will download the data from open flights (airports.dat and routes.dat) and upload them into our github repo initially. Then we will create a graph with airports as nodes, routes as edges, and the distance between two airports as the weight of the edges. Assuming there are n nodes/n airport in total, the running time of building edges between all nodes takes O(n^2) as, for each node, we need to traverse all the data to see if there’s an edge between them. And the running time of building weights takes O(n^2) as we need to traverse the airport data to get each node’s location information. Consequently, it’s estimated that the storage cost for the dataset is O(n^2). To be mentioned, the content of the graph is not covered yet in the lecture. So the big O analysis above might not be correct based on what we have learned till now.

## Graph Algorithms
- Traversal
	- We will traverse our graph by the DFS algorithm. When we are given a starting airport as the input, we will use DFS to find all the airports that have a flight connecting with it. The input to the traversal algorithm will be the graph and the target node/target airport, and the output will be the collection of nodes that connect to it. The time complexity of the DFS traversal in graphs is O(|V| + |E|), which |V| represents the number of vertices (in this case, the number of airports) and |E| represents the number of edges.
-   Shortest Path Algorithms
    

	-   Dijkstra’s Algorithm

		- Here, we will use the longitude and the latitude of the airports to calculate the distance between the airports. This distance will then serve as the weight of edges. Then we will use Dijkstra’s Algorithm to find the shortest distance travelled between two airports (node). The inputs to Dijkstra's algorithm are a directed and weighted graph consisting of 2 or more nodes, And the output is a set of edges depicting the shortest path to each destination node. Efficiency is : O(|E|+|V|log|V|) where |V| represents the number of vertices (in this case, the number of airports) and |E| represents the number of edges.

	-   Strongly Connect Component(Kosaraju's Algorithm)
   
		- Here, Kosaraju's algorithm to find strongly connected components on our graph or airplane routes. Kosaraju's algorithm actually just DFS implemented twice. So it's runtime is the same as DFS which is O(|V| + |E|), which |V| represents the number of vertices (in this case, the number of airports) and |E| represents the number of edges.

## Timeline
| Time Period |  Goal |
|--|--|
| 3.27-4.5| Load the data and build the graph. Dijkstra’s Algorithm setup (write and debug, including writing the test case )* |
|4.6-4.14  |Landmark Algorithm setup (write and debug, including writing the test case)|
| 4.15-4.22 |Building Final Project (write functions needed for achieving the goal)  |
|4.23-4.29  |Test the program (write test cases and make sure the correctness of the output)|
|4.30-5.6  |Complete Presentation and Report|