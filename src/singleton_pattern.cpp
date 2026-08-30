class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; // Created only once
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
};