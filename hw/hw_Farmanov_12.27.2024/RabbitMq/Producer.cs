using RabbitMQ.Client;

namespace RabbitHw.RabbitMq;

public class Producer(ConnectionFactory connectionFactory) : MqBase(connectionFactory)
{
    public async Task Send(string queueName, byte[] message)
    {
        await CreateQueueIfNotExists(queueName);
        await Channel.BasicPublishAsync(exchange: string.Empty, routingKey: queueName, body: message);
    }
}