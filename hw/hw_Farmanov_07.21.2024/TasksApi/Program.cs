using Microsoft.EntityFrameworkCore;
using TasksApi.Data.Contexts;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddDbContext<TasksDbContext>(opts => opts.UseSqlServer(builder.Configuration.GetConnectionString("Default")));

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.MapGet("/GetAllTasks", async (TasksDbContext context) =>
{
    return await context.Tasks.ToListAsync();
})
.WithOpenApi()
.WithName("GetAllTasks")
.WithDescription("Return all tasks available in the database");

app.MapGet("/GetTask/{id}", async (TasksDbContext context, int id) =>
{
    return await context.Tasks.FindAsync(id);
})
.WithOpenApi()
.WithName("GetTaskByID")
.WithDescription("Returns a task by the requested id");

app.MapPost("/AddTask", async (TasksDbContext context, TasksApi.Data.Entities.Task newTask) =>
{
    await context.Tasks.AddAsync(newTask);
    await context.SaveChangesAsync();
})
.WithOpenApi()
.WithName("AddNewTask")
.WithDescription("Adds new task to existing database");

app.MapPost("/EditTask/{id}", async (TasksDbContext context, int id, string newStatement, string newAnswer) =>
{
    var task = await context.Tasks.FindAsync(id);

    if (task == null)
    {
        throw new ArgumentNullException(nameof(task));
    }

    if (task.Statement != newStatement)
    {
        task.Statement = newStatement;
    }

    if (task.Answer != newAnswer)
    {
        task.Answer = newAnswer;
    }

    await context.SaveChangesAsync();
});

app.Run();

