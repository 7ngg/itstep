using Microsoft.Extensions.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace hw_Farmanov_01._09._2024
{
    public partial class Form1 : Form
    {
        private SqlConnection _connection;
        private SqlDataAdapter adapter;
        private int _selectedRow;

        public DataSet Data { get; set; }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ConfigurationBuilder builder = new();
            builder.AddJsonFile("app-settings.json");
            _connection = new(builder.Build().GetConnectionString("Default"));

            try
            {
                _connection.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            using SqlCommand cmd = new("select [name] from sys.tables", _connection);
            using SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                tablesList.Items.Add(reader["name"]);
            }
        }

        private void CreateBtn_Click(object sender, EventArgs e)
        {
            MessageBox.Show($"{dataGrid.}");
        }

        private void ReadBtn_Click(object sender, EventArgs e)
        {
            if (tablesList.SelectedItem is null)
            {
                MessageBox.Show("Please, select a table", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Update(tablesList.SelectedItem.ToString());
            }
        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            Update(tablesList.SelectedItem.ToString());
        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            string tableName = tablesList.SelectedItem.ToString();
            string[] columns = GetColumns();
            string primaryKeyColumn = columns[0];

            string deleteQuery = $"delete from {tableName} where {primaryKeyColumn} = @selectedRow";

            using SqlCommand cmd = new(deleteQuery, _connection);
            cmd.Parameters.AddWithValue("@selectedRow", _selectedRow + 1);
            cmd.ExecuteNonQuery();

            Update(tableName);
        }

        private void dataGrid_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            _selectedRow = e.RowIndex;
        }

        private void Update(string tableName)
        {
            adapter = new($"select * from {tableName}", _connection);
            Data = new();
            adapter.Fill(Data);
            dataGrid.DataSource = Data.Tables[0];
        }

        private string[] GetColumns()
        {
            List<string> columns = [];
            using SqlCommand cmd = new(
                $"select c.name from sys.columns c inner join sys.tables t on t.object_id = c.object_id and t.name = '{tablesList.SelectedItem}' and t.type = 'U'",
                _connection
            );
            using SqlDataReader reader = cmd.ExecuteReader();

            while(reader.Read())
            {
                columns.Add(reader.GetString(0));
            }

            return [.. columns];
        }

        protected override void OnClosed(EventArgs e)
        {
            _connection.Dispose();
            base.OnClosed(e);
        }
    }
}
