// @IncursioHack - https://github.com/IncursioHack
#include <Wire.h>
#include <SD.h>
#include "PCA9554.h" // Biblioteca para PCA9554

struct RfCodes {
  uint32_t frequency = 0;
  uint64_t key=0;
  String protocol = "";
  String preset = "";
  String data = "";
  int te = 0;
  String filepath = "";
  int Bit=0;
  int BitRAW=0;
};

// Define o endereço I2C do PCA9554PW
const int pca9554pw_address = 0x27;

// Cria um objeto PCA9554 com o endereço I2C do PCA9554PW
extern PCA9554 extIo1;

// Define os pinos para o receptor e transmissor
const int PCA9554RSX_PIN = 4;
const int PCA9554TRX_PIN = 0;

void rf_spectrum();
void rf_SquareWave();
void rf_jammerIntermittent();
void rf_jammerFull();
void rf_scan_copy_draw_signal(RfCodes received, int signals, bool ReadRAW=false);
String rf_scan(float start_freq, float stop_freq, int max_loops=-1);
void otherRFcodes();
bool txSubFile(FS *fs, String filepath);
String RCSwitch_Read(float frequency=0, int max_loops=-1, bool raw=false);
bool RCSwitch_SaveSignal(float frequency, RfCodes codes, bool raw, char* key);
void RCSwitch_send(uint64_t data, unsigned int bits, int pulse=0, int protocol=1, int repeat=10);
void addToRecentCodes(struct RfCodes rfcode);
void sendRfCommand(struct RfCodes rfcode);
bool initRfModule(String mode="", float frequency=0);
void initCC1101once(SPIClass* SSPI);
void deinitRfModule();
uint8_t hexCharToDecimal(char c);
void rf_scan_copy();