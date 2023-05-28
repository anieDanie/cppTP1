/*
    TP1 : numéro A
	Description: programme qui affiche certaines statistiques descriptives
    d'un échantillon.

    Auteure: Annie Rhéaume
    Dernière m-a-j: 28-05-2023
    Version: 1

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

using namespace std;

/*
    Fonction qui affiche les caractéristiques (variables continues) d'un échantillon en colonnes.
    Ne retourne rien.
*/ 

void afficherCaracteristiques(float caracteristique1[], float caracteristique2[],
int nbScores)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    cout << "Caracteristiques de l'echantillon : \n" << endl;
    cout << "Score" << setw(10) << "Taille" << setw(9) << "Poids" << endl;

    for (int i = 0; i < nbScores ; i++)
    {
        cout << setw(3) << i+1 << setw(10) << setprecision(2) << caracteristique1[i] <<
        setw(10) << setprecision(1) << caracteristique2[i] << endl;
    }
    cout << endl;
}

/*
    Fonction qui calcule les fréquences selon un critère de sélection. 
    Retourne les fréquences (type int).
*/ 

int calculerFrequences(float caracteristique[], float valeurComparee, int nbScores)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    int compteur = 0;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] >= valeurComparee)
            compteur++;
    } 
    return compteur;
}

/*
    Fonction qui calcule la valeur minimale d'un échantillon.
    Retourne cette valeur (type float)
*/

float calculerValMin(float caracteristique[], int nbScores)
{
    float valMin = FLT_MAX ;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] < valMin)
            valMin = caracteristique[i];
    } 
    return valMin;   
}

void afficherFrequences(float taille[], float poids[], int nbPers){

    cout << "Nombre de personnes d'une taille superieure ou egale a 1.73 metre : " << 
    calculerFrequences (taille, 1.73f, nbPers) << endl;

    cout << "Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : " << 
    calculerFrequences (poids, 70.0f, nbPers) << endl;
    cout << endl;
}

void afficherValMin(float taille[], float poids[], int nbPers){
    cout << "Taille minimale de l'echantillon: " << setprecision(2) << calculerValMin(taille, nbPers) << " m" << endl;
    cout << "Poids minimal de l'echantillon: "<< setprecision(1) << calculerValMin (poids, nbPers) << " kg" << endl;
    cout<< endl;
}

int main()
{

    // Scores de 2 caractéristiques de l'échantillon :

    float taille[] = {1.72, 1.65, 1.58, 1.91, 1.69, 1.54, 1.83, 1.71},
            poids[] = {65.3 ,67.1, 74.8, 77.7, 72.3, 56.4, 74.9, 72.1};

    int nbPers = sizeof(taille)/ sizeof(float); // float = 4 octets

    // Q1- Afficher le contenu des 2 tableaux
    afficherCaracteristiques (taille, poids, nbPers);

    // Q2- Calculer et afficher les fréquences pour taille >= 1,73m et poids >= 70.0kg
    afficherFrequences(taille, poids, nbPers);

    // Q3 - Calculer les valeurs minimales des caractéristiques 'taille' et 'poids'
    afficherValMin(taille, poids, nbPers);

    return 0;
}

/*
    AFFICHAGE
    C:\Users\Annie\Desktop\cppTP1>numeroA.exe
    Caracteristiques de l'echantillon : 

    Score    Taille    Poids
    1      1.72      65.3
    2      1.65      67.1
    3      1.58      74.8
    4      1.91      77.7
    5      1.69      72.3
    6      1.54      56.4
    7      1.83      74.9
    8      1.71      72.1

    Nombre de personnes d'une taille superieure ou egale a 1.73 metre : 2
    Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : 5

    Taille minimale de l'echantillon: 1.54 m
    Poids minimal de l'echantillon: 56.4 kg

*/