# **777 Game**

## Prima di Iniziare

Il programma non necessita di una connessione a internet, ma richiede la presenza di un'interfaccia grafica attraverso la quale poter interagire con l'utente.

### Prerequisiti per Sviluppare il Gioco

per lo sviluppo ocorre:

```
Aver installato la libreria SFML
```

### Installare SFML:

#### Piattaforma Linux

Per l'installazione è sufficiente lanciare questo codice da terminale:

```
sudo apt-get install libsfml-dev
```

#### Piattaforma Windows

##### Visual Studio

https://www.sfml-dev.org/tutorials/2.4/start-vc.php

##### CodeBlocks

https://www.sfml-dev.org/tutorials/2.4/start-cb.php

#### Piattaforma OSX

Per l'installazione è sufficiente aver installato il gestore di pacchetti HomeBrew per OSX.

Fatto ciò basta lanciare il seguente comando da terminale:

```
brew install sfml
```

## Giocare

Per Giocare è sufficiente lanciare l'eseguibile chiamato "777" nella cartella "cmake-build-debug".

## Realizzazione
Sviluppo di un gioco a mappa espandibile a più livelli, implementato tramite grafica 2d. 

Gioco basato su un sistema di generazione di mappe random che si susseguono come in un edificio reale: esiste un'unica torre in cui vi sono diverse stanze suddivise per piani.

Il numero di nemici è determinato dalla stanza e dal piano a cui siamo.

I nemici cambiano la loro posizione in modo random e il loro attacco cresce proporzionalmente con la visita della torre.

Lo scopo del gioco è trovare Tony Effe.

##  Sviluppato con
- C++
- SFML (graphic library)

##  Autori
Conti Matteo, Enrico Maria Fabbri, Mattia Porcelli

## Licenza

Questo programma è stato sviluppato sotto la licenza GNU GENERAL PUBLIC LICENSE (v.3). Leggere 'LICENSE.md' maggiori dettagli.
