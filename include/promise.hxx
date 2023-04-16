#pragma once

#include "message_receiver.hxx"
#include "message.hxx"

#include <semaphore>
#include <memory>

namespace ura
{

namespace messaging
{

class Promise: public MessageReceiver
{
    bool _resolved {false};
    std::binary_semaphore _resolve_lock {0};
    std::unique_ptr<Message> _message;

public:
    virtual void sendMessage(Message& m) override;
    const Message* getMessage() const;
    void waitUntilResolved();
    bool isResolved() const;

    Promise();
    virtual ~Promise();
};

}   /* namespace messaging */

}   /* namespace ura */
