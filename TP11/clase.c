




void push(stackADT s, int elem){

  TList newNode = malloc(sizeof(*newNode));
  newNode->elem = elem;
  newNode->tail = s->first;

  s->first = newNode;
  s->elemCount++;

}

int pop(stackADT s){

  assert(isEmpty(s) == 0);

  TList aux = s->first;
  s->first = aux->tail;
  s->elemCount--;
  int elemento = aux->elem;
  free(aux);
  return elemento;
}


void freeStack(stackADT s){
  freeList(s->first);
  free(s);

}

static void freeList(TList l){      // Creo esta funcion para freeStack y la hago static porque no estaba en el contrato
  if(l == NULL)
    return ;
  freeList(l->tail);
  free(l);
}

// -------------------------------------------------------------------------------------------------------


// ESTO ESTA HECHO CON VECTORES
int belongs(stackADT s, int elemento){

    for(int i = 0; i < s->elemCount; i++){
    if(s->v[i] == elemento){
      return 1;
    }
  }

  return 0;

}



