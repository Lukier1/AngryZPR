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

Wystarczy jedna komenda uruchomiana w folderze glownym

make

--------------------------------------------------------
Uruchamianie:

Do uruchomienia gry:

./game

Do uruchomienia testów:

./test

