/*
***************************************************************************  
**  Program  : OtherFiles, part of DSMRloggerAPI (status/settings/log files locally stored)
**  Version  : v2.3.2
**
**  Copyright (c) 2021 Martijn Hendriks
**
**  TERMS OF USE: MIT License. See bottom of file.                                                            
***************************************************************************      
* 1.0.11 added Mindergas Authtoken setting
*/

template <typename TSource>
void writeToJsonFile(const TSource &doc, File &_file) 
{
  if (!SPIFFSmounted) return;
  if (serializeJson(doc, _file) == 0) {
      DebugTln(F("write(): Failed to write to json file"));  
  } 
  else {
    DebugTln(F("write(): json file writen"));
    //verbose write output
    if (Verbose1) 
    {
      DebugTln(F("Save to json file:"));
      serializeJson(doc, TelnetStream); //print settingsfile to telnet output
      serializeJson(doc, Serial); //print settingsfile to serial output    
    } // Verbose1  
  }
    
  _file.flush();
  _file.close(); 
}

//====================================================================
void readLastStatus()
{  
  StaticJsonDocument<110> doc;  
  DeserializationError error;
  
  if (!SPIFFSmounted) return;
  File statusFile = SPIFFS.open("/DSMRstatus.json", "r");
  if (statusFile) error = deserializeJson(doc, statusFile);

  if (!statusFile || error) {
    DebugTln(F("read(): No /DSMRstatus.json found or failed to read"));
    statusFile.close();
    writeLastStatus();
    return;
  }
  

  statusFile.close();
  
  nrReboots = doc["Reboots"];
  slotErrors = doc["slotErrors"];
  if (strlen( doc["Timestamp"]) != 13)  snprintf(actTimestamp, sizeof(actTimestamp), "%s", "010101010101X");
  else  strcpy(actTimestamp, doc["Timestamp"]);
  
}  // readLastStatus()

//====================================================================
void writeLastStatus()
{ 
  if (bailout() || !SPIFFSmounted ) return;
  DebugTf("writeLastStatus() => %s; %u; %u;\r\n", actTimestamp, nrReboots, slotErrors);
  
  File statusFile = SPIFFS.open("/DSMRstatus.json", "w");
  if (!statusFile) DebugTln(F("write(): No /DSMRstatus.json found"));

  char buffer[74];
  sprintf_P(buffer,PSTR("{\"Timestamp\":\"%s\",\"Reboots\":%d,\"slotErrors\":%d}"), actTimestamp, nrReboots, slotErrors);
  
  int bytesWritten = statusFile.print(buffer);
  if (bytesWritten > 0) {
    DebugT(F("File was written:"));Debugln(bytesWritten);
  } else DebugTln(F("File write failed"));
 
  statusFile.flush();
  statusFile.close();
} // writeLastStatus()

//=======================================================================
void writeSettings() 
{
  StaticJsonDocument<600> doc; 
  if (!SPIFFSmounted) return;
  
  DebugT(F("Writing to [")); Debug(SETTINGS_FILE); Debugln(F("] ..."));
  
  File SettingsFile = SPIFFS.open(SETTINGS_FILE, "w"); // open for reading and writing
  
  if (!SettingsFile) 
  {
    DebugTf("open(%s, 'w') FAILED!!! --> Bailout\r\n", SETTINGS_FILE);
    return;
  }
  yield();

  if (strlen(settingIndexPage) < 7) strCopy(settingIndexPage, (sizeof(settingIndexPage) -1), _DEFAULT_HOMEPAGE);
  if (settingTelegramInterval < 2)  settingTelegramInterval = 10;
  if (settingMQTTbrokerPort < 1)    settingMQTTbrokerPort = 1883;
    
  DebugTln(F("Start writing setting data to json settings file"));
  doc["Hostname"] = settingHostname;
  doc["EnergyDeliveredT1"] = settingEDT1;
  doc["EnergyDeliveredT2"] = settingEDT2;
  doc["EnergyReturnedT1"] = settingERT1;
  doc["EnergyReturnedT2"] = settingERT2;
  doc["GASDeliveredT"] = settingGDT;
  doc["EnergyVasteKosten"] = settingENBK;
  doc["GasVasteKosten"] = settingGNBK;
  doc["SmHasFaseInfo"] = settingSmHasFaseInfo;
  doc["TelegramInterval"] = settingTelegramInterval;
  doc["IndexPage"] = settingIndexPage;
 
#ifdef USE_MQTT
  doc["MQTTbroker"] = settingMQTTbroker;
  doc["MQTTbrokerPort"] = settingMQTTbrokerPort;
  doc["MQTTUser"] = settingMQTTuser;
  doc["MQTTpasswd"] = settingMQTTpasswd;
  doc["MQTTinterval"] = settingMQTTinterval;
  doc["MQTTtopTopic"] = settingMQTTtopTopic;
  
#endif
  
#ifdef USE_MINDERGAS
  doc["MindergasAuthtoken"] = settingMQTTtsettingMindergasTokenopTopic;

#endif

  writeToJsonFile(doc, SettingsFile);
  
} // writeSettings()


