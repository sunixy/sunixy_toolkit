/*  
 *  sunixy toolkit 
 *  
 */


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _ST_QUEUE_H_
#define	_ST_QUEUE_H_

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

// TODO Insert appropriate #include <>
#include <st_stdtypes.h>
// TODO Insert C++ class definitions if appropriate
typedef uint32_t Message;  

typedef struct tagsQueue{  
    Message *queue;  
    uint16_t size;
    uint16_t head;  
    uint16_t tail;  
} Queue; 

// TODO Insert declarations
int16_t init_queue(Queue *q, Message *address, uint16_t size);
int16_t en_queue(Queue *q, Message m);
int16_t de_queue(Queue *q, Message *m);



// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation



#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* _ST_QUEUE_H_ */

