#pragma once
#include "GameField.h"
//#include "stdafx.h"
#include <fstream>
#include<iostream>
using namespace std;
namespace WindowsForms {
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			fld = gcnew GameField(
				panel1->Width,
				panel1->Height,
				panel1->CreateGraphics()
			);
			openFileDialog1->Filter = "Text files(*.txt)|*.txt";//чтобы был только текстовый формат
			saveFileDialog1->Filter = "Text files(*.txt)|*.txt";

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Button^  btnNextStep;
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::Button^  stop;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnNextStep = (gcnew System::Windows::Forms::Button());
			this->start = (gcnew System::Windows::Forms::Button());
			this->stop = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->ForeColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(877, 439);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel1_MouseClick);
			this->panel1->Resize += gcnew System::EventHandler(this, &MainForm::panel1_Resize);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->btnSave);
			this->groupBox1->Controls->Add(this->btnLoad);
			this->groupBox1->Controls->Add(this->btnNextStep);
			this->groupBox1->Controls->Add(this->start);
			this->groupBox1->Controls->Add(this->stop);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(13, 458);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(877, 146);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление";
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(454, 98);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(102, 32);
			this->btnSave->TabIndex = 11;
			this->btnSave->Text = L"Сохранить";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(315, 98);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(108, 32);
			this->btnLoad->TabIndex = 10;
			this->btnLoad->Text = L"Загрузить";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click);
			// 
			// btnNextStep
			// 
			this->btnNextStep->Location = System::Drawing::Point(315, 55);
			this->btnNextStep->Name = L"btnNextStep";
			this->btnNextStep->Size = System::Drawing::Size(123, 29);
			this->btnNextStep->TabIndex = 9;
			this->btnNextStep->Text = L"Следующий шаг";
			this->btnNextStep->UseVisualStyleBackColor = true;
			this->btnNextStep->Click += gcnew System::EventHandler(this, &MainForm::btnNextStep_Click);
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(315, 20);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(108, 29);
			this->start->TabIndex = 8;
			this->start->Text = L"Старт";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &MainForm::start_Click);
			// 
			// stop
			// 
			this->stop->Location = System::Drawing::Point(454, 20);
			this->stop->Name = L"stop";
			this->stop->Size = System::Drawing::Size(89, 29);
			this->stop->TabIndex = 7;
			this->stop->Text = L"Стоп";
			this->stop->UseVisualStyleBackColor = true;
			this->stop->Visible = false;
			this->stop->Click += gcnew System::EventHandler(this, &MainForm::stop_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(112, 83);
			this->trackBar1->Maximum = 2000;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(157, 56);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Value = 500;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MainForm::trackBar1_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Скорость:";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(218, 53);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(51, 22);
			this->numericUpDown2->TabIndex = 4;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown2_ValueChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(218, 22);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(51, 22);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Размер по вертикали:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Размер поля по горизонтали:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 17);
			this->label1->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(902, 616);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(600, 400);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра\"Жизнь\"";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		GameField^ fld;
		GameField^ fld1;
		int k = 0;
		int cntckick = 0;


	private: System::Void btnNextStep_Click(System::Object^  sender, System::EventArgs^  e) {

		fld->NextGeneration();

	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		//fld->Update(panel1->Width, panel1->Height, panel1->CreateGraphics());
		fld->Paint();

	}
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int x = e->X;
		int y = e->Y;
		fld->ChangeState(x, y);
	}
	private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {

		btnNextStep->Enabled = false;
		stop->Enabled = true;
		start->Enabled = false;
		stop->Visible = true;
		btnLoad->Enabled = false;
		btnSave->Enabled = false;
		numericUpDown1->Enabled = false;
		numericUpDown2->Enabled = false;
		
			fld->StartLife();
		
	}
	private: System::Void stop_Click(System::Object^  sender, System::EventArgs^  e) {
		btnNextStep->Enabled = true;
		stop->Enabled = false;
		start->Enabled = true;
		btnLoad->Enabled = true;
		btnSave->Enabled = true;
		numericUpDown1->Enabled = true;
		numericUpDown2->Enabled = true;
		fld->StopLife();
	}
	private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {


		fld->speed = (2000 - trackBar1->Value);



	}
	private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		fld->StopLife();
	}
	private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e) {
		int width1 = panel1->Width;
		int height1 = panel1->Height;
		if (fld != nullptr) {

			fld->Update(width1, height1, panel1->CreateGraphics());
		}

	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {//строки

		fld->StopLife();

		fld = gcnew GameField(Int32(numericUpDown1->Value), Int32(numericUpDown2->Value), panel1->Width, panel1->Height, panel1->CreateGraphics());
		fld->Paint();

	}
	private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

		fld->StopLife();
		fld = gcnew GameField(Int32(numericUpDown1->Value), Int32(numericUpDown2->Value), panel1->Width, panel1->Height, panel1->CreateGraphics());
		fld->Paint();
	}
	private: System::Void MainForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		//fld->Update(panel1->Width, panel1->Height, panel1->CreateGraphics());
	}
	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
		
		try {
			saveFileDialog1->ShowDialog();
			String^ mas = "";
			mas = fld->Cols.ToString() + "." + fld->Rows.ToString() + ".";
			for (int i = 0; i < fld->Rows; i++)
			{
				for (int j = 0; j < fld->Cols; j++)
				{
					mas += (Int32(fld->Field[i, j])).ToString();
				}

			}
			System::IO::File::WriteAllText(saveFileDialog1->FileName, mas);//сохраняет из массива в файл который выбрали
			MessageBox::Show("Файл сохранен");
		}
		catch (...)
		{
		}
	}
	

	
  private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
	cntckick++;
	
}
private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) {

	try {
		fld->StopLife();
		openFileDialog1->ShowDialog();
		String^ fileText = System::IO::File::ReadAllText(openFileDialog1->FileName);//открывает файл считвает все изаерываеь
		int x = fileText->IndexOf('.');//индекс первого входжения
		int y = fileText->LastIndexOf('.');//индекс полследнего вхождения
		int c = Int32::Parse(fileText->Substring(0, x));//подстрока
		int r = Int32::Parse(fileText->Substring(x + 1, y - x - 1));
		numericUpDown2->Value = c;
		numericUpDown1->Value = r;
		fld = gcnew GameField(Int32(numericUpDown1->Value), Int32(numericUpDown2->Value), panel1->Width, panel1->Height, panel1->CreateGraphics());
		int k = y + 1;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (fileText[k] == '0')
				{
					fld->Field[i, j] = false;
				}
				else
				{
					fld->Field[i, j] = true;
				}
				k++;

			}

		}
		fld->Paint();
	}
	catch (...) {}

}
};
}
