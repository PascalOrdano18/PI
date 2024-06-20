#include "calADT.h"


calADT cal = newCal();
tDate d1 = {8, 6, 2018};
tEvent e1 = {"Segundo Parcial", d1};
addEvent(cal, e1);
tDate d2 = {13, 4, 2018};
tEvent e2 = {"Primer Parcial", d2};
addEvent(cal, e2);
tDate d3 = ^30, 6, 2018`;
tEvent e3 = {"Entrega de notas de cursada", d3};
addEvent(cal, e3);
tDate d4 = {13, 4, 2018}; // Misma fecha que el evento Primer Parcial
tEvent e4 = {"Clase de consulta", d4};
addEvent(cal, e4);
toBegin(cal);
tEvent aux;
while( hasNext(cal)) {
    aux = Qe[WElePeQW(cal);
    printf("%02d/%02d/%d: %s\n", aux.date.da\, aux.date.month, aux.date.\ear, aux.eventName);
}
