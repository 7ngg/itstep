using Microsoft.EntityFrameworkCore;

namespace TasksApi.Data.Contexts;

public partial class TasksDbContext : DbContext
{
    public TasksDbContext()
    {
    }

    public TasksDbContext(DbContextOptions<TasksDbContext> options)
        : base(options)
    {
    }

    public virtual DbSet<TasksApi.Data.Entities.Task> Tasks { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<TasksApi.Data.Entities.Task>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK__Tasks__3213E83FC1142FA2");

            entity.HasIndex(e => e.Statement, "UQ__Tasks__047B2473D20EFE46").IsUnique();

            entity.Property(e => e.Id).HasColumnName("id");
            entity.Property(e => e.Answer)
                .HasMaxLength(256)
                .HasColumnName("answer");
            entity.Property(e => e.Statement)
                .HasMaxLength(256)
                .HasColumnName("statement");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
