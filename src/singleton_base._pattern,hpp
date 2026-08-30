/* @file    singleton_base.hpp
 * @version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 * @brief  Singleton base class template for C++20
 */
#include <iostream>

// 1. The generic Singleton base class
template <typename T>
class _singleton_base {
public:
    static T& getInstance() {
        // Meyers' Singleton pattern applied here
        static T instance;
        return instance;
    }

    // Delete copy operations
    _singleton_base(const _singleton_base&) = delete;
    _singleton_base& operator=(const _singleton_base&) = delete;

protected:
    _singleton_base() = default;
    virtual ~_singleton_base() = default;
};

// 2. The derived subclass
class DatabaseManager : public _singleton_base<DatabaseManager> {
    // Grant the base class access to the private constructor
    friend class _singleton_base<DatabaseManager>; 

private:
    DatabaseManager() { std::cout << "DatabaseManager Initialized\n"; }
    ~DatabaseManager() = default;

public:
    void query() { std::cout << "Executing query...\n"; }
};

int main() {
    // Usage
    DatabaseManager::getInstance().query();
    return 0;
}