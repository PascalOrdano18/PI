

#include <stdio.h>
#include <stdlib.h>


typedef struct calCDT* calADT;

typedef struct tDate{
    unsigned char day;
    unsigned char month;
    unsigned short year;
}tDate;

typedef struct tEvent {
    char * eventName;
    tDate date;
} tEvent;


/* Crea la estructura que dara soporte al almacenamiento de eventos. */
calADT newCal();
/*
** Agrega un evento al calendario.
** Si \a existe un evento en el calendario para la fecha del evento, la funciyn no lo agrega \
** retorna cero. Si pudo agregar el evento retorna 1.
** Se aVXPe TXe la fecha Uecibida eV Yilida
*/
int addEvent(calADT cal, tEvent event);
/*
** Funciones de iteraciyn para que el usuario pueda consultar todas los eventos del calendario
** en orden cronolygico (del mis antiguo al mis reciente).
** toBegin() iniciali]a el iterador en el evento de fecha mis antigua del calendario.
** Si el calendario es vacto no hace nada.
** hasNext() retorna 1 (uno) si una invocaciyn a nextElement() retorna un
** evento vilido. Retorna cero si no ha\ mis elementos por consumir en el iterador.
** nextElement() retorna el evento del calendario al que apunta el iterador \ hace
** apuntar el iterador al siguiente evento cronolygico del calendario.
** Si no hay mis eventos en el calendario aborta la ejecuciyn.
*/
void toBegin(calADT cal);
int hasNext(calADT cal);
tEvent nextElement(calADT cal);
