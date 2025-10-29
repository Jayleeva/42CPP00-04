# Notions importantes

**ATTENTION: on ne fait plus du C, mais bien du C++!**
- On utilise les fonctions de la librairie standard (std::)!!! Pas besoin de tout coder de zéro!!!
- On utilise les types propres au C++! Fini les char* (dans la plupart des cas), vive les string!
- On n'utilise plus ´´´malloc()´´´ et ´´´free()´´´ pour allouer dynamiquement (sur la heap), mais ´´´new´´´ et ´´´delete´´´.
- On n'utilise plus ´´´printf()´´´ pour imprimer, mais ´´´cout´´´. Pour prendre un input utilisateur, on utilise ´´´cin´´´. 

**ATTENTION: même si c'est bien pratique, pas le droit aux namespace!! Pour appeler une fonction ou un mot-clé de la std, il faut y accoller ´´´std::´´´ en préfixe.**
Exemple:
´´´
std::toupper()
´´´

## Eviter les doubles inclusions
En vérité, on peut faire comme on a fait jusque-là, avec des ´´´ifndef, define, endif´´´.

On peut aussi remplacer ce système en écrivant simplement ´´´pragma once´´´ en début de header.

## 
