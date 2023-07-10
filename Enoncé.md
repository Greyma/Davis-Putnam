Objectif du Travail
Le but de ce projet est d'implémenter en C++ l’algorithme de Davis-Putnam pour déterminer la
satisfiabilité d'une formule du calcul propositionnel.


Description de l'algorithme
L'algorithme de Davis-Putnam utilise des formules mises sous forme normale conjonctive. Chaque
formule est constituée d'un ensemble de clause. Chaque clause est constituée d'une disjonction de
littéraux. Chaque littéral est une représenté sous forme d'une variable propositionnelle ou sa la
négation d'une variable propositionnelle.


La procédure de Davis-Putnam (avec quelques optimisations quant au choix du prochain littéral à
utiliser) correspond à l'algorithme suivant :


Faire
   s'il n'y a plus de clause alors succès
     sinon
        si x est une clause formée d'un seul littéral uniquement  alors 
             on sélectionne x: suppression de toutes les clauses qui contiennent x, et suppression de ¬x dans toutes les clauses où il apparaît 
        sinon si y est un littéral qui apparaît dans une clause, mais pas sa négation alors 
           on sélectionne y: suppression de toutes les clauses qui contiennent y 
        sinon sélectionner le prochain littéral z non encore utilisé: 
            suppression de toutes les clauses qui contiennent z, et suppression de ¬z dans toutes les clauses où il apparait,
                    si on a généré la clause vide alors on sélectionne
                       ¬z: suppression de toutes les clauses qui contiennent
                       ¬z, et suppression de z dans toutes les clauses où il apparait
                              si on a généré la clause vide alors échec tant qu'on n'a pas succès (il n'y a plus de clause) ou échec (on a généré la clause vide).
           En cas d’échec la formule est insatisfiable et en cas de succès elle est satisfiable.