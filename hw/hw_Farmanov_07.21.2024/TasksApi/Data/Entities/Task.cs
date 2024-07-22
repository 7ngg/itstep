using System;
using System.Collections.Generic;

namespace TasksApi.Data.Entities;

public partial class Task
{
    public int Id { get; set; }

    public string? Statement { get; set; }

    public string Answer { get; set; } = null!;
}
