/*

Karoline Brehm
117190

SS2017

Algorithmen und Datenstrukturen - Beleg 3

Note: It wasn't clear to me what form of input was required.
The kruskal_minspan_tree only requires an adjacency matrix as input,
however, I did not want to risk making a mistake entering the 12x12 matrix
which is why I create it from the given arcs.

*/

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> matrix;

//arcs are defined as pairs of different nodes a and b, which are identified
//by their index in the adjacency matrix and have a certain weight (other than 0)
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
};

//void print_matrix(matrix matrix)
void print_matrix(matrix mat)
{
	std::cout << "\ncolumn:\t";
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

void print_arcs(std::vector<Arc> arc_list)
{
	std::cout << "List of arcs in graph: \n";
	for (Arc arcs : arc_list)
	{	
		std::cout
			<< arcs.m_a -1  << " " 
			<< arcs.m_b - 1 << " "
			<< arcs.m_weight << "\n";	
	}
}

//make adjacency matrix from arcs
matrix make_adj_matrix(std::vector<Arc> graph_arcs)
{
	// Empty Adjacency Matrix of graph

	matrix adj_matrix;
	std::cout << "adj_matrix deklaration\n";
	for(int i = 0; i<12; ++i)
	{
		adj_matrix.push_back(std::vector<int>(12,0)); //{0,0,...,0}
	}
	std::cout << "\nEmpty Matrix: \n";
	print_matrix(adj_matrix);	

	// Write weights to adjacency matrix to achieve correct representation
	// of graph and weigthed arcs
	for (Arc arc : graph_arcs)
	{
		//must substract 1 because index starts at 0, different from
		//names in graph
		adj_matrix[arc.m_a-1][arc.m_b-1] = arc.m_weight; //e.g matrix[1][2] = 4
		adj_matrix[arc.m_b-1][arc.m_a-1] = arc.m_weight; //	matrix[2][1] = 4
	}

	std::cout << "list of arcs in graph: \n";
	print_arcs(graph_arcs);

	return adj_matrix;
}

//get adjacency matrix and return minimal spanning tree
void kruskal_minspan_tree (matrix const& adj_matrix)
{

	/*
	make priority queue
	*/

	std::vector<Arc> arcs;

	//iterate all nodes
	for (int i = 0; i < adj_matrix.size(); ++i)
	{
		//iterate all nodes with greater index
		for(int j = i+1; j < adj_matrix.size(); ++j)
		{
			int weight = adj_matrix[i][j];
			if(weight != 0)
			{
				arcs.push_back(Arc{i,j,weight});
			}
		}
	}

	//sort arcs by weight
	std::sort(arcs.begin(), arcs.end(),
		[](Arc const& lhs, Arc const& rhs) -> bool{
			return (lhs.m_weight <= rhs.m_weight);
		});
	std::cout << "\nsorted arcs:\n";
	print_arcs(arcs);

	/*
	the arcs that form a/the minimal spanning tree added to the 
	at the beginning empty minimal spanning tree adjacency matrix
	*/

	//adj. matrix initialized with 0
	std::vector<std::vector<int>> minspan_tree;
	for(int i = 0; i<12; ++i)
	{
		minspan_tree.push_back(std::vector<int>(12,0));
	}
	std::cout << "\nEmpty Matrix: \n";
	print_matrix(minspan_tree);

	//vector with boolean value for each node in graph, according to
	//index in adjacency matrix, initialized with false
	std::vector<bool> visited (minspan_tree.size(),false);

	//adding arcs to minspan_tree matrix
	for(int i=0; i<arcs.size(); ++i)
	{
		int node_a = arcs[i].m_a;
		int node_b = arcs[i].m_b;

		//if node a and b that for a arc have been visited, skip the
		//arc, because it would form a circle
		if(	visited[node_a] == true and
			visited[node_b] == true )
		{
			//do nothing (= skip the arc)
		}
		//if at least one of the nodes was not visited already,
		//set both nodes to visited and add the arc to the minimal
		//spanning tree
		else
		{
			visited[node_a] = true;
			visited[node_b] = true;
			minspan_tree[node_a][node_b] = arcs[i].m_weight;
			minspan_tree[node_b][node_a] = arcs[i].m_weight;
		}
	}

	std::cout << "\nresult :\n";
	print_matrix(minspan_tree);
}

int main ()
{
	// Vector containing all arcs of graph
	std::vector<Arc> graph_arcs {
		{1,2,4}, {1,6,10},
		{2,3,2},
		{3,5,7}, {3,7,5},
		{4,5,1}, {4,7,8}, {4,8,5},
		{5,7,2}, {5,12,5},
		{6,7,2}, {6,8,10},
		{8,9,3},
		{9,10,7},
		{10,11,1}
	};

	matrix adj_matrix = make_adj_matrix(graph_arcs);
	std::cout << "\n make_adj_matrix output: \n";
	print_matrix(adj_matrix);

	//hand over adjacency matrix to kruskal function
	std::cout << "\nhand over adjacency matrix to kruskal function\n";
	kruskal_minspan_tree(adj_matrix);
}
