#include "app.h"

int main(int argc, char **argv) {
    App main(argc, argv);

    if(argc > 1) {
        main.info.Print();

        return 0;
    } else return main.Run();
}
