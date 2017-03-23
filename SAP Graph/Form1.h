#pragma once
#include "Form2.h"
#include "Storage.h"
#include "Graph.h" 
#include "NewProj.h"
#include <Windows.h>

//Storage<Vertex> *V=new Storage<Vertex>;
//Storage<Edge> *E=new Storage<Edge>;
//Storage<Vertex> *EMV=new Storage<Vertex>;
Graph *GRAPH = new Graph(true, true);

int RAD=25;
int FRAME=4;
int** MX;
int *PATH;

int** M1;
int** M2;

Vertex* con=0;
Vertex* mov=0;

bool selecting=false;

extern bool again;

namespace SAPGraph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(bool wei, bool ori)
		{
			InitializeComponent();
			w=wei; o=ori;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool o;
	private: bool w;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  управлениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  обАвтореToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  настройкиToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::ColorDialog^  colorDialog1;
	public: System::Windows::Forms::ColorDialog^  colorDialog2;
	public: System::Windows::Forms::ColorDialog^  colorDialog3;



	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  новыйToolStripMenuItem;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->новыйToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->управлениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->обАвтореToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog3 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->менюToolStripMenuItem, 
				this->информацияToolStripMenuItem, this->настройкиToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1000, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->новыйToolStripMenuItem, 
				this->открытьToolStripMenuItem, this->сохранитьToolStripMenuItem});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// новыйToolStripMenuItem
			// 
			this->новыйToolStripMenuItem->Name = L"новыйToolStripMenuItem";
			this->новыйToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->новыйToolStripMenuItem->Text = L"Новый";
			this->новыйToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::новыйToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сохранитьToolStripMenuItem_Click);
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->управлениеToolStripMenuItem, 
				this->обАвтореToolStripMenuItem});
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(93, 20);
			this->информацияToolStripMenuItem->Text = L"Информация";
			// 
			// управлениеToolStripMenuItem
			// 
			this->управлениеToolStripMenuItem->Name = L"управлениеToolStripMenuItem";
			this->управлениеToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->управлениеToolStripMenuItem->Text = L"Управление";
			this->управлениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::управлениеToolStripMenuItem_Click);
			// 
			// обАвтореToolStripMenuItem
			// 
			this->обАвтореToolStripMenuItem->Name = L"обАвтореToolStripMenuItem";
			this->обАвтореToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->обАвтореToolStripMenuItem->Text = L"Об авторе";
			this->обАвтореToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::обАвтореToolStripMenuItem_Click);
			// 
			// настройкиToolStripMenuItem
			// 
			this->настройкиToolStripMenuItem->Name = L"настройкиToolStripMenuItem";
			this->настройкиToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->настройкиToolStripMenuItem->Text = L"Настройки";
			this->настройкиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::настройкиToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(0, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 570);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(806, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(141, 88);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"На графе";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(109, 65);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 13);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Нет";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(109, 52);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Да";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 65);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Ориентированный:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Взвешанный:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ребра:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Вершины:";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(812, 413);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"0";
			this->label6->Visible = false;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(9, 19);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(51, 20);
			this->numericUpDown1->TabIndex = 2;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(9, 19);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(83, 17);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"Выделение";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 24);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Снять выделение";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox3);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(815, 162);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(138, 78);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->numericUpDown1);
			this->groupBox3->Location = System::Drawing::Point(815, 246);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(79, 51);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Вес ребра";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 600);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SAP Graph";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				colorDialog1->Color=System::Drawing::Color::Cyan;	//Vertex
				colorDialog2->Color=System::Drawing::Color::Blue;	//Edge out
				colorDialog3->Color=System::Drawing::Color::Red;	//Edge in
				numericUpDown1->Value=1;

				/*NewProj^ np = gcnew NewProj(o,w);
				np->Show();
				o=(np->o);
				w=(np->w);*/

			/*	w=true;
				o=true;*/
				groupBox3->Visible=w;
				numericUpDown1->Visible=w;

				GRAPH = new Graph(w, o);
				if(w)
					label8->Text="Да";
				else
					label8->Text="Нет";
				if(o)
					label9->Text="Да";
				else
					label9->Text="Нет";
			}

	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { //MOUSE CLICK
				Vertex* hit=GRAPH->hit(e->X, e->Y); //Check to hit
				Edge* hited=GRAPH->hit_m(e->X, e->Y);
				//MiddleVert* middle=GRAPH->hit_middle(e->X, e->Y);
				
				if(selecting){
					if(hit){
						if(hit->selected)
							hit->selected=false;
						else hit->selected=true;
						pictureBox1->Refresh();
						return;
					}
				}//Selecting end

				else if(hit){
					if(e->Button==System::Windows::Forms::MouseButtons::Left){
						if(con){ //Connection
							GRAPH->AddEdge(con, hit, System::Convert::ToInt16(numericUpDown1->Value));
							con->connecting=false;
							con=0;
						} //Con end
					}//LMB end

					
					if(e->Button==System::Windows::Forms::MouseButtons::Right){
						GRAPH->Del(hit);
						hit=0;
					}//RMB end
				}//hit end
				else if(hited){
					if(e->Button==System::Windows::Forms::MouseButtons::Left)
						hited->Action();
					else if(e->Button==System::Windows::Forms::MouseButtons::Right){
						GRAPH->Del(hited);
						hited=0;
					}
				}//hited end
				else{
					if(e->Button==System::Windows::Forms::MouseButtons::Left){
						GRAPH->AddVert(new Vertex(e->X, e->Y));
					}
					if(e->Button==System::Windows::Forms::MouseButtons::Right){
						if(con)
							con->connecting=false;
						con=0;						
					}			
				}

				//pictureBox Refresh
				label2->Text=System::Convert::ToString(GRAPH->VertNUM());
				label4->Text=System::Convert::ToString(GRAPH->EdgeNUM());
				pictureBox1->Refresh();
			} //MouseClick end

	private: System::Void pictureBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { //DOUBLE CLICK
			if(e->Button==System::Windows::Forms::MouseButtons::Left)
				con=GRAPH->hit(e->X, e->Y); //Check to hit
			if(con)
				con->connecting=true;
			pictureBox1->Refresh();
			} // DoubleClick end

	private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { //Mouse Down
				mov=GRAPH->hit(e->X, e->Y);
				if(mov)
					mov->moving=true;
			} //MouseDown end

	private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { //Mouse UP
				if(mov)
					mov->moving=false;
				mov=0;
				
				pictureBox1->Refresh();
			} //MouseUp end

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { //MOVE
				if(!selecting)
				if(mov){
						GRAPH->Move(mov, e->X-mov->x, e->Y-mov->y, pictureBox1);
						pictureBox1->Refresh();
				} 
				
			} //Move end


	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) { //PICTUREBOX_1_PAINT
				GRAPH->Paint(e, colorDialog1->Color, colorDialog2->Color, colorDialog3->Color, colorDialog1->Color);

				label2->Text=System::Convert::ToString(GRAPH->VertNUM());
				label4->Text=System::Convert::ToString(GRAPH->EdgeNUM());	

				label6->Text=System::Convert::ToString(GRAPH->EmvNUM());	
			} //Paint end



