#include <iostream>
#include <vector>

class ISubscriber{

};

class IPublisher{
    std::vector<ISubscriber> subscribers;
    public :
    virtual void subscribe() = 0;
    virtual void notifySubscriber() = 0;
};

class User{

};

class News : public ISubscriber{
    
};

int main(){

}