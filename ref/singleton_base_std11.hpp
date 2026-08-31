/* @file    symtab.c
 * @version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 * @brief  Singleton base class template for C++11
 */
#include <mutex>

template <typename T>
class _singleton_base {
public:
    static T& getInstance() {
        // double-checked locking pattern (DCLP)
        if (instance_ptr == nullptr) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (instance_ptr == nullptr) {
                // Pre-C++11 required explicit heap allocation
                // Note: True DCLP also requires compiler-specific memory barriers/volatile pre-C++11
                static T instance; 
                instance_ptr = &instance;
            }
        }
        return *instance_ptr;
    }

    _singleton_base(const _singleton_base&) = delete;
    _singleton_base& operator=(const _singleton_base&) = delete;

protected:
    _singleton_base() = default;
    virtual ~_singleton_base() = default;

private:
    static T* instance_ptr;
    static std::mutex mutex_;
};

// static member definitions
template <typename T> T* _singleton_base<T>::instance_ptr = nullptr;
template <typename T> std::mutex _singleton_base<T>::mutex_;