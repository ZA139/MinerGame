﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#ifndef _BEHAVIAC_MINER_H_
#define _BEHAVIAC_MINER_H_

#include "behaviac_headers.h"

#include "AgentWithMessage.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT
#include "AgentWithMessage.h"
#include"/data/charlesqliu/MiniMiner/src/MessageSys/Message.h"
#include "/data/charlesqliu/behaviac/inc/behaviac/common/base.h"
#include"/data/charlesqliu/behaviac/inc/behaviac/common/serialization/ionode.h"
#include"/data/charlesqliu/behaviac/inc/behaviac/common/serialization/textnode.h"
#include"/data/charlesqliu/behaviac/inc/behaviac/common/swapbyte.h"
#include"/data/charlesqliu/behaviac/inc/behaviac/common/rttibase.h"
///<<< END WRITING YOUR CODE

class Miner : public AgentWithMessage
{
public:
	Miner();
	virtual ~Miner();

	BEHAVIAC_DECLARE_AGENTTYPE(Miner, AgentWithMessage);

	private: unsigned int GoldCarried;

	private: unsigned int ThirstyTimer;

	private: unsigned int TodayGainedGold;

	private: unsigned int TotalMoney;

	private: void EnterMineAndDigForNugget();

	private: void GoToBank();

	private: void GoToBarDrinkSomeWhiskey();

	private: void Rest();

///<<< BEGIN WRITING YOUR CODE CLASS_PART
public: virtual std::string HandleMessage(Message* message);
///<<< END WRITING YOUR CODE
};

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT

///<<< END WRITING YOUR CODE

#endif