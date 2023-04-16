#pragma once

#include "message_receiver.hxx"
#include "priority.hxx"

#include <any>

namespace ura::messaging
{

class Message
{
public:
    enum class Type: int
    {
        OK,
        ERROR,
        START,
        STOP,
        REQUEST,
        RESPONSE,
    };

    const MessageReceiver* getReturnAddress() const
    {
        return _return_address;
    }

    MessageReceiver* getReturnAddress()
    {
        return _return_address;
    }

    void returnTo(MessageReceiver* return_address)
    {
        _return_address = return_address;
    }

    const std::any& getValue() const
    {
        return _value;
    }

    std::any getValue()
    {
        return _value;
    }

    Type getType() const
    {
        return _type;
    }

    unsigned int getCode() const
    {
        return _code;
    }

    uint8_t getPriority() const
    {
        return _priority;
    }

    Message copy() const
    {
        return Message(*this);
    }

    Message& operator=(const Message& other);
    Message& operator=(Message&& other);

    Message(const Message& other);
    Message(Message&& other);
    Message(MessageReceiver* return_address,
            const Type type,
            std::any value,
            const unsigned int code,
            const uint8_t priority=priority::MEDIUM);
    
    ~Message();

private:
    MessageReceiver* _return_address;

    std::any _value;
    Type _type;
    unsigned int _code;
    uint8_t _priority;
};

}   /* namespace ura::messaging */
