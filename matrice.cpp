# include "matrice.h"
# include "graphListe.h"
# include "arrete.h"
# include <vector>
# include <string>
# include <iostream>
# include <cmath>

// Renvoie 1 si la chaîne de caractère element est présente dans liste
bool isin (const std::string element, const std::vector<std::string> liste){
    for (std::string x : liste){
        if (x == element){
            return 1 ;
        }
    }
    return 0 ;
}


// J'ai l'impression que c'est quand même plus simple de partir d'un dictionnaire
// Donc le plus simple serait de construire un graph puis de le convertir en matrice
Matrice::Matrice(const std::vector<Arrete> liste_arretes){
    // On suppose que liste_arretes n'est pas triée par sommets 
    // (les arrêtes sont dans le désordre)

    std::vector<std::string> liste_sommets ; // initialisation de la liste de sommets (vide)
    std::vector<std::vector<int>> matrice ; // création de la matrice d'adjacence dont on va rajouter les éléments au fur et à mesure

    // Boucle pour remplir liste_sommets et ainsi déterminer la taille de la matrice
    for (int i=0; i<liste_arretes.size(); i++){
        std::string s1 = liste_arretes[i].sommets()[0] ;
        std::string s2 = liste_arretes[i].sommets()[1] ;
        if (not isin(s1, liste_sommets)){
            liste_sommets.push_back(s1) ;
        }
        if (not isin(s2, liste_sommets)){
            liste_sommets.push_back(s2) ;
        }
    }
    // On va maintenant remplir la matrice, ligne par ligne
    int l = liste_sommets.size() ; // nombre de sommets dans le graphe
    // On itère une première fois sur la liste de sommets
    for (int i=0 ; i<l ; i++){ 
        std::vector<int> line ; // on initialise la i-ème ligne du tableau
        // On itère une deuxième fois sur la liste de sommets
        for (int j=0 ; j<l ; j++){
            for (Arrete a : liste_arretes){
                // Si les deux sommets de l'arrête sont les sommets i et j :
                if (a.sommets()[0] == liste_sommets[i] && a.sommets()[1] == liste_sommets[j]){
                    line.push_back(a.valeur()) ; // on ajoute la valeur de l'arrête à la case i,j
                }
                // Sinon :
                else { 
                    line.push_back(std::isnan(1.)) ; // on met une valeur NaN à la case i,j
                }
            }
        }
        // On ajoute la ligne à la matrice finale
        matrice.push_back(line) ;
    }
}

void Matrice::print(){ 
    for (int i=0; i<liste_sommets.size(); i++){
        std::cout << liste_sommets[i] << " : " ;
        std::vector<int> liste_adj = matrice[i] ;
        for (int j=0; j<liste_adj.size(); j++){
            int etiquette = liste_adj[j] ;
            if (not std::isnan(etiquette)){
                std::cout << liste_adj[j] << ", " ;
            } ;         
        } ;
        std::cout << std::endl ; 
    } ;
}

GraphListe Matrice::toListe(){
    std::vector<Arrete> liste_arretes ;
    GraphListe graph (liste_arretes); 
    for (int i=0; i<liste_sommets.size(); i++){
        std::string sommet = liste_sommets[i] ;
        for (int j=0; j<liste_sommets.size(); j++){
            int etiquette = matrice[i][j] ;
            if (not std::isnan(etiquette)){
                Arrete a (sommet, liste_sommets[j], etiquette) ;
                graph.add_arrete(a) ;
            } 
        } 
    } 
    return graph ;
}