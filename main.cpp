#include <iostream>
#include "chemin.h"
#include <unistd.h>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


void help ()
{
	std::cout << "usage : 2_opt [options]" << std::endl ;
	std::cout << "\t-h\t\tafficher l'aide" << std::endl ;
	std::cout << "\t-n nombre\tmodifie le nombre de villes (défaut 10, de type int)"  << std::endl ;
	std::cout << "\t-x|-y nombre\ttaille de la fenêtre (défaut 800*600)" << std::endl ;
}




int main (int argc, char ** argv)
{

	// Gestion des options
	int c ;
	bool errflag = false ;
	int n = 10 ;
	int x_max=800, y_max=600 ;
	extern char *optarg ;
	extern int optind ;
	while ((c = getopt (argc, argv, "hvn:x:y:")) != -1)
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
			x_max = atoi (optarg) ;
			break;
		case 'y':
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

	sf::RenderWindow window ;

	window.create(sf::VideoMode(x_max, y_max), "My window");
	window.setVerticalSyncEnabled(true);


	Villes v(n,x_max,y_max);

	Chemin ch( &v, &window );

	

	ch.init_Random();
	ch.display();






	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);

		// c'est ici qu'on dessine tout
		ch.render() ;

		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

	return 0;
}