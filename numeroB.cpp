/*
    Description: programme qui affiche certaines statistiques descriptives
    d'un échantillon.

    - patron de fonction : template <class T> ?
    Lien: https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/templates.html

    - transmission de paramètres par pointeurs
    - transmission de paramètres par références

    Auteure: Annie Rhéaume
    Date : 08-05-2023
    Version initiale: cette version révise les fonctions calculerFrequences(), calculerValExtremes()
    et calculerMoyenne(). Elles utilisent toutes un patron de fonction; calculerValExtremes() et 
    calculerMoyenne() sont codées pour une transmission des paramètres par pointeurs des statistiques
    à afficher, déclarées dans le programme principal. Je dois donc revoir la question 4, qui demande
    que l'un des paramètres soit transmis PAR RÉFÉRENCE. Est-ce que ça signifie: nécessairement la moyenne?

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


// Fonction qui calcule les fréquences selon un critère de sélection. Retourne le nombre de fréquences (int),
// Transmission par valeur des paramètres; utilisation d'un patron de fonction

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


// Fonction qui calcule la valeur minimale et la valeur maximale d'une caractéristique d'un échantillon. Ne retourne rien.
// Modification des variables Min et Max (déclarées dans le programme principal) via les pointeurs
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
    // Valeurs minimales et maximales pointées vers les variables Min et Max de la caractéristique
    *ptrMin = valMin;
    *ptrMax = valMax;
   
}

// Fonction qui calcule la moyenne des scores d'une caractéristique de l'échantillon. Ne retourne rien.
// Modification des variables moyenne (déclarées dans le programme principal) via les pointeurs
// Pour le patron de fonction, voir: https://cplusplus.com/doc/oldtutorial/templates/
// Ici, on suppose que le type de l'adresse de la valeur moyenne passée en paramètre peut aussi être de différents types (double et float) - sinon, double* ptrMoyenne
template<class T, class U>
void calculerMoyenne(T caracteristique[], int nbScores, U* ptrMoyenne)
{

    float somme = 0.0f;
    for (int i = 0; i < nbScores ; i++)
    {
        somme += caracteristique[i];
    } 
    // Valeur moyenne pointée vers variable Moyenne de la caractéristique
    *ptrMoyenne = somme / nbScores;  
}


int main()
{

    // Scores de 3 caractéristiques de l'échantillon :

    int age[] = {27, 35, 41, 18, 25, 30, 54, 50};
    float taille[] = {1.72, 1.65, 1.58, 1.91, 1.69, 1.54, 1.83, 1.71},
            poids[] = {65.3 ,67.1, 74.8, 77.7, 72.3, 56.4, 74.9, 72.1};

    int nbPers = sizeof(taille)/ sizeof(float); // float = 4 octets
    
    // Mettre en forme un string pour entête du tableau
    string msg = "TODO";
    
    // Afficher les caractéristiques en colonnes
    afficherCaracteristiques (age, taille, poids, nbPers, msg);

    // Calculer les fréquences
    cout << "Nombre de personnes de 18 ans ou plus : " << 
    calculerFrequences(age, 18, nbPers) << endl;
    cout << "Nombre de personnes d'une taille superieure ou egale a 1.73 metre : " << 
    calculerFrequences (taille, 1.73f, nbPers) << endl;
    cout << "Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : " << 
    calculerFrequences (poids, 70.0f, nbPers) << endl;
    cout << endl;

    // Calculer les valeurs mininales et maximales de chacune des caractéristiques et les afficher
    int ageMin, ageMax;
    float tailleMin, tailleMax, poidsMin, poidsMax;

    calculerValExtremes(age, nbPers, &ageMin, &ageMax);
    calculerValExtremes(taille, nbPers, &tailleMin, &tailleMax);
    calculerValExtremes (poids, nbPers, &poidsMin, &poidsMax);

    cout << "Age minimal : " << ageMin << " ans.\nAge maximal : " << ageMax << " ans. " <<endl;
    cout << "Taille minimale : " << tailleMin << " metre.\nTaille maximale : " << tailleMax << " metre. " <<endl;
    cout << "Poids minimal : " << poidsMin << " kg.\nPoids maximal : " << poidsMax << " kg. " <<endl;
    cout << endl;

    // Calculer les moyennes de chacune des caractéristiques et les afficher

    double ageMoyen; 
    float tailleMoyenne, poidsMoyen;

    calculerMoyenne(age,nbPers, &ageMoyen);
    calculerMoyenne(taille,nbPers, &tailleMoyenne);
    calculerMoyenne(poids,nbPers, &poidsMoyen);

    cout << "Age moyen : " << ageMoyen << " ans." <<endl;
    cout << "Taille moyenne : " << tailleMoyenne << " metre."<<endl;
    cout << "Poids moyen : " << poidsMoyen << " kg." <<endl;
    cout << endl;

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

    Nombre de personnes de 18 ans ou plus : 8
    Nombre de personnes d'une taille superieure ou egale a 1.73 metre : 2
    Nombre de personnes ayant un poids superieur ou egal a 70.0 kg : 5

    Age minimal : 18 ans.
    Age maximal : 54 ans.
    Taille minimale : 1.5 metre.
    Taille maximale : 1.9 metre.
    Poids minimal : 56.4 kg.
    Poids maximal : 77.7 kg.

    Age moyen : 35.0 ans.
    Taille moyenne : 1.7 metre.
    Poids moyen : 70.1 kg.
*/