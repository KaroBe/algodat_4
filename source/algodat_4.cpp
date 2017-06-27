/*

Karoline Brehm
117190

SS2017

Algorithmen und Datenstrukturen - Beleg 3

*/

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

typedef std::vector<std::vector<int>> matrix;


/*
arcs are defined as pairs of different nodes a and b, which are identified
by their index in the adjacency matrix and have a certain weight
*/
struct Arc
{
	Arc(int a,int b, int weight) :
		m_a{a},
		m_b{b},
		m_weight{weight}
		{};

	int m_a;
	int m_b;
	int m_weight;
	
	//overloading < operator for priority queue
	bool operator>(Arc const& arc) const
	{
		return m_weight > arc.m_weight;
	};
};

/*
function that prints a given matrix to the command line,
adjusting spaces for 1 and 2 digit numbers
*/
void print_matrix(matrix mat)
{
	std::cout << "\ncolumn:\t";
	// print 
	for(int i=0; i<mat.size(); ++i)
	{
		std::cout << i;
		//print spaces according to value length
		if (i > 9)
		{
			std::cout << "  "; //2 spaces
		}
		else
		{
			std::cout << "   "; //3 spaces
		}
	}
	std::cout << "\n";

	//iterate rows
	for(int i = 0; i < mat.size(); ++i)
	{
		std::cout << "\nrow " << i << ":\t";
		//iterate columns
		for(int j = 0; j < mat.size(); ++j)
		{
			//print value of cell at row i and column j
			std::cout << mat[i][j];

			//print spaces according to value length
			if (mat[i][j] > 9)
			{
				std::cout << "  "; //two spaces
			}
			else
			{
				std::cout << "   "; //three spaces
			}
		}

		std::cout << "\n";
	}
}

/*
function printing an vector of arcs to the command line
*/
void print_arcs(std::vector<Arc> arc_list)
{
	std::cout << "Arcs: \n";
	for (Arc a : arc_list)
	{	
		std::cout
			<< "a: " << a.m_a  << " " 
			<< " b : " << a.m_b << " "
			<< " w : " << a.m_weight << "\n";	
	}
}

/*
function printing an priority queue of arcs to the command line
*/
void print_queue(std::priority_queue<Arc, std::vector<Arc>, std::greater<Arc>> arc_list)
{
	//copy of the Vector is passed as function argument, and elements popped until
	//empty, which does not change original Vector
	std::cout << "Arcs: \n";
	while (!arc_list.empty())
	{
		Arc a = arc_list.top();
		std::cout
			<< "a: " << a.m_a  << " " 
			<< " b : " << a.m_b << " "
			<< " w : " << a.m_weight << "\n";
		arc_list.pop();
	}
}

/*
function that constructs adjacency matrix from given vector of arcs
*/
matrix make_adj_matrix(std::vector<Arc> graph_arcs)
{
	//get number of different nodes in graph by creating set, which
	//holds each node only once as key, and getting size of that set
	std::set<int> nodes;
	for (Arc arc : graph_arcs)
	{
		nodes.insert(arc.m_a);
		nodes.insert(arc.m_b);
	}
	int num_nodes = nodes.size();

	// Empty Adjacency Matrix of graph with number columns and rows equal to
	//number of nodes in graph
	matrix adj_matrix;
	for(int i = 0; i<num_nodes; ++i)
	{
		adj_matrix.push_back(std::vector<int>(num_nodes,0)); //{0,0,...,0}
	}

	// Write weights to adjacency matrix to achieve correct representation
	// of graph and weigthed arcs
	for (Arc arc : graph_arcs)
	{
		//must substract 1 because index starts at 0, different from
		//names in graph
		adj_matrix[arc.m_a][arc.m_b] = arc.m_weight; //e.g matrix[1][2] = 4
		adj_matrix[arc.m_b][arc.m_a] = arc.m_weight; //	matrix[2][1] = 4
	}

	return adj_matrix;
}

