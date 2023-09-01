namespace Task6
{
    class Store {
        public required string Name { get; set; }
        public required string Address { get; set; }
        public string? Description { get; set; }
        public string? ContactPhone { get; set; }
        public string? ContactEmail { get; set; }

        public void print() {
            Console.WriteLine(
                $"Name: {Name}" +
                $"Address: {Address}" +
                $"Description: {Description ?? "None"}" +
                $"Contact phone: {ContactPhone ?? "None"}" +
                $"Contact email: {ContactEmail ?? "None"}"
            );
        }
    }
}