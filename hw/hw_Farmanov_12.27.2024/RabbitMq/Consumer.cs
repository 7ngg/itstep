using RabbitMQ.Client;
using RabbitMQ.Client.Events;

namespace RabbitHw.RabbitMq;

public class Consumer : MqBase
{
    private readonly AsyncEventingBasicConsumer _consumer;

    public Consumer(ConnectionFactory connectionFactory) : base(connectionFactory)
    {
        _consumer = new AsyncEventingBasicConsumer(Channel);
    }

    public void AddListener(string queueName, AsyncEventHandler<BasicDeliverEventArgs> handler)
    {
        _consumer.ReceivedAsync += handler;

        CreateQueueIfNotExists(queueName);

        Channel.BasicConsumeAsync(queue: queueName, autoAck: true, consumer: _consumer);
    }

    public void RemoveListener(AsyncEventHandler<BasicDeliverEventArgs> handler) => _consumer.ReceivedAsync -= handler;
}