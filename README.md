# Projet de chiffrage en language C

lien git du projet : https://gitlab.info.iut-tlse3.fr/pst4279a/chiffrage-projet-c-s2

Ce projet à pour but de développer une application capable de **chiffrer** et **déchiffrer** un texte écrit par l'utilisateur à l'aide du chiffrage de **César** et de celui de **Vigenère**.

## Sommaire
* [Équipe de développement](#équipe-de-développement)
* [Fonctionnement](#fonctionnement)
* [Documentation](#documentation)

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
- Supprimer le contenu du fichier log

**Exemple pour le chiffrage de César :**   
Dans un premier temps l'utilisateur va devoir rentrer un texte de son choix à chiffrer, puis une vérification alphanumérique va être effectué avec `verifierAlphanum(texte)`, si le texte comporte des accents, la méthode `convertirAccent(texte)` va se charger de remplacer les accents par leurs lettre de la table ASCII, puis le texte va pouvoir être chiffré avec `chiffrerCésar(texte, clé)` après que l'utilisateur ai rentré la clé de chiffrement. Un résumé avec les principales informations est disponible dans le fichier texte suivant : `chiffrage.txt`

## Documentation
Chaque action que l'utilisateur effectue va appeler une ou plusieurs fonction(s). Voici ci-dessous leur documentation :

##### /!\ ATTENTION /!\  
`Tout les texte entrés par l'utilisateur doivent être sans accents, sans quoi le programme s'arrêtera.`  


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



