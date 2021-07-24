#pragma once
#ifndef __MESSAGE
#define __MESSAGE
#include "/data/charlesqliu/MiniMiner/extern/MiniGame/exported/behaviac_generated/types/internal/behaviac_agent_headers.h"

class AgentWithMessage;

enum MessageType{
    HOME_SWEET_HOME,
    FOOD_IS_READY
};
struct Message {
    AgentWithMessage* sender;
    AgentWithMessage* receiver;
    MessageType type;
    void* externData;
    int delay;

    Message(AgentWithMessage * _sender,AgentWithMessage * _receiver,MessageType _type,int _delay,void* _externData=nullptr){
        sender=_sender;
        receiver = _receiver;
        type=_type;
        delay=_delay;
        externData=_externData;
    }
};
#endif