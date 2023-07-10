#include "Consumer.h"

void Consumer::run(std::mutex& g_messageMtx, std::condition_variable& cond, Message& messageContainer)
{
	Message recivedMsg;
	int lastCounter = 0;

	// Keep consuming messages until receiving the last message twice
	while (lastCounter < 2)
	{
		{
			std::unique_lock lck(g_messageMtx);
			// Wait until a new unread message is available in the message container
			cond.wait(lck, [&messageContainer]() {return !messageContainer.isRead(); });
			recivedMsg = messageContainer.read();
		}
		cond.notify_all();                  // Notify all waiting threads that the container is available
		std::cout << recivedMsg;
		lastCounter += recivedMsg.wasLast();   // Check if the received message was the last one
	}
}
