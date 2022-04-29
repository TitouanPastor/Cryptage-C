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
*  Nom du fichier : chiffrage.c                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrage.h"

bool verifierAlphanum(char* texte) {
    
    printf("\nChaîne à vérifier : %s\n\n", texte);

    bool isCorrect = true;
    char courant;
    for( int i=0; i < strlen(texte); i++ ) {
        courant = *(texte+i);
        if (!isalnum(courant)) {
            isCorrect = false;
        }
    }
    return isCorrect;
}

char* convertirAccent(char* texte) {

    char* texteConversion;
    texteConversion = malloc(sizeof(char) * strlen(texte) +1);
    unsigned char courant;
    for( int i=0; i < strlen(texte); i++ ) {

        courant = *(texte+i);

        switch (courant) {
            case 169 : //e
            case 168 : 
            case 170 : 
            case 171 : 
                *(texteConversion+i) = 'e';
                break;

            case 136 : //E
            case 137 :
            case 138 :
            case 139 :
                *(texteConversion+i) = 'E';
                break;

            case 160 : //a
            case 161 :
            case 162 :
            case 163 :
            case 164 :
                *(texteConversion+i) = 'a';
                break;

            case 128 : //A
            case 129 :
            case 130 :
            case 131 :
            case 132 :
                *(texteConversion+i) = 'A';
                break;

            case 172 : //i
            case 173 :
            case 174 :
            case 175 :
                *(texteConversion+i) = 'i';
                break;

            case 178 : //o
            case 179 :
            case 180 :
            case 181 :
            case 182 :
                *(texteConversion+i) = 'o';
                break;

            case 185 : //u
            case 186 :
            case 187 :
            case 188 :
                *(texteConversion+i) = 'u';
                break;

            default : //defaut
                *(texteConversion+i) = *(texte+i);
                break;
        }

    }

    char* texteOut;
    int indexOut = 0;
    texteOut = malloc(sizeof(char) * strlen(texte) +1);
    for( int i=0; i < strlen(texteConversion); i++ ) {

        if ( *(texteConversion + i) != -61 ) {
            *(texteOut+indexOut) = *(texteConversion + i);
            indexOut++;
        }
    }

    return texteOut;
}


char* chiffrerCesar(char* texte, int cle) {

    char* texteOut;
    char courant;
    char alphabetStart;
    int alphabetNumber;
    texteOut = malloc(sizeof(char) * strlen(texte) +1);

    for( int i=0; i < strlen(texte); i++ ) {

        if (islower(*(texte+i))) {
            alphabetStart = 'a';
            alphabetNumber = 26;
        } else if (isupper(*(texte+i))) {
            alphabetStart = 'A';
            alphabetNumber = 26;
        } else {
            alphabetStart = '0';
            alphabetNumber = 10;
        }
        
        char c = *(texte+i) - alphabetStart;
        c += cle;
        c = c % alphabetNumber;
        *(texteOut+i) = c + alphabetStart;

    }

    return texteOut;
}


char* dechiffrerCesar(char* texte, int cle) {

    char* texteOut;
    char courant;
    char alphabetStart;
    int alphabetNumber;
    texteOut = malloc(sizeof(char) * strlen(texte) +1);

    for( int i=0; i < strlen(texte); i++ ) {

        if (islower(*(texte+i))) {
            alphabetStart = 'a';
            alphabetNumber = 26;
        } else if (isupper(*(texte+i))) {
            alphabetStart = 'A';
            alphabetNumber = 26;
        } else {
            alphabetStart = '0';
            alphabetNumber = 10;
        }
        char c = *(texte+i) - alphabetStart;
        c += alphabetNumber - cle;
        c = c % alphabetNumber;
        *(texteOut+i) = c + alphabetStart;

    }

    return texteOut;
}


char* chiffrerVigenere(char* texte, char* cle) {

    int NbTexte = strlen(texte);
    char* texteOut;
    int intDecalage;
    char c;
    texteOut = malloc(sizeof(char) * NbTexte +1 );
    for ( int i = 0 ; i < NbTexte ; i++ ) {
        
        intDecalage = *(cle + (i % strlen(cle))) - 'a' + 1;
        c = (*(texte+i) - 'a') + intDecalage;
        c = c % 26;
        *(texteOut+i) = c + 'a';
    }

    return texteOut;

}

char* dechiffrerVigenere(char* texte, char* cle) {

    int NbTexte = strlen(texte);
    char* texteOut;
    int intDecalage;
    char c;
    texteOut = malloc(sizeof(char) * NbTexte +1 );
    for ( int i = 0 ; i < NbTexte ; i++ ) {
        
        intDecalage = *(cle + (i % strlen(cle))) - 'a' + 1;
        c = (*(texte+i) - 'a') + (26 - intDecalage);
        c = c % 26;
        *(texteOut+i) = c + 'a';
    }

    return texteOut;

}

