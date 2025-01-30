# TourHanoi

**TourHanoi** est une implémentation du célèbre jeu des **Tours de Hanoï**, écrit en **C++**.

## Prérequis

- **Dernière version de C++**

## Installation et Compilation

Un `Makefile` est fourni pour compiler facilement le projet.

### Compilation

Utilisez la commande suivante :

```sh
make
```

### Exécution

Une fois compilé, exécutez le programme avec :

```sh
./prog
```

## Fonctionnement

- Au démarrage, le jeu vous demande de choisir un nombre de **disques** (entre **1 et 9**).
- Ensuite, vous devez sélectionner le **mode de jeu** :
  
  ### Modes disponibles
  - **Mode automatique** :
    - L'algorithme résout le problème seul, en affichant chaque étape.
    - Appuyez sur **Entrée** pour passer à l'étape suivante.
  
  - **Mode manuel** :
    - Le joueur doit résoudre lui-même le puzzle.
    - À chaque tour, choisissez :
      - **Une tour de départ** (d'où vous souhaitez prendre un disque).
      - **Une tour d'arrivée** (où vous souhaitez poser le disque).
    - Le but est de déplacer tous les disques sur la dernière tour en respectant les règles du jeu.

## Règles du jeu

- Un disque ne peut être déplacé que s'il est en haut d'une pile.
- Un disque ne peut être posé que sur une tour vide ou sur un disque plus grand.
