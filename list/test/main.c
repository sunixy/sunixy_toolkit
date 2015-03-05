/*
 * sunixy toolkit list unit test
 */
#include "st_list.h" 

static st_list g_unit_test_list = ST_LIST_INIT;
static st_list *test_list = &g_unit_test_list;

typedef struct tagtest_node_t
{
    int id;
    st_list_node node;
    char *comment;
} test_node_t;

static test_node_t node_1 = 
{
    .id = 1,
    .comment = "unit test node 1\n",
};

static test_node_t node_2 =
{
    .id = 2,
    .comment = "unit test node 2\n",
};

static test_node_t node_3 = 
{
    .id = 3,
    .comment = "unit test node 3\n",
};

static void list_dump(st_list *list)
{
    st_list_node *tmp = NULL;
    test_node_t *entry = NULL;

    printf("list lenthg=%ld\n", list->ulLength);
    
    st_list_for_each(list, tmp)
        printf("node id=%2d, %s\n",
                (ST_MEMBER_OF(tmp, test_node_t, node))->id,
                (ST_MEMBER_OF(tmp, test_node_t, node))->comment);
    return;
}

int main(int argc, char *argv[])
{
    list_dump(test_list);
    printf("add node 1 to list head:\n");
    st_list_add_head(test_list, &node_1.node);
    list_dump(test_list);
    printf("add node 2 to list head:\n");
    st_list_add_head(test_list, &node_2.node);
    list_dump(test_list);
    printf("add node 3 to list tail:\n");
    st_list_add_tail(test_list, &node_3.node);
    list_dump(test_list);
    printf("list has node_3? %s\n", 
            st_list_have(test_list, &node_3.node)? "yes":"no");
    printf("delete node 3 from list:\n");
    st_list_delete(test_list, &node_3.node);
    printf("list has node_3? %s\n", 
            st_list_have(test_list, &node_3.node)? "yes":"no");
    printf("add node 3 to list head:\n");
    st_list_add_head(test_list, &node_3.node);
    list_dump(test_list);
    printf("delete node 2 form list:\n");
    st_list_delete(test_list, &node_2.node);
    list_dump(test_list);
    printf("delete list head:\n");
    st_list_delete_head(test_list);
    list_dump(test_list);
    printf("delete list tail:\n");
    st_list_delete_tail(test_list);
    list_dump(test_list);
    printf("add node 3 2 1 to list:\n");
    st_list_add_tail(test_list, &node_3.node);
    st_list_add_tail(test_list, &node_2.node);
    st_list_add_tail(test_list, &node_1.node);
    list_dump(test_list);
    printf("list head is node %d\n", 
            ST_MEMBER_OF(st_list_get_head(test_list), test_node_t, node)->id);
    printf("list tail is node %d\n", 
            ST_MEMBER_OF(st_list_get_tail(test_list), test_node_t, node)->id);

    printf("destroy list:\n");
    st_list_destroy(test_list);
    list_dump(test_list);

	return 0;	 
}

