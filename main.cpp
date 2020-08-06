#include <iostream>
#include "chemin.h"
#include <unistd.h>
#include <cstdlib>



void help ()
{
	std::cout << "usage : 2_opt [options]" << std::endl ;
	std::cout << "\t-h\t\tafficher l'aide" << std::endl ;
	std::cout << "\t-n nombre\tmodifie le nombre de villes (défaut 10)"  << std::endl ;
	std::cout << "\t-x|-y nombre\tcoordonnées minimales (défaut 0)" << std::endl ;
	std::cout << "\t-X|-Y nombre\tcoordonnées maximales (défaut 100)" << std::endl ;
}




int main (int argc, char ** argv)
{
	// Gestion des options
	int c ;
	bool errflag = false ;
	unsigned long n = 10 ;
	int x_min=0, x_max=100, y_min=0, y_max=100 ;
	extern char *optarg ;
	extern int optind ;
	while ((c = getopt (argc, argv, "hvn:x:X:y:Y:")) != -1)
		switch (c)
		{
		case 'h':
			help () ;
			exit (0) ;
			break ;
		case 'n':
			n = (unsigned long) atoi (optarg) ;
			break;
		case 'x':
			x_min = atoi (optarg) ;
			break;
		case 'X':
			x_max = atoi (optarg) ;
			break;
		case 'y':
			y_min = atoi (optarg) ;
			break;
		case 'Y':
			y_max = atoi (optarg) ;
			break;
		default:
			errflag = true ;
			break ;
		}

	if (errflag)
	{
		std::cerr << "usage : " << argv[0] << " [options]" << std::endl ;
		std::cerr << "Entrer " << argv[0] << " -h pour plus d'informations" << std::endl ;
		exit (1) ;
	}


	Villes v(n,x_min,x_max,y_min,y_max);
	v.display();

	std::cout << "thomas\n";
	Chemin ch(&v);
	ch.init_Order();
	ch.display();

	return 0;
}