#pragma once
#include "CFig.h"
namespace Figuras {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			bff = space->Allocate(g, panel1->ClientRectangle);
			objf = new CFig(bff->Graphics);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		CFig* objf;
		Graphics^ g;
		BufferedGraphicsContext^ space;
	private: System::Windows::Forms::Button^ btnRX;
	private: System::Windows::Forms::Button^ btnRotacion;
	private: System::Windows::Forms::Button^ btnRY;
	private: System::Windows::Forms::Button^ btnROrigen;
	private: System::Windows::Forms::TrackBar^ tBAngulo;
	private: System::Windows::Forms::Label^ lblAngulo;
	private: System::Windows::Forms::Button^ btnYequalX;

		   BufferedGraphics^ bff;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnRX = (gcnew System::Windows::Forms::Button());
			this->btnRotacion = (gcnew System::Windows::Forms::Button());
			this->btnRY = (gcnew System::Windows::Forms::Button());
			this->btnROrigen = (gcnew System::Windows::Forms::Button());
			this->tBAngulo = (gcnew System::Windows::Forms::TrackBar());
			this->lblAngulo = (gcnew System::Windows::Forms::Label());
			this->btnYequalX = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBAngulo))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(654, 463);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btnRX
			// 
			this->btnRX->Location = System::Drawing::Point(737, 30);
			this->btnRX->Name = L"btnRX";
			this->btnRX->Size = System::Drawing::Size(105, 36);
			this->btnRX->TabIndex = 1;
			this->btnRX->Text = L"Reflejo eje X";
			this->btnRX->UseVisualStyleBackColor = true;
			this->btnRX->Click += gcnew System::EventHandler(this, &MyForm::btnRX_Click);
			// 
			// btnRotacion
			// 
			this->btnRotacion->Location = System::Drawing::Point(737, 302);
			this->btnRotacion->Name = L"btnRotacion";
			this->btnRotacion->Size = System::Drawing::Size(105, 37);
			this->btnRotacion->TabIndex = 2;
			this->btnRotacion->Text = L"Rotacion";
			this->btnRotacion->UseVisualStyleBackColor = true;
			this->btnRotacion->Click += gcnew System::EventHandler(this, &MyForm::btnRotacion_Click);
			// 
			// btnRY
			// 
			this->btnRY->Location = System::Drawing::Point(737, 93);
			this->btnRY->Name = L"btnRY";
			this->btnRY->Size = System::Drawing::Size(105, 33);
			this->btnRY->TabIndex = 3;
			this->btnRY->Text = L"Reflejo eje Y";
			this->btnRY->UseVisualStyleBackColor = true;
			this->btnRY->Click += gcnew System::EventHandler(this, &MyForm::btnRY_Click);
			// 
			// btnROrigen
			// 
			this->btnROrigen->Location = System::Drawing::Point(737, 149);
			this->btnROrigen->Name = L"btnROrigen";
			this->btnROrigen->Size = System::Drawing::Size(105, 33);
			this->btnROrigen->TabIndex = 4;
			this->btnROrigen->Text = L"Reflejo Origen";
			this->btnROrigen->UseVisualStyleBackColor = true;
			this->btnROrigen->Click += gcnew System::EventHandler(this, &MyForm::btnROrigen_Click);
			// 
			// tBAngulo
			// 
			this->tBAngulo->Location = System::Drawing::Point(692, 372);
			this->tBAngulo->Maximum = 360;
			this->tBAngulo->Minimum = -360;
			this->tBAngulo->Name = L"tBAngulo";
			this->tBAngulo->Size = System::Drawing::Size(207, 45);
			this->tBAngulo->TabIndex = 5;
			this->tBAngulo->Scroll += gcnew System::EventHandler(this, &MyForm::tBAngulo_Scroll);
			// 
			// lblAngulo
			// 
			this->lblAngulo->AutoSize = true;
			this->lblAngulo->Location = System::Drawing::Point(779, 345);
			this->lblAngulo->Name = L"lblAngulo";
			this->lblAngulo->Size = System::Drawing::Size(13, 13);
			this->lblAngulo->TabIndex = 6;
			this->lblAngulo->Text = L"0";
			// 
			// btnYequalX
			// 
			this->btnYequalX->Location = System::Drawing::Point(737, 207);
			this->btnYequalX->Name = L"btnYequalX";
			this->btnYequalX->Size = System::Drawing::Size(105, 33);
			this->btnYequalX->TabIndex = 7;
			this->btnYequalX->Text = L"Reflejo Y = X";
			this->btnYequalX->UseVisualStyleBackColor = true;
			this->btnYequalX->Click += gcnew System::EventHandler(this, &MyForm::btnYequalX_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 487);
			this->Controls->Add(this->btnYequalX);
			this->Controls->Add(this->lblAngulo);
			this->Controls->Add(this->tBAngulo);
			this->Controls->Add(this->btnROrigen);
			this->Controls->Add(this->btnRY);
			this->Controls->Add(this->btnRotacion);
			this->Controls->Add(this->btnRX);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tBAngulo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bff->Graphics->Clear(Color::Black);
		objf->dibujaMapa(bff->Graphics);
		objf->dibujarFigura(bff->Graphics);
		bff->Render(g);
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btnRX_Click(System::Object^ sender, System::EventArgs^ e) {
		objf->reflejoEnX();
	}
private: System::Void btnRY_Click(System::Object^ sender, System::EventArgs^ e) {
	objf->reflejoEnY();
}
private: System::Void btnROrigen_Click(System::Object^ sender, System::EventArgs^ e) {
	objf->reflejoEnOrigen();
}
private: System::Void tBAngulo_Scroll(System::Object^ sender, System::EventArgs^ e) {
	lblAngulo->Text = tBAngulo->Value.ToString();
}
private: System::Void btnRotacion_Click(System::Object^ sender, System::EventArgs^ e) {
	objf->rotacion(tBAngulo->Value);
}
private: System::Void btnYequalX_Click(System::Object^ sender, System::EventArgs^ e) {
	objf->reflejoXequalY();
}
};
}
