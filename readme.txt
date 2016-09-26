Binome:
 $Mamamne Ayoube
 $Soufiane Fatima-Ezzahra.

Ce dossier de TP1 contient les fichiers suivantes: 
* try.c : définit les deux fonctions try et throw.
* try.h le header du try.c
* La fonction principale display_stack.c qui fait un affichage simple de deux cas d’exécution (appels de fonction récursifs, et des appels successifs).
-	(try_mul.c ou on utilise le try et throw dans l'exemple de la multiplication)
* Makefile qui fait l’exécution et les commandes nécessaires pour générer  les éxecutable.


La fonction display_stack en gros:
	
	Puisque chaque fonction est décomposées avant l’appel suivant alors les valeur des deux registre %esp et %ebp lors
  des appels récursives ne changent pas.mais pour le cas des appels récursifs, on a une restauration des contextes
  précédant car il y’a une différence de 8 octets entres les registre : esp i > ebp i+1.
