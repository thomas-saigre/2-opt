#include <vector>
#include "chemin.h"
#include <cstdlib>
#include <iostream>




void Villes::set_ville(unsigned long  i, int x, int y)
{
	villes_[i].first  = x;
	villes_[i].second = y;
}


villes_t Villes::get_villes() const
{
	return villes_;
}


ville_t Villes::get_ville(unsigned long i) const
{
	return villes_[i];
}


void Villes::display() const
{
	std::cout << "{ ";
	for (unsigned long i=0; i<get_villes().size(); i++)
	{
		std::cout << "(" << get_ville(i).first << "," << get_ville(i).second << ") ";
	}
	std::cout << "}" << std::endl;
}





unsigned long Chemin::nb_villes() const
{
	return nb_villes_;
}


chemin_t Chemin::chemin() const
{
	return chemin_;
}


void Chemin::display() const
{
	std::cout << "[ ";
	for (unsigned long i=0; i<nb_villes(); i++)
	{
		std::cout << chemin()[i] << " ";
	}
	std::cout << "]" << std::endl;
}



void Chemin::init_Random()
{

}


void Chemin::init_Order()
{
	for (unsigned long i=0; i<nb_villes(); i++)
		chemin_[i] = i;
}