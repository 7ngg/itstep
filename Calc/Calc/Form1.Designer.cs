namespace Calc
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tableLayoutPanel1 = new TableLayoutPanel();
            DivideButton = new Button();
            DotButton = new Button();
            button0 = new Button();
            ClearButton = new Button();
            MultiplyButton = new Button();
            button9 = new Button();
            button8 = new Button();
            button7 = new Button();
            MinusButton = new Button();
            button6 = new Button();
            button5 = new Button();
            button4 = new Button();
            PlusButton = new Button();
            button3 = new Button();
            button2 = new Button();
            MainTextBox = new RichTextBox();
            button1 = new Button();
            EqualsButton = new Button();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 4;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Controls.Add(DivideButton, 3, 4);
            tableLayoutPanel1.Controls.Add(DotButton, 2, 4);
            tableLayoutPanel1.Controls.Add(button0, 1, 4);
            tableLayoutPanel1.Controls.Add(ClearButton, 0, 4);
            tableLayoutPanel1.Controls.Add(MultiplyButton, 3, 3);
            tableLayoutPanel1.Controls.Add(button9, 2, 3);
            tableLayoutPanel1.Controls.Add(button8, 1, 3);
            tableLayoutPanel1.Controls.Add(button7, 0, 3);
            tableLayoutPanel1.Controls.Add(MinusButton, 3, 2);
            tableLayoutPanel1.Controls.Add(button6, 2, 2);
            tableLayoutPanel1.Controls.Add(button5, 1, 2);
            tableLayoutPanel1.Controls.Add(button4, 0, 2);
            tableLayoutPanel1.Controls.Add(PlusButton, 3, 1);
            tableLayoutPanel1.Controls.Add(button3, 2, 1);
            tableLayoutPanel1.Controls.Add(button2, 1, 1);
            tableLayoutPanel1.Controls.Add(MainTextBox, 0, 0);
            tableLayoutPanel1.Controls.Add(button1, 0, 1);
            tableLayoutPanel1.Controls.Add(EqualsButton, 1, 5);
            tableLayoutPanel1.Dock = DockStyle.Fill;
            tableLayoutPanel1.Location = new Point(0, 0);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 6;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 15F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.Size = new Size(234, 361);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // DivideButton
            // 
            DivideButton.Dock = DockStyle.Fill;
            DivideButton.Location = new Point(177, 255);
            DivideButton.Name = "DivideButton";
            DivideButton.Size = new Size(54, 48);
            DivideButton.TabIndex = 16;
            DivideButton.Text = "÷";
            DivideButton.UseVisualStyleBackColor = true;
            DivideButton.Click += DivideButton_Click;
            // 
            // DotButton
            // 
            DotButton.Dock = DockStyle.Fill;
            DotButton.Location = new Point(119, 255);
            DotButton.Name = "DotButton";
            DotButton.Size = new Size(52, 48);
            DotButton.TabIndex = 15;
            DotButton.Text = ",";
            DotButton.UseVisualStyleBackColor = true;
            DotButton.Click += DotButton_Click;
            // 
            // button0
            // 
            button0.Dock = DockStyle.Fill;
            button0.Location = new Point(61, 255);
            button0.Name = "button0";
            button0.Size = new Size(52, 48);
            button0.TabIndex = 14;
            button0.Text = "0";
            button0.UseVisualStyleBackColor = true;
            button0.Click += button0_Click;
            // 
            // ClearButton
            // 
            ClearButton.Dock = DockStyle.Fill;
            ClearButton.Location = new Point(3, 255);
            ClearButton.Name = "ClearButton";
            ClearButton.Size = new Size(52, 48);
            ClearButton.TabIndex = 13;
            ClearButton.Text = "C";
            ClearButton.UseVisualStyleBackColor = true;
            ClearButton.Click += ClearButton_Click;
            // 
            // MultiplyButton
            // 
            MultiplyButton.Dock = DockStyle.Fill;
            MultiplyButton.Location = new Point(177, 201);
            MultiplyButton.Name = "MultiplyButton";
            MultiplyButton.Size = new Size(54, 48);
            MultiplyButton.TabIndex = 12;
            MultiplyButton.Text = "*";
            MultiplyButton.UseVisualStyleBackColor = true;
            MultiplyButton.Click += MultiplyButton_Click;
            // 
            // button9
            // 
            button9.Dock = DockStyle.Fill;
            button9.Location = new Point(119, 201);
            button9.Name = "button9";
            button9.Size = new Size(52, 48);
            button9.TabIndex = 11;
            button9.Text = "9";
            button9.UseVisualStyleBackColor = true;
            button9.Click += button9_Click;
            // 
            // button8
            // 
            button8.Dock = DockStyle.Fill;
            button8.Location = new Point(61, 201);
            button8.Name = "button8";
            button8.Size = new Size(52, 48);
            button8.TabIndex = 10;
            button8.Text = "8";
            button8.UseVisualStyleBackColor = true;
            button8.Click += button8_Click;
            // 
            // button7
            // 
            button7.Dock = DockStyle.Fill;
            button7.Location = new Point(3, 201);
            button7.Name = "button7";
            button7.Size = new Size(52, 48);
            button7.TabIndex = 9;
            button7.Text = "7";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // MinusButton
            // 
            MinusButton.Dock = DockStyle.Fill;
            MinusButton.Location = new Point(177, 147);
            MinusButton.Name = "MinusButton";
            MinusButton.Size = new Size(54, 48);
            MinusButton.TabIndex = 8;
            MinusButton.Text = "-";
            MinusButton.UseVisualStyleBackColor = true;
            MinusButton.Click += MinusButton_Click;
            // 
            // button6
            // 
            button6.Dock = DockStyle.Fill;
            button6.Location = new Point(119, 147);
            button6.Name = "button6";
            button6.Size = new Size(52, 48);
            button6.TabIndex = 7;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // button5
            // 
            button5.Dock = DockStyle.Fill;
            button5.Location = new Point(61, 147);
            button5.Name = "button5";
            button5.Size = new Size(52, 48);
            button5.TabIndex = 6;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button4
            // 
            button4.Dock = DockStyle.Fill;
            button4.Location = new Point(3, 147);
            button4.Name = "button4";
            button4.Size = new Size(52, 48);
            button4.TabIndex = 5;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // PlusButton
            // 
            PlusButton.Dock = DockStyle.Fill;
            PlusButton.Location = new Point(177, 93);
            PlusButton.Name = "PlusButton";
            PlusButton.Size = new Size(54, 48);
            PlusButton.TabIndex = 4;
            PlusButton.Text = "+";
            PlusButton.UseVisualStyleBackColor = true;
            PlusButton.Click += PlusButton_Click;
            // 
            // button3
            // 
            button3.Dock = DockStyle.Fill;
            button3.Location = new Point(119, 93);
            button3.Name = "button3";
            button3.Size = new Size(52, 48);
            button3.TabIndex = 3;
            button3.Text = "3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button2
            // 
            button2.Dock = DockStyle.Fill;
            button2.Location = new Point(61, 93);
            button2.Name = "button2";
            button2.Size = new Size(52, 48);
            button2.TabIndex = 2;
            button2.Text = "2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // MainTextBox
            // 
            tableLayoutPanel1.SetColumnSpan(MainTextBox, 4);
            MainTextBox.Dock = DockStyle.Fill;
            MainTextBox.Location = new Point(3, 3);
            MainTextBox.Name = "MainTextBox";
            MainTextBox.Size = new Size(228, 84);
            MainTextBox.TabIndex = 0;
            MainTextBox.Text = "";
            // 
            // button1
            // 
            button1.Dock = DockStyle.Fill;
            button1.Location = new Point(3, 93);
            button1.Name = "button1";
            button1.Size = new Size(52, 48);
            button1.TabIndex = 1;
            button1.Text = "1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // EqualsButton
            // 
            tableLayoutPanel1.SetColumnSpan(EqualsButton, 2);
            EqualsButton.Location = new Point(61, 309);
            EqualsButton.Name = "EqualsButton";
            EqualsButton.Size = new Size(110, 48);
            EqualsButton.TabIndex = 17;
            EqualsButton.Text = "=";
            EqualsButton.UseVisualStyleBackColor = true;
            EqualsButton.Click += EqualsButton_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(234, 361);
            Controls.Add(tableLayoutPanel1);
            MaximumSize = new Size(250, 400);
            MinimumSize = new Size(250, 400);
            Name = "Form1";
            Text = "Form1";
            tableLayoutPanel1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Button button2;
        private RichTextBox MainTextBox;
        private Button button1;
        private Button EqualsButton;
        private Button DivideButton;
        private Button DotButton;
        private Button button0;
        private Button ClearButton;
        private Button MultiplyButton;
        private Button button9;
        private Button button8;
        private Button button7;
        private Button MinusButton;
        private Button button6;
        private Button button5;
        private Button button4;
        private Button PlusButton;
        private Button button3;
    }
}