#include <iostream>
#include "core/App.h"

int main() {
    App app;
    if (!app.init()) return -1;
    app.run();
    return 0;
}