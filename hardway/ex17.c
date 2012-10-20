#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


#define MAX_DATA  512
#define MAX_LINE 100


struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_LINE];
};

struct Connection {
    FILE *file;
    struct Database *db; 
};

void die(const char *message)
{
    if(errno){
        perror(message);
    }else {
        printf("ERROR: %s \n", message);
    }
}

void Database_load(struct Connection *conn){
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("failure to load database");
}

struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) die("Memory error");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) die("Memory error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    } 

    if (!conn->file)  die("Can't open the file");

    return conn;
}

void Database_create(struct Connection *conn) {
    int i = 0;

    for (i = 0; i < MAX_LINE; i++){
        struct Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email){
    struct Address *addr = &(conn->db->rows[id]);
    if (addr->set) die("already set, delete it first");

    addr->set = 1;
    
    char *res = strncpy(addr->name, name, MAX_DATA);
    if (!res) die("copy name failure");

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) die("copy email failure");
}

void Address_print(struct Address *addr){
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_get(struct Connection *conn, int id){
    struct Address *addr = &(conn->db->rows[id]);

    if (addr->set){
        Address_print(addr);
    } else {
        die("Id is not set");
    }

}

void Database_delete(struct Connection *conn, int id){
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn){
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_LINE; i++){
        struct Address *cur = &(db->rows[i]);
        if (cur->set){
            Address_print(cur);
        }
    }
}

void Database_write(struct Connection *conn) {
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) die("failure to write database");

    rc = fflush(conn->file);
    if (rc == -1) die("fialure to flush database");
}

void Database_close(struct Connection *conn){
    if (conn) {
        if (conn->file) fclose(conn->file);
        if (conn->db) free(conn->db);
        free(conn);
    }
}


int main(int argc, char *argv[])
{
    if (argc < 3) die("USAGE: ex17.o <dbfile> <action> [action params]");
    char *filename = argv[1];
    char action = argv[2][0];

    struct Connection *conn = Database_open(filename, action); 
    int id;
    id = atoi(argv[3]);
    switch (action){
        case 'c': 
            Database_create(conn);
            Database_write(conn);
            break;
        case 's':
            if (argc != 6) die("need id , name, email set");
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;
        case 'g': 
            if (argc != 4) die("need id");
            Database_get(conn, id);
            break;
        case 'd':
            if (argc != 4) die("need id to delete");
            Database_delete(conn, id);
            Database_write(conn);
            break;
        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }
    
    Database_close(conn);
    return 0;
}

