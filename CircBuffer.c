#include "CircBuffer.h"

/* Sprawdza czy buffor jest zapełniony */
bool static isFull(CircBuffer *circbuffer){

    /* ptmp = head++ */
    uint8_t *ptmp = circbuffer->phead;

    if(circbuffer->phead != &(circbuffer->abuffer[circbuffer->xbufferSize-1])){

        ptmp++;
    }
    else{

        ptmp = &(circbuffer->abuffer[0]);

    }

    /* Jeśli head++ == tail to zapełniony */
    if(ptmp == circbuffer->ptail){

        return true;

    }
    else{

        return false;

    }

}

/* Sprawdza czy buffor jest pusty */
bool static isEmpty(CircBuffer *circbuffer){

    /* Jeśli head == tail to pusty */
    if(circbuffer->phead == circbuffer->ptail){

        return true;

    }
    else{

        return false;

    }

}


void CircBuffer_init(CircBuffer *circbuffer, uint8_t* const buffer, const uint8_t buffersize){

    circbuffer->abuffer = buffer;
    circbuffer->phead = &(circbuffer->abuffer[0]);
    circbuffer->ptail = &(circbuffer->abuffer[0]);
    circbuffer->xbufferSize = buffersize;

}

bool CircBuffer_addChar(CircBuffer *circbuffer, const uint8_t *character){

    /* Jeśli jest miejsce */
    if(isFull(circbuffer) != true){


        /* Dodaj character do bufora */
        (*circbuffer->phead) = *character;

        /* Przestaw head na następny element */
        if(circbuffer->phead != &(circbuffer->abuffer[circbuffer->xbufferSize-1])){

            circbuffer->phead++;

        }
        else{

            circbuffer->phead = &(circbuffer->abuffer[0]);

        }

        return true;

    }
    /* Jeśli nie ma miejsca */
    else{

        return false;

    }

}

bool CircBuffer_getChar(CircBuffer *circbuffer, uint8_t *character){

    /* Jeśli coś jest */
    if(isEmpty(circbuffer) != true){

        /* Przypisz character element bufora */
        *character = *(circbuffer->ptail);

        /* Przestaw tail na następny element */
        if(circbuffer->ptail != &(circbuffer->abuffer[circbuffer->xbufferSize-1])){

            circbuffer->ptail++;

        }
        else{

            circbuffer->ptail = &(circbuffer->abuffer[0]);

        }

        return true;

    }
    /* Jeśli nic nie ma */
    else{

        return false;

    }

}
