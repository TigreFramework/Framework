#include <TigreFramework/Core/Kernel/Application/Bootstrap.h>
#include <TigreFramework/Core/Kernel/Application/ServiceProvider.h>
#include <TigreFramework/Apache/ApacheServiceProvider.h>
#include <TigreFramework/SimpleRouter/RouterServiceProvider.h>
#include <App/Providers/AppServiceProvider.h>
#include <TigreFramework/SimpleRouter/SimpleRouter.h>
#include <TigreFramework/PostgreSQLConnector/PostgreSQLServiceProvider.h>
#include <TigreFramework/SQLiteConnector/SQLiteServiceProvider.h>

#include "App/Http/Controllers/IndexController.h"

void Bootstrap::boot() {
    ServiceProvider::registerProvider(new AppServiceProvider());
    ServiceProvider::registerProvider(new ApacheServiceProvider());
    ServiceProvider::registerProvider(new RouterServiceProvider());
    ServiceProvider::registerProvider(new PostgreSQLServiceProvider());
    ServiceProvider::registerProvider(new SQLiteServiceProvider());

    SimpleRouter::get("/", SimpleRouter::bind(&IndexController::index, IndexController::instance));
    SimpleRouter::get("/{id}", SimpleRouter::bind(&IndexController::index, IndexController::instance));
}
