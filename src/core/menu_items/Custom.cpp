#include "Custom.h"
#include "core/display.h"
#include "core/wifi_common.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>  // Для работы с JSON


void Custom::optionsMenu() {
    options = {
        {"Weather",      [=]() {}},
        {"Bitcoin Price", [=]() {}},  // Новый пункт меню для отображения курса биткоина
        {"Main Menu",    [=]() {}},
    };

    delay(200);
    loopOptions(options,false,true,"Custom");
}

void Custom::drawIcon(float scale) {
    clearIconArea();

    int radius = scale * 9;

    int i = 0;
    for (i = 0; i < 6; i++) {
        tft.drawArc(
            iconCenterX,
            iconCenterY,
            3.5 * radius, 2 * radius,
            15 + 60 * i, 45 + 60 * i,
            bruceConfig.priColor,
            bruceConfig.bgColor,
            true
        );
    }

    tft.drawArc(
        iconCenterX,
        iconCenterY,
        2.5 * radius, radius,
        0, 360,
        bruceConfig.priColor,
        bruceConfig.bgColor,
        false
    );
}

/*
{"Bitcoin Price", [=]() {showBitcoinPrice();}},

float getBitcoinPrice() {
    String url = "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd";
    HTTPClient http;
    http.begin(url);  // Подключаемся к API
    int httpCode = http.GET();  // Выполняем GET-запрос

    float price = 0.0;

    if (httpCode == HTTP_CODE_OK) {  // Если запрос успешен
        String payload = http.getString();  // Получаем ответ в виде строки
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, payload);  // Парсим JSON-ответ
        price = doc["bitcoin"]["usd"];  // Извлекаем цену биткоина
    } else {
        Serial.println("Failed to fetch Bitcoin price.");
    }

    http.end();  // Закрываем соединение
    return price;




}

void Custom::showBitcoinPrice() {

    float bitcoinPrice = getBitcoinPrice();  // Получаем цену биткоина

    clearIconArea();  // Очищаем область для иконки

    String priceText = "BTC: $" + String(bitcoinPrice, 2);  // Форматируем текст с курсом биткоина

    // Отображаем текст с курсом биткоина
    tft.setTextColor(bruceConfig.priColor);
    tft.setTextSize(2);
    tft.setCursor(10, 10);  // Позиция на экране
    tft.print(priceText);

    delay(2000);  // Задержка, чтобы показать цену перед возвратом в меню
    backToMenu();  // Возврат в меню
}

void Custom::clearIconArea() {
    // Замените на реальный код очистки области экрана
    tft.fillRect(iconCenterX - 40, iconCenterY - 40, 80, 80, bruceConfig.bgColor);
}

*/
