# AngryZPR

#Instalcja 

W konsoli:
git clone https://github.com/Lukier1/AngryZPR.git
cd  AngryZPR

Kopiujemy folder Libs do folderu AngryZPR

sudo apt-get install sudo apt-get install cmake-gui

Dla Box2D:
W CMake:
Source code: Na folder gdzie jest plik CMakeList.txt(Libs/Box2D/Box2D)
Binary code: To ten sam folder tylko dopisujemy /bin na koncu (to bedzie miejsce gdzie zostana utowrzony makefile)
Klikamy Configure. Wyskakuje oknoi ze nie ma takie folderu /bin klimamy Yes, nastepnie Next Next Next( nie pamietam ile ich tam bylo)
Bo configuracji nie martwimy sie ze checkboxy swieca sie na czerwono. Odznamy BOX2D_BUILD_EXAMPLE, kliamy przycisk Advanced i w polu CMAKE_CXX_FLAGS wpisujemy -std=gnu++11
Klikamy Generate, powinno to pojsc bez zadnego problemu.  
Nastepnie terminalem wchodzimy do folderu bin, i tam wpisujemy sudo make install.

Dla SFML:
sudo apt-get install libfreetype6-dev libjpeg-dev libx11-dev libxrandr-dev libx11-xcb-dev libxcb-randr0-dev libxcb-image0-dev  libogg-dev libudev-dev libopenal-dev libflac-dev libvorbis-dev libx11-dev freeglut3-dev
Analogiczne kroki jak poprzednio( CMake soruce folder to Libs/SFML) i po skonczeniu Configure:
Nastepnie Generate. 
Nastepnie terminalem wchodzimy do folderu bin, i tam wpisujemy sudo make install.

Kompilacja:
Aby skompilowac wchodzimy z konsoli do folderu z plikiem AngryZPR.bkl(AngryZPR/) i nastepnei poleceniem
libs/bakefile/bkl AngryZPR.bkl
make
