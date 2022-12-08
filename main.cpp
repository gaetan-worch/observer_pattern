#include <iostream>
#include <vector>
#include <map>

class ISubscriber{
    public:
    void virtual update() = 0;
};

class User : public ISubscriber{
    int id;
    public:
    static int idprovider;
    std::string name;
    User(std::string name) : name{name}, id(++idprovider){}
    void update() override{ std::cout << "Hi " << name <<", New news" << std::endl;}
    int getid(){return id;}
};

int User::idprovider = 0;
class IPublisher{
    public :
    virtual void subscribe(User &sub) = 0;
    virtual void notifySubscriber() = 0;
    virtual void publish(std::string news) = 0;
    virtual void unsubscribe(User &sub) = 0;
};

class News : public IPublisher{
    std::map<int, User> subscribers;
    public : 
    void subscribe(User &sub) override{
        subscribers.insert(std::pair<int, User>(sub.getid(), sub));
    }
    void notifySubscriber() override{
        for (auto &a : subscribers)
        {
            a.second.update();
        }
        
    }
    void publish(std::string news) override{
        std::cout << "News published : " << news << std::endl;
        notifySubscriber();
    }
    void unsubscribe(User &sub) override{
        for(auto &a : subscribers)
        {
            if(a.first == sub.getid())
            {
                subscribers.erase(a.first);
                break;
            }
        }
    }
};

int main(){
    News news;
    User user1("John");
    User user2("Jane");
    User user3("Bob");
    User user4("Michel");
    news.subscribe(user1);
    news.subscribe(user2);
    news.subscribe(user3);
    news.subscribe(user4);
    news.publish("Hello World");
    news.unsubscribe(user3);
    news.publish("I am back");
    return 0;
}