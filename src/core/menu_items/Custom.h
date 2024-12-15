#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#include "MenuItemInterface.h"

class Custom : public MenuItemInterface {
public:
    Custom() : MenuItemInterface("Custom") {}

    void optionsMenu(void);
    void drawIcon(float scale);
};

#endif