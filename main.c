#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#include "chiffrage.h"




void main() {

    char *texteVAN;
    texteVAN = malloc(256); //256 caractères max ici (on peut changer)
    printf("entrer un texte pour vérifier si il est alphanumérique ou non : ");
    scanf("%s", texteVAN);
    if (verifierAlphanum(texteVAN)) {
        printf("Votre texte est bien alphanumérique !\n");
    } else {
        printf("Votre texte n'est pas alphanumérique !! CONVERSION DES ACCENTS !!\n");
        printf("\n###############################################################################\n\n");
        texteVAN = convertirAccent(texteVAN);

        for( int i=0; i < strlen(texteVAN); i++ ) {

            printf("%c : %d\n", *(texteVAN +i), *(texteVAN +i));
        }

        printf("Texte transformé sans accents :%s\n", texteVAN);
    }

    //CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR//CESAR
    
    printf("\n###############################################################################\n\n");

    printf("Maintenant on le chiffre avec l'algorithme de César !\n");
    printf("Entrez la clé pour chiffrer en césar : ");
    int input_cle;
    scanf("%d", &input_cle);
    printf("Texte chiffré en césar (clé = %d) %s = %s\n",input_cle, texteVAN, chiffrerCesar(texteVAN, input_cle));

    printf("\n###############################################################################\n\n");

    char* texteCHIFFRER;
    texteCHIFFRER = malloc(256); //Taille max
    printf("Entrez un texte à déchiffrer avec l'algorithme de césar : \n");
    scanf("%s", texteCHIFFRER);
    printf("Entrez sa clé de déchiffrement :");
    scanf("%d", &input_cle);
    printf("Texte %s déchiffré en césar (clé = %d) : %s\n",texteCHIFFRER, input_cle ,dechiffrerCesar(texteCHIFFRER, input_cle));


    //VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//VIGENERE//

    char *texteVANV;
    texteVANV = malloc(256); //256 caractères max ici (on peut changer)
    printf("entrer un texte pour vérifier si il est alphanumérique ou non : ");
    scanf("%s", texteVANV);
    if (verifierAlphanum(texteVANV)) {
        printf("Votre texte est bien alphanumérique !\n");
    } else {
        printf("Votre texte n'est pas alphanumérique !! CONVERSION DES ACCENTS !!\n");
        printf("\n###############################################################################\n\n");
        texteVANV = convertirAccent(texteVANV);

        for( int i=0; i < strlen(texteVANV); i++ ) {

            printf("%c : %d\n", *(texteVANV +i), *(texteVANV +i));
        }

        printf("Texte transformé sans accents :%s\n", texteVANV);
    }

    printf("\n###############################################################################\n\n");

    printf("Maintenant on le chiffre avec l'algorithme de Vigenere !\n");
    printf("Entrez la clé pour chiffrer en Vigenere (chaine de caractère) : ");
    char *input_cleV;
    input_cleV = malloc(256); //256 caractères max ici (on peut changer)
    scanf("%s", input_cleV);
    char* resultat = chiffrerVigenere(texteVANV, input_cleV);
    printf("%s\n", resultat);
    //printf("Texte chiffré en Vigenere (clé = %s) %s = %s\n",input_cleV, texteVAN, chiffrerVigenere(texteVAN, input_cleV));

    printf("\n###############################################################################\n\n");

    char* texteCHIFFRERV;
    texteCHIFFRERV = malloc(256); //Taille max
    printf("Entrez un texte à déchiffrer avec l'algorithme de Vigenere : \n");
    scanf("%s", texteCHIFFRERV);
    printf("Entrez sa clé de déchiffrement :");
    scanf("%d", &input_cleV);
    printf("Texte %s déchiffré en Vigenere (clé = %s) : %s\n",texteCHIFFRERV, input_cleV ,dechiffrerVigenere(texteCHIFFRERV, input_cleV));


    //char* texteAccent = "e é è ê ë a à á â ä i í ì î ï o ó ò ô õ ö u ú ù û ü E É È Ê Ë A Á À Â Ã Ä";
    //printf("Texte avec accents : %s\n", texteAccent);
    //printf("Texte transformé sans accents : %s\n",convertirAccent(texteAccent));

    

    //char* texteCesar = "Aabcxyz19";
    //printf("Texte chiffré en césar (clé = 3) %s = %s\n", texteCesar, chiffrerCesar(texteCesar,3));
    //printf("Texte %s déchiffré en césar (clé = 3) : %s\n",chiffrerCesar(texteCesar,3) ,dechiffrerCesar(chiffrerCesar(texteCesar,3), 3));

    

}





