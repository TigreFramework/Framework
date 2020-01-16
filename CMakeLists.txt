project(TigreFramework)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(vendor)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /var/www/public/)

## ================================================================

set(SITE_FILES
        config/bootstrap.cpp
        App/Exception/ExceptionHandler.cpp
        App/Providers/AppServiceProvider.cpp
        App/Http/Controllers/IndexController.h
        )

set(SOURCE_FILES main.cpp ${SITE_FILES})

## ================================================================

add_executable(index.TigreFramework ${SOURCE_FILES})

## ================================================================

add_subdirectory(vendor/TigreFramework/Core)
target_link_libraries(index.TigreFramework tgcore)

add_subdirectory(vendor/TigreFramework/Types)
target_link_libraries(index.TigreFramework tgTypes)

add_subdirectory(vendor/TigreFramework/Database)
target_link_libraries(index.TigreFramework tgDatabase)

add_subdirectory(vendor/TigreFramework/PostgreSQLConnector)
target_link_libraries(index.TigreFramework tgPostgreSQLConnector)

add_subdirectory(vendor/TigreFramework/SQLiteConnector)
target_link_libraries(index.TigreFramework tgSQLiteConnector ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(vendor/TigreFramework/String)
target_link_libraries(index.TigreFramework String)

add_subdirectory(vendor/TigreFramework/Apache)
target_link_libraries(index.TigreFramework tgApacheCgi)

add_subdirectory(vendor/TigreFramework/SimpleRouter)
target_link_libraries(index.TigreFramework tgSimpleRouter)

add_subdirectory(vendor/trusch/libbcrypt)
target_link_libraries(index.TigreFramework bcrypt)