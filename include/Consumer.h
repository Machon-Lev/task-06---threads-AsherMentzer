#pragma once
#include "Message.h"
#include <mutex>
#include <condition_variable>

/**
 * @class Consumer
 * @brief Represents a consumer that processes messages from a message container.
 *
 * The Consumer class provides a run function that consumes messages from a message container
 * until the last message is received twice. It uses a mutex and condition variable for
 * synchronization with the message container.
 */
class Consumer {
public:
    /**
     * @brief Runs the consumer to process messages from a message container.
     *
     * This function consumes messages from the provided message container until the last message
     * is received twice. It waits for a new unread message to become available in the message
     * container and then processes it.
     *
     * @param g_messageMtx The mutex to protect access to the message container.
     * @param cond The condition variable for synchronization with the message container.
     * @param messageContainer The message container to read messages from.
     */
    void run(std::mutex& g_messageMtx, std::condition_variable& cond, Message& messageContainer);
};


