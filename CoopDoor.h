#include <Servo.h>
#include <SoftwareSerial.h>

using namespace std;

class CoopDoor {

  private:
    Servo Engine;
    

  public:
    bool isOpened = false;
    int pin;
    CoopDoor(int doorPin) {
      this->pin = doorPin;
    }

    void _setup(){
      this->_close();
      this->Engine.attach(this->pin);
    }

    void _open() {
      
      if (!this->isOpened) {
        this->Engine.write(180);
        this->isOpened = true;
      }
    }

    void _close() {
      if (this->isOpened) {
        this->Engine.write(90);
        this->isOpened = false;
      }
    }
};
