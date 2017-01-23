# AngryZPR

--------------------------------------------------------
Generowanie odpowiednich plików budujących dla Widnwos/Linux

Wykorzystałem tutaj narzędzie bakefile, które służy do generowania makefile dla linux'a i odpowiednich plików projektowych dla Visuala.
Jest ono do ściagnięcia pod tym linkiem.
https://github.com/vslavik/bakefile/releases

Jako że to narzędzie wymaga kompilacji pod linuksem, dołączam wygenerowany przez nie plik GNUmakefile do oddawanego projektu, by nie było potrzeby kompilacji tego narzędzia.

------------------------------------------------------------
Generowanie plików przez bakefile:
Aby skompilować wchodzimy z konsoli do folderu AngryZPR(znajduję się tam plik AngryZPR.bkl) i nastepne poleceniami budujemy:

<Ścieżka do skompilowanego programu bakefile>/bkl AngryZPR.bkl

--------------------------------------------------------
Kompilacja:
Linux:
Wystarczy jedna komenda uruchomiana w folderze glownym

make

Windows:
Należy stworzyc fodler Libs w folderze projektu, a w nim odpowiednio podązając za bakefilem dodać i skompilować odpowiednie biblioteki.
Następnie kompilacja odbywa sie poprzez skompilowanie i uruchomienie projektu game.


--------------------------------------------------------
Uruchamianie:
Linux:
Do uruchomienia gry:

./game

Do uruchomienia testów:

./test

