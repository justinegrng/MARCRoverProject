# MARCRoverProject 🤖 Rover Run !
![Bannière GitHub Projet MARCRover](https://github.com/user-attachments/assets/caf2dc6c-530e-4501-99e5-d717c883eb2f)

## Pour commencer ...
[Lien vers le dépôt GitHub](https://github.com/justinegrng/MARCRoverProject.git)
### Membres du projet
> Justine GARNUNG  
> Yéléna SAINTE-ROSE  
> Mélia TANGUY

### Files organization
> [!TIP]
> Il suffit de cliquer ci-dessous sur "📁 MARCRoverProject" afin de visualiser l'arborescence de notre projet.


<details>
<summary> 📁 MARCRoverProject </summary>

- `main.c`
- `loc.c`
- `loc.h`
- `map.c`
- `map.h`
- `moves.c`
- `moves.h`
- `queue.c`
- `queue.h`
- `stack.c`
- `stack.h`
- `tree.c`
- `tree.h`
- `menu.c`
- `menu.h`
<details>
<summary> 📁 maps </summary>
  
- `example1.map`
- `training.map`
</details>
</details>

## Fonctions
✔ La fonction a été développée et elle fonctionne (elle n'est pas forcément implémentée).  
❌La fonction a été développée mais elle ne fonctionne pas ou alors elle n'a pas été développée.  
*Vous pouvez voir le nom de chaque juste après son commentaire pour les repérer dans le code.*

  ✔ *Calcul de l’arbre des déplacements* →  `buildTree`  
	✔ *Choix de la ‘meilleure’ séquence à appliquer pour une phase* → `findOptimalPath` `getOptimalSequence`  
	✔ *Mise à jour de la localisation de MARC après chaque phase* → `applyOptimalSequence`  
	✔ *Vérification de l’arrivée à la base* → `isAtBaseStation`  
	✔ *Vérification de la sortie de la carte* → `isOutOfMap`  
	✔ *Vérification des passages ou arrêt sur les crevasses* → `isOnCrevasse`  
	❌*Utilisation d’un fichier de carte quelconque* → `createMapFromFile`  
	❌*Choix aléatoire des mouvements disponibles pour une phase* → `getRandomMove`   
	❌*Prise en compte des types de sols pour les modifications de déplacements* → `Not done` 

