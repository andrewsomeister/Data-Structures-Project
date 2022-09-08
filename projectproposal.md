# Final Project Proposal
connorm9-shallat3-andrew40-messina4

## Leading Question
- Where are the points of highest concentration of cars in California? Are these points near each other? Additionally, how can we connect and supply power to intersections using the least amount of resources? The dataset does not contain information about power generating sources or car locations, so we will be acting under the assumption that there will be a power generating source somewhere in the minimum spanning tree. These questions should be addressed by our implementations of Prim's algorithm and Betweenness Centrality.


## Dataset Acquisition and Processing
- We plan to use a dataset where intersections can be represented as vertices, and the edges are roads with their corresponding lengths. The data is acquired from University of Utah online at https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm. The data will be stored in a .txt file, with values separated by spaces and stored inside of the git repository. To parse this data, we will traverse through the data and enter values into a 2d array, with the first column being the edge number, the second being the starting node, the third being the ending node, and the final being the edge distance. Each data point has one of each of these values. In our code, we will convert the data into a graph datastructure and perform our algorithms on the graph. The datastructure will consist of a list of integers for the nodes, and a list of pairs of integers for the edges. In the case of any missing entries or clear mistypings, the entire datapoint will be deleted from the .txt file.

## Graph Algorithms
- Our group will implement the Breadth First Search algorithm, Prim's algorithm, and find the Betweenness Centrality of the graph utilizing the Dijkstra's Algorithm.
- The BFS will take an arbitrary starting node as an input, and will return a traversal through all of the nodes of the graph. 
- In the case where the graph is disconnected, once a connected component is finished with the BFS, if all nodes have not yet been visited, we will search the node list for the first non-visited node, and begin the BFS traversal again at that node.
- The BFS will be used to traverse the graph and reach all of the nodes and edges.
- Prim's Algorithm will help us to decipher the minimum spanning tree of the set of nodes, which represent intersections in our dataset. Our method will take in a set of nodes and output the set of edges that make up the minimum spanning tree. We expect our implementation to run in O(Elog(V)) time, where E is the number of edges and V is the number of vertices.
- For the Betweenness Centrality, we will take in a set of nodes, and return a sorted list of nodes from most-central to least central. Since there are multiple ways to perform this algorithm, we decided to use Dijkstra's algorithm. We expect the algorithm to be run in O(N^3) time.
- The output of our algorithms will be printed into different files within the git repository, where the results can be analyzed.
- By Narrowing down which nodes are the most central in the dataset, the Betweenness Centrality algorithm should give us a good estimate of the intersections that might have high volume of traffic. This is true because the edges in the dataset have the distance as the weight, and intersections as the nodes.
- Because Prim's algorithm connects a group of nodes using the least distance (in our use case), it should display the most optimal way of connecting a group of nodes. Since power lines must all connect to one another, this algorithm should give a good way of optimizing the use of materials. We acknowledge that we do not have data on power suppliers, however, so we are assuming that there are adequate suppliers in any group of nodes.

## Timeline
- First, we will find our data (we already have). We expect to finish the code for processing the data and storing it, along with the BFS traversal by November 22. We expect to finish Prim's algorithm by the Mid-Project checkin. This should give us enough time to focus on the development of Betweenness Centrality during the final weeks of the project. We then expect to finish Dijkstra's algorithm by December 5, and the Betweenness Centrality implementation by December 10. This gives us enough time before December 13 to wrap up our Final Project Deliverables.
