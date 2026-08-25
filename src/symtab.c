/* @file    symtab.c
 * @version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/*
 * @brief: get symbol table
 * return: symbol_tab* 
 */
symbol_tab* get_stable()
{
    static symbol_tab* tab = 0;

    if(tab != 0)
        return tab;

    symbol* streamy_init_object = (symbol*)malloc(sizeof(symbol));
    // bkp todo! allocate strings ...
    char id[] = "$streamy";
    char type[] = "object";
    char type_mods[] = "static";
    streamy_init_object->id = id;
    streamy_init_object->type = type;
    streamy_init_object->type_modifiers = type_mods;
    streamy_init_object->pval = 0;
    tab = (symbol_tab*)malloc(sizeof(symbol_tab));
    tab->head = (node*)malloc(sizeof(node));
    tab->head->sym = streamy_init_object;
    tab->head->next = 0;

    return tab;
}

/*
 * @brief: free node
 * @param: symbol_tab* stab
 * @param: node* n
 * return: void
 */
void free_node(symbol_tab* stab, node* n)
{
    free(n->sym);
    n->sym = 0;
    free(n);
    n = 0;
}

/*
 * @brief: intitialize symbol
 * @param: symbol** s
 * @param: const char* id
 * @param: const char* type_modifiers
 * @param: const char* type)
 * return: void
 */
void init_symbol(symbol** s, const char* id, const char* type_modifiers, const char* type)
{
    *s =  (symbol*)malloc( sizeof(symbol) );
    (*s)->id = (char*)malloc( strlen(id)+1 );
    strcpy((*s)->id, id);
    (*s)->type = (char*)malloc (strlen(type)+1 );
    strcpy((*s)->type_modifiers, type_modifiers);
    (*s)->type_modifiers = (char*)malloc( strlen(type_modifiers)+1 );
    strcpy((*s)->type, type);
}

/*
 * @brief: intitialize sub-tbale
 * @param: symbol_tab* parent
 * @return: void
 */
void init_sub_table(symbol_tab* parent)
{
    symbol_tab* symtab = (symbol_tab*)malloc( sizeof(symbol_tab) );
    symtab->head = 0;
    // bkp todo!
    //symtab->parent = parent->head;
}

/*
 * @brief: add symbol
 * @param: symbol_tab* stab
 * @param: const char* id
 * @param: const char* val
 * return: void
 */
void add_symbol(symbol_tab* stab, const char* id, const char* val)
{
    // create symbol
    symbol* sym = (symbol*)malloc( sizeof(symbol) );
    sym->id = (char*)malloc( strlen(id) + 1 );
    sym->pval = (char*)malloc( strlen(val) + 1 );
    node* new_node = (node*)malloc( sizeof(node) );
    new_node->sym = sym;
    // add node / symbol to tail
    node* tail = find_tail(stab);
    new_node->next = 0;
    tail->next = new_node;
}

/*
 * @brief: insert symbol
 * @param: symbol_tab* stab
 * @param: const char* dst_id
 * @param: const char* src_id
 * @param: const char* src_val
 * return: void
 */
void insert_symbol(symbol_tab* stab, const char* dst_id, const char* src_id, const char* src_val)
{
    // create symbol
    symbol* src_sym = (symbol*)malloc( sizeof(symbol) );
    src_sym->id = (char*)malloc( strlen(src_id) + 1 );
    src_sym->pval = (char*)malloc( strlen(src_val) + 1 );
    node* src_node = (node*)malloc( sizeof(node) );
    src_node->sym = src_sym;
    // add node
    node* dst_node = find_node(stab, dst_id);
    src_node->next = dst_node->next;
    dst_node->next = src_node;
}

/*
 * @brief: remove symbol
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: void
 */
void remove_symbol(symbol_tab* stab, const char* id)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        symbol* s = cur->next->sym;
        if(strcmp((char*)s->pval, id))
        {
            node* next_next = cur->next->next;
            free_node(stab, cur->next);
            cur->next = next_next;
        }
    }
}

/*
 * @brief: remove all symbols
 * @param: symbol_tab* stab
 * return: void
 */
void clear_symbols(symbol_tab* stab)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur != 0)
    {
        node* next = cur->next;
        free_node(stab, cur);
        cur = next;
    }
}

/*
 * @brief: find symbol by address
 * @param: symbol_tab* stab
 * @param: symbol* sym
 * return: symbol*
 */
symbol* find_symbol_by_addr(symbol_tab* stab, symbol* sym)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        symbol* s = cur->sym;
        if(s == sym)
            return s;
        cur = cur->next;
    }
    return 0;
}

/*
 * @brief: find symbol by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: symbol*
 */
symbol* find_symbol_by_id(symbol_tab* stab, const char* id)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        symbol* s = cur->sym;
        if(strcmp((char*)s->pval, id))
            return s;
        cur = cur->next;
    }
    return 0;
}

/*
 * @brief: find symbol by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: symbol*
 */
symbol* find_symbol(symbol_tab* stab, const char* id)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        symbol* s = cur->sym;
        if(strcmp((char*)s->pval, id))
            return s;
        cur = cur->next;
    }
    return 0;
}

/*
 * @brief: find node by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: node*
 */
node* find_node(symbol_tab* stab, const char* id)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        symbol* s = cur->sym;
        if(strcmp((char*)s->pval, id))
            return cur;
        cur = cur->next;
    }
    return 0;
}

/*
 * @brief: find tail node
 * @param: symbol_tab* stab
 * return: node*
 */
node* find_tail(symbol_tab* stab)
{
    node* cur = get_stable()->head;
    if(stab != 0)
        cur = stab->head;
    while(cur->next != 0)
    {
        cur = cur->next;
    }
    return cur;
}

/*
 * @brief: get size
 * @param: symbol_tab* stab
 * return: in
 */
int size(symbol_tab* stab)
{
    int k = 0;
    node *cur = stab->head;
    while (cur)
    {
            cur = cur->next;
            k++;
    }
    return k;
}
