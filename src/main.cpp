#include <iostream>
#include <exception>
#include "Message.h"
#include <mutex>
#include <condition_variable>
#include "Consumer.h"
#include "Producer.h"

using std::cout;
using std::exception;

int main()
{
	std::mutex g_messageMtx;                  // Mutex for protecting shared data
	std::condition_variable cond;             // Condition variable for synchronization
	Message messageContainer;
	Consumer consumer;
	Producer producer1;
	Producer producer2;

	std::thread consumerThread([&]() {
		consumer.run(std::ref(g_messageMtx), std::ref(cond), std::ref(messageContainer));
		});
	std::thread producer1Thread([&]() {
		producer1.run(std::ref(g_messageMtx), std::ref(cond), std::ref(messageContainer));
		});
	std::thread producer2Thread([&]() {
		producer2.run(std::ref(g_messageMtx), std::ref(cond), std::ref(messageContainer));
		});

	consumerThread.join();                     // Wait for the consumer thread to finish
	producer1Thread.join();                    // Wait for producer thread 1 to finish
	producer2Thread.join();                    // Wait for producer thread 2 to finish
}



