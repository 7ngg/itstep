using RabbitMQ.Client;

namespace RabbitHw.RabbitMq;

public abstract class MqBase
{
    private readonly IConnection _connection;
    protected readonly IChannel Channel;

    protected MqBase(ConnectionFactory factory)
    {
        _connection = factory.CreateConnectionAsync().GetAwaiter().GetResult();
        Channel = _connection.CreateChannelAsync().GetAwaiter().GetResult();
    }

    protected Task CreateQueueIfNotExists(string queueName)
    {
        return Channel.QueueDeclareAsync(queueName, autoDelete: false, exclusive: false, durable: true);
    }

    ~MqBase()
    {
        _connection.Dispose();
        Channel.Dispose();
    }
}