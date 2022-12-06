#include <iostream>
#include <vector>

class ISubscriber{

};

class IPublisher{
    public :
    virtual void subscribe(ISubscriber &sub) = 0;
    virtual void notifySubscriber() = 0;
};

class User{

};

class News : public IPublisher{
    std::vector<ISubscriber> subscribers;
    public : 
    void subscribe(ISubscriber &sub) override{
        subscribers.push_back(sub);
    }
};

int main(){

}