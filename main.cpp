#include <iostream>

class ISubscriber(){

};

class IPublisher(){
    public :
    virtual void subscribe() = 0;
    virtual void notifySubscriber() = 0;
};

class User(){

};

class News() : public ISubscriber{
    
};

int main(){

}