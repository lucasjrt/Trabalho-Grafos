/*melhor caso: O(N^2)
  pior caso: O(N^2)*/
/*n é estável: altera a ordem de dados iguais*/
/*ineficiente para grandes conjs de dados*/

void selectionSort(int *v, int n){//v é o vetor e o n é o tam do vetor
    int i, j, menor, troca;
    for(i=0 ; i<n-1 ; i++){//pecorre td o vetor
        menor = i;//considera o i como menor valor
        for(j=i+1 ; j<n ; j++){//vai do i até o final do vetor, procurando o menor elemento
            if(v[j]<v[menor])//verifica se é menor do q o i
                menor = j;//se for, atualiza o menor
        }
        if(i != menor){//realiza a troca do elemento, ou seja, o i troca de pos cm o menor
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}
