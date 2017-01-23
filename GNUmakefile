# This file was automatically generated by bakefile.
#
# Any manual changes will be lost if it is regenerated,
# modify the source .bkl file instead if possible.

# You may define standard make variables such as CFLAGS or
# CXXFLAGS to affect the build. For example, you could use:
#
#      make CXXFLAGS=-g
#
# to build with debug information. The full list of variables
# that can be used by this makefile is:
# AR, CC, CFLAGS, CPPFLAGS, CXX, CXXFLAGS, LD, LDFLAGS, MAKE, RANLIB.

# You may also specify config=Debug|Release
# or their corresponding lower case variants on make command line to select
# the corresponding default flags values.
ifeq ($(config),debug)
override config := Debug
endif
ifeq ($(config),release)
override config := Release
endif
ifeq ($(config),Debug)
override CPPFLAGS += -DDEBUG
override CFLAGS += -g -O0
override CXXFLAGS += -g -O0
override LDFLAGS += -g
else ifeq ($(config),Release)
override CPPFLAGS += -DNDEBUG
override CFLAGS += -O2
override CXXFLAGS += -O2
else ifneq (,$(config))
$(warning Unknown configuration "$(config)")
endif

# Use "make RANLIB=''" for platforms without ranlib.
RANLIB ?= ranlib

CC := cc
CXX := c++

# The directory for the build files, may be overridden on make command line.
builddir = .

ifneq ($(builddir),.)
_builddir := $(builddir)/
_builddir_error := $(shell mkdir -p $(_builddir) 2>&1)
$(if $(_builddir_error),$(error Failed to create build directory: $(_builddir_error)))
endif
all: $(_builddir)libAngryZPR.a $(_builddir)test $(_builddir)game

$(_builddir)libAngryZPR.a: $(_builddir)AngryZPR_Root.o $(_builddir)AngryZPR_SystemManager.o $(_builddir)AngryZPR_StateManager.o $(_builddir)AngryZPR_WorldImpl.o $(_builddir)AngryZPR_WorldObject.o $(_builddir)AngryZPR_Slingshot.o $(_builddir)AngryZPR_Bird.o $(_builddir)AngryZPR_PhysicObject.o $(_builddir)AngryZPR_Block.o $(_builddir)AngryZPR_Pig.o
	$(AR) rcu $@ $(_builddir)AngryZPR_Root.o $(_builddir)AngryZPR_SystemManager.o $(_builddir)AngryZPR_StateManager.o $(_builddir)AngryZPR_WorldImpl.o $(_builddir)AngryZPR_WorldObject.o $(_builddir)AngryZPR_Slingshot.o $(_builddir)AngryZPR_Bird.o $(_builddir)AngryZPR_PhysicObject.o $(_builddir)AngryZPR_Block.o $(_builddir)AngryZPR_Pig.o
	$(RANLIB) $@

$(_builddir)AngryZPR_Root.o: Src/Root.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/Root.cpp

$(_builddir)AngryZPR_SystemManager.o: Src/SystemManager.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/SystemManager.cpp

$(_builddir)AngryZPR_StateManager.o: Src/StateManager.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/StateManager.cpp

$(_builddir)AngryZPR_WorldImpl.o: Src/WorldImpl.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/WorldImpl.cpp

$(_builddir)AngryZPR_WorldObject.o: Src/WorldObject.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/WorldObject.cpp

$(_builddir)AngryZPR_Slingshot.o: Src/Slingshot.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/Slingshot.cpp

$(_builddir)AngryZPR_Bird.o: Src/Bird.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/Bird.cpp

$(_builddir)AngryZPR_PhysicObject.o: Src/PhysicObject.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/PhysicObject.cpp

$(_builddir)AngryZPR_Block.o: Src/Block.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/Block.cpp

$(_builddir)AngryZPR_Pig.o: Src/Pig.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -fPIC -DPIC -pthread -std=c++11 Src/Pig.cpp

$(_builddir)test: $(_builddir)test_MockTest.o $(_builddir)test_Mock.o $(_builddir)libAngryZPR.a
	$(CXX) -o $@ $(LDFLAGS) $(_builddir)test_MockTest.o $(_builddir)test_Mock.o $(_builddir)libAngryZPR.a -lsfml-graphics -lsfml-window -lsfml-system -lBox2D -pthread

$(_builddir)test_MockTest.o: Test/MockTest.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -ILibs/boost_1_62_0 -std=c++11 Test/MockTest.cpp

$(_builddir)test_Mock.o: Src/Mock.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -ILibs/boost_1_62_0 -std=c++11 Src/Mock.cpp

$(_builddir)game: $(_builddir)game_Main.o $(_builddir)libAngryZPR.a
	$(CXX) -o $@ $(LDFLAGS) $(_builddir)game_Main.o $(_builddir)libAngryZPR.a -lsfml-graphics -lsfml-window -lsfml-system -lBox2D -pthread

$(_builddir)game_Main.o: Src/Main.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -std=c++11 Src/Main.cpp

clean:
	rm -f $(_builddir)*.o
	rm -f $(_builddir)*.d
	rm -f $(_builddir)libAngryZPR.a
	rm -f $(_builddir)test
	rm -f $(_builddir)game

.PHONY: all clean

# Dependencies tracking:
-include $(_builddir)*.d
