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

typedef std::vector<std::vector<int>> matrix;


//arcs are defined as pairs of different nodes a and b, which are identified
//by their index in the adjacency matrix and have a certain weight
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
	bool operator<(Arc const& arc) const
	{
		return m_weight < arc.m_weight;
	};
};

/*
function that prints a given matrix to the command line,
adjusting spaces for 1 and 2 digit numbers
*/
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

//function printing an vector of arcs to the command line
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
		adj_matrix[arc.m_a][arc.m_b] = arc.m_weight; //e.g matrix[1][2] = 4
		adj_matrix[arc.m_b][arc.m_a] = arc.m_weight; //	matrix[2][1] = 4
	}

	std::cout << "list of arcs in graph: \n";
	print_arcs(graph_arcs);

	return adj_matrix;
}

//get adjacency matrix and return minimal spanning tree
void prim (matrix const& adj_matrix)
{
	//priority queue holding arcs that have been reached but
	//not added to minimal spanning tree
	std::priority_queue<Arc> pr_queue;
	
	pr_queue.push(Arc{1,2,3});
	std::cout << pr_queue.top().m_weight;
}

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
