# Algoritmi di ordinamento

In questa sezione vengono trattati due algoritmi di ***ordinamento ricorsivi***:

- MergeSort
- QuickSort

Entrambi gli algoritmi utilizzano un approccio ***divide et impera***.

## MergeSort
L'algoritmo si suddivide in tre step:

1. gli `n` elementi da ordinare vengono suddivisi in due gruppi da `n / 2` elementi.
2. le due sottosequenze vengono riordinate ricorsivamente con l'utilizzo della funzione ***Merge***.
3. le sottosequenze ordinate vengono *combinate* per creare la sequenza originale ordinata.

La seguente figura raffigura l'albero dell'algoritmo:

![mergesort](img_doc/merge_sort_tree_4.png)

La complessità computazionale è la seguente:

- tempo O(nlogn)
- spazio O(logn)

## QuickSort
L'algoritmo si suddivide in tre step:

1. viene scelto un elemento(in maniera casuale o l'ultimo) dagli elementi da ordinare.
2. gli elementi < dell'elemento scelto verrano disposti alla sua sinistra, i > sulla destra.
3. si applica ricorsivamente il meccanismo alle sottosequenze che si creano suddividendo gli elementi iniziali.

La seguente figura raffigura l'albero dell'algoritmo:

![quicksort](img_doc/quick_sort_tree.png)

La complessità computazionale dipende da quale elemento cardine viene scelto, se l'elemento cardine divide sempre a metà gli elementi:

- tempo O(nlogn)
- spazio O(nlogn)

Nel caso peggiore invece avremo:

- tempo O(n^2)
- spazio O(n)

## Differenze principali

L'algoritmo ***Quicksort*** non necessita di una struttura dati di supporto per l'ordinamento data la modifica dei dati *in place*, invece nel ***Mergesort*** è fondamentale per la realizzazione del suddetto.

Ulteriori differenze risiedono nella complessità computazionale: il Mergesort ha una complessità fissa, il Quicksort dipende dalla scelta del cardine; nonostante ciò si è sperimentato che il Quicksort mediamente ha una performance migliore.