#include "..\hFiles\Mission.h"
Mission::Mission(missiontype a,int ed, int c, int d, int e, int f)
{
	TYP = a;
	ID = c;
	Rassigned = nullptr;
	CD = -1;
	ED = ed;
	TLOC = d;
	MDUR = e;
	SIG = f;
}
void Mission::Assign(Rover* R,int cd)
{
	Rassigned = R;
	CD = cd + MDUR + ((TLOC/R->getspeed()) / 25);
}
int Mission::getcmpday()
{
	return CD;
}
int Mission::gettype()
{
	return TYP;
}
int Mission::getPkey() {
	return 0;
}
int Mission::getMDUR()
{
	return MDUR;
}