private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Refresh();
		 }

private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			pictureBox1->Refresh();
		 }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*if(is_path){
				int N=V->numOf();
				Storage<Vertex>* NV=new Storage<Vertex>;
					for(int i=0;i<N;++i)
						NV->add(V->getObject(PATH[i]));
					V=NV;
			 }
			 textBox1->Text="";
			 button1->Enabled=false;
			 pictureBox1->Refresh();*/
		 }

		string SystemToStl(String ^s)
		{
			using namespace Runtime::InteropServices;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			return string(ptr);
		}

private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult dialogResult = MessageBox::Show("Хотите добавить файл в проект?", "Открыть", MessageBoxButtons::YesNo);
			if(dialogResult == System::Windows::Forms::DialogResult::Yes)
			{
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
				//openFileDialog1->Filter = "WeightOrinent Graph|*.wogrph|Weight Graph|*.wgrph|Orinent Graph|*.ogrph|Graph|*.grph";
				if(w){
					if(o)
						openFileDialog1->Filter = "WeightOrient Graph|*.wogrph";
					else
						openFileDialog1->Filter = "Weight Graph|*.wgrph";
				}
				else
					if(o)
						openFileDialog1->Filter = "Orinent Graph|*.ogrph";
					else
						openFileDialog1->Filter = "Graph|*.grph";


				openFileDialog1->Title = "Load Graph";
				openFileDialog1->ShowDialog();

				if(openFileDialog1->FileName != ""){					
					String^ fname=openFileDialog1->FileName;
					fname->Replace("\\", "/");
					ifstream* fin=new ifstream;
					fin->open(SystemToStl(fname));//("WOG.wogrph");//("gf.grp");

					GRAPH->AddLoad(fin);
					fin->close();

					o=GRAPH->isOriented();
					w=GRAPH->isWeight();				
				}
			}
			
			if(dialogResult == System::Windows::Forms::DialogResult::No)
			{
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
				openFileDialog1->Filter = "WeightOrinent Graph|*.wogrph|Weight Graph|*.wgrph|Orient Graph|*.ogrph|Graph|*.grph";
				//openFileDialog1->Filter = "WeightOrinent Graph|*.wogrph";
				openFileDialog1->Title = "Load Graph";
				openFileDialog1->ShowDialog();		

				if(openFileDialog1->FileName != ""){
					Graph* NewGRAPH = new Graph();
					String^ fname=openFileDialog1->FileName;
					fname->Replace("\\", "/");
					ifstream* fin=new ifstream;
					fin->open(SystemToStl(fname));//("WOG.wogrph");//("gf.grp");

					NewGRAPH->Load(fin);
					fin->close();

					o=NewGRAPH->isOriented();
					w=NewGRAPH->isWeight();
					if(GRAPH){ delete GRAPH;}
					GRAPH=NewGRAPH;

				
				}
			}
					
			groupBox3->Visible=GRAPH->isWeight();
			numericUpDown1->Visible=GRAPH->isWeight();
				if(w)
					label8->Text="Да";
				else
					label8->Text="Нет";
				if(o)
					label9->Text="Да";
				else
					label9->Text="Нет";
			pictureBox1->Refresh();
		}

