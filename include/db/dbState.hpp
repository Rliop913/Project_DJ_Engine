#pragma once

#include <string>
#include <vector>

#include <sqlite3.h>

#ifdef __WINDOWS__
    using u_int8_t = uint8_t;
#endif

using BIN = std::vector<u_int8_t>;

enum COL_TYPE{
    INT,
    DOUBLE,
    TEXT,
    BLOB
};

/**
 * @brief the statement wrapper for sqlite.
 * 
 */
struct stmt
{
public:

    std::string placeHold;

    sqlite3_stmt* S = nullptr;
    /// @brief binds null
    /// @param idx starts with 1
    /// @return int sqlite err msg
    int bind_null(int idx);
    /**
     * @brief binds text
     * 
     * @param idx starts with 1
     * @param str text to bind
     * @return int sqlite err msg
     */
    int bind_text(int idx, std::string& str);
    /**
     * @brief binds blob
     * 
     * @param idx starts with 1
     * @param bin binary to bind
     * @return int sqlite err msg
     */
    int bind_blob(int idx, BIN& bin);
    /**
     * @brief binds double
     * 
     * @param idx starts with 1
     * @param num double to bind
     * @return int sqlite err msg
     */
    int bind_double(int idx, double num);
    /**
     * @brief binds int
     * 
     * @param idx starts with 1
     * @param num int to bind
     * @return int sqlite err msg
     */
    int bind_int(int idx, double num);
    
    /**
     * @brief get a column
     * 
     * @tparam T_COL the column type
     * @tparam res the result type
     * @param idx starts with 1
     * @return res the column data
     */
    template<int T_COL, typename res>
    res
    colGet(int idx);

    /**
     * @brief activates the query
     * 
     * @param db Root database
     * @return true 
     * @return false 
     */
    bool activate(sqlite3* db);

    stmt();
    ~stmt();
};
