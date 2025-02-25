CPP = g++
W = -Wall
DABIN = nebin2
BLD = ./build
INC = ./include
SRC = ./src
LIST = $(wildcard $(SRC)/*.cpp)
OLIST = $(wildcard $(BLD)/*.o)
PAT_OPP = $(patsubst $(SRC)/%.cpp, $(BLD)/%.o, $(LIST))

$(BLD)/%.o:	$(SRC)/%.cpp
	$(CPP) $(W) -I$(INC) -o $@ -c $<

$(DABIN):	$(LIST)
	$(CPP) $(W) -o $@ $^
