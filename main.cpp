

#include <TigreFramework/Core/Kernel/Application.h>

int main(int argc, char* argv[], char** envp) {
    Application application(argc, argv, envp);
    return application.run();
}