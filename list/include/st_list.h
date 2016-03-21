/*
 * sunixy toolkit header file
 */
#ifndef _ST_LIST_H_
#define _ST_LIST_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <st_stdtypes.h>

typedef struct tagst_list_node {
	struct tagst_list_node *prev;
	struct tagst_list_node *next;
}st_list_node;

typedef struct tagst_list  {
	uint32_t ulLength;
	st_list_node *head;
	st_list_node *tail;	
} st_list;

#define ST_LIST_INIT {0, NULL, NULL}
#define HAVE    (0x01U)
#define NONE    (0x00U)
#define st_list_for_each(list, node)    \
    for (node = list->head; node != NULL; node = node->next)

#if 0 
#define container_of(ptr, type, member) ({                      \
         const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
         (type *)( (char *)__mptr - offsetof(type,member) );})
#endif

#define ST_MEMBER_OF_IMPL(pMember, Type, MemberName) \
    ((Type *)(((unsigned char *)(pMember)) - (int)&(((Type *)0)->MemberName)))

#define ST_MEMBER_OF(pMember, Type, MemberName) \
    ((pMember != NULL) ? ST_MEMBER_OF_IMPL(pMember, Type, MemberName) : NULL)

typedef unsigned char (*find_fun)(st_list_node *node, unsigned long value);

void st_list_init(st_list *list);
void st_list_destroy(st_list *list);
void st_list_add_head(st_list *list, st_list_node *node);
void st_list_add_tail(st_list *list, st_list_node *node);
void st_list_delete(st_list *list, st_list_node *node);
uint8_t st_list_have(st_list *list, st_list_node *node);
uint32_t st_list_length(st_list *list);
st_list_node *st_list_get_head(st_list *list);
st_list_node *st_list_get_tail(st_list *list);
st_list_node *st_list_delete_head(st_list *list);
st_list_node *st_list_delete_tail(st_list *list);
st_list_node *st_list_foreach_find(st_list *list, find_fun fn, uint32_t value);


#ifdef	__cplusplus
}
#endif /* __cplusplus */
#endif   /*_ST_LIST_H_*/