void afficherMenu() {

    int choix = 0;
    char *texte;
    char *texteOut;
    texte = malloc(256);
    texteOut = malloc(256);
    printf("\n\n- ################### - Menu principal - ################### -\n\n");
    printf("1 - Chiffrer un texte avec l'algorithme de César\n");
    printf("2 - Déchiffrer un texte avec l'algorithme de César\n");
    printf("3 - Chiffrer un texte avec l'algorithme de Vigenère\n");
    printf("4 - Déchiffrer un texte avec l'algorithme de Vigenère\n");
    printf("5 - Vérifier si un texte est alphanumérique\n");
    printf("6 - Nettoyer le fichier log\n");
    printf("0 - Quitter l'application\n");

    printf("Sélectionnez votre option : ");
    scanf("%d", &choix);

     switch (choix) {

        case 1: {

            FILE* file  = fopen("Chiffrage.txt", "a");
            printf("Entrez votre texte à chiffrer avec César : ");
            scanf("%s", texte);
            if (!verifierAlphanum(texte)) {
                printf("Votre texte n'est pas alphanumérique !! CONVERSION DES ACCENTS !!\n");
                texte = convertirAccent(texte);
                printf("Maintenant on le chiffre avec l'algorithme de César !\n");
            }

            printf("Entrez la clé pour chiffrer en césar : ");
            int input_cle;
            scanf("%d", &input_cle);
            texteOut = chiffrerCesar(texte, input_cle);
            printf("Texte chiffré en césar (clé = %d) %s = %s\n",input_cle, texte, texteOut);

            fprintf(file,"\n/================/ Chiffrage César /================/\n\n");
            fprintf(file, "Texte initial : %s\n", texte);
            fprintf(file, "Chiffrage avec la clé : %i\n", input_cle);
            fprintf(file, "Texte chiffré : %s\n", texteOut);
            fprintf(file,"\n/===================================================/\n\n");
            fclose(file);

            free(texte);
            free(texteOut);
            afficherMenu();
            break;
        }

        case 2: {

            FILE* file  = fopen("Chiffrage.txt", "a");
            printf("Entrez un texte à déchiffrer avec l'algorithme de césar : \n");
            scanf("%s", texte);
            
            printf("Entrez sa clé de déchiffrement :");
            int input_cle;
            scanf("%d", &input_cle);
            texteOut = dechiffrerCesar(texte, input_cle);
            printf("Texte %s déchiffré en césar (clé = %d) : %s\n",texte, input_cle , texteOut);

            fprintf(file,"\n/===============/ Déchiffrage César /===============/\n\n");
            fprintf(file, "Texte initial chiffré : %s\n", texte);
            fprintf(file, "Déchiffrage avec la clé : %i\n", input_cle);
            fprintf(file, "Texte déchiffré : %s\n", texteOut);
            fprintf(file,"\n/===================================================/\n\n");
            fclose(file);

            free(texte);
            free(texteOut);
            afficherMenu();
            break;
        }

        case 3: {

            FILE* file  = fopen("Chiffrage.txt", "a");
            printf("Entrez votre texte à chiffrer avec Vigenère : ");
            scanf("%s", texte);
            if (!verifierAlphanum(texte)) {
                printf("Votre texte n'est pas alphanumérique !! CONVERSION DES ACCENTS !!\n");
                texte = convertirAccent(texte);
                printf("Maintenant on le chiffre avec l'algorithme de Vigenère !\n");
            }
            printf("Entrez la clé pour chiffrer en Vigenère (chaine de caractère) : ");
            char *input_cleV;
            input_cleV = malloc(256);
            scanf("%s", input_cleV);
            texteOut = chiffrerVigenere(texte, input_cleV);
            printf("Texte chiffré en Vigenere (clé = %s) %s = %s\n",input_cleV, texte, texteOut);

            fprintf(file,"\n/==============/ Chiffrage Vigenère /===============/\n\n");
            fprintf(file, "Texte initial : %s\n", texte);
            fprintf(file, "Chiffrage avec la clé : %s\n", input_cleV);
            fprintf(file, "Texte chiffré : %s\n", texteOut);
            fprintf(file,"\n/===================================================/\n\n");
            fclose(file);

            free(texte);
            free(input_cleV);
            afficherMenu();
            break;

        }

        case 4: {

            FILE* file  = fopen("Chiffrage.txt", "a");
            printf("Entrez un texte à déchiffrer avec l'algorithme de Vigenere : \n");
            scanf("%s", texte);
            char *input_cleV;
            input_cleV = malloc(256);
            printf("Entrez sa clé de déchiffrement :");
            scanf("%s", input_cleV);
            texteOut = dechiffrerVigenere(texte, input_cleV);
            printf("Texte %s déchiffré en Vigenere (clé = %s) : %s\n",texte, input_cleV ,texteOut);

            fprintf(file,"\n/=============/ Déchiffrage Vigenère /==============/\n\n");
            fprintf(file, "Texte initial chiffré : %s\n", texte);
            fprintf(file, "Déchiffrage avec la clé : %s\n", input_cleV);
            fprintf(file, "Texte déchiffré : %s\n", texteOut);
            fprintf(file,"\n/===================================================/\n\n");
            fclose(file);

            free(texte);
            free(input_cleV);
            afficherMenu();
            break;

        }
            
        case 5: {

            FILE* file  = fopen("Chiffrage.txt", "a");
            printf("entrer un texte pour vérifier si il est alphanumérique ou non : ");
            scanf("%s", texte);

            fprintf(file,"\n/==========/ Vérification alphanumérique /==========/\n\n");
            fprintf(file, "Texte à vérifier : %s\n", texte);

            if (verifierAlphanum(texte)) {
                fprintf(file, "Texte alphanumérique\n");
                printf("Votre texte est bien alphanumérique.\n");
            } else {
                fprintf(file, "Texte non alphanumérique\n");
                printf("Votre texte n'est pas alphanumérique !!\n");
            }
            fprintf(file,"\n/===================================================/\n\n");

            fclose(file);
            afficherMenu();
            break;

        }

        case 6: {
            FILE* file  = fopen("Chiffrage.txt", "a");
            file=freopen(NULL,"w",file);
            fclose(file);
            printf("\nNettoyage effectué\n");
            afficherMenu();
            break;
        }
            

        case 0:
            break;
        default:
            printf("Chiffre incorrect, recommencez s-il vous plaît.\n");
            afficherMenu();
            break;

     }

}