/*
function that takes adjacency matrix and prints minimal spanning tree
*/
matrix prim (matrix const& adj_matrix)
{
	//num_nodes holds number of nodes in the graph
	int num_nodes = adj_matrix.size();

	//priority queue holding arcs that have been reached but
	//not added to minimal spanning tree
	//top element in queue is arc with smallest weight
	std::priority_queue<Arc, std::vector<Arc>, std::greater<Arc>> pr_queue;

	//vector of nodes that have NOT been visited
	//fill with indices of all nodes, as none has been visited yet
	std::set<int> unvisited;
	for(int i = 0; i<num_nodes; ++i)
	{
		unvisited.insert(i);
	}

	//vector of nodes that have been visited
	//emtpy, as none has been visited yet
	std::set<int> visited;

	//vector holding arcs that form minimal spanning tree
	std::vector<Arc> tree;

	/* STEP A

	- start with first node of index i in unvisited
	- iterate column i of adj_matrix with variable j
	- if j is unvisited and has connection to i, so that
	  adj_matrix[i][j] != 0, add that arc to the priority queue
	  and move the node from the unvistited set to the visited set

	*/

	for(int j = 1; j<num_nodes; ++j)
	{
		int weight = adj_matrix[0][j];
		if(unvisited.find(j) != unvisited.end() and weight != 0)
		{
			pr_queue.push(Arc{0,j,weight});
		}
	}

	visited.insert(0);
	unvisited.erase(0);

	/* STEP B

	- repeat Step B while there are unvisited nodes:

	- while the top arc (defined by nodes a and b, and a weight) of the priority queue has a "b" node
	  that has been visited,  skip the arc and pop it from the queue,
	  because it would form a circle, as the "a" node must have been visited already if the arc 		  appears in the priority queue
	 
	- then, if the priority queue is not empty
		- add the arc on top of the priority queue (which has the
		  minimal weight and does not create a circle) to the minimal spanning tree
		- move second arc node "b" to the visited vector ("a" has)
		- iterate column of the newly visited node "b" with variable j
		- if j is unvisited and has connection to i, so that
	  	  adj_matrix[i][j] != 0, add that arc to the priority queue
			-> adding all arcs connected to j to the priority queue, then start from
			   the beginning of Step B
	*/

	//while there are unvisited nodes
	while(!unvisited.empty())
	{
		Arc top = pr_queue.top();

		//visited.find() returns iterator to node in visited -> if it points to end of
		//set if the node has not been visited yet
		if(visited.find(top.m_b) != visited.end())
		{
			pr_queue.pop(); 	//pop arc from priority queue
			top = pr_queue.top();	//top contains the new top element of the queue
		}

		if(!pr_queue.empty())
		{
			Arc added_arc = pr_queue.top();

			tree.push_back(top);	//add arc to minspan tree

			pr_queue.pop();		//pop from priority queue

			//move node "b" from unvisited to visited set
			unvisited.erase(added_arc.m_b);
			visited.insert(added_arc.m_b);

			Arc new_top = pr_queue.top();

			//iterate column of newly visited node "b"
			for(int j = 0; j<num_nodes; ++j)
			{
				int weight = adj_matrix[added_arc.m_b][j];
				if(visited.find(j) == visited.end() and weight != 0)
				{
					//add all arcs attached to "b" to the priority queue
					pr_queue.push(Arc{added_arc.m_b,j,weight});
				}
			}
		}
	}

	//return the minimal spanning tree as matrix created with make_adj_matrix function
	return make_adj_matrix(tree);
	
} //end prim

int main ()
{
	// Vector containing all arcs of graph
	std::vector<Arc> graph_arcs {
		{0,1,4}, {0,5,10},
		{1,2,2},
		{2,4,7}, {2,6,5},
		{3,4,1}, {3,6,8}, {3,7,5},
		{4,6,2}, {4,11,5},
		{5,6,2}, {5,7,10},
		{7,8,3},
		{8,9,7},
		{9,10,1}
	};

	//make adjacency matrix from given arcs
	matrix adj_matrix = make_adj_matrix(graph_arcs);
	std::cout << "\nOriginal Adjacency Matrix: \n";
	print_matrix(adj_matrix);

	//hand over adjacency matrix to prim function to calculate minimal spanning tree
	matrix minspan_tree = prim(adj_matrix);
	std::cout << "\nMinimal Spanning Tree: \n";
	print_matrix(minspan_tree);
}