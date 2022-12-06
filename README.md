# observer_pattern
Une classe User peut s'abonner à un flux d'information News. Lorsqu'une nouvelle est publiée les utilisateurs sont notifiés:

User est un Subscriber qui dispose d'une méthode update()
News est un Publisher qui dispose d'une méthode subscribe() et notifySubscribers()
News dispose d'une méthode publish(std::string news) qui insert une nouvelle information et notifie tous les abonnés.
