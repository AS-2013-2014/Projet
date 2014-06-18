#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
using namespace std;

#include "fonctionsGUI.hpp"

void saveLevel(int level)
{
    /** Ouvre le fichier saveLevel en écriture **/
    string nomFic = "saveLevel.txt";
    ofstream flux(nomFic.c_str(), ios::out | ios::trunc);

    if(flux)
    {
        /** écrit le niveau envoyé en paramètre dans le fichier **/
        flux << "Niveau: " << level;
        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

void loadLevel()
{
    string nomFic = "saveLevel.txt";
    ifstream flux(nomFic.c_str(), ios::in);

    if(flux)
    {
        int level;
        char a[3];
//        int atoi(char *chaîne); convertit la chaîne en entier
//        float atof(char *chaine); convertit la chaîne en réel


        // Positionnement dans le fichier
        flux.seekg(0, ios::beg);    // Première ligne
        flux.ignore(7,' ');         // On ignore jusqu'au caractère espace
        flux.get(a[0]);             // On lit le premier caractère
        flux.get(a[1]);             // On lite le 2e s'il existe
        level = atoi(a);            // Conversion en entier du tableau de caractère lu
        cout << "Niveau : " << level << endl;

        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

void saveVolume(int volume)
{
    /** Ouvre le fichier saveVolume en écriture **/
    string nomFic = "saveVolume.txt";
    ofstream flux(nomFic.c_str(), ios::out | ios::trunc);

    if(flux)
    {
        /** écrit le volume envoyé en paramètre dans le fichier **/
        flux << "Volume: " << volume;
        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

void loadVolume()
{
    string nomFic = "saveVolume.txt";
    ifstream flux(nomFic.c_str(), ios::in);

    if(flux)
    {
        int volume;
        char a[3];
//        int atoi(char *chaîne); convertit la chaîne en entier
//        float atof(char *chaine); convertit la chaîne en réel


        // Positionnement dans le fichier
        flux.seekg(0, ios::cur);    // Première ligne
        flux.ignore(8,' ');         // On ignore jusqu'au caractère espace
        flux.get(a[0]);             // On lit le premier caractère
        flux.get(a[1]);             // On lite le 2e s'il existe
        flux.get(a[2]);             // On lite le 3e s'il existe
        volume = atoi(a);           // Conversion en entier du tableau de caractère lu
        cout << "Volume : " << volume << endl;

        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

