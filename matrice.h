# pragma once
# include "graphListe.h"
# include <cmath>
# include <vector>
# include <string>

class Matrice {
    private :
        std::vector<std::vector<int>> matrice ;
        std::vector<std::string> liste_sommets ;
    public :
        Matrice(const std::vector<Arrete> liste_arretes) ;
        void print() ;
        GraphListe toListe() ; // renvoie le graphe en format liste d'adjacence
} ;


