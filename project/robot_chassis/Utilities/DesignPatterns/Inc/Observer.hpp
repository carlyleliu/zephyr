#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

#include <string>
#include <vector>

namespace DesignedPattern
{
class Subject;

class Observer
{
  public:
    Observer() {}
    Observer(std::string name):name_(name){}
    virtual ~Observer() {}
    void setSubjecter(Subject* subjecter)
    {
        subjecter_ = subjecter;
    }

    virtual void update() = 0;

  protected:
    std::string name_;
    Subject* subjecter_;
};

class Subject
{
  public:
    Subject() {}
    Subject(std::string name):name_(name){}
    virtual ~Subject() {}
    void attach(Observer* observer)
    {
        observers_.push_back(observer);
    }

    void detach(Observer* observer)
    {
        for (std::vector <Observer*> ::iterator it = observers_.begin(); it != observers_.end(); ++it) {
            if (*it == observer) {
                observers_.erase(it);
                return;
            }
        }
    }

    void notify()
    {
        for(std::vector <Observer*> ::iterator it = observers_.begin(); it != observers_.end(); ++it) {
            (*it)->update();
        }
    }

  protected:
    std::vector <Observer*> observers_;
    std::string name_;
};

} /* namespace DesignedPattern */

#endif // ! DESIGN_PATTERNS_OBSERVER_H
