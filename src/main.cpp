/**
 * @file  main.cpp
 * @brief A few short examples in a row.
 *
 *  Demonstrates how-to use the SQLite++ wrapper
 *
 * Copyright (c) 2012-2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <exception>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;

#ifdef SQLITECPP_ENABLE_ASSERT_HANDLER
namespace SQLite
{
/// definition of the assertion handler enabled when SQLITECPP_ENABLE_ASSERT_HANDLER is defined in the project (CMakeList.txt)
void assertion_failed(const char* apFile, const long apLine, const char* apFunc, const char* apExpr, const char* apMsg)
{
    // Print a message to the standard error output stream, and abort the program.
    std::cerr << apFile << ":" << apLine << ":" << " error: assertion failed (" << apExpr << ") in " << apFunc << "() with message \"" << apMsg << "\"\n";
    std::abort();
}
}
#endif

int main()
{
    // Using SQLITE_VERSION would require #include <sqlite3.h> which we want to avoid: use SQLite::VERSION if possible.
    // cout << "SQlite3 version " << SQLITE_VERSION << '\n';
    cout << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << '\n';
    cout << "SQliteC++ version " << SQLITECPP_VERSION << '\n';

    // Simple batch queries example
    try
    {
        // Open a database file in create/write mode
        SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        cout << "SQLite database file '" << db.getFilename() << "' opened successfully\n";

        // Create a new table with an explicit "id" column aliasing the underlying rowid
        db.exec("DROP TABLE IF EXISTS test");
        db.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

        // first row
        int nb = db.exec("INSERT INTO test VALUES (NULL, \"first\")");
        cout << "INSERT INTO test VALUES (NULL, \"first\")\", returned " << nb << '\n';

        // second row
        nb = db.exec("INSERT INTO test VALUES (NULL, \"second\")");
        cout << "INSERT INTO test VALUES (NULL, \"second\")\", returned " << nb << '\n';

        // update the second row
        nb = db.exec("UPDATE test SET value=\"second-updated\" WHERE id='2'");
        cout << "UPDATE test SET value=\"second-updated\" WHERE id='2', returned " << nb << '\n';

        // Check the results: expect two rows
        SQLite::Statement query(db, "SELECT * FROM test");
        cout << "SELECT * FROM test\n";

        while (query.executeStep())
        {
            cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
        }

        db.exec("DROP TABLE test");
    }
    catch (exception const &e)
    {
        cout << "SQLite exception: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    remove("test.db3");

    cout << "Everything OK, quitting\n";

    return EXIT_SUCCESS;
}
