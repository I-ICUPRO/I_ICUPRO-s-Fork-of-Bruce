#ifndef __NRF24_MENU_H__
#define __NRF24_MENU_H__

#include "MenuItemInterface.h"


class NRF24Menu : public MenuItemInterface {
public:
    NRF24Menu() : MenuItemInterface("NRF24") {}

    void optionsMenu(void);
    void drawIcon(float scale);
};

#endif