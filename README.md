# Arduino-Ethernet-Shield-SQL-and-PHP
Arduino Uno med Ethernet Shield - SQL via PHP fil. 

Med dette setup er det muligt at skrive til en ekstern SQL database via Ethernet. Dette eksempel benytter sig af en statisk værdi, men man kan tilkoble en temperatur føler eller ligende. 

# Step 1
<img src="http://blog.mlsdesign.dk/images/SQL/image2.JPG" width="350"/>

På billedet ses de to boards som bliver brugt til dette eksempel. Eksemplet viser hvordan man laver en forbindelse samt indsætter dataen "666" på en ekstern MySQL database på et andet domæne. Hvilket også kan være localhost. Denne løsning man kombineres med føler som fx. temp, Co2, Gas osv. Derudover er det muligt at benytte sig af GSM eller WiFi i stedet for det indbygget Ethernet Shield. (Der vil komme en guide i den nærmeste fremtid hvordan man opretter forbindelse med GSM)

# Step 2
Den pågældende C kode opretter forbindelse til Internettet og derefter kalder en Url adresse med GET værdierne: Token og Temp. Token bruges som sikkerhed for at checke om koden passer på begge enheder. I dette eksempel: "token1234".  Temperaturen er statisk da jeg ikke har fokuseret på at angive en værdi. Tilsidst i koden er der et delay() script som gør at den laver en måling hvert 5 sec.  

# Step 3
Dette kode skal placeres på en platform som kan afvikle PHP filer og har en gyldig sti. fx: www.madslind.nu
