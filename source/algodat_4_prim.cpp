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
			//print value
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
function that constructs adjacency matrix from given arcs
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

	// Empty Adjacency Matrix of graph with num_nodes columns and rows
	matrix adj_matrix;
	std::cout << "adj_matrix deklaration\n";
	for(int i = 0; i<num_nodes; ++i)
	{
		adj_matrix.push_back(std::vector<int>(num_nodes,0)); //{0,0,...,0}
	}

/*
	std::cout << "\nEmpty Matrix: \n";
	print_matrix(adj_matrix);	
*/

	// Write weights to adjacency matrix to achieve correct representation
	// of graph and weigthed arcs
	for (Arc arc : graph_arcs)
	{
		//must substract 1 because index starts at 0, different from
		//names in graph
		adj_matrix[arc.m_a][arc.m_b] = arc.m_weight; //e.g matrix[1][2] = 4
		adj_matrix[arc.m_b][arc.m_a] = arc.m_weight; //	matrix[2][1] = 4
	}

/*
	std::cout << "list of arcs in graph: \n";
	print_arcs(graph_arcs);
*/

	return adj_matrix;
}

/*
function that takes adjacency matrix and prints minimal spanning tree
*/
void prim (matrix const& adj_matrix)
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
	std::cout << "print unvisited nodes: \n";
	std::copy(std::begin(unvisited), std::end(unvisited),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << "-\n";


	//vector of nodes that have been visited
	//emtpy, as none has been visited yet
	std::set<int> visited;
	std::cout << "print visited nodes: \n";
	std::copy(std::begin(visited), std::end(visited),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << "-\n";

	//vector holding arcs that form minimal spanning tree
	std::vector<Arc> tree;

	/* STEP A

	- start with first node of index i in unvisited
	- iterate column i of adj_matrix with variable j
	- if j is unvisited and has connection to i, so that
	  adj_matrix[i][j] != 0, add that arc to the priority queue
	*/

	for(int j = 1; j<num_nodes; ++j)
	{
		int weight = adj_matrix[0][j];
		if(unvisited.find(j) != unvisited.end() and weight != 0)
		{
			pr_queue.push(Arc{0,j,weight});
			std::cout << "add to priority queue " << 0 << " " << j
				<< " " << weight << "\n";
		}
	}

	visited.insert(0);
	unvisited.erase(0);

	std::cout << "print visited nodes: \n";
	std::copy(std::begin(visited), std::end(visited),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << "-\n";

	std::cout << "\npriority queue: \n";
	print_queue(pr_queue);
	std::cout << "\n";

	/* STEP B

	- while there are unvisited nodes
	{
	- while the top arc of the priority queue has nodes that both have been
	  visited, discard the arc
	- if the priority queue is not empty
		- add the arc on top of the priority queue (which has the
		  minimal weight) to the minimal spanning tree
		- move second arc node arc.m_b to the visited vector
		- iterate column of the newly visited node i with variable j
		- if j is unvisited and has connection to i, so that
	  	  adj_matrix[i][j] != 0, add that arc to the priority queue
	}
	*/

	//while there are unvisited nodes
	while(!unvisited.empty())
	{
		Arc top = pr_queue.top();
		std::cout << "Top arc: " << top.m_a << " " << top.m_b
				<< " " << top.m_weight << "\n";

		//while the top arc of the priority queue has nodes that both have been
	  	//visited, discard the arc
		//visited.find() returns iterator to node in visited -> if it points to end
		//the node has not been visited yet

		bool test = visited.find(top.m_b) != visited.end(); //if this is true: node has been visited
									//	false : not has NOT been visited
		std::cout << "\nhas b been visited? " << test << "\n";
		
		if(visited.find(top.m_b) != visited.end())
		{
			std::cout << "skip " << top.m_a << " " << top.m_b
				<< " " << top.m_weight << "\n";
			std::cout << "pop from queue: " << pr_queue.top().m_a << " " << pr_queue.top().m_b
				<< " " << pr_queue.top().m_weight << "\n";
			pr_queue.pop();
			top = pr_queue.top();
			std::cout << "new top is: " << top.m_a << " " << top.m_b
				<< " " << top.m_weight << "\n";

		}

		if(!pr_queue.empty())
		{
			Arc added_arc = pr_queue.top();

			tree.push_back(top);	//add arc to minspan tree
			std::cout << "add to minspan tree : " << added_arc.m_a << " " << added_arc.m_b
				<< " " << added_arc.m_weight << "\n";
			std::cout << "pop from queue : " << added_arc.m_a << " " << added_arc.m_b
				<< " " << added_arc.m_weight << "\n";	

			pr_queue.pop();			//pop from priority queue

			unvisited.erase(added_arc.m_b);
			std::cout << "unvisited.erase: " << added_arc.m_b << "\n";
			visited.insert(added_arc.m_b);
			std::cout << "visited.insert top: " << added_arc.m_b << "\n";

			Arc new_top = pr_queue.top();

			//iterate column of newly visited 
			for(int j = 0; j<num_nodes; ++j)
			{
				int weight = adj_matrix[added_arc.m_b][j];
				if(visited.find(j) == visited.end() and weight != 0)
				{
					pr_queue.push(Arc{added_arc.m_b,j,weight});
					std::cout << "add to priority queue: " << added_arc.m_b << " " << j
					<< " " << weight << "\n";
				}
			}

			std::cout << "print visited nodes: \n";
				std::copy(std::begin(visited), std::end(visited),
				std::ostream_iterator<int>(std::cout, " "));
				std::cout << "-\n";	
			
			std::cout << "print unvisited nodes: \n";
				std::copy(std::begin(unvisited), std::end(unvisited),
				std::ostream_iterator<int>(std::cout, " "));
				std::cout << "-\n";	
			
			std::cout << "\n_this is the end of one while (unvisited != empty) loop __\n";

		} //endif
		

	} //end while unvisited not empty

	matrix minimal_spanning_tree = make_adj_matrix(tree);
	print_matrix(minimal_spanning_tree);
	
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

	matrix adj_matrix = make_adj_matrix(graph_arcs);
	std::cout << "\n make_adj_matrix output: \n";
	print_matrix(adj_matrix);

	//hand over adjacency matrix to kruskal function
	std::cout << "\nhand over adjacency matrix to prim function\n";
	prim(adj_matrix);
}
