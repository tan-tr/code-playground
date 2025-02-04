#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "Pool.h"

ClientNode * create_client_node(pid_t client_pid)
{
    ClientNode *client_node = (ClientNode *) malloc(sizeof(ClientNode));
    if (client_node != NULL)
    {
        client_node->client_pid = client_pid;
        client_node->next = NULL;
    }
    return client_node;
}

PoolNode * create_pool_node(int value, ClientNode *client)
{
    PoolNode *node = (PoolNode *) malloc(sizeof(PoolNode));
    if (node != NULL)
    {
        node->value = value;
        node->is_in_use = 1;
        node->client = client;
        node->next = NULL;
    }
    return node;
}

LList * llist_init()
{
    LList *llist = (LList *) malloc(sizeof(LList));
    llist->head = NULL;
    llist->tail = NULL;
    llist->list_size = 0;
    return llist;
}

int llist_is_empty(LList *llist)
{
    return (llist->list_size == 0);
}