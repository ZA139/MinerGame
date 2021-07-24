#pragma once
#ifndef __RELATIONSHIPMGR
#define __RELATIONSHIPMGR
#include "./Util/SingletonBaseClass.h"
#include "/data/charlesqliu/MiniMiner/extern/MiniGame/exported/behaviac_generated/types/internal/behaviac_agent_headers.h"
class RelationShipMgr :public Singleton<RelationShipMgr> {
	public:
		Wife * getWifeInstance(Miner* tar) const;
		void RegMiner(Miner * tar);
		void RegWife(Wife* tar);
	private:
		std::map<Miner*, Wife*> RelationShip;
		Wife* wife;
		Miner* miner;
};
#endif