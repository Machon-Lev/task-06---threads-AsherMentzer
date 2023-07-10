#pragma once
#include "Message.h"
#include <mutex>
#include <condition_variable>

/**
 * @class Producer
 * @brief Represents a producer that generates messages and adds them to a message container.
 *
 * The Producer class provides a run function that generates messages and adds them to a message
 * container. It uses a mutex and condition variable for synchronization with the consumer.
 */
class Producer {
public:
    /**
     * @brief Runs the producer to generate and add messages to a message container.
     *
     * This function generates messages and adds them to the provided message container. It
     * notifies the consumer using a condition variable when a new message is added.
     *
     * @param g_messageMtx The mutex to protect access to the message container.
     * @param cond The condition variable for synchronization with the consumer.
     * @param messageContainer The message container to add messages to.
     */
    void run(std::mutex& g_messageMtx, std::condition_variable& cond, Message& messageContainer);
};


