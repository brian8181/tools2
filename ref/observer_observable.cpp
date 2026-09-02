#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// 1. The Observer Interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float temperature) = 0;
};

// 2. The Observable (Subject) Interface/Base Class
class Observable {
private:
    std::vector<Observer*> observers; // Tracks registered observers

public:
    virtual ~Observable() = default;

    void attach(Observer* observer) {
        if (observer) {
            observers.push_back(observer);
        }
    }

    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(float temperature) {
        for (Observer* observer : observers) {
            observer->update(temperature);
        }
    }
};

// 3. Concrete Subject
class WeatherStation : public Observable {
private:
    float temperature = 0.0f;

public:
    void setTemperature(float newTemperature) {
        std::cout << "WeatherStation: New temperature is " << newTemperature << "°C\n";
        temperature = newTemperature;
        notifyObservers(temperature); // Automatically trigger notifications
    }
};

// 4. Concrete Observer
class PhoneDisplay : public Observer {
private:
    std::string deviceName;

public:
    explicit PhoneDisplay(std::string name) : deviceName(std::move(name)) {}

    void update(float temperature) override {
        std::cout << "[" << deviceName << "] Display updated: " << temperature << "°C\n";
    }
};

int main() {
    WeatherStation station;

    // Create observers
    PhoneDisplay iPhone("iPhone 15");
    PhoneDisplay pixel("Pixel 8");

    // Register observers
    station.attach(&iPhone);
    station.attach(&pixel);

    // Simulate state changes
    station.setTemperature(24.5f);
    std::cout << "\n";
    
    // Detach an observer and update again
    station.detach(&iPhone);
    station.setTemperature(26.0f);

    return 0;
}