//=======================================================================
void readSettings(bool show) 
{
  StaticJsonDocument<600> doc; 
  File SettingsFile;
  if (!SPIFFSmounted) return;
  
  DebugTf(" %s ..\r\n", SETTINGS_FILE);
 
   if (!SPIFFS.exists(SETTINGS_FILE)) 
  {
    DebugTln(F(" .. DSMRsettings.json file not found! --> created file!"));
    writeSettings();
    return;
  }
    SettingsFile = SPIFFS.open(SETTINGS_FILE, "r");
    if (!SettingsFile) DebugTf(" .. something went wrong opening [%s]\r\n", SETTINGS_FILE);
    else DebugTln(F("Reading settings:\r"));

  DeserializationError error = deserializeJson(doc, SettingsFile);
  if (error) {
    DebugTln(F("read():Failed to read DSMRsettings.json file"));
    SettingsFile.close();
    writeSettings();
    return;
  }
  
  //strcpy(spiffsTimestamp, doc["Timestamp"]);
  strcpy(settingHostname, doc["Hostname"] | _DEFAULT_HOSTNAME );
  settingEDT1 = doc["EnergyDeliveredT1"];
  settingEDT2 = doc["EnergyDeliveredT2"];
  settingERT1 = doc["EnergyReturnedT1"];
  settingERT2 = doc["EnergyReturnedT2"];
  settingGDT = doc["GASDeliveredT"];
  settingENBK = doc["EnergyVasteKosten"];
  settingGNBK = doc["GasVasteKosten"];
  settingSmHasFaseInfo = doc["SmHasFaseInfo"];
  settingTelegramInterval = doc["TelegramInterval"];
  strcpy(settingIndexPage, doc["IndexPage"] | _DEFAULT_HOMEPAGE);
  
  CHANGE_INTERVAL_SEC(nextTelegram, settingTelegramInterval);
 
#ifdef USE_MQTT
  //sprintf(settingMQTTbroker, "%s:%d", MQTTbroker, MQTTbrokerPort);
  strcpy(settingMQTTbroker, doc["MQTTbroker"]);
  settingMQTTbrokerPort = doc["MQTTbrokerPort"];
  strcpy(settingMQTTuser, doc["MQTTUser"]);
  strcpy(settingMQTTpasswd, doc["MQTTpasswd"]);
  settingMQTTinterval = doc["MQTTinterval"];
  strcpy(settingMQTTtopTopic, doc["MQTTtopTopic"]);
  
  CHANGE_INTERVAL_SEC(publishMQTTtimer, settingMQTTinterval);
  CHANGE_INTERVAL_MIN(reconnectMQTTtimer, 1);
  
#endif
  
#ifdef USE_MINDERGAS
  strcpy(settingMQTTtsettingMindergasTokenopTopic, doc["MindergasAuthtoken"]);
#endif
 
  SettingsFile.close();
  //end json

  //--- this will take some time to settle in
  //--- probably need a reboot before that to happen :-(
  MDNS.setHostname(settingHostname);    // start advertising with new(?) settingHostname

  DebugTln(F(" .. done\r"));


  if (strlen(settingIndexPage) < 7) strCopy(settingIndexPage, (sizeof(settingIndexPage) -1), "DSMRindexEDGE.html");
  if (settingTelegramInterval  < 2) settingTelegramInterval = 10;
  if (settingMQTTbrokerPort    < 1) settingMQTTbrokerPort   = 1883;

  if (!show) return;
  
  Debugln(F("\r\n==== Settings ===================================================\r"));
  Debugf("                    Hostname : %s\r\n",     settingHostname);
  Debugf("   Energy Delivered Tarief 1 : %9.7f\r\n",  settingEDT1);
  Debugf("   Energy Delivered Tarief 2 : %9.7f\r\n",  settingEDT2);
  Debugf("   Energy Delivered Tarief 1 : %9.7f\r\n",  settingERT1);
  Debugf("   Energy Delivered Tarief 2 : %9.7f\r\n",  settingERT2);
  Debugf("        Gas Delivered Tarief : %9.7f\r\n",  settingGDT);
  Debugf("     Energy Netbeheer Kosten : %9.2f\r\n",  settingENBK);
  Debugf("        Gas Netbeheer Kosten : %9.2f\r\n",  settingGNBK);
  Debugf("  SM Fase Info (0=No, 1=Yes) : %d\r\n",     settingSmHasFaseInfo);
  Debugf("   Telegram Process Interval : %d\r\n",     settingTelegramInterval);
  
  Debugf("                  Index Page : %s\r\n",     settingIndexPage);

#ifdef USE_MQTT
  Debugln(F("\r\n==== MQTT settings ==============================================\r"));
  Debugf("          MQTT broker URL/IP : %s:%d", settingMQTTbroker, settingMQTTbrokerPort);
  if (MQTTclient.connected()) Debugln(F(" (is Connected!)\r"));
  else                 Debugln(F(" (NOT Connected!)\r"));
  Debugf("                   MQTT user : %s\r\n", settingMQTTuser);
#ifdef SHOW_PASSWRDS
  Debugf("               MQTT password : %s\r\n", settingMQTTpasswd);
#else
  Debug( "               MQTT password : *************\r\n");
#endif
  Debugf("          MQTT send Interval : %d\r\n", settingMQTTinterval);
  Debugf("              MQTT top Topic : %s\r\n", settingMQTTtopTopic);
#endif  // USE_MQTT
#ifdef USE_MINDERGAS
  Debugln(F("\r\n==== Mindergas settings ==============================================\r"));
  Debugf("         Mindergas Authtoken : %s\r\n", settingMindergasToken);
#endif  
  
  Debugln(F("-\r"));

} // readSettings()


