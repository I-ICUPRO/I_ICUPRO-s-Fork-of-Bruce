#pragma once
#include <FS.h>
#include <LittleFS.h>
#include <SD.h>
#include <SPI.h>

struct FileList {
  String filename;
  bool folder;
  bool operation;
};

//extern SPIClass sdcardSPI;

bool setupSdCard();

void closeSdCard();

bool ToggleSDCard();

bool deleteFromSd(FS fs, String path);

bool renameFile(FS fs, String path, String filename);

bool copyFile(FS fs, String path);

bool copyToFs(FS from, FS to, String path, bool draw=true);

bool pasteFile(FS fs, String path);

bool createFolder(FS fs, String path);

String readLineFromFile(File myFile);

String readSmallFile(FS &fs, String filepath);

String md5File(FS &fs, String filepath);

String crc32File(FS &fs, String filepath);

void readFs(FS fs, String folder, String allowed_ext = "*");

bool sortList(const FileList& a, const FileList& b);

String loopSD(FS &fs, bool filePicker = false, String allowed_ext = "*");

void viewFile(FS fs, String filepath);

int createFilePages(String fileContent);

bool checkLittleFsSize();

bool checkLittleFsSizeNM(); //Don't display msg

bool getFsStorage(FS *&fs);

void fileInfo(FS fs, String filepath);