#include "gui/application.h"

int main() {
    try {
        Application app;
        app.run();
    } catch (std::exception &e) {
        // TODO: handle exceptions gracefully
    }
}
