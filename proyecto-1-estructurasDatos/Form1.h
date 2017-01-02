#pragma once
#include <fstream>  //fstream, ifstream, ofstream
#include <string>   //string, getline()
#include <iostream> //cout
#include "sobre.h"

using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
using namespace System::IO;


namespace proyecto1estructurasDatos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>

	lista enPostFijo;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			
			//
			//TODO: agregar código de constructor aquí
			//

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sepToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  autoresToolStripMenuItem;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->autoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(7, 71);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(646, 29);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Abra archivo o digite la expresión en infijo a convertir";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(7, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Expresión convertida en postfijo";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(7, 143);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(646, 29);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 267);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 43);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Convertir a postfijo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(8, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Archivo : Ninguno";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(7, 218);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(278, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Conservar paréntesis en expresión destino convertida";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(7, 241);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(462, 17);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"Colocar brackets a expresión destino convertida para diferenciar números de 2 o m" 
				L"ás dígitos";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->archivoToolStripMenuItem, 
				this->sobreToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(668, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->abrirToolStripMenuItem, 
				this->sepToolStripMenuItem});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::abrirToolStripMenuItem_Click);
			// 
			// sepToolStripMenuItem
			// 
			this->sepToolStripMenuItem->Name = L"sepToolStripMenuItem";
			this->sepToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sepToolStripMenuItem->Text = L"Salir";
			this->sepToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sepToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 267);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 43);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Evaluar expresión convertida";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(7, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Resultado : ";
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->autoresToolStripMenuItem});
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			// 
			// autoresToolStripMenuItem
			// 
			this->autoresToolStripMenuItem->Name = L"autoresToolStripMenuItem";
			this->autoresToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->autoresToolStripMenuItem->Text = L"Los Autores";
			this->autoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::autoresToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 318);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Convertidor de expresiones InFijas a PostFijas";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {



			 }


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	

				 String^ exp = textBox1->Text; //crea string para contener el texto en textbox1
				 
				 if(!exp->Contains("#")){
					 MessageBox::Show("La expresión debe terminar con el carácter #");
					 return;
				 }
				 
				 lista expresion; //lista contenedora de toda la expresion

			     int pos = -1;
				 char car = NULL;


				 while(car != '#'){
					 pos++;
					 car = exp[pos];
					 //car contiene el caracter en posicion pos;
					 
					 //verificar si es un digito mas grande
					 String^ num = "";
					 
					 while(System::Char().IsDigit((exp[pos]))){
						 num+= exp->Substring(pos, 1);
						 pos++;
					 }

					 //agrega a la lista dependiendo del tipo de dato
					 if (num == "") { expresion.insertaAlFinal(car); };
					 if (num != "") { 
						 int numero = Convert::ToInt32(num);
						 expresion.insertaAlFinal(numero);
						 pos--;
					 }

				 }
				 
				 

				//MessageBox::Show(expresion.muestraLista());
				//--------------- HASTA AQUI CARGA LA EXPRESION en TEXTBOX1 EN UNA LISTA

				 
				 //aqui convierte
				util util;
				enPostFijo.~lista();

				//chequea los parentesis
				if(util.checkSintaxis(expresion) != 0){
					String^ lado;
					if(util.checkSintaxis(expresion) > 0) { lado = "derecha"; };
					if(util.checkSintaxis(expresion) < 0) { lado = "izquierda"; };
					MessageBox::Show("Hay un error en la sintaxis de la expresión, cuente bien los paréntesis. Faltan " + Convert::ToString(Math::Abs(util.checkSintaxis(expresion))) + " paréntesis a la " + lado);
					return;
				}

				
				
				util.convierteAPostFijo(expresion, enPostFijo, checkBox1->Checked::get(), checkBox2->Checked::get());
				textBox2->Text::set(enPostFijo.muestraLista());

				//MessageBox::Show(enPostFijo.muestraLista());
				


				 
				 


				 
				


			 }


	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {




		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void sepToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 //salir del programa
			 exit(0);


		 }
private: System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 
			 //aqui abre el archivo pedido y lo pone en el textbox


			 label4->Text::set("Resultado : 0");

				System::Windows::Forms::DialogResult res = openFileDialog1->ShowDialog(); 

				if(res == System::Windows::Forms::DialogResult::OK){

					String^ archivo = openFileDialog1->FileName;
					StreamReader^ lee = gcnew StreamReader(archivo);

					label3->Text::set("Archivo : " + archivo);
					textBox1->Text::set(lee->ReadLine());

					lee->Close();

				}




		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {


			 util util;
			 if (!enPostFijo.ListaVacia()) label4->Text::set("Resultado : " + util.evaluaEnPostFijo(enPostFijo).ToString());
			 if (enPostFijo.ListaVacia()) {
				 MessageBox::Show("No ha convertido ninguna expresion de infijo a postfijo aún, debe de convertir primero para ejecutar esta función.");
			 }


		 }
private: System::Void autoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


			 
			 sobre^ s = gcnew sobre();
			 
			 s->ShowDialog();


		 }
};




}