//=======================================================================
void updateSetting(const char *field, const char *newValue)
{
  DebugTf("-> field[%s], newValue[%s]\r\n", field, newValue);
  if (!SPIFFSmounted) return;
  if (!stricmp(field, "Hostname")) {
    strCopy(settingHostname, 29, newValue); 
    if (strlen(settingHostname) < 1) strCopy(settingHostname, 29, _DEFAULT_HOSTNAME); 
    char *dotPntr = strchr(settingHostname, '.') ;
    if (dotPntr != NULL)
    {
      byte dotPos = (dotPntr-settingHostname);
      if (dotPos > 0)  settingHostname[dotPos] = '\0';
    }
    Debugln();
    DebugTf("Need reboot before new %s.local will be available!\r\n\n", settingHostname);
  }
  if (!stricmp(field, "ed_tariff1"))        settingEDT1         = String(newValue).toFloat();  
  if (!stricmp(field, "ed_tariff2"))        settingEDT2         = String(newValue).toFloat();  
  if (!stricmp(field, "er_tariff1"))        settingERT1         = String(newValue).toFloat();  
  if (!stricmp(field, "er_tariff2"))        settingERT2         = String(newValue).toFloat();  
  if (!stricmp(field, "electr_netw_costs")) settingENBK         = String(newValue).toFloat();

  if (!stricmp(field, "gd_tariff"))         settingGDT          = String(newValue).toFloat();  
  if (!stricmp(field, "gas_netw_costs"))    settingGNBK         = String(newValue).toFloat();

  if (!stricmp(field, "sm_has_fase_info")) 
  {
    settingSmHasFaseInfo = String(newValue).toInt(); 
    if (settingSmHasFaseInfo != 0)  settingSmHasFaseInfo = 1;
    else                            settingSmHasFaseInfo = 0;  
  }

  if (!stricmp(field, "tlgrm_interval"))    
  {
    settingTelegramInterval     = String(newValue).toInt();  
    CHANGE_INTERVAL_SEC(nextTelegram, settingTelegramInterval);
  }

  if (!stricmp(field, "IndexPage"))        strCopy(settingIndexPage, (sizeof(settingIndexPage) -1), newValue);  

#ifdef USE_MINDERGAS
  if (!stricmp(field, "MindergasToken"))    strCopy(settingMindergasToken, 20, newValue);  
#endif //USE_MINDERGAS

#ifdef USE_MQTT
  if (!stricmp(field, "mqtt_broker"))  {
    DebugT("settingMQTTbroker! to : ");
    memset(settingMQTTbroker, '\0', sizeof(settingMQTTbroker));
    strCopy(settingMQTTbroker, 100, newValue);
    Debugf("[%s]\r\n", settingMQTTbroker);
    mqttIsConnected = false;
    CHANGE_INTERVAL_MS(reconnectMQTTtimer, 100); // try reconnecting cyclus timer
  }
  if (!stricmp(field, "mqtt_broker_port")) {
    settingMQTTbrokerPort = String(newValue).toInt();  
    mqttIsConnected = false;
    CHANGE_INTERVAL_MS(reconnectMQTTtimer, 100); // try reconnecting cyclus timer
  }
  if (!stricmp(field, "mqtt_user")) {
    strCopy(settingMQTTuser    ,35, newValue);  
    mqttIsConnected = false;
    CHANGE_INTERVAL_MS(reconnectMQTTtimer, 100); // try reconnecting cyclus timer
  }
  if (!stricmp(field, "mqtt_passwd")) {
    strCopy(settingMQTTpasswd  ,25, newValue);  
    mqttIsConnected = false;
    CHANGE_INTERVAL_MS(reconnectMQTTtimer, 100); // try reconnecting cyclus timer
  }
  if (!stricmp(field, "mqtt_interval")) {
    settingMQTTinterval   = String(newValue).toInt();  
    CHANGE_INTERVAL_SEC(publishMQTTtimer, settingMQTTinterval);
  }
  if (!stricmp(field, "mqtt_toptopic"))     strCopy(settingMQTTtopTopic, 20, newValue);  
#endif

  writeSettings();
  
} // updateSetting()

//=======================================================================
void Rebootlog(){
  if (!SPIFFSmounted) return;
  File RebootFile = SPIFFS.open("/Reboot.log", "a"); // open for appending  
  if (!RebootFile) {
    DebugTln(F("open RebootLog file FAILED!!!--> Bailout\r\n"));
    return;
  }
  
  //log rotate
  if (RebootFile.size() > 1500){ 
//    DebugT(F("RebootLog filesize: "));Debugln(RebootFile.size());
    SPIFFS.remove("/Rebootlog.old");     //remove .old if existing 
    //rename file
    DebugTln(F("RebootLog: rename file"));
    RebootFile.close(); 
    SPIFFS.rename("/Reboot.log", "/Rebootlog.old");
    RebootFile = SPIFFS.open("/Reboot.log", "a"); // open for appending  
    }
  
    //make one record : {"time":"2020-09-23 17:03:25","reason":"Software/System restart","reboots":42}
    RebootFile.println("{\"time\":\"" + buildDateTimeString(actTimestamp, sizeof(actTimestamp)) + "\",\"reason\":\"" + lastReset + "\",\"reboots\":" +  (int)nrReboots + "}");
  
    //closing the file
    RebootFile.close(); 
}

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