private: System::Void сохранитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			//saveFileDialog1->Filter = "Graph File|*.grp";
			if(w==true){
				if(o==true)
					saveFileDialog1->Filter = "WeightOrinent Graph|*.wogrph";
				else if(o==false)
					saveFileDialog1->Filter = "Weight Graph|*.wgrph";
			}
			else if(w==false){
				if(o==true)
					saveFileDialog1->Filter = "Orinent Graph|*.ogrph";
				else if(o==false)
					saveFileDialog1->Filter = "Graph|*.grph";
			}
			saveFileDialog1->Title = "Save Graph";
			saveFileDialog1->ShowDialog();
			if(saveFileDialog1->FileName != "")			{
				ofstream* fout=new ofstream;
				fout->open(SystemToStl(saveFileDialog1->FileName));
				if(w) *fout<<"t "; else *fout<<"f ";
				if(o) *fout<<"t "; else *fout<<"f ";
				*fout<<endl;
				GRAPH->Save(fout);
				fout->close();
			}
		}
		

private: System::Void настройкиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Form2 ^gform2 = gcnew Form2(colorDialog1, colorDialog2, colorDialog3, pictureBox1, &GRAPH->RAD, &GRAPH->FRAME);
			 gform2->numericUpDown1->Value=GRAPH->RAD;
			 gform2->numericUpDown2->Value=GRAPH->FRAME;
			 gform2->colorDialog1->Color=colorDialog1->Color;
			 gform2->colorDialog2->Color=colorDialog2->Color;
			 gform2->colorDialog3->Color=colorDialog3->Color;
			 gform2->Show();

		}
private: System::Void управлениеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Вершины:\n  Создать новую вершину - клик левой кнопкой на пустое место.\n  Удалить вершину - клик правой кнопкой на вершину.\n\nРебра:\n  Соединить вершины ребром - двойной клик на начальной вершине, затем\n  клик на конечной.\n  Удалить ребро - клик правой кнопкой на центр ребра.\n\nАлгоритмы:\n  Для применения алгоритма выберите его из соответствующего пункта\n  меню, а затем кликните на начальную вершину.","Управление");
		 }
private: System::Void обАвтореToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Автор: Степанов Алексей Павлович. ПРО-209\nДанная программа разработана в качестве курсовой работы по дисциплине объектно-ориентированное программирование.","Об авторе");
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 selecting=checkBox3->Checked;
		 }
private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 checkBox3->Checked=false;
			 selecting=false;
			 GRAPH->Unselect();
			 pictureBox1->Refresh();
		 }
private: System::Void новыйToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult dialogResult = MessageBox::Show("Несохраненные данные будут потеряны. Вы уверены?", "Новый проект", MessageBoxButtons::YesNo);
			if(dialogResult == System::Windows::Forms::DialogResult::Yes)
			{
				again=true;
				Close();
			}
					
		 }
};
}