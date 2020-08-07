#include <vector>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef CHEMIN_H_
#define CHEMIN_H_


#define TAILLE_VILLE 3.f
#define TPS_ATTENTE 41000



using ville_t  = std::pair<int,int>;
using villes_t = std::vector<ville_t>;
using chemin_t = std::vector<int >;

class Villes
{
public:
	// Initialise les villes aléatoirement
	Villes(int n, int _max_x=800, int _max_y=600) :
	villes_(n)
	{
		for (int i=0; i<n; i++)
		{
			villes_[i].first  = rand() % _max_x;
			villes_[i].second = rand() % _max_y;
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
	Chemin(Villes *villes, sf::RenderWindow *window):
	nb_villes_(villes->get_villes().size()), chemin_(villes->get_villes().size())
	{
		villes_ = villes ;
		window_ = window ;
	}
	void init_Random();
	void init_Order();

	int nb_villes() const;
	Villes *villes() const;
	ville_t get_ville(int i) const;
	chemin_t chemin() const;
	int ville(int i) const;
	void display() const;
	double distance(int i, int j) const;
	double length() const;
	double gain(int i, int j) const;

	void render() const;

	void echanger(int i, int j);
	void echanger_aretes(int i, int j);
	void opt();

private:
	int nb_villes_;
	chemin_t chemin_;	// indice des villes dans le chemin
	Villes *villes_;
	sf::RenderWindow *window_;
};

#endif
