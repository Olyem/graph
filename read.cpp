#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

void read_points (std::string filename) {
  // chaque ligne du fichier contient la liste des coordonnées d'un point
  // on ouvre le fichier en lecture
  std::ifstream input_file(filename);
  // si problème d'ouverture de fichier on s'en va
  if (!input_file.is_open()) {
    std::cerr << "cannot open file '" << filename << "'" << std::endl;
    return;
  }
  // on lit le fichier ligne par ligne

  // par souci de simplicité, on considère qu'on ne connait pas la
  // dimension des points, mais on pourrait la connaître en lisant la
  // première ligne et en comptant le nombre de coordonnées

  // la chaîne de caractères qui contient toute la ligne
  std::string line;
  // on va lire toutes les lignes du fichier: quand il n'y en aura
  // plus getline retournera 0

  // on lit la ligne et on met son contenu dans la variable line
  while (getline(input_file, line)) {
    std::cout << "analyse de la ligne " << line << std::endl;

    // comme on sait qu'on n'a que des chiffres, on crée un objet
    // (pour lire les input dans les streams de string) pour extraire
    // les nombres de la ligne.
    // on initialise cet objet à notre ligne
    std::istringstream iss(line);
    // on cherche à lire des nombre réels
    double x;
    // tant qu'il y a des nombres dans la ligne on les lit
    std::vector<double> coords;
    while (iss >> x) {
      // on les affiche et les met dans un vector
      std::cout << x << ", ";
      coords.push_back(x);
    }
    std::cout << std::endl;

    // on met capacity à size (le vector ne va plus grandir)
    // on aurait pu calculer la dimension du premier point
    // et utiliser un std::array de la taille de la dimension
    coords.shrink_to_fit();

    // il existe des petites choses pour faire de calculs sur les
    // conteneurs (inclure numeric)
    // par exemple calculer la somme des éléments d'un vector:
    std::cout << "   total "
	      << std::accumulate(coords.begin(), coords.end(), 0)
	      << std::endl;
    // on appliquer une fonction à tous les éléments d'un conteneur
    int nb = 98;
    std::for_each(coords.begin(), coords.end(),
		  // c'est une lambda une fonction sans nom
		  // mais on peut utiliser une vraie fonction aussi
		  [nb](auto& x) { x = x*nb; }); // référence parce que
					       // je modifie le vector
    std::cout << "   total des éléments multipliés par " << nb << " "
	      << std::accumulate(coords.begin(), coords.end(), 0)
	      << std::endl;
    
  }
}

int main (int argc, char** argv) {
  // par exemple ici je passe le nom du fichier en argument
  if (argc == 1)
    return EXIT_FAILURE ;

  read_points(argv[1]) ;
  
  return EXIT_SUCCESS ;
}
