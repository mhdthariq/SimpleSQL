#ifndef DB_H
#define DB_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Buffer to handle user input
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

// Results of executing a statement
typedef enum {
    EXECUTE_SUCCESS,
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

extern const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLE_MAX_ROWS;

// Table structure with pages and number of rows
typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];  // Array of pages for rows
} Table;

// Functions for handling user input and table operations
InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

// Table management functions
Table* new_table();
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_statement(Statement* statement, Table* table);

// Row management functions
void print_row(Row* row);
void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);
void* row_slot(Table* table, uint32_t row_num);
void free_table(Table* table);

#endif // DB_H
