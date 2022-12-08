#include <iostream>
#include <vector>
#include <map>

class ISubscriber{
    public:
    void virtual update() = 0;
    void virtual update(std::string news) = 0;
};

class User : public ISubscriber{
    int id;
    public:
    static int idprovider;
    std::string name;
    User(std::string name) : name{name}, id(++idprovider){}
    void update() override{ std::cout << "Hi " << name <<", New news" << std::endl;}
    void update(std::string news) override{ std::cout << "Hi " << name <<", New news : " << news << std::endl;}
    int getid(){return id;}
};

int User::idprovider = 0;
class IPublisher{
    public :
    virtual void subscribe(User &sub) = 0;
    virtual void notifySubscriber() = 0;
    virtual void notifySubscriber(std::string news) = 0;
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
    void notifySubscriber(std::string news) override{
        for (auto &a : subscribers)
        {
            a.second.update(news);
        }
        
    }
    void publish(std::string news) override{
        std::cout << "News published : " << news << std::endl;
        notifySubscriber(news);
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
    User user5("Paul");
    news.subscribe(user1);
    news.subscribe(user2);
    news.subscribe(user3);
    news.subscribe(user4);
    news.publish("Hello World");
    news.unsubscribe(user3);
    news.publish("I am back");
    news.subscribe(user5);
    news.publish("6-1 pour la Suisse !");
    news.publish("retraction: Fake news, si seulement...");
    return 0;
}