#include <iostream>
#include "core/app.h"

int main() {
    app app;
    if (!app.init()) return -1;
    app.run();
    return 0;
}