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

int main ()
{
	std::vector<Arc> arcs {{1,2,4},{1,2,7},{1,2,1}};
	std::sort(arcs.begin(), arcs.end(),
		[](Arc const& lhs, Arc const& rhs) -> bool{
			return (lhs.m_weight <= rhs.m_weight);
		});

	for (int i = 0; i < arcs.size(); ++i)
	{
		std::cout << arcs[i].m_weight << " ";
	}
}