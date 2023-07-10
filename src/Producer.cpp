#include "Producer.h"

void Producer::run(std::mutex& g_messageMtx, std::condition_variable& cond, Message& messageContainer)
{
	auto thisThreadId = std::this_thread::get_id();
	double dataToSend = (double)std::hash<std::thread::id>{}(thisThreadId);   // Generate data to send based on the thread ID

	while (true)
	{
		{
			std::unique_lock lck(g_messageMtx);
			// Wait until the message container is read by the consumer
			cond.wait(lck, [&messageContainer]() {return messageContainer.isRead(); });
			messageContainer.write(thisThreadId, dataToSend, dataToSend == 0);
		}
		cond.notify_all();                  // Notify all waiting threads that the container is available
		if (!dataToSend)
		{
			break;                          // Stop producing messages if the data to send is 0
		}
		dataToSend /= 10;
	}
}
