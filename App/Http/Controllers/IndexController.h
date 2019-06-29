#ifndef TIGREFRAMEWORK_INDEXCONTROLLER_H
#define TIGREFRAMEWORK_INDEXCONTROLLER_H

#include <TigreFramework/SimpleRouter/Controller.h>
#include <TigreFramework/Database/DataObject.h>

class IndexController : public Controller {

    Controller(IndexController);

    public:
        Response index(){
            //DataObject conn("pgsql:host=172.18.0.2 port=5432 dbname=postgres", "postgres", "1234");
            DataObject conn("sqlite:sqlite_database.sqlite");

            //auto result = conn.prepare("select * from users;");
            //result->execute();

            //auto result = conn.prepare("select * from users where email = :email;");
            //result->execute(std::map<string, Value>({{":email", "jhon@due.com"}}));

            auto result = conn.prepare("select * from users where email = ? or password = ?;");
            result->execute(std::vector<Value>({"jhon@due.com", "1234"}));

            return Response(nlohmann::json(result->fetchAll()));
        }

};

#endif //TIGREFRAMEWORK_INDEXCONTROLLER_H
