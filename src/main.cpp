#include <sqlite3.h>
#include <iostream>
#include <git2.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    sqlite3* db;
    char* errMsg = nullptr;

    // Open database in memory
    if (sqlite3_open(":memory:", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << "\n";
        return 1;
    }

    // Create table
    const char* create_sql =
        "CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT);";

    if (sqlite3_exec(db, create_sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return 1;
    }

    // Insert data
    const char* insert_sql =
        "INSERT INTO users (name) VALUES ('Alice'), ('Bob');";

    if (sqlite3_exec(db, insert_sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return 1;
    }

    // Query data
    const char* query_sql = "SELECT id, name FROM users;";

    auto callback = [](void*, int argc, char** argv, char** colNames) -> int {
        for (int i = 0; i < argc; i++) {
            std::cout << colNames[i] << ": " << argv[i] << "  ";
        }
        std::cout << "\n";
        return 0;
    };

    if (sqlite3_exec(db, query_sql, callback, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}