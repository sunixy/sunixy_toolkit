/*
 * sunixy toolkit source file
 */
#include "st_list.h"
#include <assert.h>

void st_list_init(st_list *list) {	
	assert(NULL != list);

    list->head = NULL;	
	list->tail = NULL;
	list->ulLength = 0;
	return;
}

void st_list_destroy(st_list *list) {
    assert(NULL != list);

    while (NULL != list->head) {
        st_list_delete_head(list);
    }
    return;
}

static void add_first_node(st_list *list, st_list_node *node) {
	assert(0 == list->ulLength);
	assert(NULL == list->head);
	assert(NULL == list->tail);

	node->next = NULL;
	list->head = node;		
	list->tail = node;
    return;
}

void st_list_add_head(st_list *list, st_list_node *node) {
	assert(NULL != list);
	assert(NULL != node);

	if (NULL != list->head) {
		assert(list->ulLength > 0);
		assert(NULL != list->tail);
		assert(NULL == list->head->prev);
		assert(NULL == list->tail->next);

		node->next = list->head;
		node->prev = NULL;
		list->head->prev = node;
		list->head = node;
	} else {
		add_first_node(list, node);
	}
	list->ulLength++;
	return;
}

void st_list_add_tail(st_list *list, st_list_node *node) {
	assert(NULL != list);
	assert(NULL != node);

	if (NULL != list->tail) {
		assert(list->ulLength > 0);
		assert(NULL != list->head);
		assert(NULL == list->head->prev);
		assert(NULL == list->tail->next);

		node->prev = list->tail;
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	} else {
		add_first_node(list, node);
	}
	list->ulLength++;
	return;
}

void st_list_delete(st_list *list, st_list_node *node) {
    assert(NULL != list);
    assert(NULL != node);
    assert(HAVE == st_list_have(list, node));

    if (NULL != node->prev) { 
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (NULL != node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    list->ulLength--;

    return;
}

uint8_t st_list_have(st_list *list, st_list_node *node) {
    st_list_node *tmp = NULL;
    assert(NULL != list);
    assert(NULL != node);

    st_list_for_each(list, tmp)
        if (tmp == node) {
            return HAVE;
        }
    return NONE;
}

uint32_t st_list_length(st_list *list) {
    assert(NULL != list);
    return list->ulLength;
}

st_list_node *st_list_get_head(st_list *list) {
    assert(NULL != list);
    return list->head;
}

st_list_node *st_list_get_tail(st_list *list) {
    assert(NULL != list);
    return list->tail;
}

st_list_node *st_list_delete_head(st_list *list) {
    st_list_node *head = NULL;
    assert(NULL != list);

    head = st_list_get_head(list);
    if (NULL == head) {
        return NULL;
    }
    if (NULL != head->next) {
        head->next->prev = NULL;
        list->head = head->next;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    list->ulLength--;
    head->next = NULL;

    return head;
}

st_list_node *st_list_delete_tail(st_list *list) {
    st_list_node *tail = NULL;
    assert(NULL != list);
    tail = st_list_get_tail(list);
    if (NULL == tail) {
        return NULL;
    }
    if (NULL != tail->prev) {
        tail->prev->next = NULL;
        list->tail = tail->prev;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    list->ulLength--;
    tail->prev = NULL;

    return tail;
}

st_list_node *st_list_foreach_find(st_list *list, find_fun fn, uint32_t value) {
    st_list_node *node = NULL;
    assert(NULL != list);
    assert(NULL != fn);

    st_list_for_each(list, node)
        if (fn(node, value)) {
            return node;
        }

    return NULL;
}

