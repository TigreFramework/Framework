//
// Created by pedrosoares on 5/1/18.
//

#ifndef TIGREFRAMEWORK_APPSERVICEPROVIDER_H
#define TIGREFRAMEWORK_APPSERVICEPROVIDER_H


#include <TigreFramework/Core/Kernel/Application/ServiceProvider.h>

class AppServiceProvider : public ServiceProvider {

    public:
        void boot() override;

};


#endif //TIGREFRAMEWORK_APPSERVICEPROVIDER_H
