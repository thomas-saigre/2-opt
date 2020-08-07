#include <vector>
#include "chemin.h"
#include <cstdlib>
#include <iostream>
#include <cmath>


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



double Chemin::distance(int i, int j) const
{
	double  x1 = villes_->get_ville(i).first,  x2 = villes_->get_ville(j).first,
			y1 = villes_->get_ville(i).second, y2 = villes_->get_ville(j).second;
	return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}


double Chemin::length() const
{
	double d = 0;
	for (int i=0; i<nb_villes(); i++)
		d += distance(i, (i+1)%nb_villes());
	return d;
}


double Chemin::gain(int i, int j) const
{
	return distance( i, (i+1)%nb_villes() ) + distance( j, (j+1)%nb_villes() )
			- distance( i, j ) - distance( (i+1)%nb_villes(), (j+1)%nb_villes() );
}




void Chemin::echanger(int i, int j)
{
	int tmp = chemin_[i] ;
	chemin_[i] = chemin_[j] ;
	chemin_[j] = tmp ; 
}

void Chemin::echanger_aretes(int i, int j)
{
	int k = i+1, l = j ;
	while (k < l)
	{
		echanger(k, l) ;
		k++ ;
		l-- ;
	}
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



void Chemin::opt()
{
	bool ame = true ;
	while (!ame)
	{
		ame = false ;
		std::cout << length() << std::endl ;
		for (int i=0; i<nb_villes(); i++){
			for (int j=0; j<nb_villes(); j++)
			{
				if ( (j != (i-1)%nb_villes()) && (j != (i+1)%nb_villes()) && (j != i)
					 && (gain(i,j) > 0))
				{
					display();
					echanger_aretes(i,j);
					ame = true;
				}
			}
		}
	}
	std::cout << "Done : " << length() << std::endl ;
}
