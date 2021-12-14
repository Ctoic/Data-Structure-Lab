#include <iostream>
#include<queue>
#include <chrono>
#include<iomanip>
#include<string>
#include<cstring>
#include <Windows.h>
using namespace std;

#define TIMER_VALUE (5 * 1000) //5 seconds = 5000 milli seconds
HANDLE g_hExitEvent = NULL;

bool doneInTime = false;
string name;

bool inputWords();


//The below function will be called when the timer ends
void CALLBACK doWhenTimerEnds(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{
	if (!doneInTime)
	{
		cout << "\nOut of time ... try again ..." << endl;
		doneInTime = inputWords();
	}
	SetEvent(g_hExitEvent);
}


bool inputWords()
{

	/* doWhenTimerEnds() will be called after time set by 5-th parameter and repeat every 6-th parameter. After time elapses,
	callback is called, executes some processing and sets event to allow exit */
	HANDLE hNewTimer = NULL;
	BOOL IsCreated = CreateTimerQueueTimer(&hNewTimer, NULL, doWhenTimerEnds, NULL, TIMER_VALUE, 0, WT_EXECUTELONGFUNCTION);

	g_hExitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	cout << "Enter the message in 5 seconds .. " << endl;
	getline(cin, name);

	DeleteTimerQueueTimer(NULL, hNewTimer, NULL);
	return true;
}


class Timer
{

public:

	bool stimer = false;
	long double starttime = 0;

	void setTimer()
	{
		stimer = true;
		starttime = chrono::duration_cast<std::chrono::milliseconds>(
			chrono::system_clock::now().time_since_epoch()
			).count();
	}

	void stopTimer()
	{
		stimer = false;
		cout << "Time Duration: " << (chrono::duration_cast<std::chrono::milliseconds>(
			chrono::system_clock::now().time_since_epoch()
			).count()) - starttime << " miliseconds." << endl;
	}

};

Timer time2;
Timer time1;

struct Message
{
	string from;
	string to;
	string message;
};

class Troops
{

public:

	string General;
	string Captain_1;
	string Captain_2;
	string Captain_3;
	queue<Message> incoming;
	queue<Message> outgoing;
	Message Msg;

};

void sendMessage(Troops send, Troops receive)
{
	//setting timer.
	::time1.setTimer();

	//enqueue message.
	send.outgoing.push(send.Msg);

	cout << "Sending Message: '" << send.Msg.message << "' is sent from captain '" << send.Msg.from << "' to captain '" << send.Msg.to << "'" << endl;
	receive.incoming.push(send.outgoing.front());
	send.outgoing.pop();
	cout << "Receiving Message: '" << receive.incoming.front().message << "' is recieved by captain '" << receive.incoming.front().to << "' from captain '" << receive.incoming.front().from << "'" << endl;
	receive.incoming.pop();
	::time1.stopTimer();
}

//function to return current time.
long double curtime()
{
	return chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

int main()
{
	Troops troop;
	string Captain_1;
	string Captain_2;
	string Captain_3;
	string msg;
	string from;
	string to;

	cout << "Enter captain_1 id: ";
	cin >> Captain_1;
	cout << "Enter captain_2 id: ";
	cin >> Captain_2;
	cout << "Enter captain_3 id: ";
	cin >> Captain_3;

	//assigning values to captains.
	troop.Captain_1 = Captain_1;
	troop.Captain_2 = Captain_2;
	troop.Captain_3 = Captain_3;

	cout << "Enter the id of sender: ";
	cin >> from;

	cout << "Enter the id of receiver: ";
	cin >> to;

	cin.ignore();

	doneInTime = inputWords();
	//storing message information.
	troop.Msg.message = name;
	troop.Msg.from = from;
	troop.Msg.to = to;

	//calling the send message function.
	sendMessage(troop, troop);

	return 0;
}