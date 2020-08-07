#include <vector>
#include <cstdlib>
#include <iostream>

#ifndef CHEMIN_H_
#define CHEMIN_H_



using ville_t  = std::pair<int,int>;
using villes_t = std::vector<ville_t>;
using chemin_t = std::vector<int >;

class Villes
{
public:
	// Initialise les villes aléatoirement
	Villes(int n,
		   int _min_x=0, int _max_x=100, int _min_y=0, int _max_y=100) :
	villes_(n)
	{
		for (int i=0; i<n; i++)
		{
			villes_[i].first  = rand() % (_max_x+_min_x) + _min_x;
			villes_[i].second = rand() % (_max_y+_min_y) + _min_y;
		}
	}
	Villes(Villes const &v): villes_(v.get_villes().size())
	{
		int n = villes_.size();
		for (int i=0; i<n; i++)
		{
			villes_[i].first  = v.get_ville(i).first;
			villes_[i].second = v.get_ville(i).second;
		}
	}

	// mutateurs
	void set_ville(int i, int x, int y);

	// accesseurs
	villes_t get_villes() const;
	ville_t get_ville(int i) const;
	void display() const;


private:
	villes_t villes_ ;
};




class Chemin
{
public:
	Chemin(Villes *villes):
	nb_villes_(villes->get_villes().size()), chemin_(villes->get_villes().size())
	{
		villes_ = villes;
	}
	void init_Random();
	void init_Order();

	void echanger(int i, int j);


	int nb_villes() const;
	chemin_t chemin() const;
	void display() const;

private:
	int nb_villes_;
	chemin_t chemin_;	// indice des villes dans le chemin
	Villes *villes_;
};

#endif
