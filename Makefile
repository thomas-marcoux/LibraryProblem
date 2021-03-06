NAME=	library

CC=	g++

CFLAGS=	-Wall -g -Wno-write-strings -lmysqlcppconn `pkg-config --cflags --libs gtk+-2.0`

RM=	rm -fv

SRC=	Connector.cpp		\
	Window.cpp		\
	main.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(META)

re:	fclean all
