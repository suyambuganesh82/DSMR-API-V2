/*
***************************************************************************  
**  Program  : ntpStuff, part of DSMRloggerAPI
**  Version  : v3.0.0
**
**  Copyright (c) 2021 Martijn Hendriks
**
**  TERMS OF USE: MIT License. See bottom of file.                                                            
***************************************************************************      
*/
#ifdef USE_UPDATE_SERVER

// minified code based on https://github.com/Gheotic/ESP-HTML-Compressor
const PROGMEM char UpdateHTML[]  = {0X3C,0X73,0X63,0X72,0X69,0X70,0X74,0X20,0X73,0X72,0X63,0X3D,0X68,0X74,0X74,0X70,0X73,0X3A,0X2F,0X2F,0X61,0X6A,0X61,0X78,0X2E,0X67,0X6F,0X6F,0X67,0X6C,0X65,0X61,0X70,0X69,0X73,0X2E,0X63,0X6F,0X6D,0X2F,0X61,0X6A,0X61,0X78,0X2F,0X6C,0X69,0X62,0X73,0X2F,0X6A,0X71,0X75,0X65,0X72,0X79,0X2F,0X33,0X2E,0X32,0X2E,0X31,0X2F,0X6A,0X71,0X75,0X65,0X72,0X79,0X2E,0X6D,0X69,0X6E,0X2E,0X6A,0X73,0X3E,0X3C,0X2F,0X73,0X63,0X72,0X69,0X70,0X74,0X3E,0XA,0X3C,0X66,0X6F,0X72,0X6D,0X20,0X6D,0X65,0X74,0X68,0X6F,0X64,0X3D,0X50,0X4F,0X53,0X54,0X20,0X61,0X63,0X74,0X69,0X6F,0X6E,0X3D,0X23,0X20,0X65,0X6E,0X63,0X74,0X79,0X70,0X65,0X3D,0X6D,0X75,0X6C,0X74,0X69,0X70,0X61,0X72,0X74,0X2F,0X66,0X6F,0X72,0X6D,0X2D,0X64,0X61,0X74,0X61,0X20,0X69,0X64,0X3D,0X75,0X70,0X6C,0X6F,0X61,0X64,0X5F,0X66,0X6F,0X72,0X6D,0X3E,0XA,0X3C,0X61,0X20,0X68,0X72,0X65,0X66,0X3D,0X2F,0X20,0X69,0X64,0X3D,0X78,0X3E,0X58,0X3C,0X2F,0X61,0X3E,0XA,0X3C,0X68,0X31,0X3E,0X55,0X70,0X64,0X61,0X74,0X65,0X20,0X50,0X31,0X20,0X44,0X6F,0X6E,0X67,0X65,0X6C,0X3C,0X2F,0X68,0X31,0X3E,0X3C,0X62,0X72,0X3E,0XA,0X3C,0X64,0X69,0X76,0X3E,0X55,0X70,0X64,0X61,0X74,0X65,0X20,0X73,0X6F,0X66,0X74,0X77,0X61,0X72,0X65,0X20,0X6F,0X66,0X20,0X64,0X61,0X74,0X61,0X20,0X76,0X61,0X6E,0X20,0X64,0X65,0X20,0X50,0X31,0X20,0X44,0X6F,0X6E,0X67,0X65,0X6C,0X2E,0X20,0X53,0X6F,0X66,0X74,0X77,0X61,0X72,0X65,0X20,0X69,0X73,0X20,0X74,0X65,0X20,0X68,0X65,0X72,0X6B,0X65,0X6E,0X6E,0X65,0X6E,0X20,0X61,0X61,0X6E,0X20,0X3C,0X62,0X3E,0X2E,0X62,0X69,0X6E,0X28,0X2E,0X67,0X7A,0X29,0X3C,0X2F,0X62,0X3E,0X20,0X64,0X61,0X74,0X61,0X62,0X65,0X73,0X74,0X61,0X6E,0X64,0X20,0X61,0X61,0X6E,0X20,0X3C,0X62,0X3E,0X2E,0X6C,0X69,0X74,0X74,0X6C,0X65,0X66,0X73,0X2E,0X62,0X69,0X6E,0X28,0X2E,0X67,0X7A,0X29,0X3C,0X2F,0X62,0X3E,0X3C,0X62,0X72,0X3E,0X3C,0X62,0X72,0X3E,0X3C,0X2F,0X64,0X69,0X76,0X3E,0XA,0X3C,0X69,0X6E,0X70,0X75,0X74,0X20,0X74,0X79,0X70,0X65,0X3D,0X66,0X69,0X6C,0X65,0X20,0X6E,0X61,0X6D,0X65,0X3D,0X75,0X70,0X64,0X61,0X74,0X65,0X20,0X69,0X64,0X3D,0X66,0X69,0X6C,0X65,0X20,0X6F,0X6E,0X63,0X68,0X61,0X6E,0X67,0X65,0X3D,0X73,0X75,0X62,0X28,0X74,0X68,0X69,0X73,0X29,0X3E,0XA,0X3C,0X6C,0X61,0X62,0X65,0X6C,0X20,0X69,0X64,0X3D,0X66,0X69,0X6C,0X65,0X2D,0X69,0X6E,0X70,0X75,0X74,0X20,0X66,0X6F,0X72,0X3D,0X66,0X69,0X6C,0X65,0X3E,0X3C,0X73,0X70,0X61,0X6E,0X3E,0X53,0X65,0X6C,0X65,0X63,0X74,0X65,0X65,0X72,0X20,0X66,0X69,0X6C,0X65,0X2E,0X2E,0X2E,0X3C,0X2F,0X73,0X70,0X61,0X6E,0X3E,0X3C,0X2F,0X6C,0X61,0X62,0X65,0X6C,0X3E,0XA,0X3C,0X64,0X69,0X76,0X20,0X69,0X64,0X3D,0X70,0X72,0X67,0X3E,0X3C,0X2F,0X64,0X69,0X76,0X3E,0X3C,0X64,0X69,0X76,0X20,0X69,0X64,0X3D,0X70,0X72,0X67,0X62,0X61,0X72,0X3E,0X3C,0X64,0X69,0X76,0X20,0X69,0X64,0X3D,0X62,0X61,0X72,0X3E,0X3C,0X2F,0X64,0X69,0X76,0X3E,0X3C,0X2F,0X64,0X69,0X76,0X3E,0X3C,0X62,0X72,0X3E,0XA,0X3C,0X69,0X6E,0X70,0X75,0X74,0X20,0X74,0X79,0X70,0X65,0X3D,0X73,0X75,0X62,0X6D,0X69,0X74,0X20,0X63,0X6C,0X61,0X73,0X73,0X3D,0X62,0X74,0X6E,0X20,0X76,0X61,0X6C,0X75,0X65,0X3D,0X55,0X50,0X44,0X41,0X54,0X45,0X20,0X6F,0X6E,0X63,0X68,0X61,0X6E,0X67,0X65,0X3D,0X75,0X70,0X6C,0X6F,0X61,0X64,0X28,0X74,0X68,0X69,0X73,0X29,0X3E,0XA,0X3C,0X64,0X69,0X76,0X20,0X69,0X64,0X3D,0X6C,0X65,0X74,0X6F,0X70,0X3E,0X4C,0X45,0X54,0X20,0X4F,0X50,0X21,0X3C,0X62,0X72,0X3E,0X4D,0X61,0X61,0X6B,0X20,0X65,0X65,0X6E,0X20,0X6B,0X6F,0X70,0X69,0X65,0X20,0X76,0X61,0X6E,0X20,0X64,0X61,0X74,0X61,0X62,0X65,0X73,0X74,0X61,0X6E,0X64,0X65,0X6E,0X20,0X28,0X76,0X69,0X61,0X20,0X62,0X65,0X73,0X74,0X61,0X6E,0X64,0X73,0X62,0X65,0X68,0X65,0X65,0X72,0X29,0X20,0X65,0X6E,0X20,0X7A,0X65,0X74,0X20,0X64,0X65,0X20,0X64,0X61,0X74,0X61,0X62,0X65,0X73,0X74,0X61,0X6E,0X64,0X65,0X6E,0X20,0X6E,0X61,0X20,0X68,0X65,0X74,0X20,0X75,0X70,0X64,0X61,0X74,0X65,0X6E,0X20,0X77,0X65,0X65,0X72,0X20,0X74,0X65,0X72,0X75,0X67,0X2E,0X3C,0X2F,0X64,0X69,0X76,0X3E,0XA,0X3C,0X2F,0X66,0X6F,0X72,0X6D,0X3E,0XA,0X3C,0X73,0X63,0X72,0X69,0X70,0X74,0X3E,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X20,0X73,0X75,0X62,0X28,0X74,0X29,0X7B,0X76,0X61,0X72,0X20,0X65,0X3D,0X74,0X2E,0X76,0X61,0X6C,0X75,0X65,0X2E,0X73,0X70,0X6C,0X69,0X74,0X28,0X22,0X5C,0X5C,0X5C,0X5C,0X22,0X29,0X3B,0X24,0X28,0X22,0X23,0X66,0X69,0X6C,0X65,0X2D,0X69,0X6E,0X70,0X75,0X74,0X22,0X29,0X2E,0X68,0X74,0X6D,0X6C,0X28,0X22,0X3C,0X73,0X70,0X61,0X6E,0X3E,0X22,0X2B,0X65,0X5B,0X65,0X2E,0X6C,0X65,0X6E,0X67,0X74,0X68,0X2D,0X31,0X5D,0X2B,0X22,0X3C,0X2F,0X73,0X70,0X61,0X6E,0X3E,0X22,0X29,0X2C,0X2D,0X31,0X3C,0X74,0X2E,0X76,0X61,0X6C,0X75,0X65,0X2E,0X69,0X6E,0X64,0X65,0X78,0X4F,0X66,0X28,0X22,0X6C,0X69,0X74,0X74,0X6C,0X65,0X66,0X73,0X22,0X29,0X3F,0X24,0X28,0X22,0X23,0X6C,0X65,0X74,0X6F,0X70,0X22,0X29,0X2E,0X63,0X73,0X73,0X28,0X22,0X64,0X69,0X73,0X70,0X6C,0X61,0X79,0X22,0X2C,0X22,0X62,0X6C,0X6F,0X63,0X6B,0X22,0X29,0X3A,0X24,0X28,0X22,0X23,0X6C,0X65,0X74,0X6F,0X70,0X22,0X29,0X2E,0X63,0X73,0X73,0X28,0X22,0X64,0X69,0X73,0X70,0X6C,0X61,0X79,0X22,0X2C,0X22,0X6E,0X6F,0X6E,0X65,0X22,0X29,0X7D,0X24,0X28,0X22,0X66,0X6F,0X72,0X6D,0X22,0X29,0X2E,0X73,0X75,0X62,0X6D,0X69,0X74,0X28,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X74,0X29,0X7B,0X74,0X2E,0X70,0X72,0X65,0X76,0X65,0X6E,0X74,0X44,0X65,0X66,0X61,0X75,0X6C,0X74,0X28,0X29,0X3B,0X76,0X61,0X72,0X20,0X65,0X3D,0X24,0X28,0X22,0X23,0X75,0X70,0X6C,0X6F,0X61,0X64,0X5F,0X66,0X6F,0X72,0X6D,0X22,0X29,0X5B,0X30,0X5D,0X2C,0X6E,0X3D,0X6E,0X65,0X77,0X20,0X46,0X6F,0X72,0X6D,0X44,0X61,0X74,0X61,0X28,0X65,0X29,0X3B,0X24,0X2E,0X61,0X6A,0X61,0X78,0X28,0X7B,0X75,0X72,0X6C,0X3A,0X22,0X2F,0X75,0X70,0X64,0X61,0X74,0X65,0X22,0X2C,0X74,0X79,0X70,0X65,0X3A,0X22,0X50,0X4F,0X53,0X54,0X22,0X2C,0X64,0X61,0X74,0X61,0X3A,0X6E,0X2C,0X63,0X6F,0X6E,0X74,0X65,0X6E,0X74,0X54,0X79,0X70,0X65,0X3A,0X21,0X31,0X2C,0X70,0X72,0X6F,0X63,0X65,0X73,0X73,0X44,0X61,0X74,0X61,0X3A,0X21,0X31,0X2C,0X78,0X68,0X72,0X3A,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X29,0X7B,0X76,0X61,0X72,0X20,0X74,0X3D,0X6E,0X65,0X77,0X20,0X77,0X69,0X6E,0X64,0X6F,0X77,0X2E,0X58,0X4D,0X4C,0X48,0X74,0X74,0X70,0X52,0X65,0X71,0X75,0X65,0X73,0X74,0X3B,0X72,0X65,0X74,0X75,0X72,0X6E,0X20,0X74,0X2E,0X75,0X70,0X6C,0X6F,0X61,0X64,0X2E,0X61,0X64,0X64,0X45,0X76,0X65,0X6E,0X74,0X4C,0X69,0X73,0X74,0X65,0X6E,0X65,0X72,0X28,0X22,0X70,0X72,0X6F,0X67,0X72,0X65,0X73,0X73,0X22,0X2C,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X74,0X29,0X7B,0X69,0X66,0X28,0X74,0X2E,0X6C,0X65,0X6E,0X67,0X74,0X68,0X43,0X6F,0X6D,0X70,0X75,0X74,0X61,0X62,0X6C,0X65,0X29,0X7B,0X76,0X61,0X72,0X20,0X65,0X3D,0X31,0X30,0X30,0X2A,0X74,0X2E,0X6C,0X6F,0X61,0X64,0X65,0X64,0X2F,0X74,0X2E,0X74,0X6F,0X74,0X61,0X6C,0X3B,0X24,0X28,0X22,0X23,0X70,0X72,0X67,0X22,0X29,0X2E,0X68,0X74,0X6D,0X6C,0X28,0X22,0X76,0X6F,0X6F,0X72,0X74,0X67,0X61,0X6E,0X67,0X3A,0X20,0X22,0X2B,0X65,0X2E,0X74,0X6F,0X46,0X69,0X78,0X65,0X64,0X28,0X30,0X29,0X2B,0X22,0X25,0X22,0X29,0X2C,0X24,0X28,0X22,0X23,0X62,0X61,0X72,0X22,0X29,0X2E,0X63,0X73,0X73,0X28,0X22,0X77,0X69,0X64,0X74,0X68,0X22,0X2C,0X65,0X2E,0X74,0X6F,0X46,0X69,0X78,0X65,0X64,0X28,0X30,0X29,0X2B,0X22,0X25,0X22,0X29,0X7D,0X7D,0X2C,0X21,0X31,0X29,0X2C,0X74,0X2E,0X75,0X70,0X6C,0X6F,0X61,0X64,0X2E,0X61,0X64,0X64,0X45,0X76,0X65,0X6E,0X74,0X4C,0X69,0X73,0X74,0X65,0X6E,0X65,0X72,0X28,0X22,0X6C,0X6F,0X61,0X64,0X22,0X2C,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X74,0X29,0X7B,0X24,0X28,0X22,0X23,0X70,0X72,0X67,0X22,0X29,0X2E,0X68,0X74,0X6D,0X6C,0X28,0X22,0X55,0X70,0X6C,0X6F,0X61,0X64,0X65,0X64,0X20,0X3A,0X20,0X68,0X65,0X72,0X73,0X74,0X61,0X72,0X74,0X65,0X6E,0X20,0X2E,0X2E,0X2E,0X22,0X29,0X7D,0X2C,0X21,0X31,0X29,0X2C,0X74,0X7D,0X2C,0X73,0X75,0X63,0X63,0X65,0X73,0X73,0X3A,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X74,0X2C,0X65,0X29,0X7B,0X63,0X6F,0X6E,0X73,0X6F,0X6C,0X65,0X2E,0X6C,0X6F,0X67,0X28,0X22,0X73,0X75,0X63,0X63,0X65,0X73,0X73,0X21,0X22,0X29,0X2C,0X64,0X6F,0X63,0X75,0X6D,0X65,0X6E,0X74,0X2E,0X6C,0X6F,0X63,0X61,0X74,0X69,0X6F,0X6E,0X2E,0X68,0X72,0X65,0X66,0X3D,0X22,0X2F,0X22,0X7D,0X2C,0X65,0X72,0X72,0X6F,0X72,0X3A,0X66,0X75,0X6E,0X63,0X74,0X69,0X6F,0X6E,0X28,0X74,0X2C,0X65,0X2C,0X6E,0X29,0X7B,0X7D,0X7D,0X29,0X7D,0X29,0X3C,0X2F,0X73,0X63,0X72,0X69,0X70,0X74,0X3E,0X3C,0X73,0X74,0X79,0X6C,0X65,0X3E,0X23,0X66,0X69,0X6C,0X65,0X2D,0X69,0X6E,0X70,0X75,0X74,0X2C,0X69,0X6E,0X70,0X75,0X74,0X7B,0X77,0X69,0X64,0X74,0X68,0X3A,0X31,0X30,0X30,0X25,0X3B,0X68,0X65,0X69,0X67,0X68,0X74,0X3A,0X34,0X34,0X70,0X78,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X2D,0X72,0X61,0X64,0X69,0X75,0X73,0X3A,0X34,0X70,0X78,0X3B,0X6D,0X61,0X72,0X67,0X69,0X6E,0X3A,0X31,0X30,0X70,0X78,0X20,0X61,0X75,0X74,0X6F,0X3B,0X66,0X6F,0X6E,0X74,0X2D,0X73,0X69,0X7A,0X65,0X3A,0X31,0X35,0X70,0X78,0X7D,0X69,0X6E,0X70,0X75,0X74,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X3A,0X23,0X66,0X31,0X66,0X31,0X66,0X31,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X3A,0X30,0X3B,0X70,0X61,0X64,0X64,0X69,0X6E,0X67,0X3A,0X30,0X20,0X31,0X35,0X70,0X78,0X7D,0X62,0X6F,0X64,0X79,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X3A,0X23,0X33,0X34,0X39,0X38,0X64,0X62,0X3B,0X66,0X6F,0X6E,0X74,0X2D,0X66,0X61,0X6D,0X69,0X6C,0X79,0X3A,0X73,0X61,0X6E,0X73,0X2D,0X73,0X65,0X72,0X69,0X66,0X3B,0X66,0X6F,0X6E,0X74,0X2D,0X73,0X69,0X7A,0X65,0X3A,0X31,0X34,0X70,0X78,0X3B,0X63,0X6F,0X6C,0X6F,0X72,0X3A,0X23,0X37,0X37,0X37,0X7D,0X23,0X66,0X69,0X6C,0X65,0X2D,0X69,0X6E,0X70,0X75,0X74,0X7B,0X70,0X61,0X64,0X64,0X69,0X6E,0X67,0X3A,0X30,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X3A,0X31,0X70,0X78,0X20,0X73,0X6F,0X6C,0X69,0X64,0X20,0X23,0X64,0X64,0X64,0X3B,0X6C,0X69,0X6E,0X65,0X2D,0X68,0X65,0X69,0X67,0X68,0X74,0X3A,0X34,0X34,0X70,0X78,0X3B,0X64,0X69,0X73,0X70,0X6C,0X61,0X79,0X3A,0X62,0X6C,0X6F,0X63,0X6B,0X3B,0X63,0X75,0X72,0X73,0X6F,0X72,0X3A,0X70,0X6F,0X69,0X6E,0X74,0X65,0X72,0X7D,0X23,0X62,0X61,0X72,0X2C,0X23,0X70,0X72,0X67,0X62,0X61,0X72,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X2D,0X63,0X6F,0X6C,0X6F,0X72,0X3A,0X23,0X66,0X31,0X66,0X31,0X66,0X31,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X2D,0X72,0X61,0X64,0X69,0X75,0X73,0X3A,0X31,0X30,0X70,0X78,0X3B,0X77,0X69,0X64,0X74,0X68,0X3A,0X31,0X30,0X30,0X25,0X7D,0X23,0X62,0X61,0X72,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X2D,0X63,0X6F,0X6C,0X6F,0X72,0X3A,0X23,0X33,0X34,0X39,0X38,0X64,0X62,0X3B,0X77,0X69,0X64,0X74,0X68,0X3A,0X30,0X25,0X3B,0X68,0X65,0X69,0X67,0X68,0X74,0X3A,0X31,0X30,0X70,0X78,0X7D,0X23,0X66,0X69,0X6C,0X65,0X2D,0X69,0X6E,0X70,0X75,0X74,0X20,0X73,0X70,0X61,0X6E,0X7B,0X6D,0X61,0X72,0X67,0X69,0X6E,0X2D,0X6C,0X65,0X66,0X74,0X3A,0X36,0X70,0X78,0X7D,0X66,0X6F,0X72,0X6D,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X3A,0X23,0X66,0X66,0X66,0X3B,0X6D,0X61,0X78,0X2D,0X77,0X69,0X64,0X74,0X68,0X3A,0X34,0X35,0X30,0X70,0X78,0X3B,0X6D,0X61,0X72,0X67,0X69,0X6E,0X3A,0X37,0X35,0X70,0X78,0X20,0X61,0X75,0X74,0X6F,0X3B,0X70,0X61,0X64,0X64,0X69,0X6E,0X67,0X3A,0X33,0X30,0X70,0X78,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X2D,0X72,0X61,0X64,0X69,0X75,0X73,0X3A,0X35,0X70,0X78,0X7D,0X2E,0X62,0X74,0X6E,0X7B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X3A,0X23,0X33,0X34,0X39,0X38,0X64,0X62,0X3B,0X63,0X6F,0X6C,0X6F,0X72,0X3A,0X23,0X66,0X66,0X66,0X3B,0X63,0X75,0X72,0X73,0X6F,0X72,0X3A,0X70,0X6F,0X69,0X6E,0X74,0X65,0X72,0X7D,0X64,0X69,0X76,0X7B,0X6D,0X61,0X72,0X67,0X69,0X6E,0X3A,0X31,0X30,0X70,0X78,0X20,0X61,0X75,0X74,0X6F,0X7D,0X68,0X31,0X7B,0X74,0X65,0X78,0X74,0X2D,0X61,0X6C,0X69,0X67,0X6E,0X3A,0X63,0X65,0X6E,0X74,0X65,0X72,0X7D,0X23,0X6C,0X65,0X74,0X6F,0X70,0X2C,0X69,0X6E,0X70,0X75,0X74,0X5B,0X74,0X79,0X70,0X65,0X3D,0X66,0X69,0X6C,0X65,0X5D,0X7B,0X64,0X69,0X73,0X70,0X6C,0X61,0X79,0X3A,0X6E,0X6F,0X6E,0X65,0X3B,0X63,0X6F,0X6C,0X6F,0X72,0X3A,0X72,0X65,0X64,0X7D,0X23,0X78,0X7B,0X70,0X6F,0X73,0X69,0X74,0X69,0X6F,0X6E,0X3A,0X72,0X65,0X6C,0X61,0X74,0X69,0X76,0X65,0X3B,0X66,0X6C,0X6F,0X61,0X74,0X3A,0X72,0X69,0X67,0X68,0X74,0X3B,0X62,0X61,0X63,0X6B,0X67,0X72,0X6F,0X75,0X6E,0X64,0X3A,0X30,0X20,0X30,0X3B,0X62,0X6F,0X72,0X64,0X65,0X72,0X3A,0X6E,0X6F,0X6E,0X65,0X3B,0X74,0X6F,0X70,0X3A,0X2D,0X31,0X30,0X70,0X78,0X3B,0X72,0X69,0X67,0X68,0X74,0X3A,0X2D,0X31,0X30,0X70,0X78,0X3B,0X74,0X65,0X78,0X74,0X2D,0X64,0X65,0X63,0X6F,0X72,0X61,0X74,0X69,0X6F,0X6E,0X3A,0X6E,0X6F,0X6E,0X65,0X7D,0X3C,0X2F,0X73,0X74,0X79,0X6C,0X65,0X3E};

