# Aquarium---based-on-project-Javaquarium

Histoire : 

Monsieur Shingshan, aquariophile accompli, vous demande de faire un programme de simulation pour son prochain aquarium.
Il compte y mettre un certain nombre d'espèces de poissons rares et chères, et n'a pas envie qu'au bout de deux mois 
son précieux investissement se transforme en désert…
Votre mission (et vous l'acceptez) : lui concevoir un programme qui fera la chose suivante :

Citation : le cahier des charges
 - Je devrai pouvoir mettre des poissons et des plantes dans mon aquarium virtuel, et faire passer le temps
 pour savoir si tout se passe bien.
 
Traduit en geek / développeur, ça veut dire qu'il faudra un programme en deux phases :
    1. L'initialisation : les poissons et les algues sont ajoutés dans l'aquarium 
    2. Le temps qui passe : on résous les actions d'un tour, et on fait un rapport de la situation. 
    
On est partis ? On y va !

Partie 1 : Peuplons notre Aquarium
Exercice 1.1 : Remplissage de l'aquarium
Il s'agit de la base du programme : avoir un aquarium rempli. L'aquarium contient des poissons et des algues, un nombre
quelconque de chaque. L'algue ne fait rien : c'est une algue, elle se contente d'exister ou non. Le poisson, lui, a un
nom (monsieur Shingshan aime ses poissons et leur donne un nom à chacun) et un sexe (mâle ou femelle). L'aquarium a une
méthode pour ajouter un poisson (avec son nom et son sexe), et une autre méthode pour ajouter une algue. L'aquarium a une
méthode pour faire passer le temps : à chaque nouveau tour, on fait toutes les actions (ce qui n'est pas très passionnant 
pour l'instant puisqu'il n'y en a aucune) et on affiche sur la console :
    • Le nombre d'algues présentes 
    • La liste des poissons avec leur nom et leur sexe. 
Exercice 1.2 : un peu de diversité
En fait, des poissons tous identiques, c'est pas très passionnant. Dans le magasin où se fournit monsieur Shingshan, on 
trouve des poissons carnivores et d'autres herbivores. 
Il y a six races de poissons : Poissons carnivores : Mérou, Thon, Poisson-clown. Poissons herbivores : Sole, Bar, Carpe. 
Chaque poisson peut donc manger (une méthode) : selon s'il est carnivore, il mange une algue (paramètre : une algue), ou un
autre poisson (paramètre : un poisson quel qu'il soit). Cela sera mis en place dans l'étape d'après
