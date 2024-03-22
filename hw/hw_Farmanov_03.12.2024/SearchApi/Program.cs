using SearchApi.Services;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.MapGet("googlesearch", async (string query) =>
    {
        try
        {
            var response = await Search.GoogleSearch(query);
            return Results.Ok(response.Result);
        }
        catch (System.Exception e)
        {
            return Results.BadRequest(e.Message);
        }
    });

app.MapGet("googleimagesearch", async (string query) =>
    {
        try
        {
            var response = await Search.GoogleImageSearch(query);
            return Results.Ok(response.Result);
        }
        catch (System.Exception e)
        {
            return Results.BadRequest(e.Message);
        }
    });

app.Run();
