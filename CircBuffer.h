#ifndef CIRCBUFFER_H
#define CIRCBUFFER_H

#include <stdint.h>
#include <stdbool.h>

/* Struktura bufora kołowego, zawiera:

   bufor abuffer
   wskaźnik zapisu head
   wskaźnik odczytu tail
   zmienną rozmiaru bufora

 */
typedef struct{

    uint8_t *abuffer;
    uint8_t *phead;
    uint8_t *ptail;
    uint8_t xbufferSize;

} CircBuffer;

/* Inicjuje strukturę bufora kołowego (circbuffer) buforem (buffer) o rozmiarze (buffersize) */
void CircBuffer_init(CircBuffer *circbuffer, uint8_t* const buffer, const uint8_t buffersize);

/* Dodaje znak (character) do buforu kołowego pod warunkiem, że jest miejsce
   Jeśli było miejsce to dodaje znak i zwraca [true]
   Jeśli nie było miejsca porzuca znak i zwraca [false]
*/
bool CircBuffer_addChar(CircBuffer *circbuffer, const uint8_t *character);

/* Ściąga znak z bufora kołowego pod warunkiem, że bufor nie jest pusty
   Jeśli nie jest pusty to ściąga znak do zmiennej (character) i zwraca [true]
   Jeśli jest pusty zwraca [false]
*/
bool CircBuffer_getChar(CircBuffer *circbuffer, uint8_t *character);


#endif
