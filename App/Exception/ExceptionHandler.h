//
// Created by pedrosoares on 5/1/18.
//

#ifndef TIGREFRAMEWORK_EXCEPTION_HANDLER_H
#define TIGREFRAMEWORK_EXCEPTION_HANDLER_H

#include <string>
#include <TigreFramework/Core/Kernel/ExceptionHandler.h>
#include <TigreFramework/Core/Kernel/Response.h>
#include <TigreFramework/Core/Kernel/Application/Configurable.h>

class TgExceptionHandler : public ExceptionHandler {};

namespace App {
    class ExceptionHandler : public TgExceptionHandler, public Configurable {

        public:
            void report(Exception &exception) override;
            Response render(Exception &exception) override;

    };
}



#endif //TIGREFRAMEWORK_EXCEPTIONHANDLER_H
