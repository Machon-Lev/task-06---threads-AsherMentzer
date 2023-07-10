#pragma once

#include <iostream>
#include <thread>


/**
 * @class Message
 * @brief A class for messaging between two threads.
 *
 * The Message class allows communication between two threads by passing data
 * with additional information such as the thread ID and whether it is the last message.
 * It provides methods to write, read, and check the status of the message.
 */
class Message {
    std::thread::id _threadId;  /**< The ID of the thread that wrote the message. */
    double _data;               /**< The data contained in the message. */
    bool _isLast;               /**< Indicates whether the message is the last in a series. */
    bool _isRead = true;        /**< Indicates whether the message has been read. */

public:
    /**
     * Writes a message with the specified thread ID, data, and last message flag.
     * @param threadId The ID of the thread writing the message.
     * @param data The data to be stored in the message.
     * @param isLast A flag indicating whether the message is the last in a series.
     */
    void write(std::thread::id threadId, double data, bool isLast);

    /**
     * Checks if the message has been read.
     * @return True if the message has been read, false otherwise.
     */
    bool isRead();

    /**
     * Checks if the message is the last in a series.
     * @return True if the message is the last, false otherwise.
     */
    bool wasLast();

    /**
     * Reads the message and returns it.
     * After reading, the message is marked as read.
     * @return The message containing the thread ID, data, and last message flag.
     */
    Message read();

    /**
     * Overloaded stream insertion operator for displaying the message's contents.
     * @param os The output stream to write the message to.
     * @param msg The message to be written.
     * @return The output stream after writing the message.
     */
    friend std::ostream& operator<<(std::ostream& os, const Message& msg);
};



