#ifndef CIRCBUFFER_H
#define CIRCBUFFER_H

#include <stdint.h>
#include <stdbool.h>

/*
@brief Circular Buffer structure definition
*/
typedef struct{

    uint8_t *buffer;     /*!< Circular buffer buffer >*/
    uint8_t  bufferSize; /*!< Size of buffer >*/
    uint8_t *head;       /*!< Circular buffer head >*/
    uint8_t *tail;       /*!< Circular buffer tail >*/

} CircBuffer;

/* Initialization function */
bool CircBuffer_init(CircBuffer * const circbuffer, uint8_t * const buffer, const uint8_t buffersize);

/* Operation functions */
bool CircBuffer_write(CircBuffer * const circbuffer, const uint8_t * const data, const uint8_t datasize);
bool CircBuffer_read(CircBuffer * const circbuffer, uint8_t * const data, const uint8_t datasize);

#endif
