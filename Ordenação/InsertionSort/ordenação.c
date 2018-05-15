/*melhor caso: O(N)
  pior caso: O(N^2)*/
/*eficiente para peq conj de dados*/
/*estável: n altera ordem igual dos dados*/
/*ordena em tempo real, ou seja, a medida q recebe, ja ordena*/

void insertionSort(int *v, int n){ //v é o vetor e n é o tam do vetor
    int i, j, aux;
    for(i=1 ; i<n ; i++){//pecorre td o vetor, começa na 1 pois compara cm os anteriores
        aux = v[i];
        for(j=i ; (j>0) && (aux<v[j-1]) ; j--)//move os elemento maiores para frente
            v[j] = v[j-1];
        v[j] = aux;//coloca o elemento em questão no seu devido lugar
    }
}
