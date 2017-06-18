#pragma once

#define SEND_MSG_IMMEDIATELY 0
#define NO_ADDITIONAL_INFO 0

enum message_type
{
	Msg_HiHoneyImHome = 0,
	Msg_StewReady,
};

struct Telegram
{
	Telegram(double delay, int sender, int receiver, int msg, void* extraInfo)
	{
		m_dispatchTime = delay;
		m_sender = sender;
		m_receiver = receiver;
		m_msg = msg;
		m_extraInfo = extraInfo;
	}
	double m_dispatchTime;
	int m_sender;
	int m_receiver;
	int m_msg;
	void* m_extraInfo;
};