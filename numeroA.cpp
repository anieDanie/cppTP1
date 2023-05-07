#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

using namespace std;

// Fonction qui affiche les caractéristiques (variables continues) d'un échantillon en colonnes

void afficherCaracteristiques(float caracteristique1[], float caracteristique2[], int nbScores, string message)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    cout << "Caracteristiques de l'echantillon : \n" << endl;
    // cout << message << endl; // TODO
    cout << "Score" << setw(10) << "Taille" << setw(9) << "Poids" << endl;

    for (int i = 0; i < nbScores ; i++)
    {
        cout << setw(3) << i+1 << setw(10) << setprecision(2) << caracteristique1[i] <<
        setw(10) << setprecision(1) << caracteristique2[i] << endl;
    }
    cout << endl;
}

// Fonction qui affiche les fréquences selon un critère de sélection

void afficherFrequences(float caracteristique[], float valeurComparee, int nbScores)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    int compteur = 0;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] >= valeurComparee)
            compteur++;
    } 

    /* Il faut formater le nombre de décimales après la virgule: 2 pour la taille et 1 pour le poids*/
    cout << "Dans cet echantillon : " << compteur << " scores sont superieurs ou egaux a " << valeurComparee << endl;
    cout << endl;

}

// Fonction qui affiche une valeur minimale d'un échantillon

void afficherValMin(float caracteristique[], int nbScores)
{
    float valMin = FLT_MAX ;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] < valMin)
            valMin = caracteristique[i];
    } 

    /* Il faut formater le nombre de décimales après la virgule: 2 pour la taille et 1 pour le poids*/
    cout << "Dans cet echantillon, la valeur minimale est " << valMin << endl;
    cout << endl;   
}

int main()
{

    // Scores de 2 caractéristiques de l'échantillon :

    float taille[] = {1.72, 1.65, 1.58, 1.91, 1.69, 1.54, 1.83, 1.71},
            poids[] = {65.3 ,67.1, 74.8, 77.7, 72.3, 56.4, 74.9, 72.1};

    int nbPers = sizeof(taille)/ sizeof(float); // float = 4 octets

    string msg = "TODO";
    // Mettre en forme un string pour entête du tableau

    afficherCaracteristiques (taille, poids, nbPers, msg);

    afficherFrequences (taille, 1.73f, nbPers);
    afficherFrequences (poids, 70.0f, nbPers);

    afficherValMin(taille, nbPers);
    afficherValMin (poids, nbPers);

    return 0;

}

/*

    Affichage en console

    C:\Users\Annie\Desktop\cppTP1>numeroA.exe
    Caracteristiques de l'echantillon :

    Score  Taille    Poids
    1      1.72      65.3
    2      1.65      67.1
    3      1.58      74.8
    4      1.91      77.7
    5      1.69      72.3
    6      1.54      56.4
    7      1.83      74.9
    8      1.71      72.1

    Dans cet echantillon : 2 scores sont superieurs ou egaux a 1.7

    Dans cet echantillon : 5 scores sont superieurs ou egaux a 70.0

    Dans cet echantillon, la valeur minimale est 1.5

    Dans cet echantillon, la valeur minimale est 56.4

*/