
/* 
  TP1 - Numéro C
  Fichier Ex4.cpp modifié selon les spécifications du TP1, numéro C
  
  Description: programme qui affiche certaines statistiques descriptives
  d'un échantillon.

  Auteure: Annie Rhéaume
  Date : 09-05-2023
  Version initiale: pour l'instant, les numéros (1), (2) et (3). Il me faut vérifier si (2) et (3)
  sont nécessairement des cas où les paramètres sont transmis par valeur...

  Il me reste aussi à coder la fonction de tri (4).
*/
                          

#include <iostream>
#include <iomanip>
using namespace std;

  // FONCTIONS EXISTANTES

  void afficher(int age[], int nbCafe[], char sexe[], float taille[], int nbPers, 
                   const char message[])
  {
     cout.setf(ios::fixed);
     cout.setf(ios::showpoint);   
     
     cout << "Contenu des 4 tableaux " << message << " :\n";
     cout << "indice      age     cafe   sexe   taille  " << endl ;
     
     for(int i = 0; i < nbPers; i++)
       cout << setw(3) << i << ") " << setw(10) << age[i] << setw(8) << nbCafe[i]
            << setw(6) << sexe[i] << setw(10) << setprecision(2) << taille[i]
            << endl;
     cout << endl;       
        
  }
  
  template <class T>
  float moyenne(T tab[], int nbElem)
  { float somme = 0.0 ;
    for(int i = 0; i < nbElem ; i++)
       somme += tab[i];
  
    return somme / nbElem ;      
  }

  // NOUVELLES FONCTIONS

  // Fonction qui calcule les fréquences d'une variable qualitative selon un critère de sélection.
  // Transmission par référence de paramètres (pour les fréquences).

  template<class T>
  void calculerFrequencesVarQual(T caracteristique[], T valeurComparee, int nbScores, int& refFrequences)
  {
      int compteur = 0;
      for (int i = 0; i < nbScores ; i++)
      {
          if(caracteristique[i] == valeurComparee)
              compteur++;
      }
      refFrequences = compteur; 
  }

  // Fonction qui calcule les fréquences d'une variable quantitative selon un critère de sélection. Retourne les fréquences (int).
  // Transmission par valeur des paramètres.

  template<class T>
  int calculerFrequencesVarQuant(T caracteristique[], T valeurComparee, int nbScores)
  {
      int compteur = 0;
      for (int i = 0; i < nbScores ; i++)
      {
          if(caracteristique[i] > valeurComparee)
              compteur++;
      } 
      return compteur;   
  }  

// Fonction qui calcule la valeur maximale d'un échantillon. Retourne la valeur maximale (type générique T).
// Transmission par valeur des paramètres

template<class T>
T calculerValMax(T caracteristique[], int nbScores)
{
    T valMax = caracteristique[0];
    for (int i = 1; i < nbScores ; i++)
    {
        if(caracteristique[i] > valMax)
            valMax = caracteristique[i];
    } 
    return valMax;
}

// Fonction qui trie les données d'un tableau en ordre croissant
// TODO

int main()
{
  int age[] = { 25, 19, 41, 37, 20, 37 },
      nbCafe[] = { 3, 4, 0, 6, 3, 2 } ;
  char sexe[] = { 'F', 'M', 'F', 'F', 'M', 'F' };
  float taille[] = { 1.72, 1.84, 1.65, 1.57, 1.93, 1.85 };
  
  int nbPers = sizeof(age) / sizeof(int);
      
  afficher(age, nbCafe, sexe, taille, nbPers, " au debut");    
  
  cout << "Age moyen : " << setw(6) 
       << setprecision(2) << moyenne(age, nbPers) << " an(s) " << endl ;
  cout << "Consommation moyenne de cafe : " << setw(6) 
       << setprecision(2) << moyenne(nbCafe, nbPers) 
       << " tasse(s) par jour" << endl ;
       
  cout << "Taille moyenne : " << setprecision(2) 
       << moyenne(taille, nbPers) << " metre" << endl;
  cout << endl;

  // Calculer les fréquences d'une catégorie d'une variable nominale et les afficher

  int nbFemmes, nbHommes;

  calculerFrequencesVarQual(sexe, 'F', nbPers, nbFemmes);
  calculerFrequencesVarQual(sexe, 'M', nbPers, nbHommes);

  cout << "Nombre de femmes : " << nbFemmes << endl;
  cout << "Nombre d'hommes : " << nbHommes << endl;
  cout << endl;

  // Calculer les fréquences d'une variable quantitative selon une valeur de comparaison et les afficher

  cout << "Nombre de personnes de plus de 29 ans : " << 
  calculerFrequencesVarQuant(age, 29, nbPers) << endl;
  cout << "Nombre de personnes qui consomment plus de 2 cafes par jour : " << 
  calculerFrequencesVarQuant(nbCafe, 2, nbPers) << endl;  
  cout << "Nombre de personnes d'une taille superieure a 1.80 metre : " << 
  calculerFrequencesVarQuant (taille, 1.80f, nbPers) << endl;
  cout << endl;

  // Calculer la valeur maximale et l'afficher

  cout << "Age maximal : " << calculerValMax(age, nbPers) << " an(s)" <<endl;
  cout << "Consommation maximale de cafe : " << calculerValMax(nbCafe, nbPers) << " cafe(s) par jour" << endl;
  cout << "Taille maximale : " << calculerValMax(taille, nbPers) << " metre" << endl;
  cout << endl;

  // Trier les scores selon la taille et afficher en console les données triées
  // TODO
  
                                                       
  return 0;   
}
/* 
  Affichage en console
  
  C:\Users\Annie\Desktop\cppTP1>TP1_1166_NumC_E23.exe
  Contenu des 4 tableaux  au debut :
  indice      age     cafe   sexe   taille
    0)         25       3     F      1.72
    1)         19       4     M      1.84
    2)         41       0     F      1.65
    3)         37       6     F      1.57
    4)         20       3     M      1.93
    5)         37       2     F      1.85

  Age moyen :  29.83 an(s)
  Consommation moyenne de cafe :   3.00 tasse(s) par jour
  Taille moyenne : 1.76 metre

  Nombre de femmes : 4
  Nombre d'hommes : 2

  Nombre de personnes de plus de 29 ans : 3
  Nombre de personnes qui consomment plus de 2 cafes par jour : 4
  Nombre de personnes d'une taille superieure a 1.80 metre : 3

  Age maximal : 41 an(s)
  Consommation maximale de cafe : 6 cafe(s) par jour
  Taille maximale : 1.93 metre

*/
