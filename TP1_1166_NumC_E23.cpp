
/* 
  TP1 : numéro C
  Fichier Ex4.cpp modifié selon les spécifications du TP1, numéro C
  
  Description: programme qui affiche certaines statistiques descriptives
  d'un échantillon.

  Auteure: Annie Rhéaume
  Date : 10-05-2023
  Version 1
  
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

// Fonction qui permutent 2 valeurs transmises en paramètres. Ne retourne rien.
// Transmission des paramètres par références
template <class T>
void permuterVal(T& val1, T& val2)
{
  T temp = val1;
  val1 = val2;
  val2 = temp;
}

// Fonction qui trie les données d'un tableau en ordre croissant
// Transmission des paramètres par références
void trier (int age[], int nbCafe[], char sexe[], float taille[], int nbElem)
{
  for (int i = 0; i < nbElem-1 ; i++)
  {
    int indMin = i;
    for (int j = i+1; j < nbElem; j++){
      if (taille[j] < taille[indMin])
        indMin = j;
      if (indMin != i) 
      {
        permuterVal(age[i], age[indMin]);
        permuterVal(nbCafe[i], nbCafe[indMin]);
        permuterVal(sexe[i], sexe[indMin]);
        permuterVal(taille[i], taille[indMin]);
      }
    }
  }
}


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
  
  trier(age, nbCafe, sexe, taille,nbPers);
  afficher(age, nbCafe, sexe, taille, nbPers, " a la fin");
  
                                                       
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

  Contenu des 4 tableaux  a la fin :
  indice      age     cafe   sexe   taille
    0)         37       6     F      1.57
    1)         41       0     F      1.65
    2)         25       3     F      1.72
    3)         19       4     M      1.84
    4)         37       2     F      1.85
    5)         20       3     M      1.93

*/
