#include "await.hxx"
#include "promise.hxx"
#include "message.hxx"

namespace ura::messaging
{

void await(Message& m, MessageReceiver& recipient)
{
    Promise p;
    m.returnTo(&p);

    recipient.sendMessage(m);
    p.waitUntilResolved();
}

void await(Promise& p, Message& m, MessageReceiver& recipient)
{
    m.returnTo(&p);
    recipient.sendMessage(m);
}

void await(Promise& p)
{
    p.waitUntilResolved();
}

void meanwhile(Promise& p, std::function<void()> to_execute)
{
    to_execute();
    p.waitUntilResolved();
}

}   /* namespace ura::messaging */
