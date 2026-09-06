#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

/* 
* @class observer 
*/
class observer 
{
public:
    virtual ~observer() = default;
    virtual void update() = 0;
};

/* 
* @class observable 
*/
class observable 
{
private:
    std::vector<observer*> observers; // registered observers

public:
    virtual ~observable() = default;

    void attach(observer* observer) 
    {
        if (observer) {
            observers.push_back(observer);
        }
    }

    void detach(observer* observer) 
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() 
    {
        for (observer* observer : observers) 
        {
            observer->update();
        }
    }
};
