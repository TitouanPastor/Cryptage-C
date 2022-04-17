# Projet de chiffrage en language C

Ce projet à pour but de développer une application capable de **chiffrer** et **déchiffrer** un texte écrit par l'utilisateur à l'aide du chiffrage de **César** et de celui de **Vigenère**.

## Sommaire
* [Équipe de développement](#Équipe-de-développement)
* [Fonctionnement](#Fonctionnement)
* [Documentation](#Documentation)

## Équipe de développement
* Titouan Pastor  
* Gaia Ducournau  
* Jonathan Bezara  
* Chloé Sechi  

## Fonctionnement
Un **menu** permet à l'utilisateur de choisir entre plusieurs options :

- Chiffrer un texte avec le chiffrage de César
- Déchiffrer un texte avec le chiffrage de César
- Chiffrer un texte avec le chiffrage de Vigenère
- Déchiffrer un texte avec le chiffrage de Vigenère
- Vérifier si un texte est bien alphanumérique

## Documentation
Chaque action que l'utilisateur va appeler une ou plusieurs fonction(s). Voici ci-dessous leur documentation :

> ### Vérification alphanumérique
> **Entête** : boolean verifierAlphanum(char* texte);  
> **Entrée** : texte en clair (char*)  
> **Sortie** : Retourne vrai si le texte est alphanumérique, faux sinon.
 
> ### Conversion des accents
> **Entête** : char* convertirAccent(char* texte);    
> **Entrée** : texte   
> **Sortie** : Nouveau texte sans accents  

> ### Chiffrer un texte
> **Entête** : char* chiffrerCésar(char* texte, int cle) **ou** char* chiffrerVigenère(char* texte, char* cle);    
> **Entrée** : le texte ainsi que la clé (int ou char*)   
> **Sortie** : le texte chiffré avec césar ou autre   
> Appel la fonction convertirAccent si le texte n'est pas alphanumérique.  
 
> ### Déchiffrer un texte
> **Entête** : char* dechiffrerCésar(char* texte, int cle) **ou** char* dechiffrerVigenère(char* texte, char* cle);  
> **Entrée** : le texte chiffré ainsi que la clé (int ou char*)   
> **Sortie** : le texte déchiffrer  
> Appel la fonction convertirAccent si le texte n'est pas alphanumérique.  



