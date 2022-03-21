# push_swap
Ce projet vous demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles. Pour le réussir, vous devrez manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.

# ALGORITHME
* Je prends toutes données pour leurs mettre dans un stack a avec la methode fifo.
* Dans un premier j'ai créé un tableau de référence où je met toutes mes données puis leurs triées avec le tri par insertion.
* Je divise ce tableau trié en 5, dans mon stack a je push tous les elements inferieur oubien egal au 5eme element de mon tableau trié vers mon stack b, puis je compare au 10eme, au 15eme ainsi de suit.
* Dans mon stack b je fait un tri par selection, en selectionnant le maximum pour l'envoyer vers mon stack a, à la fin on verra que mes données sont triées du plus petit au plus grand.

