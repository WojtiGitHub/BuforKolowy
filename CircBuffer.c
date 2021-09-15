#include "CircBuffer.h"

static bool isFull(const CircBuffer * const circbuffer){

    if(circbuffer){

        /* ptmp = head++ */
        uint8_t *ptmp = circbuffer->head;

        if(circbuffer->head != &(circbuffer->buffer[circbuffer->bufferSize-1])){

            ptmp++;
        }
        else{

            ptmp = &(circbuffer->buffer[0]);

        }

        /* Jeśli head++ == tail to zapełniony */
        if(ptmp == circbuffer->tail){

            return true;

        }
        else{

            return false;

        }

    }
    else{

        return false;

    }

}

static bool isEmpty(const CircBuffer * const circbuffer){

    if(circbuffer){

        /* Jeśli head == tail to pusty */
        if(circbuffer->head == circbuffer->tail){

            return true;

        }
        else{

            return false;

        }

    }
    else{

        return false;

    }

}

static bool addChar(CircBuffer * const circbuffer, const uint8_t * const character){

    if((circbuffer) && (character)){

        /* Jeśli jest miejsce */
        if(!isFull(circbuffer)){

            /* Dodaj character do bufora */
            (*circbuffer->head) = *character;

            /* Przestaw head na następny element */
            if(circbuffer->head != &(circbuffer->buffer[circbuffer->bufferSize-1])){

                circbuffer->head++;

            }
            else{

                circbuffer->head = &(circbuffer->buffer[0]);

            }

            return true;

        }
        /* Jeśli nie ma miejsca */
        else{

            return false;

        }

    }
    else{

        return false;

    }

}

static bool removeChar(CircBuffer * const circbuffer, uint8_t * const character){

    if((circbuffer) && (character)){

        /* Jeśli coś jest */
        if(!isEmpty(circbuffer)){

        /* Przypisz character element bufora */
        *character = *(circbuffer->tail);

        /* Przestaw tail na następny element */
        if(circbuffer->tail != &(circbuffer->buffer[circbuffer->bufferSize-1])){

            circbuffer->tail++;

        }
        else{

            circbuffer->tail = &(circbuffer->buffer[0]);

        }

        return true;

        }
        /* Jeśli nic nie ma */
        else{

            return false;

        }

    }
    else{

        return false;

    }

}

/*
@brief  Initializes circular buffer struct with a given buffer.
@note   Buffer used by circular buffer is not a part of the struct.
        Circular buffer holds only the buffers address.
@param  circbuffer - Pointer to CircBuffer struct.
@param  buffer - Pointer to buffer that will act as circular.
@param  buffersize - Size of the pointed buffer.
@retval true if initialize passed otherwise false
*/
bool CircBuffer_init(CircBuffer * const circbuffer, uint8_t * const buffer, const uint8_t buffersize){

    if((circbuffer) && (buffer) && (buffersize > 0U)){

        circbuffer->buffer = buffer;
        circbuffer->bufferSize = buffersize;
        circbuffer->head = &(circbuffer->buffer[0]);
        circbuffer->tail = &(circbuffer->buffer[0]);

        return true;

    }
    else{

        return false;

    }

}

/*
@brief  Writes array of data to the circular buffer.
@param  circbuffer - Pointer to CircBuffer struct.
@param  data - Pointer to data buffer.
@param  datasize - Amount of data elements u8 to be added.
@retval true if all data added otherwise false
@note   Function returns false if circular buffer gets full while
        adding data.
*/
bool CircBuffer_write(CircBuffer * const circbuffer, const uint8_t * const data, const uint8_t datasize){

    if((circbuffer) && (data) && (datasize > 0U)){

        for(uint8_t i = 0 ; i < datasize ; i++){

            if(!addChar(circbuffer, &data[i])){

            return false;

            }

        }

        return true;

    }
    else{

        return false;

    }

}

/*
@brief  Reads array of data from the circular buffer.
@param  circbuffer - Pointer to CircBuffer struct.
@param  data - Pointer to data buffer.
@param  datasize - Amount of data elements u8 to be removed.
@retval true if datasize data removed otherwise false
@note   Function returns false if circular buffer gets empty while
        removing data.
*/
bool CircBuffer_read(CircBuffer * const circbuffer, uint8_t * const data, const uint8_t datasize){

    if((circbuffer) && (data) && (datasize > 0U)){

        for(uint8_t i = 0 ; i < datasize ; i++){

            if(!removeChar(circbuffer, &data[i])){

            return false;

            }

        }

        return true;

    }
    else{

        return false;

    }

}
