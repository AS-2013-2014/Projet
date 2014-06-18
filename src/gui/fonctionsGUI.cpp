#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
using namespace std;

#include "fonctionsGUI.hpp"

void saveLevel(int level)
{
    /** Ouvre le fichier saveLevel en �criture **/
    string nomFic = "saveLevel.txt";
    ofstream flux(nomFic.c_str(), ios::out | ios::trunc);

    if(flux)
    {
        /** �crit le niveau envoy� en param�tre dans le fichier **/
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
//        int atoi(char *cha�ne); convertit la cha�ne en entier
//        float atof(char *chaine); convertit la cha�ne en r�el


        // Positionnement dans le fichier
        flux.seekg(0, ios::beg);    // Premi�re ligne
        flux.ignore(7,' ');         // On ignore jusqu'au caract�re espace
        flux.get(a[0]);             // On lit le premier caract�re
        flux.get(a[1]);             // On lite le 2e s'il existe
        level = atoi(a);            // Conversion en entier du tableau de caract�re lu
        cout << "Niveau : " << level << endl;

        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

void saveVolume(int volume)
{
    /** Ouvre le fichier saveVolume en �criture **/
    string nomFic = "saveVolume.txt";
    ofstream flux(nomFic.c_str(), ios::out | ios::trunc);

    if(flux)
    {
        /** �crit le volume envoy� en param�tre dans le fichier **/
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
//        int atoi(char *cha�ne); convertit la cha�ne en entier
//        float atof(char *chaine); convertit la cha�ne en r�el


        // Positionnement dans le fichier
        flux.seekg(0, ios::cur);    // Premi�re ligne
        flux.ignore(8,' ');         // On ignore jusqu'au caract�re espace
        flux.get(a[0]);             // On lit le premier caract�re
        flux.get(a[1]);             // On lite le 2e s'il existe
        flux.get(a[2]);             // On lite le 3e s'il existe
        volume = atoi(a);           // Conversion en entier du tableau de caract�re lu
        cout << "Volume : " << volume << endl;

        flux.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier." << endl;
}

