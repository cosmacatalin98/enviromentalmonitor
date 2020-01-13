# Enviromental Monitor
Implementarea circuitului are la bază citirea unor valori de la 3 senzori (temperatură și umiditate, intensitatea luminii, intensitatea sunetului) și stabilirea comunicări cu un smartphone prin intermediul unui modul bluetooth HC-05 cu scopul de a afișa valorile citite de la senzori pe o matrice de LED-uri 8x8 în funcție de comenzile primite de la smartphone.

# Instalare
Se ansamblează componentele conform diagramei circuitului după care se deschide mediul de dezvoltare integrat Arduino și se începe prin instalarea librăriilor :
- SoftwareSerial
- LedControl
- DHT
Se încarcă codul din schema EnviromentalMonitor.ino , se compilează și se încarcă pe placă.În cazul în care compilarea și încărcarea au fost realizate cu succes un mesaj de întâmpinare denumit “HELLO” va fi afișat pe matricea de LED-uri.În continuare se conectează smartpone-ul la modulul bluetooth prin intermediul aplicației “Serial Bluetooth Terminal” (Se poate descărca de pe Google Play).Din interfața aplicației se poate selecta una dintre opțiunile : 
Tmp – pentru afișarea temperaturii
Umd – pentru afișarea umidității
Lum – pentru afișarea intensității luminii
Sun - pentru afișarea intensității sunetului
Def – pentru afișarea mesajului de întâmpinare

# Versiuni

V 1.0

# Autori

Cosma Cătălin
