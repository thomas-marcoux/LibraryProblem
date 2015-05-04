NAME=	library

CC=	g++

CFLAGS=	-Wall -g -lmysqlcppconn
#-I/usr/include/cppconn -L/usr/lib

RM=	rm -fv

SRC=	Connector.cpp		\
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
