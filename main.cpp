#include "Connector.h"
#include "Window.h"


int main(int argc, char *argv[ ])
{
  Connector	c = Connector();
  Window	w = Window(argc, argv, &c);

  return 0;
}
