# AngryZPR

# Paczki bibliotek
Linux:
Windows(skompilowane):

# Budowanie Ubuntu/Mint: 

Ściąganie repozytorium:

W konsoli:

git clone https://github.com/Lukier1/AngryZPR.git

cd AngryZPR

Kopiujemy folder Libs do folderu AngryZPR.

Jeśli nie posiadamy CMake-GUI to instalujemy go za pomocą komendy:

sudo apt-get install sudo apt-get install cmake-gui

--------------------------------------------------------
Dla Box2D:

W CMake:
Source code: Na folder gdzie jest plik CMakeList.txt(Libs/Box2D/Box2D)
Binary code: To ten sam folder tylko dopisujemy /bin na koncu (to bedzie miejsce gdzie zostana utowrzony makefile)

Klikamy Configure. Wyskakuje okno że folder /bin nie istnieje, tam klikamy Yes, następnie sprawdzamy czy wybrany jest Unix Makefile i klikamy Finish. 

Bo konfiguracji może wyskoczyć błąd, i nie martwimy sie ze checkboxy swieca sie na czerwono. Odznamy BOX2D_BUILD_EXAMPLE, kliamy przycisk Advanced i w polu CMAKE_CXX_FLAGS wpisujemy -std=gnu++11. I klikamy Configure ponownie. 

Klikamy Generate, powinno to pojsc bez zadnego problemu.  

Nastepnie terminalem wchodzimy do nowo utworzonego folderu bin, i tam wpisujemy sudo make install

--------------------------------------------------------
Dla SFML:
Instalujemy z początku potrzebne biblioteki:

sudo apt-get install libfreetype6-dev libjpeg-dev libx11-dev libxrandr-dev libx11-xcb-dev libxcb-randr0-dev libxcb-image0-dev  libogg-dev libudev-dev libopenal-dev libflac-dev libvorbis-dev libx11-dev freeglut3-dev

Potem w CMake:
Source code: Na folder gdzie jest plik CMakeList.txt(Libs/SFML)
Binary code: To ten sam folder tylko dopisujemy /bin na koncu (to bedzie miejsce gdzie zostana utowrzony makefile)

Klikamy Configure, powinno ono zakończyć sie powodzedzeniem.

Nastepnie klikamy Generate.
 
Terminalem wchodzimy do nowo utworzonego folderu bin, i tam wpisujemy sudo make install

--------------------------------------------------------
Kompilacja:

Aby skompilować wchodzimy z konsoli do folderu AngryZPR(znajduję się tam plik AngryZPR.bkl) i nastepne poleceniami budujemy:

Libs/bakefile/bkl AngryZPR.bkl

make

--------------------------------------------------------
Uruchamianie:

Do uruchomienia gry:

./game

Do uruchomienia testów:

./test

---------------------------------------------------------
Znane problemy:

Bład przy uruchomieniu gry że nie ma bibliotek sfml.
Aby ten błąd naprawiać należy przy konfiguracji projektu sfml zmienić wartość CMAKE_INSTALL_PREFIX z /usr/local na /usr 
I następnie wygenerować makefile dla SFML ponownie(poprzez przycisk Generate) i w folderze bin, powinniśmy wpisać polecenie 

sudo make install 


# Windows instalacja
Ściąganie repozytorium:

W konsoli:

git clone https://github.com/Lukier1/AngryZPR.git

Nastepnie kopiujemy folder Libs do folderu AngryZPR

Żeby utworzyć pliki z projektem dla Visuala:

Otwieramy konsole w folderze AngryZPR

W konsoli wpisujemy 

Libs\bakefile-1.2.5.1_beta-win\bkl.exe AngryZPR.bkl

Nastepnie otwieramy przy pomocy Visual Studio plik AngryZPR.sln

Jeżeli mamy innego Visual Studio niż 2013 to we właściowściach każdego projektu(prawym przyciskiem myszy na projekt a nastepnie wybieramy Properties) w zakładce General zmienamy wartośc Platform Toolset na ten który jest zainstalowane.

Teraz zmieniając uruchamiany projektu za pomocą Set as Startup Project z menu kontekstowego projektu wybieramy czy chcemy wykonać testy czy uruchomić grę.
