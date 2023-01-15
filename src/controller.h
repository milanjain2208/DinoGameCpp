#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "dinosaur.h"

class Controller {
 public:
  void HandleInput(bool &running,Dinosaur &dino) const;
};

#endif