#include <stdio.h>

typedef struct tContact {
    char * name;
    char * phoneNumber;
} tContact;

typedef struct addressBookCDT * addressBookADT;

/* Crea un nuevo TAD vacÃ­o */
addressBookADT newAddressBook(void);

/* Almacena un nuevo grupo de contactos. Si el grupo existe, no hace nada.
** No diferencia entre minÃºsculas y mayÃºsculas, el grupo "abc" es el mismo que "ABC",
** "Abc", etc. pero distinto que " abc" o "abc "
** Almacena una copia del nombre, que no tiene un lÃ­mite para su longitud
*/
int addGroup(addressBookADT addressBook, const char * groupName);

/* Si existe un grupo de nombre groupName, agrega el contacto contact a la agenda
** Si el grupo no existe, no hace nada
** Si el contact ya estaba relacionado al grupo (habÃ­a uno con el mismo nombre),
** no lo agrega
*/
int addContact(addressBookADT addressBook, const char * groupName, tContact contact);

/*
** Permite iterar por todos los contactos de la agenda
** QUE PERTENEZCAN AL GRUPO INDICADO por parÃ¡metro en toBegin
** El orden es alfabÃ©tico por nombre del contacto.
*/
void toBeginForGroup(addressBookADT addressBook, const char * groupName);

int hasNextForGroup(addressBookADT addressBook);

/* Retorna un contacto, aborta si no hay siguiente */
tContact nextForGroup(addressBookADT addressBook);

/*
** Permite iterar por todos los grupos de la agenda
** El orden es alfabÃ©tico por nombre del grupo.
*/
void toBegin(addressBookADT);

int hasNext(addressBookADT);

/* Retorna una copia del grupo, aborta si no hay siguiente */
char * next(addressBookADT);