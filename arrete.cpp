# include "arrete.h"
# include <iostream>
# include <vector>

Arrete::Arrete (const std::string s1, const std::string s2, const int val) :
    s1 (s1) ,
    s2 (s2) ,
    val (val) 
    {}

std::vector<std::string> Arrete::sommets() const{
    std::vector<std::string> vect {s1,s2} ;
    return vect ;
}

int Arrete::valeur(){
    return val ;
}

void Arrete::print_detail(){
    std::cout << "Sommet de départ : " << s1 << std::endl ;
    std::cout << "Sommet d'arrivée : " << s2 << std::endl ;
    std::cout << "Etiquette : " << val << std::endl ;
}

void Arrete::print(){
    std::cout << "[" << s1 << "->" << s2 << ", " << val << "]" << std::endl ;
}

