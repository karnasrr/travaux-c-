//
//  main.cpp
//  SQL-cpp
//
//  Created by nasr on 27/10/2024.
//  extrait: https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm

/*
 Affiche
 
 sqlite3 version:3.47.0
 sqlite3 source ID:2024-10-21 16:30:22 03a9703e27c44437c39363d0baf82db4ebc94538a0f28411c85dda156f82636e
 Opened database successfully
 Table created successfully
 Records created successfully
 Callback_r function called: ID = 1
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 25000.0

 Callback_r function called: ID = 2
 NAME = Allen
 AGE = 25
 ADDRESS = Texas
 SALARY = 15000.0

 Callback_r function called: ID = 3
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 Callback_r function called: ID = 4
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 Callback_r function called: ID = 5
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 20000.0

 Callback_r function called: ID = 6
 NAME = Allen
 AGE = 25
 ADDRESS = Texas
 SALARY = 15000.0

 Callback_r function called: ID = 7
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 Callback_r function called: ID = 8
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 Operation done successfully
 ID = 1
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 25000.0

 ID = 2
 NAME = Allen
 AGE = 25
 ADDRESS = Texas
 SALARY = 15000.0

 ID = 3
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 ID = 4
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 ID = 5
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 20000.0

 ID = 6
 NAME = Allen
 AGE = 25
 ADDRESS = Texas
 SALARY = 15000.0

 ID = 7
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 ID = 8
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 Operation done successfully
 ID = 1
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 25000.0

 ID = 3
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 ID = 4
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 ID = 5
 NAME = Paul
 AGE = 32
 ADDRESS = California
 SALARY = 20000.0

 ID = 6
 NAME = Allen
 AGE = 25
 ADDRESS = Texas
 SALARY = 15000.0

 ID = 7
 NAME = Teddy
 AGE = 23
 ADDRESS = Norway
 SALARY = 20000.0

 ID = 8
 NAME = Mark
 AGE = 25
 ADDRESS = Rich-Mond
 SALARY = 65000.0

 Operation done successfully
 Program ended with exit code: 0
 
 **/



#include <stdio.h>
#include <sqlite3.h>


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


static int callback_r(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    
    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        //std::cout << azColName[i] << " : " << (argv[i]? argv[i]: "NULL") << '\n';
    }
    
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
    char *sql,*sql1;
    
    sqlite3_stmt *pstmt; // prepared statements corresponding to sql
    
    const char* data = "Callback_r function called";
    
   rc = sqlite3_open("testExemple.db", &db);

  printf("sqlite3 version:%s\n",sqlite3_libversion());
  printf("sqlite3 source ID:%s\n",sqlite3_sourceid());
    
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
    
    /* Create SQL statement */
       sql = "CREATE TABLE COMPANY("  \
          "ID INT PRIMARY KEY     NOT NULL," \
          "NAME           TEXT    NOT NULL," \
          "AGE            INT     NOT NULL," \
          "ADDRESS        CHAR(50)," \
          "SALARY         REAL );";

       /* Execute SQL statement */
       //rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
       
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Table created successfully\n");
       }
    
    
    /* Create SQL statement */
       sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
             "VALUES (5, 'Paul', 32, 'California', 20000.00 ); " \
             "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
             "VALUES (6, 'Allen', 25, 'Texas', 15000.00 ); "     \
             "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
             "VALUES (7, 'Teddy', 23, 'Norway', 20000.00 );" \
             "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
             "VALUES (8, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

       /* Execute SQL statement */
       //rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
       
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
    
    
    /* Create SQL statement */
       sql1 = "SELECT * from COMPANY";

       /* Execute SQL statement */
       rc = sqlite3_exec(db, sql1, callback_r, (void*)data, &zErrMsg);
       
       if( rc != SQLITE_OK ) {
          fprintf(stderr, "SQL error1: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Operation done successfully\n");
       }
    
    /* Create merged SQL statement */
     sql1 = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
           "SELECT * from COMPANY";

     /* Execute SQL statement */
     rc = sqlite3_exec(db, sql1, callback, (void*)data, &zErrMsg);
     
     if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
     } else {
        fprintf(stdout, "Operation done successfully\n");
     }
    
    
    /* Create merged SQL statement */
      sql1 = "DELETE from COMPANY where ID=2; " \
            "SELECT * from COMPANY";

      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql1, callback, (void*)data, &zErrMsg);
      
      if( rc != SQLITE_OK ) {
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      } else {
         fprintf(stdout, "Operation done successfully\n");
      }
    
   sqlite3_close(db);
}
