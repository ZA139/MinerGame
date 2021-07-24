#include "./RelationShipMgr.h"
#define regRelationShip if(wife&&miner){ RelationShip[miner] = wife; miner =nullptr; wife=nullptr; }
Wife * RelationShipMgr::getWifeInstance(Miner* tar) const {
	return RelationShip.find(tar)->second;
}
void RelationShipMgr::RegMiner(Miner * tar) {
	miner=tar;
	regRelationShip
	return;
}
void RelationShipMgr::RegWife(Wife* tar) {
	wife=tar;
	regRelationShip
	return;
}