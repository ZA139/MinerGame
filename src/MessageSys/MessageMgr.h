#pragma once
#ifndef __MESSAGEMGR
#define __MESSAGEMGR
#include "./Util/SingletonBaseClass.h"
#include"/data/charlesqliu/MiniMiner/extern/MiniGame/exported/behaviac_generated/types/internal/behaviac_agent_headers.h"
#include"./Util/LinkedList.h"
using namespace std;
class MessageMgr :public Singleton<MessageMgr> {
private:
	map<AgentWithMessage*, LinkedList<Message> > MessageQueue;
public:
	bool SendMessage(Message* message);
	bool RegAgent(AgentWithMessage* agent);
	bool RemoveAgent(AgentWithMessage* agent);
	void HandleMessageQueue();
};
#endif