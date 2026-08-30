/* @file    singleton.hpp
 * @version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 * @brief   Singleton base class template for C++20
 */
#include <iostream>

// singleton base class
template <typename T>
class singleton_base {
public:
    static T& getInstance() {
        // singleton pattern applied here
        static T instance;
        return instance;
    }

    // delete copy operations
    singleton_base(const singleton_base&) = delete;
    singleton_base& operator=(const singleton_base&) = delete;

protected:
    singleton_base() = default;
    virtual ~singleton_base() = default;
};
