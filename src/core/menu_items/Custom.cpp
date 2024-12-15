#include "Custom.h"
#include "core/display.h"

/* изменения происходял в менюшке в main_menu.cpp и в main_menu.h*/

void Custom::optionsMenu() {
    options = {
        {"Crypt",        [=]() {}},
        {"Weather",      [=]() {}},
        {"Main Menu",    [=]() {}},
    };

    delay(200);
    loopOptions(options,false,true,"Custom");
}


void Custom::drawIcon(float scale) {
    clearIconArea();

    int radius = scale * 9;

    int i=0;
    for(i=0; i<6; i++) {
        tft.drawArc(
            iconCenterX,
            iconCenterY,
            3.5*radius, 2*radius,
            15+60*i, 45+60*i,
            bruceConfig.priColor,
            bruceConfig.bgColor,
            true
        );
    }

    tft.drawArc(
        iconCenterX,
        iconCenterY,
        2.5*radius, radius,
        0, 360,
        bruceConfig.priColor,
        bruceConfig.bgColor,
        false
    );
}