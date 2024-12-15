#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#include "MenuItemInterface.h"

class Custom : public MenuItemInterface {
public:
    Custom() : MenuItemInterface("Custom") {}

    void optionsMenu(void);
    void drawIcon(float scale);
    //void showBitcoinPrice();  // Объявление метода для отображения курса биткоина
    //void clearIconArea();     // Объявление метода для очистки области
};

#endif
