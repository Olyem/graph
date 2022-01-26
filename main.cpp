# include "graphListe.h"
# include "arrete.h"
# include "matrice.h"
# include <iostream>
# include <unordered_map>
# include <string>
# include <vector>
# include <cmath>
#include <fstream>
#include <sstream>

std::vector<Arrete> read_graph (std::string filename) {
    
    // si problème d'ouverture de fichier on retourne simplement empty
    std::vector<Arrete> empty ;
    std::ifstream input_file (filename) ;
    if (!input_file.is_open()) {
        std::cerr << "cannot open file '" << filename << "'" << std::endl;
        return empty ;
    }
    
    // On initialise la liste contenant les arrêtes
    std::vector<Arrete> liste_arretes ;

    // On crée un vecteur contenant les lignes du fichier,
    // qu'on va parcourir par la suite
    std::vector<std::string> lines ;
    std::string line;
    while(getline(input_file, line)) {
        lines.push_back(line);
    }

    // On met le contenu de chaque ligne dans une arrête  
    for(std::string edgeLine: lines){

        // Déclaration des variables que l'on va mettre dans l'arrête
        std::string s1 ;
        std::string s2 ;
        std::string value ;
        int i {0} ; // i va parcourir toute la ligne

        // Boucle pour déterminer s1
        while (not isspace(edgeLine[i]) && i<line.size()){ 
            s1 += edgeLine[i] ;
            i += 1 ;
        }
        i += 1 ;

        // Boucle pour déterminer s2
        while (not isspace(edgeLine[i]) && i<line.size()){ 
            s2 += edgeLine[i] ;
            i += 1 ;
        }
        i += 1 ;

        // Boucle pour déterminer value
        while (not isspace(edgeLine[i]) && i<line.size()){ 
            value += edgeLine[i] ;
            i += 1 ;
        }
        // Que l'on transforme en int ensuite :
        int val = stoi(value) ;

        // On crée l'arrête correspondante :
        Arrete arrete (s1, s2, val) ;
        // Et on l'ajoute au vecteur d'arrêtes
        liste_arretes.push_back(arrete) ;

    }

    return liste_arretes ;
}


int main(int argc, char** argv){

    Arrete a ("s1","s2",12) ;
    Arrete b ("s1","s3",13) ;
    std::vector<Arrete> list_a {a,b} ;
    Matrice mat (list_a) ;

    return 0 ;
}

