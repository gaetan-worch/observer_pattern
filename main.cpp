#include <iostream>
#include <vector>

class ISubscriber{
    public:
    void virtual update() = 0;
};

class User : public ISubscriber{
    public:
    std::string name;
    User(std::string name) : name{name}{}
    void update() override{ std::cout << "Hi " << name <<", New news" << std::endl;}

};

class IPublisher{
    public :
    virtual void subscribe(User &sub) = 0;
    virtual void notifySubscriber() = 0;
    virtual void publish(std::string news) = 0;
    virtual void unsubscribe(User &sub) = 0;
};

class News : public IPublisher{
    std::vector<User> subscribers;
    public : 
    void subscribe(User &sub) override{
        subscribers.push_back(sub);
    }
    void notifySubscriber() override{
        for (auto &a : subscribers)
        {
            a.update();
        }
        
    }
    void publish(std::string news) override{
        std::cout << "News published : " << news << std::endl;
        notifySubscriber();
    }
    void unsubscribe(User &sub) override{
        for (auto it = subscribers.begin(); it != subscribers.end(); it++)
        {
            if (it->name == sub.name)
            {
                subscribers.erase(it);
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