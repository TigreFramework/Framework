//
// Created by pedrosoares on 5/2/18.
//

#ifndef TIGREFRAMEWORK_INDEXCONTROLLER_H
#define TIGREFRAMEWORK_INDEXCONTROLLER_H

#include <TigreFramework/SimpleRouter/Controller.h>

class IndexController : public Controller {

    Controller(IndexController);

    public:
        Response index(){
            return Response(nlohmann::json({ {"Hello", "World"} }));
        }

};

#endif //TIGREFRAMEWORK_INDEXCONTROLLER_H
