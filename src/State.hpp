#ifndef STATE_HPP
#define STATE_HPP

using namespace std;

class State
{
  private:

  public:
    virtual void setup();
    virtual void update();
    virtual void draw();
};

#endif
