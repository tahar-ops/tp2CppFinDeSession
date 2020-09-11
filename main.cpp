#include "Score.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
 
int main()
{                
    std::map<Score,long> lsiteJoueurs;
    std::ifstream lecteur("hiscore.txt");
    while (lecteur.eof() == false) 
        {
        long identifiant;
        std::string login1;
        long score1;
        lecteur >> identifiant;
        lecteur >> login1;
        lecteur >> score1;
          if (lecteur.eof() == false) 
          {       
          lsiteJoueurs[Score(identifiant, login1, score1)]=identifiant;
          }   
        }
    std::ofstream fichier("Asterostorm.txt");
    fichier.close();
    std::ofstream Jeux("Asterostorm.txt", std::ios::app);                                   
    std::map<Score,long>::iterator it;
    for (it =lsiteJoueurs.begin(); it != lsiteJoueurs.end(); ++it) 
      {          
         Jeux << it->first.getLogin() << std::endl;  
         Jeux << it->first.getIdentifiantPartie() << std::endl;
         Jeux << "Asterostorm="<< it->first.getScore() << std::endl;
      }
         Jeux.close();
}




