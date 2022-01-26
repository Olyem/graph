# pragma once
# include <string>
# include <vector>

class Arrete {
    private :
        std::string s1 ; // sommet de départ
        std::string s2 ; // sommet d'arrivée
        int val ; // étiquette
    public :
        Arrete (const std::string s1, const std::string s2, const int val) ;
        std::vector<std::string> sommets() const ; // renvoie les noms des deux sommets de l'arrête
        int valeur() ; // renvoie l'étiquette de l'arrête
        void print_detail() ; // affiche les deux sommets et l'étiquette 
        void print() ; // affiche sous forme de liste l'arrête
} ;