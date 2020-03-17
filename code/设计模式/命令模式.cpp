#include "命令模式.h"

void RemoteControlTest::main()
{
    SimpleRemoteControl* remote = new SimpleRemoteControl();
    Light* light = new Light();
    LightOnCommand* lightOn = new LightOnCommand(light);
    LightOFFCommand* lightOff = new LightOFFCommand(light);

    remote->setCommand(lightOn);
    remote->buttonWasPressed();

    remote->setCommand(lightOff);
    remote->buttonWasPressed();
}