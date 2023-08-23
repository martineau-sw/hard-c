#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address 
{
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA]; 
};

struct Database
{
  struct Address rows[MAX_ROWS]; 
};

struct Connection
{
  FILE *file;
  struct Database *db;
};

void die(const char *message)
{
  if(errno)
  {
    perror(message);
  }
  else
  {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

void Address_print(struct Address *address)
{
  printf("%d:\t%s\t%s\n", address->id, address->name, address->email);
}

void Database_load(struct Connection *connection)
{
  int rc = fread(connection->db, sizeof(struct Database), 1, connection->file);

  if(rc != 1) die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode)
{
  struct Connection *connection;

  // Allocate memory for connection
    
  connection = malloc(sizeof(struct Connection));

  if(!connection) die("Memory error");

  // Allocate memory for database in connection
  
  connection->db = malloc(sizeof(struct Database));

  if(!connection->db) die("Memory error");

  // Create a new database file if specified
  // Otherwise, open database from existing file

  if(mode == 'c')
  {
    connection->file = fopen(filename, "w");
  }
  else
  {
    connection->file = fopen(filename, "r+");

    if(connection->file) 
    {
      Database_load(connection);
    }
  }

  // Check if file was succesfully loaded

  if(!connection->file) die("Failed to open file");

  return connection;
}

void Database_close(struct Connection *connection)
{
  if(connection) 
  {
    if(connection->file) fclose(connection->file);
    if(connection->db) free(connection->db);
    free(connection);  
  }
}

void Database_write(struct Connection *connection)
{
  rewind(connection->file);

  int rc = fwrite(connection->db, sizeof(struct Database), 1, connection->file);

  if(rc != 1) die("Failed writing to file");

  rc = fflush(connection->file);

  if(rc == -1) die("Cannot write to database");
}

void Database_create(struct Connection *connection)
{
  int i = 0;

  for(i = 0; i < MAX_ROWS; i++)
  {
    struct Address address = { .id = i, .set = 0 };

    connection->db->rows[i] = address;
  }
}

void Database_set(struct Connection *connection, int id, const char *name, const char *email)
{
  struct Address *address = &connection->db->rows[id];
  
  if(address->set) die("Address already set");

  address->set = 1;

  char *res = strcpy(address->name, name);

  if(!res) die("Name copy failed");

  res = strcpy(address->email, email);

  if(!res) die("Name copy failed");
}

void Database_get(struct Connection *connection, int id)
{
  struct Address *address = &connection->db->rows[id];

  if(address->set)
  {
    Address_print(address);
  }
  else
  {
    die("ID is not set");
  }
}

void Database_delete(struct Connection *connection, int id) 
{
  struct Address address = { .id = id, .set = 0 };

  connection->db->rows[id] = address;
}

void Database_list(struct Connection *connection)
{
  int i = 0;

  struct Database *db = connection->db;

  for(i = 0; i < MAX_ROWS; i++) 
  {
    struct Address *address = &db->rows[i];

    if(address->set) Address_print(address);
  }
}

int main(int argc, char *argv[])
{
  if(argc < 3) die("USAGE: app17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *connection = Database_open(filename, action);

  int id = 0;

  if(argc > 3) id = atoi(argv[3]);

  if(id >= MAX_ROWS) die("ID entry exceeds maximum rows");

  switch(action)
  {
    case 'c':
      Database_create(connection);
      Database_write(connection);
      break;

    case 'g':
      if(argc != 4) die("Enter ID for get operation");
      Database_get(connection, id);
      break;

    case 's':
      if(argc != 6) die("Enter ID, Name, and Email for set operation");
      Database_set(connection, id, argv[4], argv[5]);
      Database_write(connection);
      break;

    case 'd':
      if(argc != 4) die("Enter ID for delete operation");
      Database_delete(connection, id);
      Database_write(connection);
      break;

    default:
    case 'l':
      Database_list(connection);
      break;
  }

  Database_close(connection);

  return 0;
}
