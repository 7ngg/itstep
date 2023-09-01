using System.Net;
using System.Text.RegularExpressions;

namespace Task4
{

    class Website
    {
        readonly string IP_pattern = @"^((25[0-5]|(2[0-4]|1\d|[1-9]|)\d)\.?\b){4}$";
        public required string Name { get; set; }
        public string? Description { get; set ; }
        public required string IP { 
            get { return IP; }
            set
            {
                if (Regex.Match(value, IP_pattern).Success)
                {
                    IP = value;
                }
                else
                {
                    throw new Exception("Invalid IP");
                }
            }
        }
        public string? Domain { get; set; }

        
        public void edit() {
            string tmpStr;

            Console.Write(
                "Edit: \n" +
                "1. Name \n" +
                "2. Descrition \n" +
                "3. IP \n" +
                "4. Domain \n" +
                "> "
            );
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.Write("New name: ");
                    tmpStr = Console.ReadLine() ?? throw new Exception("Website has to have a name");
                    this.Name = tmpStr;

                    break;

                case 2:
                    Console.WriteLine("Description: ");
                    tmpStr = Console.ReadLine() ?? "None";
                    this.Description = tmpStr;

                    break;

                case 3:
                    Console.Write("New IP: ");
                    tmpStr = Console.ReadLine() ?? "0.0.0.0";

                    if (Regex.Match(tmpStr, IP_pattern).Success)
                    {
                        this.IP = tmpStr;
                    }
                    else
                    {
                        System.Console.WriteLine("No match found");
                    }

                    break;

                case 4:
                    Console.Write("New domain: ");
                    tmpStr = Console.ReadLine() ?? "None";
                    this.Domain = tmpStr;

                    break;

                default:
                    break;
            }
        }
    

        public void print() {
            Console.WriteLine(
                $"Name: {Name}\n" +
                $"IP: {IP}\n" +
                $"Domain: {Domain}\n"
            );
        }
    }
}