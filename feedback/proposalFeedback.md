### Grade
Incomplete (0%) [Please dont edit these feedback documents.]

Must resubmit! (But will not be penalized for resubmission since only major issue is landmark path)
### Comments
A very well-written proposal overall but unfortunately one that you will need to resubmit to include three valid algorithms. One minor flaw in the runtime for algorithms (in addition to the major problem of landmark path.)

**Leading Question**
The leading question makes sense and has room for a more ambitious version, which is good to see.

**Dataset**
The dataset is well described and the intuition on the efficiency of runtime and storage are good (although we will see alternatives which are better in some contexts).

**Algorithm**
Your proposed efficiency for Dijkstras seems incomplete. |E| log |V| is *probably* not the only factor here -- I would consider taking a look further at the efficiency. Note that some of the more advanced versions of Dijkstras use challenging data structures like a Fibonnaci min-heap. You do not need to implement such functions but make sure that your proposed efficiency is something you can accomplish. This is only a minor issue though and one you can easily adjust moving forward as you learn more about Dijkstras. 

The main issue with your proposal is that landmark path is simply not an allowed 'uncovered' algorithm as it is literally just Dijkstras run X-1 times for X landmarks. I would suggest something like betweenness-centrality, strongly connected components, or an Eulerian path / cycle algorithm. 