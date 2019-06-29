#include <TigreFramework/Core/Kernel/Application/Configuration.h>
#include <App/Exception/ExceptionHandler.h>
#include "AppServiceProvider.h"

void AppServiceProvider::boot() {
    Configuration::set("Exception.Handler", new App::ExceptionHandler());
}