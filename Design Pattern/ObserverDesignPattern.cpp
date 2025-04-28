/* 
# Observer Design Pattern :-
=> The Observer Design Pattern is a behavioral pattern that allows an object (called the subject) to notify a list of dependent objects (called observers) automatically whenever its state changes.
=> It defines a **one-to-many** dependency.

🧠 Real-world Analogy:-
(#) Think of YouTube subscriptions:-
(*) When you subscribe (observer) to a channel (subject), you get a notification every time the channel uploads a new video.
(*) You can unsubscribe any time.
(*) The channel doesn’t care who you are — it just notifies all subscribers.

🧩 Key Components:-

Role :-	                 Description
A) Subject(observable)	 Maintains a list of observers and notifies them of changes.
B) Observer	             Defines an interface for objects that should be notified.
C) ConcreteSubject	     Stores state of interest and notifies observers.
D) ConcreteObserver	     Reacts to changes in subject.

🧩 Main Benefits:
- Loose coupling between Subject and Observers
- Easy to add/remove observers at runtime
- Flexible broadcasting mechanism

*/



#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


--------------------------------------------
🌦️ Observer Design Pattern (Weather Station Example)

- **WSObservable**: Abstract Subject
- **WSObservableImpl**: Concrete Subject
- **DisplayObserver**: Abstract Observer
- **MobileDisplayObserver**: Concrete Observer
- **TVDisplayObserver**: Concrete Observer
--------------------------------------------


// Abstract Observer
class DisplayObserver {
public:
    virtual void update(int temp) = 0; // whenever temperature changes, update()
    virtual ~DisplayObserver() = default;
};

// Abstract Observable
class WSObservable {
public:
    virtual void add(DisplayObserver* observer) = 0;
    virtual void removed(DisplayObserver* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual void setTemp(int temp) = 0;
    virtual ~WSObservable() = default;
};

// Concrete Observable
class WSObservableImpl : public WSObservable {
private:
    vector<DisplayObserver*> displayList;
    int currentTemp = 0;

public:
    void add(DisplayObserver* observer) override {
        displayList.push_back(observer);
    }

    void removed(DisplayObserver* observer) override {
        displayList.erase(remove(displayList.begin(), displayList.end(), observer), displayList.end());
    }

    void notifyObservers() override {
        for (auto observer : displayList) {
            observer->update(currentTemp);
        }
    }

    void setTemp(int newTemp) override {
        if (currentTemp != newTemp) {
            currentTemp = newTemp;
            notifyObservers(); // Notify all observers about the temperature change
        }
    }
};

// Concrete Observer - Mobile Display
class MobileDisplayObserver : public DisplayObserver {
private:
    WSObservable& weatherStation; // Reference to observable (dependency)

public:
    MobileDisplayObserver(WSObservable& obj) : weatherStation(obj) {
        weatherStation.add(this); // Register itself with the observable
    }

    void update(int temp) override {
        cout << "Mobile Display Updated: Current Temperature is " << temp << "°C" << endl;
    }
};

// Concrete Observer - TV Display
class TVDisplayObserver : public DisplayObserver {
private:
    WSObservable& weatherStation;

public:
    TVDisplayObserver(WSObservable& obj) : weatherStation(obj) {
        weatherStation.add(this);
    }

    void update(int temp) override {
        cout << "TV Display Updated: Current Temperature is " << temp << "°C" << endl;
    }
};

int main() {
    // Create Weather Station (Observable)
    WSObservableImpl weatherStation;

    // Create Displays (Observers)
    MobileDisplayObserver mobile(weatherStation);
    TVDisplayObserver tv(weatherStation);

    // Simulate temperature changes
    weatherStation.setTemp(25);
    weatherStation.setTemp(30);
    weatherStation.setTemp(30); // No change, so no notification
    weatherStation.setTemp(35);

    return 0;
}




/*
Example given in class.....

// Abstract Observer class (interface)
class Observer {
public:
    virtual void update() = 0; // pure virtual function (forces subclass to implement it)
    virtual ~Observer() = default; // virtual destructor for proper cleanup
};

// Concrete Observer class
class User : public Observer {
    int userId;
public:
    User(int id) : userId(id) {}

    void update() override {
        cout << "User Id " << userId << " received an update notification!" << endl;
    }
};

// Abstract Subject class (interface)
class Subject {
public:
    virtual void addUser(Observer* user) = 0;     // Attach new observer
    virtual void removeUser(Observer* user) = 0;  // Detach observer
    virtual void sendNotification() = 0;          // Notify all observers
    virtual ~Subject() = default;                 // Virtual destructor
};

// Concrete Subject class
class Group : public Subject {
    list<Observer*> userList; // List of observers (users)

public:
    void addUser(Observer* user) override {
        userList.push_back(user);
    }

    void removeUser(Observer* user) override {
        userList.remove(user);
    }

    void sendNotification() override {
        for (auto observer : userList) {
            observer->update(); // Notify each user
        }
    }
};

int main() {

    // Create a Group (subject)
    Subject* group = new Group();

    // Add users (observers) to the group
    group->addUser(new User(10));
    group->addUser(new User(110));
    group->addUser(new User(101));
    group->addUser(new User(222));

    // Notify all users
    group->sendNotification();

    // In a real application, remember to delete allocated memory
    // (memory leaks are being ignored here for simplicity)

    return 0;
}


*/
