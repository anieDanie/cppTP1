/*
    Description: programme qui affiche certaines statistiques descriptives
    d'un échantillon.

    - patron de fonction : template <class T> ?
    Lien: https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/templates.html

    - transmission de paramètres par pointeurs
    - transmission de paramètres par références

    Auteure: Annie Rhéaume
    Date : 07-05-2023
    Version : initiale en cours (il me reste à préciser les spécifications pour les points 3 et 4 pour les appels de fonctions)
    NOTA: les fonctions afficherValExtremes() et afficherMoyenne() transmettent, pour l'instant,
    leur paramètres EN VALEUR.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

using namespace std;

// Fonction qui affiche les caractéristiques (variables continues et discrètes) d'un échantillon en colonnes

void afficherCaracteristiques(int caracteristique1[], float caracteristique2[], float caracteristique3[], int nbScores, string message)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    cout << "Caracteristiques de l'echantillon : \n" << endl;
    // cout << message << endl; // TODO
    cout << "Score" << setw(5) << "Age" << setw(10) << "Taille" << setw(9) << "Poids" << endl;

    for (int i = 0; i < nbScores ; i++)
    {
        cout << setw(3) << i+1 << setw(6) << caracteristique1[i] << setw(9) << setprecision(2) << 
        caracteristique2[i] << setw(10) << setprecision(1) << caracteristique3[i] << endl;
    }
    cout << endl;
}


// Fonction qui affiche les fréquences selon un critère de sélection
template<class T>
void afficherFrequences(T caracteristique[], T valeurComparee, int nbScores)
{
    cout.setf(ios::fixed); // format décimal
    cout.setf(ios::showpoint); // marqueur décimal

    int compteur = 0;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] >= valeurComparee)
            compteur++;
    } 

    /* Il faut formater le nombre de décimales après la virgule: 0 pour l'age, 2 pour la taille et 1 pour le poids*/
    cout << "Dans cet echantillon : " << compteur << " scores sont superieurs ou egaux a " << valeurComparee << endl;
    cout << endl;
    
}


// Fonction qui affiche la valeur minimale et la valeur maximale d'une caractéristique d'un échantillon
template<class T>
void afficherValExtremes( T caracteristique[], int nbScores)
{
    float valMin = FLT_MAX;
    float valMax = -FLT_MAX;
    for (int i = 0; i < nbScores ; i++)
    {
        if(caracteristique[i] < valMin)
            valMin = caracteristique[i];
        if (caracteristique[i] > valMax)
            valMax = caracteristique[i];
    } 

    /* Il faut formater le nombre de décimales après la virgule: 0 pour l'age, 2 pour la taille et 1 pour le poids*/
    cout << "La valeur minimale est " << valMin << " et la valeur maximale est " << valMax << endl;
    cout << endl;   
}

// Fonction qui affiche la moyenne des scores d'une caractéristique de l'échantillon
template<class T>
void afficherMoyenne( T caracteristique[], int nbScores)
{

    float somme = 0.0f;
    for (int i = 0; i < nbScores ; i++)
    {
        somme += caracteristique[i];
    } 
    double moyenne = somme / nbScores;

    /* Il faut formater le nombre de décimales après la virgule: 2 */
    cout << "La moyenne est " << moyenne << endl;
    cout << endl;   
}


int main()
{

    // Scores de 3 caractéristiques de l'échantillon :

    int age[] = {27, 35, 41, 18, 25, 30, 54, 50};
    float taille[] = {1.72, 1.65, 1.58, 1.91, 1.69, 1.54, 1.83, 1.71},
            poids[] = {65.3 ,67.1, 74.8, 77.7, 72.3, 56.4, 74.9, 72.1};

    int nbPers = sizeof(taille)/ sizeof(float); // float = 4 octets

    string msg = "TODO";
    // Mettre en forme un string pour entête du tableau

    afficherCaracteristiques (age, taille, poids, nbPers, msg);

    afficherFrequences(age, 18, nbPers);
    afficherFrequences (taille, 1.73f, nbPers);
    afficherFrequences (poids, 70.0f, nbPers);

    afficherValExtremes(age, nbPers);
    afficherValExtremes(taille, nbPers);
    afficherValExtremes (poids, nbPers);

    afficherMoyenne(age,nbPers);
    afficherMoyenne(taille,nbPers);
    afficherMoyenne(poids,nbPers);

    return 0;

}

/*

    Affichage en console

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

    Dans cet echantillon : 8 scores sont superieurs ou egaux a 18

    Dans cet echantillon : 2 scores sont superieurs ou egaux a 1.7

    Dans cet echantillon : 5 scores sont superieurs ou egaux a 70.0

    La valeur minimale est 18.0 et la valeur maximale est 54.0

    La valeur minimale est 1.5 et la valeur maximale est 1.9

    La valeur minimale est 56.4 et la valeur maximale est 77.7

    La moyenne est 35.0

    La moyenne est 1.7

    La moyenne est 70.1

*/