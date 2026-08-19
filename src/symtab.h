/* @file    symtab.h
 * @version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 */
#ifndef _SYMTAB_H_
#define _SYMTAB_H_

typedef struct symbol
{
    char* id;
    char* type_modifiers;
    char* type;
    void* pval;
} symbol;

typedef struct node
{
    symbol* sym;
    struct node* next;
    struct node* prev;
} node;

typedef struct binary_node
{
    void* data;
    struct node* left;
    struct node* right;
} binary_node;

typedef struct tree_node
{
    void* data;
    int count;
    struct tree_node* nodes;
} tree_node;


typedef struct map_node
{
    int key;
    char*name;
    symbol* sym;
} map_node;

typedef struct object
{
    char* fields[255];
    symbol symbols[255];
    node* next;
} object;

typedef struct symbol_tab
{
   node* head;
   struct symbol_tab* parent;
} symbol_tab;

// get root symbol table

/*
 * @brief: get symbol table
 * return: symbol_tab* 
 */
symbol_tab* get_stable();
/*
 * @brief: free node
 * @param: symbol_tab* stab
 * @param: node* n
 * return: void
 */
void free_node(symbol_tab* stab, node* n);
/*
 * @brief: intitialize symbol
 * @param: symbol** s
 * @param: const char* id
 * @param: const char* type_modifiers
 * @param: const char* type)
 * return: void
 */
void init_symbol(symbol** s, const char* id, const char* type_modifiers, const char* type);
/*
 * @brief: intitialize sub-tbale
 * @param: symbol_tab* parent
 * @return: void
 */
void init_sub_table(symbol_tab* parent);
/*
 * @brief: add symbol
 * @param: symbol_tab* stab
 * @param: const char* id
 * @param: const char* val
 * return: void
 */
void add_symbol(symbol_tab* stab, const char* id, const char* val);
/*
 * @brief: insert symbol
 * @param: symbol_tab* stab
 * @param: const char* dst_id
 * @param: const char* src_id
 * @param: const char* src_val
 * return: void
 */
void insert_symbol(symbol_tab* stab, const char* dst_id, const char* src_id, const char* src_val);
/*
 * @brief: remove symbol
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: void
 */
void remove_symbol(symbol_tab* stab, const char* id);
/*
 * @brief: remove all symbols
 * @param: symbol_tab* stab
 * return: void
 */
void clear_symbols(symbol_tab* stab);
/*
 * @brief: find symbol by address
 * @param: symbol_tab* stab
 * @param: symbol* sym
 * return: symbol*
 */
symbol* find_symbol_by_addr(symbol_tab* stab, symbol* sym);
/*
 * @brief: find symbol by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: symbol*
 */
symbol* find_symbol_by_id(symbol_tab* stab, const char* id);
/*
 * @brief: find symbol by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: symbol*
 */symbol* find_symbol(symbol_tab* stab, const char* id);
/*
 * @brief: find node by id
 * @param: symbol_tab* stab
 * @param: const char* id
 * return: node*
 */
node* find_node(symbol_tab* stab, const char* id);
/*
 * @brief: find tail node
 * @param: symbol_tab* stab
 * return: node*
 */
node* find_tail(symbol_tab* stab);
/*
 * @brief: get size
 * @param: symbol_tab* stab
 * return: in
 */
int size(symbol_tab* stab);

#endif
