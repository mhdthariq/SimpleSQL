#ifndef DB_H
#define DB_H

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

// Buffer to handle user input
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

// Results of executing a statement
typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_DUPLICATE_KEY,
    EXECUTE_TABLE_FULL
} ExecuteResult;

// Meta-command results
typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

// Prepare statement results
typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

// Types of statements
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

// Sizes for columns in the database
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

// Row definition in the table
typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

// Statement type (insert or select) and the row to insert
typedef struct {
    StatementType type;
    Row row_to_insert; // only used by insert statement
} Statement;

// Macro to get the size of a struct's attribute
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

// Declare constants to be used for row sizes, offsets, and page sizes
extern const uint32_t ID_SIZE;
extern const uint32_t USERNAME_SIZE;
extern const uint32_t EMAIL_SIZE;
extern const uint32_t ID_OFFSET;
extern const uint32_t USERNAME_OFFSET;
extern const uint32_t EMAIL_OFFSET;
extern const uint32_t ROW_SIZE;

// Declare constants for common node header layout
extern const uint32_t NODE_TYPE_SIZE;
extern const uint32_t NODE_TYPE_OFFSET;
extern const uint32_t IS_ROOT_SIZE;
extern const uint32_t IS_ROOT_OFFSET;
extern const uint32_t PARENT_POINTER_SIZE;
extern const uint32_t PARENT_POINTER_OFFSET;
extern const uint32_t COMMON_NODE_HEADER_SIZE;

// Declare constants for leaf node header layout
extern const uint32_t LEAF_NODE_NUM_CELLS_SIZE;
extern const uint32_t LEAF_NODE_NUM_CELLS_OFFSET;
extern const uint32_t LEAF_NODE_HEADER_SIZE;

// Declare constants for leaf node body layout
extern const uint32_t LEAF_NODE_KEY_SIZE;
extern const uint32_t LEAF_NODE_KEY_OFFSET;
extern const uint32_t LEAF_NODE_VALUE_SIZE;
extern const uint32_t LEAF_NODE_VALUE_OFFSET;
extern const uint32_t LEAF_NODE_CELL_SIZE;
extern const uint32_t LEAF_NODE_SPACE_FOR_CELLS;
extern const uint32_t LEAF_NODE_MAX_CELLS;

// Declare constants for leaf node split
extern const uint32_t LEAF_NODE_RIGHT_SPLIT_COUNT;
extern const uint32_t LEAF_NODE_LEFT_SPLIT_COUNT;

// Declare constants for internal node header layout
extern const uint32_t INTERNAL_NODE_NUM_KEYS_SIZE;
extern const uint32_t INTERNAL_NODE_NUM_KEYS_OFFSET;
extern const uint32_t INTERNAL_NODE_RIGHT_CHILD_SIZE;
extern const uint32_t INTERNAL_NODE_RIGHT_CHILD_OFFSET;
extern const uint32_t INTERNAL_NODE_HEADER_SIZE;

// Declare constants for internal node body layout
extern const uint32_t INTERNAL_NODE_KEY_SIZE;
extern const uint32_t INTERNAL_NODE_CHILD_SIZE;
extern const uint32_t INTERNAL_NODE_CELL_SIZE;

extern const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100

// Page structure with number of rows and page size
typedef struct {
    int file_descriptor;
    uint32_t file_length;
    uint32_t num_pages;
    void* pages[TABLE_MAX_PAGES];
} Pager;

// Table structure with pages and number of rows
typedef struct {
    Pager* pager;
    uint32_t root_page_num;
} Table;

// Cursor structure to keep track of the current row
typedef struct {
    Table* table;
    uint32_t page_num;
    uint32_t cell_num;
    bool end_of_table; // Indicates a position past the last element
} Cursor;

// Node type for internal nodes and leaf nodes
typedef enum {
    NODE_INTERNAL,
    NODE_LEAF
} NodeType;

// Functions for handling user input and table operations
InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

// Table management functions
Table* db_open(const char* filename);
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_statement(Statement* statement, Table* table);


// Row management functions
void print_row(Row* row);
void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);
void* row_slot(Table* table, uint32_t row_num);

// Pager functions
void* get_page(Pager* pager, uint32_t page_num);
Pager* pager_open(const char* filename);
uint32_t get_unused_page_num(Pager* pager);
void db_close(Table* table);

// Cursor functions
Cursor* table_start(Table* table);
Cursor* table_find(Table* table, uint32_t key);
void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);

// Node functions (B-tree)
void initialize_leaf_node(void* node);
uint32_t* leaf_node_num_cells(void* node);
void* leaf_node_cell(void* node, uint32_t cell_num);
uint32_t* leaf_node_key(void* node, uint32_t cell_num);
void* leaf_node_value(void* node, uint32_t cell_num);
void print_leaf_node(void* node);
void print_constants();
void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);
Cursor* leaf_node_find(Table* table, uint32_t page_num, uint32_t key);
NodeType get_node_type(void* node);
void set_node_type(void* node, NodeType type);
void set_node_root(void* node, bool is_root);
void print_tree(Pager* pager, uint32_t page_num, uint32_t indentation_level);


#endif // DB_H
