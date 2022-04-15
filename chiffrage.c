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
        //printf("%c : %i \n", courant, isCorrect); // debug
    }
    return isCorrect;
}


char* convertirAccent(char* texte) {



    char* texteConversion;
    texteConversion = malloc(sizeof(char) * strlen(texte) +1);
    unsigned char courant;
    for( int i=0; i < strlen(texte); i++ ) {

        courant = *(texte+i);
        printf("Char %c : %i\n",courant, courant); //debug

        switch (courant) {
            case 169 : //e
            case 168 : 
            case 170 : 
            case 171 : 
                printf("'e' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'e';
                break;

            case 136 : //E
            case 137 :
            case 138 :
            case 139 :
                printf("'E' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'E';
                break;

            case 160 : //a
            case 161 :
            case 162 :
            case 163 :
            case 164 :
                printf("'a' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'a';
                break;

            case 128 : //A
            case 129 :
            case 130 :
            case 131 :
            case 132 :
                printf("'A' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'A';
                break;

            case 172 : //i
            case 173 :
            case 174 :
            case 175 :
                printf("'i' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'i';
                break;

            case 178 : //o
            case 179 :
            case 180 :
            case 181 :
            case 182 :
                printf("'o' accentué trouvé à la place %i du texte\n", i);
                *(texteConversion+i) = 'o';
                break;

            case 185 : //u
            case 186 :
            case 187 :
            case 188 :
                printf("'u' accentué trouvé à la place %i du texte\n", i);
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
        //printf("index : %d texte : %c decalage : %d texteOut : %c\n",i, *(texte+i), intDecalage, *(texteOut+i)); //debug

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
        //printf("index : %d texte : %c decalage : %d texteOut : %c\n",i, *(texte+i), intDecalage, *(texteOut+i)); //debug

    }

    return texteOut;

}