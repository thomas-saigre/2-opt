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