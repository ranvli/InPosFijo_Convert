#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace proyecto1estructurasDatos {

	/// <summary>
	/// Resumen de sobre
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deber� cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilaci�n de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los dise�adores no podr�n interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class sobre : public System::Windows::Forms::Form
	{
	public:
		sobre(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n utilizando.
		/// </summary>
		~sobre()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido del m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(sobre::typeid));
			this->SuspendLayout();
			// 
			// sobre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1014, 738);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"sobre";
			this->Text = L"sobre";
			this->Load += gcnew System::EventHandler(this, &sobre::sobre_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void sobre_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};

}
