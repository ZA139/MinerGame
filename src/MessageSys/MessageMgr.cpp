#include "MessageMgr.h"
#include<iostream>
//#define __MSG_DEBUG
bool MessageMgr::SendMessage(Message * message)
{
	if (MessageQueue.find(message->receiver)==MessageQueue.end()) {
		printf("reciver:%p\n",message->receiver);
		std::cerr<<"Size:"<<MessageQueue.size()<<endl;
		auto it=MessageQueue.begin();
		printf("reciver:%p\n",it->first);
		it++;
		printf("reciver:%p\n",(it)->first);
		std::cerr << "Receiver hasn't register\n";
		return false;
	}
	MessageQueue[message->receiver].add(message);
	return true;
}

bool MessageMgr::RegAgent(AgentWithMessage *agent)
{
	MessageQueue[agent] = *(new LinkedList<Message>());
	return false;
}

bool MessageMgr::RemoveAgent(AgentWithMessage *agent)
{
	delete &MessageQueue[agent];
	MessageQueue.erase(agent);
	return false;
}

void MessageMgr::HandleMessageQueue()
{
	auto it = MessageQueue.begin();
	while (it != MessageQueue.end()) {
		AgentWithMessage* Agent = it->first;
		LinkedList<Message> * nowAgentQueue = &(it->second);
		ListNode<Message>* now = nowAgentQueue->getHead();
		ListNode<Message>* temp = nullptr;
		Message* message = nullptr;
		string errorMessage;
		while (now->next) {
			now = now->next;
			message = now->entity;
			if (message->delay == 0) {
				if ((errorMessage=Agent->HandleMessage(message)).size()) {
					cerr << "HandlerMessage Error:" << errorMessage << "\n";
					return;
				}
				temp = now->pre;
				nowAgentQueue->remove(now);
				now = temp;
			}
			else {
				#ifdef __MSG_DEBUG
				cerr<<"过期消息"<<endl;
				#endif
				temp = now->pre;
				nowAgentQueue->remove(now);
				now = temp;
			}
			message->delay--;
		}
		it++;
	}
	return;
}
