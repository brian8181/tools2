#include <mutex>

template <typename T>
class SingletonBase {
public:
    static T& getInstance() {
        // Double-Checked Locking Pattern (DCLP)
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

    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;

protected:
    SingletonBase() = default;
    virtual ~SingletonBase() = default;

private:
    static T* instance_ptr;
    static std::mutex mutex_;
};

// Static member definitions
template <typename T> T* SingletonBase<T>::instance_ptr = nullptr;
template <typename T> std::mutex SingletonBase<T>::mutex_;
