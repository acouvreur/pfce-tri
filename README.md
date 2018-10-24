# Programmation fine et complexité empirique

## Useful links

* Kanban Project [here](https://github.com/acouvreur/pfce-tri/projects/1)

## Différents générateurs de données

1. Tableau trié
2. Tableau trié inversé
3. Tableau constant (une même valeur)
4. Tableau aléatoire de 0 à N
5. Tableau aléatoire de 0 à log(n)
6. Tableau aléatoire de 0 à n^2

Taille des jeux de données : 2^6 à 2^18. A

## Différents algorithmes de tri

1. Tri par insertion
2. Tri par fusion
3. Tri par tas
4. Quicksort
    1. Itératif pivot arbitraire
    2. Itératif pivot aléatoire
    3. Itératif médian 3
    4. Itératif médian 3 avec seuil
5. Tri "built-in" C
6. Smooth sort

## Observations

#### Est-ce que je vois la différence entre tris optimaux (fusion, tas) et non optimaux (insertion, tri rapide dans certains cas) ?

> La différence est visible, car les tris optimaux ont des performances équivalentes peu importe les données.

#### Comparaison des tris optimaux, quel est le meilleur pour mon langage ?

> Même s'il ne ressort pas grand vainqueurs des premiers cas, il conserve des performances très raisonables, cependant il bat tous les autres tris dans des cas plus aléatoires. Cependant il est en concurrence direct avec le quicksort median3 avec seuil, mais qui lui est moins stable. 

#### Comparaisons des méthodes de choix de pivot sur le tri rapide

> Globalement les résultats sont très similaires, voire extrêmement similaires.

4 4 3 3 3 3 4 4 4 4 5 4 X X 4 4