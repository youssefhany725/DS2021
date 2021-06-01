#include "..\hFiles\MarsStation.h"
#include "..\hFiles\Mission.h"
#include "..\hFiles\Event.h"

MarsStation::MarsStation()
{
	CurrentDay = 0;
	UserI.input(this);
}

void MarsStation::StationInput(LinkedQueue<Event>*)
{

}

void MarsStation::MExecute()
{
	Event *E;
	bool b = EventList.peek(E);
	if (b && CurrentDay == E->getday())
	{
		EventList.dequeue(E);
		E->Execute();
		Mission* M = E->getMission();
		if (M->gettype() == 3)
			EMissionList.enqueue(M,M->getPkey());//priority needed
		else
			PMissionList.enqueue(M);
	}
}

void MarsStation::Assign()
{
	Mission* M;
	if (EMissionList.peek(M))
	{
		Rover* R;
		if (M->gettype() == polar)//Polar
		{
			if (!PRoverList.isEmpty())
			{
				PRoverList.dequeue(R);
				PMissionList.dequeue(M);
				M->Assign(R,CurrentDay);
				InExMissions.enqueue(M,-M->getcmpday());
				InExRovers.enqueue(R, -M->getcmpday());
			}
		}
		if (M->gettype() == emergency)//Emergency
		{
			ERoverList.dequeue(R);
			EMissionList.dequeue(M);
			M->Assign(R,CurrentDay);
			InExMissions.enqueue(M,-M->getcmpday());
			InExRovers.enqueue(R,-M->getcmpday());
		}
	}
}

void MarsStation::Complete()
{

	Mission* M;
	Rover* R;
}

void MarsStation::AddEvent(missiontype missionType, int eventDay, int ID, int targetLocation, int missionDuration, int significance)
{
	Event* e = new Event(missionType, eventDay, ID, targetLocation, missionDuration, significance);
	EventList.enqueue(e);
}

void MarsStation::AddRover(rovertype roverType, int ID)
{
	Rover* r = new Rover(roverType, ID);
	if (roverType == polarrover) PRoverList.enqueue(r);
	else ERoverList.enqueue(r);
}

void MarsStation::setMissionsToCheckup(int n)
{
	Rover::setMissionsToCheckup(n);
}

void MarsStation::setPolar_checkupDuration(int n)
{
	Rover::setPolar_checkupDuration(n);
}

void MarsStation::setEmergency_checkupDuration(int n)
{
	Rover::setEmergency_checkupDuration(n);
}

void MarsStation::setPolar_speed(int n)
{
	Rover::setPolar_speed(n);
}

void MarsStation::setEmergency_speed(int n)
{
	Rover::setEmergency_speed(n);
}

