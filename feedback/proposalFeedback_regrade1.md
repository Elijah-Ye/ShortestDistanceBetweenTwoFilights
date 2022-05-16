### Grade
Competent (90%) [Please dont edit these feedback documents.]

### Comments
The replacement of Kosaraju's algorithm instead of landmark path is sufficient but the algorithm is not well-described. Notably it is missing the input / output (which would normally be an immediate 70%). However since I can conceive of a Kosaraju algorithm which has mostly the same input as DFS I'm only going to take off 10%.

**Algorithm**
As one further comment on Kosaraju -- it is theoretically equivalent to running DFS twice but there's more to it than that. Your summary of the algorithm makes me worried you might not understand the algorithm itself. Be sure you understand (1) where to start the DFS search in both directions (2) how to adjust the graph edge directions (3) how to identify strongly connected components based on the two DFS output. 