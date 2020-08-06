#include <vector>
#include "chemin.h"
#include <cstdlib>
#include <iostream>




void Villes::set_ville(int i, int x, int y)
{
	villes_[i].first  = x;
	villes_[i].second = y;
}


villes_t Villes::get_villes() const
{
	return villes_;
}


ville_t Villes::get_ville(int i) const
{
	return villes_[i];
}





int Chemin::nb_villes() const
{
	return nb_villes_;
}


chemin_t Chemin::chemin() const
{
	return chemin_;
}


void Chemin::init_Random()
{

}


void Chemin::init_Order()
{
	for (int i=0; i<nb_villes(); i++)
		chemin_[i] = i;
}