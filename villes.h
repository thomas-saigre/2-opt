#include <vector>
#include <cstdlib>
#include <iostream>

#ifndef VILLES_H_
#define VILLES_H_


class Villes
{
public:
	// Initialise les villes aléatoirement
	Villes(int n, bool _verbose = false,
		   int _min_x=0, int _max_x=100, int _min_y=0, int _max_y=100) :
	villes_(n), verbose_(_verbose)
	{
		for (int i=0; i<n; i++)
		{
			villes_[i].first  = rand() % (_max_x+_min_x) + _min_x;
			villes_[i].second = rand() % (_max_y+_min_y) + _min_y;
			if (verbose_)
				std::cout << villes_[i].first << "," << villes_[i].second << std::endl;
		}
	}

private:
	std::vector<std::pair<int,int>> villes_ ;
	bool verbose_ ;
};


#endif