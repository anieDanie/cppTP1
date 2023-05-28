/*
    TP1: numéro B
    Description: programme qui affiche certaines statistiques descriptives
    d'un échantillon.

    - patron de fonction : template <class T> : (2) (3) (4)
    - transmission de paramètres par valeur (1) et (2)
    - transmission de paramètres par pointeurs (3)
    - transmission de paramètres par références (4)

    Auteure: Annie Rhéaume
    Dernière m-a-j : 28-05-2023

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

using namespace std;

/*
    Fonction qui affiche les caractéristiques (variables continues et discrètes) 
    d'un échantillon en colonnes
*/

void afficherCaracteristiques(int caracteristique1[], float caracteristique2[], 
float caracteristique3[], int nbScores)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    cout << "Caracteristiques de l'echantillon : \n" << endl;
    cout << "Score" << setw(5) << "Age" << setw(10) << "Taille" << setw(9) << "Poids" << endl;

    for (int i = 0; i < nbScores ; i++)
    {
        cout << setw(3) << i+1 << setw(6) << caracteristique1[i] << setw(9) << setprecision(2) << 
        caracteristique2[i] << setw(10) << setprecision(1) << caracteristique3[i] << endl;
    }
}


/*
Fonction qui calcule les fréquences selon un critère de sélection. 
Retourne les fréquences (type int).
Utilisation d'un patron de fonction; transmission par valeur des paramètres
*/

template<class T>
int calculerFrequences(T caracteristique[], T valeurComparee, int nbScores)
{
    int compteur = 0;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] >= valeurComparee)
            compteur++;
    } 
    return compteur;   
}


/*Fonction qui calcule la valeur minimale et la valeur maximale
d'une caractéristique d'un échantillon. Ne retourne rien.
Modification des variables Min et Max (déclarées dans le programme principal) via leurs pointeurs
*/
template<class T>
void calculerValExtremes( T caracteristique[], int nbScores, T* ptrMin, T* ptrMax)
{
    T valMin = caracteristique[0];
    T valMax = caracteristique[0];
    for (int i = 1; i < nbScores ; i++)
    {
        if(caracteristique[i] < valMin)
            valMin = caracteristique[i];
        if (caracteristique[i] > valMax)
            valMax = caracteristique[i];
    } 
    // Modification des valeurs minimale et maximale pointées par ptrMin et ptrMax
    *ptrMin = valMin;
    *ptrMax = valMax;
   
}

/*Fonction qui calcule la moyenne des scores d'une caractéristique de l'échantillon.
Ne retourne rien.
Modification des variables 'moyennes' (déclarées dans le programme principal) via leur référence.
*/
template<class T>
void calculerMoyenne(T caracteristique[], int nbScores, float& refMoyenne)
{
    float somme = 0.0f;
    for (int i = 0; i < nbScores ; i++)
    {
        somme += caracteristique[i];
    } 
    // Modification de la valeur de la variable "moyenne" référencée par refMoyenne
    refMoyenne = somme / nbScores;  
}

void afficherFrequences(int age[], float taille[], float poids[], int nbPers){
    cout << "Nombre de personnes de 18 ans ou plus : " << 
    calculerFrequences(age, 18, nbPers) << endl;
    cout << "Nombre de personnes d'une taille superieure ou egale a 1.73 metre : " << 
    calculerFrequences (taille, 1.73f, nbPers) << endl;
    cout << "Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : " << 
    calculerFrequences (poids, 70.0f, nbPers) << endl;
    cout << endl;
}

int main()
{

    // Scores de 3 caractéristiques de l'échantillon :

    int age[] = {27, 35, 41, 18, 25, 30, 54, 50};
    float taille[] = {1.72, 1.65, 1.58, 1.91, 1.69, 1.54, 1.83, 1.71},
            poids[] = {65.3 ,67.1, 74.8, 77.7, 72.3, 56.4, 74.9, 72.1};

    int nbPers = sizeof(taille)/ sizeof(float); // float = 4 octets
    
    // Q1 - Afficher le contenu des 3 tableaux
    afficherCaracteristiques (age, taille, poids, nbPers);
    cout << endl;

    // Q2 - Afficher les fréquences calculées
    afficherFrequences(age, taille, poids, nbPers);

    // Q3 - Afficher les valeurs mininales et maximales
    int ageMin, ageMax;
    float tailleMin, tailleMax, poidsMin, poidsMax;

    calculerValExtremes(age, nbPers, &ageMin, &ageMax);
    calculerValExtremes(taille, nbPers, &tailleMin, &tailleMax);
    calculerValExtremes (poids, nbPers, &poidsMin, &poidsMax);

    cout << "Age minimal : " << ageMin << " ans.\nAge maximal : " << ageMax << " ans.\n " <<endl;
    cout << "Taille minimale : "<< setprecision(2) << tailleMin << " metre.\nTaille maximale : " 
    << tailleMax << " metre.\n " <<endl;
    cout << "Poids minimal : " << setprecision(1) << poidsMin << " kg.\nPoids maximal : " 
    << poidsMax << " kg.\n " <<endl;

    // Q4 - Afficher les valeurs moyennes 
    float ageMoyen, tailleMoyenne, poidsMoyen;

    calculerMoyenne(age,nbPers, ageMoyen);
    calculerMoyenne(taille,nbPers, tailleMoyenne);
    calculerMoyenne(poids,nbPers, poidsMoyen);

    cout << "Age moyen : " << setprecision(2) << ageMoyen << " ans." <<endl;
    cout << "Taille moyenne : " << tailleMoyenne << " metre."<<endl;
    cout << "Poids moyen : " << poidsMoyen << " kg." <<endl;
    cout << endl;

    return 0;

}

/*
    AFFICHAGE
    C:\Users\Annie\Desktop\cppTP1>numeroB.exe
    Caracteristiques de l'echantillon : 

    Score  Age    Taille    Poids
    1    27     1.72      65.3
    2    35     1.65      67.1
    3    41     1.58      74.8
    4    18     1.91      77.7
    5    25     1.69      72.3
    6    30     1.54      56.4
    7    54     1.83      74.9
    8    50     1.71      72.1

    Nombre de personnes de 18 ans ou plus : 8
    Nombre de personnes d'une taille superieure ou egale a 1.73 metre : 2
    Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : 5

    Age minimal : 18 ans.
    Age maximal : 54 ans.

    Taille minimale : 1.54 metre.
    Taille maximale : 1.91 metre.

    Poids minimal : 56.4 kg.
    Poids maximal : 77.7 kg.

    Age moyen : 35.00 ans.
    Taille moyenne : 1.70 metre.
    Poids moyen : 70.07 kg.
*/