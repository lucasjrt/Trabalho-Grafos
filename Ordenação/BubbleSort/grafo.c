/*no melhor caso: O(N)
  no pior caso: O(N^2)*/
/*n recomendado para grandes qtd de dados*/

void bubbleSort(int *v, int n){//v é o vetor e n é o tam do vetor
    int i, continua, aux, fim = n;
    do{//ele repete até q o vetor esteja td ordenado
        continua = 0;
        for(i=0 ; i<fim-1 ; i++){//pecorrer td o vetor
            if(v[i] > v[i+1]){//se o atual é maior q o anterior, troca eles de lugar
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;//decrementa, pois smp q faz o do uma vez. o ultimo elemento fica ordenado
    }while(continua != 0);
}
