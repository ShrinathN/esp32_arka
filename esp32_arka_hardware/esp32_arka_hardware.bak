EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 5F0217C4
P 1100 1650
F 0 "J?" H 1180 1642 50  0000 L CNN
F 1 "Solar_input" H 1180 1551 50  0000 L CNN
F 2 "" H 1100 1650 50  0001 C CNN
F 3 "~" H 1100 1650 50  0001 C CNN
	1    1100 1650
	1    0    0    -1  
$EndComp
Text Label 900  1650 2    50   ~ 0
SOLAR_VIN
Text Label 900  1750 2    50   ~ 0
GND
$Comp
L RF_Module:ESP32-WROOM-32 U?
U 1 1 5F0218BA
P 6250 2800
F 0 "U?" H 6250 4550 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 6850 4550 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 6250 1300 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 5950 2850 50  0001 C CNN
	1    6250 2800
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 5F021A87
P 1700 800
F 0 "U?" H 1700 1042 50  0000 C CNN
F 1 "AMS1117-3.3" H 1700 951 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 1700 1000 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 1800 550 50  0001 C CNN
	1    1700 800 
	1    0    0    -1  
$EndComp
Text Label 1700 1200 3    50   ~ 0
GND
Text Label 900  800  2    50   ~ 0
SOLAR_VIN
Text Label 2500 800  0    50   ~ 0
3V3
Wire Wire Line
	1700 1200 1700 1100
Wire Wire Line
	2000 800  2200 800 
Wire Wire Line
	1400 800  1200 800 
$Comp
L Device:C C?
U 1 1 5F021B64
P 1200 950
F 0 "C?" H 1315 996 50  0000 L CNN
F 1 "100m" H 1315 905 50  0000 L CNN
F 2 "" H 1238 800 50  0001 C CNN
F 3 "~" H 1200 950 50  0001 C CNN
	1    1200 950 
	1    0    0    -1  
$EndComp
Connection ~ 1200 800 
Wire Wire Line
	1200 800  900  800 
$Comp
L Device:C C?
U 1 1 5F021BA8
P 2200 950
F 0 "C?" H 2315 996 50  0000 L CNN
F 1 "100m" H 2315 905 50  0000 L CNN
F 2 "" H 2238 800 50  0001 C CNN
F 3 "~" H 2200 950 50  0001 C CNN
	1    2200 950 
	1    0    0    -1  
$EndComp
Connection ~ 2200 800 
Wire Wire Line
	2200 800  2500 800 
Text Label 6250 1400 1    50   ~ 0
3V3
Text Label 6250 4200 3    50   ~ 0
GND
$Comp
L Device:R R?
U 1 1 5F0220FA
P 5650 1450
F 0 "R?" H 5450 1600 50  0000 L CNN
F 1 "10k" H 5450 1500 50  0000 L CNN
F 2 "" V 5580 1450 50  0001 C CNN
F 3 "~" H 5650 1450 50  0001 C CNN
	1    5650 1450
	1    0    0    -1  
$EndComp
Text Label 5650 1300 0    50   ~ 0
3V3
Text Label 6850 1600 0    50   ~ 0
FLASH_PIN
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5F022AB0
P 10350 900
F 0 "J?" H 10322 873 50  0000 R CNN
F 1 "Flashing_connector" V 10200 1200 50  0000 R CNN
F 2 "" H 10350 900 50  0001 C CNN
F 3 "~" H 10350 900 50  0001 C CNN
	1    10350 900 
	-1   0    0    -1  
$EndComp
Text Label 6850 1700 0    50   ~ 0
TXD0
Text Label 6850 1900 0    50   ~ 0
RXD0
Text Label 10150 1000 2    50   ~ 0
TXD0
Text Label 10150 1100 2    50   ~ 0
RXD0
Text Label 10150 900  2    50   ~ 0
GND
Text Label 10150 800  2    50   ~ 0
3V3
$EndSCHEMATC
