/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Pastor Titouan                                               *
*                                                                             *
*  Nom-prénom2 : Ducournau Gaia                                               *
*                                                                             *
*  Nom-prénom3 : Bezara Jonathan                                              *
*                                                                             *
*  Nom-prénom4 : Sechi Chloé                                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : chiffrage.h                                               *
*                                                                             *
******************************************************************************/

/*Permet de vérifier si un texte est alphanumérique ou non
retourne 1 si il est alphanumérique, 0 sinon */
bool verifierAlphanum(char* texte);

/*Permet de convertir les accents en leur équivalents dans la table ASCII*/
char* convertirAccent(char* texte);

/*Permet de chiffrer un texte avec l'algorithme de César et sa clé de chiffrement*/
char* chiffrerCesar(char* texte, int cle);

/*Permet de chiffrer un texte avec l'algorithme de César et sa clé de déchiffrement*/
char* dechiffrerCesar(char* texte, int cle);

/*Permet de chiffrer un texte avec l'algorithme de Vigenère et sa clé de chiffrement*/
char* chiffrerVigenere(char* texte, char* cle);

/*Permet de chiffrer un texte avec l'algorithme de Vigenère et sa clé de déchiffrement*/
char* dechiffrerVigenere(char* texte, char* cle);

/*Permet d'afficher le menu du programme*/
void afficherMenu();