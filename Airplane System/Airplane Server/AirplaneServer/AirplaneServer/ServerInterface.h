#pragma once
#include "Server.h"
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


namespace AirplaneServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	public ref class ServerInterface : public System::Windows::Forms::Form
	{
		//GUI components
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btnLoadLog;
	private: System::Windows::Forms::ListBox^  lstLog;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  lblNumOfClients;

	private: System::Windows::Forms::RichTextBox^  txtView;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::ComboBox^  cboAirplanes;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  txtWarning;
	public: System::Windows::Forms::TextBox^  txtFlightNumber;
	private:
	private: System::Windows::Forms::Label^  label6;
	public:
	private: System::Windows::Forms::Label^  lblFuelWarning;
	private: System::Windows::Forms::Label^  label13;
	public: System::Windows::Forms::TextBox^  txtSize;
	private:
	private: System::Windows::Forms::Label^  label10;
	public:
	public: System::Windows::Forms::TextBox^  txtDistance;
	private:
	private: System::Windows::Forms::Label^  label9;
	public:
	public: System::Windows::Forms::TextBox^  txtDestLat;
	private:
	private: System::Windows::Forms::Label^  label8;
	public:
	public: System::Windows::Forms::TextBox^  txtDestLong;
	private:
	private: System::Windows::Forms::Label^  label7;
	public:
	private: System::Windows::Forms::PictureBox^  picAlarm;
	private: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::TextBox^  txtAltitude;
	private:
	private: System::Windows::Forms::Label^  label3;
	public:
	private: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::TextBox^  txtTemperature;
	private:
	private: System::Windows::Forms::Label^  lbl1;
	public:
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TextBox^  txtLatitude;
	private:
	public: System::Windows::Forms::TextBox^  txtSpeed;
	public: System::Windows::Forms::TextBox^  txtLongitude;
	private: System::Windows::Forms::Label^  label1;
	public:
	public: System::Windows::Forms::TextBox^  txtFuel;
	private:
	private: System::Windows::Forms::GroupBox^  groupBox3;
	public:
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  systemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;






			 //public methods and variables
	public:
		delegate void InvokeDelegate();
		Server *server;
		void LongRunningOperation();
		void onAnEvent();
		void updateTextBoxes();
		void fuelWarning();
		void minusValues(int index);
		int numberOfClients;

		ServerInterface(void)
		{
			//initialise
			InitializeComponent();
			numberOfClients = 0;
			server = new Server();
		}

	protected:
		~ServerInterface()
		{
			if (components)
			{
				delete components;
			}
		}
		//More GUI components


























	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

			 void InitializeComponent(void)
			 {
				 this->btnClear = (gcnew System::Windows::Forms::Button());
				 this->btnLoadLog = (gcnew System::Windows::Forms::Button());
				 this->lstLog = (gcnew System::Windows::Forms::ListBox());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->lblNumOfClients = (gcnew System::Windows::Forms::Label());
				 this->txtView = (gcnew System::Windows::Forms::RichTextBox());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->cboAirplanes = (gcnew System::Windows::Forms::ComboBox());
				 this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				 this->txtWarning = (gcnew System::Windows::Forms::Label());
				 this->txtFlightNumber = (gcnew System::Windows::Forms::TextBox());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->lblFuelWarning = (gcnew System::Windows::Forms::Label());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->txtSize = (gcnew System::Windows::Forms::TextBox());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->txtDistance = (gcnew System::Windows::Forms::TextBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->txtDestLat = (gcnew System::Windows::Forms::TextBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->txtDestLong = (gcnew System::Windows::Forms::TextBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->picAlarm = (gcnew System::Windows::Forms::PictureBox());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->txtAltitude = (gcnew System::Windows::Forms::TextBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->txtTemperature = (gcnew System::Windows::Forms::TextBox());
				 this->lbl1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->txtLatitude = (gcnew System::Windows::Forms::TextBox());
				 this->txtSpeed = (gcnew System::Windows::Forms::TextBox());
				 this->txtLongitude = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->txtFuel = (gcnew System::Windows::Forms::TextBox());
				 this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->systemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->groupBox1->SuspendLayout();
				 this->groupBox2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAlarm))->BeginInit();
				 this->groupBox3->SuspendLayout();
				 this->groupBox4->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // btnClear
				 // 
				 this->btnClear->Location = System::Drawing::Point(302, 515);
				 this->btnClear->Name = L"btnClear";
				 this->btnClear->Size = System::Drawing::Size(98, 32);
				 this->btnClear->TabIndex = 24;
				 this->btnClear->Text = L"Clear";
				 this->btnClear->UseVisualStyleBackColor = true;
				 this->btnClear->Click += gcnew System::EventHandler(this, &ServerInterface::btnClear_Click_1);
				 // 
				 // btnLoadLog
				 // 
				 this->btnLoadLog->Location = System::Drawing::Point(160, 514);
				 this->btnLoadLog->Name = L"btnLoadLog";
				 this->btnLoadLog->Size = System::Drawing::Size(117, 32);
				 this->btnLoadLog->TabIndex = 23;
				 this->btnLoadLog->Text = L"Load Log";
				 this->btnLoadLog->UseVisualStyleBackColor = true;
				 this->btnLoadLog->Click += gcnew System::EventHandler(this, &ServerInterface::btnLoadLog_Click_1);
				 // 
				 // lstLog
				 // 
				 this->lstLog->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lstLog->FormattingEnabled = true;
				 this->lstLog->ItemHeight = 16;
				 this->lstLog->Location = System::Drawing::Point(6, 17);
				 this->lstLog->Name = L"lstLog";
				 this->lstLog->Size = System::Drawing::Size(555, 484);
				 this->lstLog->TabIndex = 22;
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(98, 532);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(96, 13);
				 this->label12->TabIndex = 27;
				 this->label12->Text = L"Number of Clients :";
				 // 
				 // lblNumOfClients
				 // 
				 this->lblNumOfClients->AutoSize = true;
				 this->lblNumOfClients->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->lblNumOfClients->Location = System::Drawing::Point(200, 532);
				 this->lblNumOfClients->Name = L"lblNumOfClients";
				 this->lblNumOfClients->Size = System::Drawing::Size(30, 15);
				 this->lblNumOfClients->TabIndex = 26;
				 this->lblNumOfClients->Text = L" 0    ";
				 // 
				 // txtView
				 // 
				 this->txtView->Location = System::Drawing::Point(6, 16);
				 this->txtView->Name = L"txtView";
				 this->txtView->ReadOnly = true;
				 this->txtView->Size = System::Drawing::Size(303, 513);
				 this->txtView->TabIndex = 25;
				 this->txtView->Text = L"";
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->label14);
				 this->groupBox1->Controls->Add(this->cboAirplanes);
				 this->groupBox1->Location = System::Drawing::Point(4, 24);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(371, 52);
				 this->groupBox1->TabIndex = 29;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Choose a client";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(130, 22);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(76, 13);
				 this->label14->TabIndex = 17;
				 this->label14->Text = L"Client Number:";
				 // 
				 // cboAirplanes
				 // 
				 this->cboAirplanes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->cboAirplanes->FormattingEnabled = true;
				 this->cboAirplanes->Location = System::Drawing::Point(227, 19);
				 this->cboAirplanes->Name = L"cboAirplanes";
				 this->cboAirplanes->Size = System::Drawing::Size(43, 21);
				 this->cboAirplanes->TabIndex = 16;
				 this->cboAirplanes->SelectedIndexChanged += gcnew System::EventHandler(this, &ServerInterface::cboAirplanes_SelectedIndexChanged_1);
				 // 
				 // groupBox2
				 // 
				 this->groupBox2->Controls->Add(this->txtWarning);
				 this->groupBox2->Controls->Add(this->txtFlightNumber);
				 this->groupBox2->Controls->Add(this->label6);
				 this->groupBox2->Controls->Add(this->lblFuelWarning);
				 this->groupBox2->Controls->Add(this->label13);
				 this->groupBox2->Controls->Add(this->txtSize);
				 this->groupBox2->Controls->Add(this->label10);
				 this->groupBox2->Controls->Add(this->txtDistance);
				 this->groupBox2->Controls->Add(this->label9);
				 this->groupBox2->Controls->Add(this->txtDestLat);
				 this->groupBox2->Controls->Add(this->label8);
				 this->groupBox2->Controls->Add(this->txtDestLong);
				 this->groupBox2->Controls->Add(this->label7);
				 this->groupBox2->Controls->Add(this->picAlarm);
				 this->groupBox2->Controls->Add(this->label4);
				 this->groupBox2->Controls->Add(this->txtAltitude);
				 this->groupBox2->Controls->Add(this->label3);
				 this->groupBox2->Controls->Add(this->label5);
				 this->groupBox2->Controls->Add(this->txtTemperature);
				 this->groupBox2->Controls->Add(this->lbl1);
				 this->groupBox2->Controls->Add(this->label2);
				 this->groupBox2->Controls->Add(this->txtLatitude);
				 this->groupBox2->Controls->Add(this->txtSpeed);
				 this->groupBox2->Controls->Add(this->txtLongitude);
				 this->groupBox2->Controls->Add(this->label1);
				 this->groupBox2->Controls->Add(this->txtFuel);
				 this->groupBox2->Location = System::Drawing::Point(8, 82);
				 this->groupBox2->Name = L"groupBox2";
				 this->groupBox2->Size = System::Drawing::Size(366, 510);
				 this->groupBox2->TabIndex = 28;
				 this->groupBox2->TabStop = false;
				 this->groupBox2->Text = L"Airplane Details:";
				 // 
				 // txtWarning
				 // 
				 this->txtWarning->AutoSize = true;
				 this->txtWarning->BackColor = System::Drawing::Color::Transparent;
				 this->txtWarning->ForeColor = System::Drawing::Color::Maroon;
				 this->txtWarning->Location = System::Drawing::Point(144, 494);
				 this->txtWarning->Name = L"txtWarning";
				 this->txtWarning->Size = System::Drawing::Size(0, 13);
				 this->txtWarning->TabIndex = 28;
				 // 
				 // txtFlightNumber
				 // 
				 this->txtFlightNumber->Enabled = false;
				 this->txtFlightNumber->Location = System::Drawing::Point(172, 29);
				 this->txtFlightNumber->Name = L"txtFlightNumber";
				 this->txtFlightNumber->Size = System::Drawing::Size(182, 20);
				 this->txtFlightNumber->TabIndex = 26;
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(19, 32);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(75, 13);
				 this->label6->TabIndex = 27;
				 this->label6->Text = L"Flight Number:";
				 // 
				 // lblFuelWarning
				 // 
				 this->lblFuelWarning->AutoSize = true;
				 this->lblFuelWarning->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblFuelWarning->ForeColor = System::Drawing::Color::Maroon;
				 this->lblFuelWarning->Location = System::Drawing::Point(241, 274);
				 this->lblFuelWarning->Name = L"lblFuelWarning";
				 this->lblFuelWarning->Size = System::Drawing::Size(46, 12);
				 this->lblFuelWarning->TabIndex = 25;
				 this->lblFuelWarning->Text = L"Fuel Low!";
				 this->lblFuelWarning->Visible = false;
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(19, 406);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(136, 13);
				 this->label13->TabIndex = 24;
				 this->label13->Text = L"Last Packet Received Size";
				 // 
				 // txtSize
				 // 
				 this->txtSize->Enabled = false;
				 this->txtSize->Location = System::Drawing::Point(172, 406);
				 this->txtSize->Name = L"txtSize";
				 this->txtSize->Size = System::Drawing::Size(182, 20);
				 this->txtSize->TabIndex = 23;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(19, 371);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(102, 13);
				 this->label10->TabIndex = 20;
				 this->label10->Text = L"Distance Remaining";
				 // 
				 // txtDistance
				 // 
				 this->txtDistance->Enabled = false;
				 this->txtDistance->Location = System::Drawing::Point(172, 368);
				 this->txtDistance->Name = L"txtDistance";
				 this->txtDistance->Size = System::Drawing::Size(182, 20);
				 this->txtDistance->TabIndex = 19;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(19, 180);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(101, 13);
				 this->label9->TabIndex = 18;
				 this->label9->Text = L"Destination Latitude";
				 // 
				 // txtDestLat
				 // 
				 this->txtDestLat->Enabled = false;
				 this->txtDestLat->Location = System::Drawing::Point(171, 177);
				 this->txtDestLat->Name = L"txtDestLat";
				 this->txtDestLat->Size = System::Drawing::Size(183, 20);
				 this->txtDestLat->TabIndex = 17;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(19, 216);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(110, 13);
				 this->label8->TabIndex = 16;
				 this->label8->Text = L"Destination Longitude";
				 // 
				 // txtDestLong
				 // 
				 this->txtDestLong->Enabled = false;
				 this->txtDestLong->Location = System::Drawing::Point(171, 213);
				 this->txtDestLong->Name = L"txtDestLong";
				 this->txtDestLong->Size = System::Drawing::Size(183, 20);
				 this->txtDestLong->TabIndex = 15;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(188, 443);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(33, 13);
				 this->label7->TabIndex = 14;
				 this->label7->Text = L"Alarm";
				 // 
				 // picAlarm
				 // 
				 this->picAlarm->BackColor = System::Drawing::SystemColors::ButtonShadow;
				 this->picAlarm->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->picAlarm->Location = System::Drawing::Point(147, 459);
				 this->picAlarm->Name = L"picAlarm";
				 this->picAlarm->Size = System::Drawing::Size(118, 34);
				 this->picAlarm->TabIndex = 13;
				 this->picAlarm->TabStop = false;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(19, 145);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(91, 13);
				 this->label4->TabIndex = 10;
				 this->label4->Text = L"Current Longitude";
				 // 
				 // txtAltitude
				 // 
				 this->txtAltitude->Enabled = false;
				 this->txtAltitude->Location = System::Drawing::Point(172, 64);
				 this->txtAltitude->Name = L"txtAltitude";
				 this->txtAltitude->Size = System::Drawing::Size(182, 20);
				 this->txtAltitude->TabIndex = 1;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(19, 333);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(143, 13);
				 this->label3->TabIndex = 8;
				 this->label3->Text = L"Airplane Interior Temperature";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(19, 109);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(82, 13);
				 this->label5->TabIndex = 12;
				 this->label5->Text = L"Current Latitude";
				 // 
				 // txtTemperature
				 // 
				 this->txtTemperature->Enabled = false;
				 this->txtTemperature->Location = System::Drawing::Point(171, 330);
				 this->txtTemperature->Name = L"txtTemperature";
				 this->txtTemperature->Size = System::Drawing::Size(183, 20);
				 this->txtTemperature->TabIndex = 7;
				 // 
				 // lbl1
				 // 
				 this->lbl1->AutoSize = true;
				 this->lbl1->Location = System::Drawing::Point(19, 67);
				 this->lbl1->Name = L"lbl1";
				 this->lbl1->Size = System::Drawing::Size(42, 13);
				 this->lbl1->TabIndex = 2;
				 this->lbl1->Text = L"Altitude";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(19, 297);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(38, 13);
				 this->label2->TabIndex = 6;
				 this->label2->Text = L"Speed";
				 // 
				 // txtLatitude
				 // 
				 this->txtLatitude->Enabled = false;
				 this->txtLatitude->Location = System::Drawing::Point(172, 106);
				 this->txtLatitude->Name = L"txtLatitude";
				 this->txtLatitude->Size = System::Drawing::Size(182, 20);
				 this->txtLatitude->TabIndex = 11;
				 // 
				 // txtSpeed
				 // 
				 this->txtSpeed->Enabled = false;
				 this->txtSpeed->Location = System::Drawing::Point(171, 294);
				 this->txtSpeed->Name = L"txtSpeed";
				 this->txtSpeed->Size = System::Drawing::Size(183, 20);
				 this->txtSpeed->TabIndex = 5;
				 // 
				 // txtLongitude
				 // 
				 this->txtLongitude->Enabled = false;
				 this->txtLongitude->Location = System::Drawing::Point(172, 142);
				 this->txtLongitude->Name = L"txtLongitude";
				 this->txtLongitude->Size = System::Drawing::Size(182, 20);
				 this->txtLongitude->TabIndex = 9;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(19, 254);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(80, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Remaining Fuel";
				 // 
				 // txtFuel
				 // 
				 this->txtFuel->Enabled = false;
				 this->txtFuel->Location = System::Drawing::Point(171, 251);
				 this->txtFuel->Name = L"txtFuel";
				 this->txtFuel->Size = System::Drawing::Size(183, 20);
				 this->txtFuel->TabIndex = 3;
				 // 
				 // groupBox3
				 // 
				 this->groupBox3->Controls->Add(this->txtView);
				 this->groupBox3->Controls->Add(this->lblNumOfClients);
				 this->groupBox3->Controls->Add(this->label12);
				 this->groupBox3->Location = System::Drawing::Point(382, 24);
				 this->groupBox3->Name = L"groupBox3";
				 this->groupBox3->Size = System::Drawing::Size(316, 568);
				 this->groupBox3->TabIndex = 30;
				 this->groupBox3->TabStop = false;
				 this->groupBox3->Text = L"Console View";
				 // 
				 // groupBox4
				 // 
				 this->groupBox4->Controls->Add(this->lstLog);
				 this->groupBox4->Controls->Add(this->btnLoadLog);
				 this->groupBox4->Controls->Add(this->btnClear);
				 this->groupBox4->Location = System::Drawing::Point(707, 24);
				 this->groupBox4->Name = L"groupBox4";
				 this->groupBox4->Size = System::Drawing::Size(570, 568);
				 this->groupBox4->TabIndex = 31;
				 this->groupBox4->TabStop = false;
				 this->groupBox4->Text = L"Log Viewer";
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->systemToolStripMenuItem });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(1287, 24);
				 this->menuStrip1->TabIndex = 32;
				 this->menuStrip1->Text = L"menuStrip1";
				 this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &ServerInterface::menuStrip1_ItemClicked);
				 // 
				 // systemToolStripMenuItem
				 // 
				 this->systemToolStripMenuItem->BackColor = System::Drawing::Color::Gainsboro;
				 this->systemToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
				 this->systemToolStripMenuItem->Name = L"systemToolStripMenuItem";
				 this->systemToolStripMenuItem->Size = System::Drawing::Size(57, 20);
				 this->systemToolStripMenuItem->Text = L"System";
				 // 
				 // exitToolStripMenuItem
				 // 
				 this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
				 this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
				 this->exitToolStripMenuItem->Text = L"Exit";
				 this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ServerInterface::exitToolStripMenuItem_Click);
				 // 
				 // ServerInterface
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1287, 595);
				 this->Controls->Add(this->groupBox4);
				 this->Controls->Add(this->groupBox3);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->groupBox2);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->MaximumSize = System::Drawing::Size(1303, 634);
				 this->MinimumSize = System::Drawing::Size(1303, 634);
				 this->Name = L"ServerInterface";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Server";
				 this->Load += gcnew System::EventHandler(this, &ServerInterface::ServerInterface_Load);
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->groupBox2->ResumeLayout(false);
				 this->groupBox2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAlarm))->EndInit();
				 this->groupBox3->ResumeLayout(false);
				 this->groupBox3->PerformLayout();
				 this->groupBox4->ResumeLayout(false);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void ServerInterface_Load(System::Object^  sender, System::EventArgs^  e) {
		txtView->Text = "Server started. . .";
		//start new thread which listens for clients and outputs
		ThreadStart^ start = gcnew ThreadStart(this, &ServerInterface::LongRunningOperation);
		Thread^ t = gcnew Thread(start);
		t->Start();

	}
	private: System::Void btnLoadLog_Click(System::Object^  sender, System::EventArgs^  e) {
		//Loads log file into list box
		lstLog->Items->Clear();
		lstLog->Items->Add("Flight  Speed  Lat  Long  DestLat  DestLong  Alt  Temp  Fuel  Dist");
		std::ifstream log("logFile.log");
		std::string line;
		vector<std::string> myLines;
		if (!log)
		{
			lstLog->Items->Add("Log File Not Found");
		}
		else
		{
			while (std::getline(log, line))
			{
				replace(line.begin(), line.end(), ',', ' ');
				myLines.push_back(line);
				String^ newLine = gcnew String(line.c_str());
				lstLog->Items->Add(newLine);
			}
			log.close();
		}
	}
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		//exit button
		exit(0);
	}
	private: System::Void cboAirplanes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtSize_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtTime_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtDistance_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtTemperature_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtSpeed_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void lblFuelWarning_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtFuel_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtDestLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtDestLat_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtLongitude_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtLatitude_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtAltitude_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtFlightNumber_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void lbl1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
		lstLog->Items->Clear();
	}
	private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void btnLoadLog_Click_1(System::Object^  sender, System::EventArgs^  e) {
		lstLog->Items->Clear();
		lstLog->Items->Add("FID  Speed  Lat  Long  DestLa  DestLo  Alt  Temp  Fuel  Dist");
		std::ifstream log("logFile.log");
		std::string line;
		if (!log)
		{
			lstLog->Items->Add("Log file not found");
		}
		else
		{
			vector<std::string> myLines;
			while (std::getline(log, line))
			{
				replace(line.begin(), line.end(), ',', ' ');
				myLines.push_back(line);
				String^ newLine = gcnew String(line.c_str());
				lstLog->Items->Add(newLine);
			}
			log.close();
		}
	}
	private: System::Void btnClear_Click_1(System::Object^  sender, System::EventArgs^  e) {
		lstLog->Items->Clear();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void cboAirplanes_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
	picAlarm->BackColor = Color::White;
	txtWarning->Text = "";
}
};

	void ServerInterface::LongRunningOperation() {
		while (true)
		{
			this->CheckForIllegalCrossThreadCalls = false;
			this->ControlBox = false;
			//	this->CheckForIllegalCrossThreadCalls = false;
			//update the number of clients
			numberOfClients = server->update(txtView, cboAirplanes);
			//display number of clients on form
			this->lblNumOfClients->Text = numberOfClients + "";
			onAnEvent();
			Sleep(1000);
		}
	}

	void ServerInterface::onAnEvent() {
		if (InvokeRequired) {
			BeginInvoke(gcnew InvokeDelegate(this, &ServerInterface::onAnEvent));
		}
		updateTextBoxes();
	}


	void ServerInterface::updateTextBoxes()
	{
		if (cboAirplanes->Text != "")
		{
			//place the last received information for the client number selected
			//into the GUI
			int selectedIndex = Int32::Parse(cboAirplanes->Text);
			this->txtAltitude->Text = server->lastAltitude[selectedIndex] + " feet";
			this->txtLatitude->Text = server->lastLat[selectedIndex] + "";
			this->txtLongitude->Text = server->lastLong[selectedIndex] + "";
			this->txtDestLat->Text = server->lastDestLat[selectedIndex] + "";
			this->txtDestLong->Text = server->lastDestLong[selectedIndex] + "";
			this->txtFuel->Text = server->lastRemainingFuel[selectedIndex] + " litres";
			this->txtSpeed->Text = server->lastSpeed[selectedIndex] + " mph";
			this->txtTemperature->Text = server->lastTemp[selectedIndex] + " c";
			this->txtDistance->Text = (server->lastDistance[selectedIndex] + " miles");
			this->txtFlightNumber->Text = server->lastFlightNumber[selectedIndex] + "";
			this->txtSize->Text = server->lastSize[selectedIndex] + " bytes";
			minusValues(selectedIndex);
			if (server->lastLat[selectedIndex] != server->lastDestLat[selectedIndex] &&
				server->lastLong[selectedIndex != server->lastDestLong[selectedIndex]])
			{
				switch (server->warningStatus[selectedIndex])
				{
				case 1:
					//if warning number is 1, yellow alarm and add text
					picAlarm->BackColor = Color::Yellow;
					txtWarning->Text = "Warning Alarm Triggered";
					break;

				case 2:
					//if warning number is 2, orange alarm and add text
					picAlarm->BackColor = Color::Orange;
					txtWarning->Text = "Severe Alarm Triggered";
					break;
				case 3:
					//if warning number is 1, red alarm and add text
					picAlarm->BackColor = Color::Red;
					txtWarning->Text = "Critical Alarm Triggered";
					break;
				default:
					//By default, color is white and no message
					picAlarm->BackColor = Color::White;
					txtWarning->Text = "";
				}
			}
			server->dataReceived = false;
		}
	}

	//displays a warning when fuel is low
	void ServerInterface::fuelWarning()
	{
		if (server->returnFuelRemaining() < 1000)
		{
			lblFuelWarning->Visible = true;
		}
		else
		{
			lblFuelWarning->Visible = false;
		}
	}

	//prevents fraudulent data by ensuring no minus values where applicable
	void ServerInterface::minusValues(int selectedIndex)
	{
		if (server->lastAltitude[selectedIndex] < 0)
		{
			this->txtAltitude->Text = "0 feet";
		}


		if (server->lastRemainingFuel[selectedIndex] < 0)
		{
			this->txtFuel->Text = "0 litres";
		}


		if (server->lastSpeed[selectedIndex] < 0)
		{
			this->txtSpeed->Text = "0 mph";
		}

		if (server->lastDistance[selectedIndex] < 0)
		{
			this->txtDistance->Text = "0 miles";
		}
	}

}
