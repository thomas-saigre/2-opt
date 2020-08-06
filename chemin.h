#include <vector>
#include <cstdlib>
#include <iostream>

#ifndef CHEMIN_H_
#define CHEMIN_H_


using ville_t  = std::pair<int,int>;
using villes_t = std::vector<ville_t>;

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
				std::cout << "Création ville " << i <<
					"(" << villes_[i].first << "," << villes_[i].second << ")" << std::endl;
		}
	}

	// mutateurs
	void set_ville(int i, int x, int y);

	// accesseurs
	villes_t get_villes() const;
	ville_t get_ville(int i) const;



private:
	villes_t villes_ ;
	bool verbose_ ;
};




class Chemin
{
public:

private:
	int nb_villes_;
	std::vector<int> chemin_;	// indice des villes dans le chemin
	Villes villes_;
};

#endif