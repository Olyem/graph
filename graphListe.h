# pragma once 
# include "arrete.h"
# include <unordered_map>
# include <string>
# include <vector>

class Matrice ;

class GraphListe {
    private :
        std::unordered_map<std::string, std::vector<Arrete>> graph ;
    public :
        GraphListe(const std::vector<Arrete> liste_arretes) ;
        std::vector<Arrete> liste_adjacence (const std::string sommet) ; 
        void print() ; // affiche le graphe sous forme textuelle
        void add_arrete (const Arrete arrete);
        // fonction qui à partir du nom d'un sommet rend les arrêtes sortantes
        void add_sommet (const std::string sommet) ;
        Matrice toMatrice() ; // renvoie le graphe en format matrice
} ;