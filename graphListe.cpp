# include "graphListe.h"
# include "matrice.h"
# include "arrete.h"
# include <unordered_map>
# include <string>
# include <iostream>
# include <cmath>


GraphListe::GraphListe(const std::vector<Arrete> liste_arretes){
    for(Arrete arrete : liste_arretes){
        std::string s1 {arrete.sommets()[0]} ;
        // si le s1 existe déjà, il faut modifier le vecteur d'arrêtes
        if (graph.find(s1) != graph.end()){
            graph[s1].push_back(arrete) ;
        }
        // si s1 n'existe pas dans le dico, il faut le créer et mettre un nouveau vecteur avec une seule arrête
        else {
            std::vector<Arrete> liste {arrete} ;
            graph[s1] = liste ;
        }
    }
}

std::vector<Arrete> GraphListe::liste_adjacence (const std::string sommet){
    return graph.at(sommet) ;
}

void GraphListe::print(){
    for (auto p: graph){
        std::cout << p.first << " : " ;
        std::vector<Arrete> liste_adj = p.second ;
        for (int i=0; i<p.second.size(); i++){
            liste_adj[i].print() ;
            std::cout << ", " ;
        } ;
        std::cout << std::endl ;

    } ;
}

void GraphListe::add_arrete (const Arrete arrete){
    std::string s1 {arrete.sommets()[0]} ;
    // si le s1 existe déjà, il faut modifier le vecteur d'arrêtes
    if (graph.find(s1) != graph.end()){
        graph[s1].push_back(arrete) ;
    }
    // si s1 n'existe pas dans le dico, il faut le créer et mettre un nouveau vecteur avec une seule arrête
    else {
        std::vector<Arrete> liste {arrete} ;
        graph[s1] = liste ;
    }
    
}

Matrice GraphListe::toMatrice(){ 
    std::vector<Arrete> liste_arretes ;
    for (auto p: graph){
        std::vector<Arrete> liste {p.second} ;
        for (Arrete a : liste){
            liste_arretes.push_back(a) ;
        }
    }
    Matrice mat (liste_arretes) ;
    return mat ;
}