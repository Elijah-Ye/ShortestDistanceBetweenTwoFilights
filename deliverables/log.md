# Development Log
## March 27 7-9pm
- Last week goal and our status
	We finished our finalProjectProposal and teamContract. However, there are some mistakes that we need to fix. 

- Goals for next week
	We plan to fix our finalProjectProposal first. Then we will retrive all of our data from open flight and push them into our git repo. We want to contruct our graph with node being the airport and the edge being the route. 
- Work Divided
	retrieve data from openFlight - Elijah
	parse data into a data structure - Elijah
	airport.h & airport.cpp - Bowei
	route.h & route.cpp - Michael

## April 3rd 7-9pm
- Last week goal and our status
	We downloaded the airport and route data. Finished the airport and route class, which will be used as vertex and edge for the graph construction. The airport and route class might need further implemented depending on the development of the project.

- Meetings for this week:
    -Git: We learned about how git teamwork works from this video (https://www.youtube.com/watch?app=desktop&v=RzYJvSnzlMk) and decided to create branches for each team member for the sake of better collaboration and avoiding code confiction. We also learned some basic git commands.
	-Time commitment: We talked about each team member's time commitment schedule for the following weeks.
		Elijah: M. W. F. 12.30-2pm + Saturday if goal not complished
		Bowei: M-W 2.5h T-F 2h + Saturday if goal not complished
		Micahel: T 2h F 2-3 hours
	-Modulazation: We talked about the modulazation of git projects and will follow the pattern as what is used in the template.

- Goals and Work division for next week
=======
	parsing (Elijah)
	Graph construction using Adjacent List (Bowei, Michael):
		- Building new graph branch, building the structure of graph.h based on the goal , implementing some of graph class functions, writing some of the test case.(Bowei)
		- Implementing some of graph class functions, writing some of the test case. (Michael)
>>>>>>> main

## April 10th 10-12pm
- Last week goals and our status
	We finished the parsing function which is used to parse the data file (in this case, the airport data and route data) into two vector files. We created the graph class which contains the methods like adding vertex and edge into our graph.

- Meeting for this week
	We set our goal as completing the DFS algorithm before Friday next week. 
	
- Goals and Work division for next week
	Graph class build (Bowei, Elijah):
		- change some graph class functions and implementing some functions.
	BFS & DFS build (Michael):
		- implement DFS algorithm in map class. 

## April 17th 3-5pm
- Last week goals and our status
  - We changed our template to something we can understand better. We finished building our Graph class. We might need a few more functions in it if we find them helpful. We started DFS, but we run into some bugs. 

- Meeting for this week
  - Bowei talked about how our DFS is very similar to MP_traversal. We talked about how to debug. We divided the work for next week. 

- Goals and work for next week
  - Debug our DFS (Elijah)
  - Writing test cases (Bowei)
  - Review code before Tuesday (Michael) Dijstra after Wednesday(Michael)

## April 17th 3-5pm
- Last week goals and our status
	- We finished the DFS algorithm along with changing the strategy of building our Graph from implementing through pointers to string. We also wrote test cases for them and passed for mid-checkpoint

- Meeting for this week
	- We divided the work for next week.

- Goals and work for next week
	- Update test cases according to the requirements: creating a small private dataset for parsing + testcase for connected components (
	Elijah)
	- Write Dij. algorithm (Elijah & Bowei)
	- Write strongly connected component algorithm (Bowei, firstly to understand)

## May 1st 3-5pm
- Last week goals and our status
	- We finished the last algorithm :SCC algorithm and the corresponding test cases. 
	
- Meeting for this week
	Elijah and me discuss about the content we want to include in the github "readme", final report and presentation.

- Goals and work for next week
 - Write the readme file in github (Bowei, May 3rd)
 - Finish the final report (Elijah, May 3rd)
 - Finish the presentation (Bowei, Elijah, Michael, May 4th)
 - User input based code to update. (Elijah, May 1st)

