/*melhor caso: O(N log N)
  pior caso (raro): O(N^2)*/
/*desvantagens: como escolher o pivô?*/
/*é estável*/

void quickSort(int *v, int ini, int fim){
    int pivo;
    if(fim>ini){
        pivo = particiona(v,ini,fim);//acha o pivo
        quickSort(v,ini,pivo-1);//para elementos antes do pivo
        quickSort(v,pivo+1,fim);//para elementos dpois do pivo
    }
}

int particiona(int *v, int ini, int fim){
    int esq, dir, pivo, aux;
    esq = ini;
    dir = fim;
    pivo = v[ini];//pivo é o inicio da linha
    while(esq<dir){//separa, deixando a esq do pivo os menores q ele, e a dir do pivo os maiores q ele
        while(v[esq] <= pivo)//avança a pos da esq, perando os menores q o pivo
            esq++;
        while(v[dir] > pivo)//retrocede a da dir, parando nos maiores q o pivo
            dir--;
        if(esq<dir){//troca os elementos da esq cm os da dir
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[ini] = v[dir];//inicio vale o ultimo valor da dir
    v[dir] = pivo;//pivo recebe o valor da dir
    return dir;
}
