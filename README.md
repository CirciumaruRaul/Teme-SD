# Teme-SD 

<--- Aici sunt cerintele de la fiecare tema.

#1.   Spunem ca o imagine digitala binară M este o matrice de m x m elemente (pixeli) 0 sau 1. Un element a al matricei este adiacent
cu b, daca b se afla deasupra, la dreapta, dedesubtul, sau la stanga lui a in imaginea M.
Spunem ca doi pixeli 1 adiacenti apartin aceleiasi componente. Problema va cere sa etichetati pixelii imaginii astfel incat doi 
pixeli primesc aceeasi eticheta daca si numai daca apartin aceleiasi componente.

#2.  Implementati un arbore binar de cautare in care informatia este de tip string (char[]) cu urmatorul comportament:
-ordinea arborelui este ordinea lexicografica
-cand doresc sa inserez un string care exista deja in arbore, se sterge cel egal din arbore in loc sa se insereze ceva

#3.  Folosind (quicksort sau mergesort sau heapsort), implementati diferenta a doua multimi. Fiecare multime este un array de intregi,
iar rezultatul este un array de intregi, continand elementele din diferenta. O(n log n + m log m).

#4.  Folosind un tabel de dispersie pentru multimea mai mare, implementati diferenta a doua multimi. Cealalta multime este un array de
intregi, iar rezultatul este un array de intregi, continand elementele din diferenta. O(n + m + coliziuni).

#5.  Scrieți un program care să funcționeze pe orice graf neorientat care să enumere 3-ciclurile din graf.Testati-l pe graful complet
K6 minus muchia (1,2).

<--- Idee de rezolvare pentru probleme:

#1 - Am pornit cu 2 matrici, cea pe care doresc sa o "colorez" si una "alba" (adica plina de 0). Verific in matricea initiala daca am
este 1 pixelul pe care ma aflu si pixelul corespondent din matricea "alba" este 0, daca este o colorez pe cea "alba" la acele coordonate.

#2 - Am creat structura de arbore binar la care am modificat inserarea, verifica la inceput daca exista un nod cu aceasi informatie,
daca nu exista il adauga, daca exista il sterge.

#3 - Am sortat cele 2 array-uri, apoi am modificat putin o interclasare.

#4 - Am folosit hashtable pentru a avea timp constant de acces la fiecare element din tabel, astfel am creat un hashtable pentru 
array-ul mai mare, iar apoi printr-o simpla iterare prin al doilea array, am verificat daca exista sau nu elementul in hashtable.

#5 - Am adaugat o functie de "exista_muchie" pentru ca ulterior sa folosesc un for i,j,k cu i=0, j=i+1, k=j+1 pentru a nu parcurge de
2 ori aceiasi muchie cu punct de opriere i<=lungime-2, j<=lungime-1, k<=lungime. 