//static const char UpdateHTML[] PROGMEM =
//R"(<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>
//<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>
//<a href="/" id="x">X</a>
//<h1>Update P1 Dongel</h1><br>
//<div>Update software of data van de P1 Dongel. Software is te herkennen aan <b>.bin(.gz)</b> databestand aan <b>.littlefs.bin(.gz)</b><br><br></div>
//<input type='file' name='update' id='file' onchange='sub(this)'>
//<label id='file-input' for='file'><span>Selecteer file...</span></label>
//<div id='prg'></div><div id='prgbar'><div id='bar'></div></div><br>
//<input type='submit' class=btn value='UPDATE' onchange='upload(this)'></div>
//<div id=letop>LET OP!<br>Maak een kopie van databestanden (via bestandsbeheer) en zet de databestanden na het updaten weer terug.</div>
//</form>
//<script>
//function sub(obj){
//var fileName = obj.value.split('\\\\');
//$('#file-input').html('<span>'+ fileName[fileName.length-1]+'</span>');
//if (obj.value.indexOf('littlefs')>-1) {$('#letop').css('display','block')} else $('#letop').css('display','none');}
//$('form').submit(function(e){
//e.preventDefault();
//var form = $('#upload_form')[0];
//var data = new FormData(form);
//$.ajax({
//url: '/update',
//type: 'POST',
//data: data,
//contentType: false,
//processData:false,
//xhr: function() {
//var xhr = new window.XMLHttpRequest();
//xhr.upload.addEventListener('progress', function(e) {
//if (e.lengthComputable) {
//var per = 100 * e.loaded / e.total;
//$('#prg').html('voortgang: '+per.toFixed(0)+'%');
//$('#bar').css('width',per.toFixed(0)+'%');
//}
//}, false);
//xhr.upload.addEventListener('load', function(e) {
//$('#prg').html('Uploaded : herstarten ...');
//}, false);
//return xhr;
//},
//success:function(d, s) {
//console.log('success!');
//document.location.href='/';
//},
//error: function (a, b, c) {
//}
//});
//});
//</script><style>
//#file-input,input{width:100%;height:44px;border-radius:4px;margin:10px auto;font-size:15px}
//input{background:#f1f1f1;border:0;padding:0 15px}body{background:#3498db;font-family:sans-serif;font-size:14px;color:#777}
//#file-input{padding:0;border:1px solid #ddd;line-height:44px;display:block;cursor:pointer}
//#bar,#prgbar{background-color:#f1f1f1;border-radius:10px;width:100%}#bar{background-color:#3498db;width:0%;height:10px}
//#file-input span{margin-left:6px}
//form{background:#fff;max-width:450px;margin:75px auto;padding:30px;border-radius:5px}
//.btn{background:#3498db;color:#fff;cursor:pointer}
//div{margin:10px auto}
//h1{text-align:center}
//#letop,input[type=file]{display:none;color:red}
//#x{position:relative; float:right;background:none;border:none;top:-10px;right:-10px;text-decoration:none;
//</style>)";

#endif
/***************************************************************************
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the
* following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
* THE USE OR OTHER DEALINGS IN THE SOFTWARE.
* 
***************************************************************************/
