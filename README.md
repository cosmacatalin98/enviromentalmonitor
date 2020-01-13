# Enviromental Monitor
Implementarea circuitului are la bază citirea unor valori de la 3 senzori (temperatură și umiditate, intensitatea luminii, intensitatea sunetului) și stabilirea comunicări cu un smartphone prin intermediul unui modul bluetooth HC-05 cu scopul de a afișa valorile citite de la senzori pe o matrice de LED-uri 8x8 în funcție de comenzile primite de la smartphone.

# Componente necesare
 - 1 x Arduino Uno                                 
 - 1 x Breadboard      
 - 1 x DHT 11 Temperature and Humidity Sensor      
 - 1 x KY-037 Sound Detection Sensor
 - 1 x LDR Sensor                              
 - 1 x HC-05 Bluetooth Module
 - 1 x 8x8 LED Matrix                            
 - 23 x Jumper Wires  
 - 1 x 1K Ohm Resistor         
 - 1 x 2K Ohm Resistor         
 - 1 x 10K Ohm Resistor
 
# Instalare și utilizare
Se ansamblează componentele conform diagramei circuitului după care se deschide mediul de dezvoltare integrat Arduino și se începe prin instalarea librăriilor :
- SoftwareSerial
- LedControl
- DHT

Se încarcă codul din schema EnviromentalMonitor.ino , se compilează și se încarcă pe placă.În cazul în care compilarea și încărcarea au fost realizate cu succes un mesaj de întâmpinare denumit “HELLO” va fi afișat pe matricea de LED-uri.În continuare se conectează smartpone-ul la modulul bluetooth prin intermediul aplicației “Serial Bluetooth Terminal” (Se poate descărca de pe Google Play).Din interfața aplicației se poate selecta una dintre opțiunile : 
- Tmp – pentru afișarea temperaturii
- Umd – pentru afișarea umidității
- Lum – pentru afișarea intensității luminii
- Sun - pentru afișarea intensității sunetului
- Def – pentru afișarea mesajului de întâmpinare

# Versiuni

V 1.0

# Autori

Cosma Cătălin
