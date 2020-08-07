#include <vector>
#include "chemin.h"
#include <cstdlib>
#include <iostream>


// On suppose a<b
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}




void Villes::set_ville(int  i, int x, int y)
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


void Villes::display() const
{
	std::cout << "{ ";
	for (int i=0; i<(int) get_villes().size(); i++)
	{
		std::cout << "(" << get_ville(i).first << "," << get_ville(i).second << ") ";
	}
	std::cout << "}" << std::endl;
}





int Chemin::nb_villes() const
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
	for (int i=0; i<nb_villes(); i++)
	{
		std::cout << chemin()[i] << " ";
	}
	std::cout << "]" << std::endl;
}



void Chemin::echanger(int i, int j)
{
	int tmp = chemin_[i] ;
	chemin_[i] = chemin_[j] ;
	chemin_[j] = tmp ; 
}



void Chemin::init_Random()
{
	init_Order() ;
	for (int i=0; i<nb_villes(); i++)
	{
		int indice = rand_a_b(i,nb_villes());
		echanger(i, indice);
	}
}


void Chemin::init_Order()
{
	for (int i=0; i<nb_villes(); i++)
		chemin_[i] = i ;
}