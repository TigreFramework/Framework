//
// Created by pedrosoares on 5/1/18.
//

#include <TigreFramework/Core/Kernel/PageNotFoundException.h>
#include <typeinfo>
#include "ExceptionHandler.h"

void App::ExceptionHandler::report(Exception &exception) {
    try {
        auto pg = dynamic_cast<PageNotFoundException &>(exception);
        return;
    }catch (std::bad_cast &bad_cast){}

    return;
}

Response App::ExceptionHandler::render(Exception &exception) {
    try {
        auto pg = dynamic_cast<PageNotFoundException &>(exception);
        Response response(pg.what(), 404);
        return response;
    }catch (std::bad_cast &bad_cast){}

    Response response(exception.what(), 500);
    return response;
}